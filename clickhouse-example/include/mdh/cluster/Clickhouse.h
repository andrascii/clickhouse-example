#pragma once
#include <boost/asio.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <mdh/cluster/Args.h>
#include <mdh/cluster/Logger.h>
#include <mdh/cluster/Mutex.h>
#include <mdh/cluster/NullMutex.h>
#include <mdh/cluster/ProtobufAdapter.h>
#include <mdh/cluster/protobuf/clickhouse_grpc.grpc.pb.h>
#include <toml.hpp>
#include <vector>

namespace mdh::cluster {

class InsecureChannel final {
public:
  InsecureChannel() = delete;

  explicit InsecureChannel(std::string host);

  auto operator()() const -> std::shared_ptr<grpc::ChannelInterface>;

private:
  std::string host_;
};

template <typename T, typename Lock = NullMutex, typename Container = std::vector<T>>
class Clickhouse final {
  using Adapter = ProtobufContainerAdapter<T>;

public:
  Clickhouse(std::string name, std::size_t index, std::shared_ptr<Args const> args);

  auto Write(Container const &container) noexcept -> void;

private:
  std::string name_;
  std::size_t index_;
  std::shared_ptr<Adapter> adapter_;
  std::shared_ptr<Args const> args_;
  std::shared_ptr<grpc::ChannelInterface> grpc_channel_;
  std::shared_ptr<clickhouse::grpc::ClickHouse::Stub> grpc_client_;
  clickhouse::grpc::QueryInfo query_info_;
  std::string query_;
  std::string host_;
  std::string database_name_;
  std::string table_name_;
  std::string message_name_;
  std::string query_id_;
  std::string user_;
  std::string password_;
  Lock monitor_;
};

template <typename T, typename Lock, typename Container>
Clickhouse<T, Lock, Container>::Clickhouse(std::string name, std::size_t const index, std::shared_ptr<Args const> args)
    : name_{std::move(name)}
    , index_{index}
    , args_{std::move(args)} {
  try {
    adapter_ = std::make_shared<Adapter>();
    auto const root = toml::find((*args_)(), name_);
    auto const objects = toml::find(root, "objects").as_array();
    auto object = objects[index_];
    host_ = toml::find(object, "host").as_string();
    database_name_ = toml::find(object, "database").as_string();
    table_name_ = toml::find(object, "table").as_string();
    message_name_ = toml::find(object, "message").as_string();
    // query_id_ = toml::find(object, "query").as_string();
    query_id_ = "";
    user_ = toml::find(object, "user").as_string();
    password_ = toml::find(object, "password").as_string();
    grpc_channel_ = InsecureChannel{host_}();
    grpc_client_ = clickhouse::grpc::ClickHouse::NewStub(grpc_channel_);
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s}", ex.what());
    _Exit(EXIT_FAILURE);
  }

  query_ = std::format(
    "INSERT INTO {:s}.{:s} SETTINGS format_schema='{:s}:{:s}' FORMAT Protobuf",
    database_name_,
    table_name_,
    table_name_,
    message_name_
  );
}

template <typename T, typename Lock, typename Container>
auto Clickhouse<T, Lock, Container>::Write(Container const &container) noexcept -> void {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;
  std::unique_lock _{monitor_};
  try {
    std::stringstream str;
    for (auto const &message : container) {
      str << '\n';
      str << message;
    }
    LOG_INFO("{:s}", str.str());
    auto adapted = (*adapter_)(container);
    query_info_.set_query(query_);
    query_info_.set_database(database_name_);
    query_info_.set_query_id(query_id_);
    query_info_.set_output_format("TabSeparated");
    query_info_.set_send_output_columns(true);
    query_info_.set_user_name(user_);
    query_info_.set_password(password_);
    query_info_.set_input_data(adapted.data(), adapted.size());
    grpc::ClientContext context;
    clickhouse::grpc::Result result;
    if (auto const status = grpc_client_->ExecuteQuery(&context, query_info_, &result); status.error_code()) {
      LOG_FATAL("GRPC error {:s}", status.error_message());
      _Exit(EXIT_FAILURE);
    }
    if (result.has_exception()) {
      LOG_FATAL("ClickHouse error {:s}", result.exception().display_text());
      _Exit(EXIT_FAILURE);
    }
    LOG_INFO("{:s}: wrote {:d} rows of type {:s} to clickhouse", name_, container.size(), typeid(T).name());
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s} at {:s}:{:d}\n", ex.what(), __FILE__, __LINE__);
    _Exit(EXIT_FAILURE);
  }
}
} // namespace mdh::cluster
