#if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable : 5054)
#pragma warning(disable : 4996)
#pragma warning(disable : 4127)
#pragma warning(disable : 5054)
#pragma warning(disable : 4251)
#endif

#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>

#if defined(_WIN32)
#pragma warning(pop)
#endif

#include <clickhouse.grpc.pb.h>
#include <clickhouse.pb.h>
#include <google/protobuf/io/zero_copy_stream.h>

#include <boost/asio.hpp>
#include <toml.hpp>
#include <random>

#include "mdh/cluster/adapter/ProtobufAdapter.h"
#include "mdh/cluster/args/Args.h"
#include "mdh/cluster/log/Logger.h"
#include "order_book.h"
#include "auto_layoff_strategy.h"
#include "client_orders.h"
#include "client_trades.h"
#include "core_price_filtered.h"
#include "fads_markup.h"
#include "ilp_trades.h"
#include "tca_orders.h"
#include "tca_trades.h"
#include "forward_points_blending_weight.h"
#include "manual_forward_points.h"
#include "position_transfer_service_data.h"
#include "order_book_wide.h"

namespace mdh::cluster::db {

class InsecureChannel final {
 public:
  InsecureChannel() = delete;

  explicit InsecureChannel(std::string h) : host_{std::move(h)} {}

  auto operator()() const -> std::shared_ptr<grpc::ChannelInterface> {
    grpc::ChannelArguments args;
    args.SetLoadBalancingPolicyName("round_robin");
    args.SetCompressionAlgorithm(GRPC_COMPRESS_DEFLATE);
    return CreateCustomChannel(host_, grpc::InsecureChannelCredentials(), args);
  }

 private:
  std::string host_;
};

template <
  typename T,
  typename S = InsecureChannel,
  typename Buffer = std::vector<char>,
  typename Container = std::vector<T>>
class Clickhouse final {
  using Adapter = adapter::ProtobufAdapter<T, Buffer, Container>;

 public:
  explicit Clickhouse(
    std::string name,
    logger::Logger logger,
    std::shared_ptr<args::Args> args,
    std::string message_name,
    std::string table_name);

  auto Write(const Container& container) noexcept -> void;

  auto Select(
    const std::string& table,
    const std::vector<std::string>& fields) noexcept -> std::string;

 private:
  std::string name_;
  logger::Logger logger_;
  std::shared_ptr<Adapter> adapter_;
  std::shared_ptr<args::Args> args_;
  std::shared_ptr<grpc::ChannelInterface> grpc_channel_;
  std::unique_ptr<clickhouse::grpc::ClickHouse::Stub> grpc_client_;
  clickhouse::grpc::QueryInfo query_info_;
  std::string query_;
  std::string host_;
  std::string database_name_;
  std::string table_name_;
  std::string message_name_;
  std::string query_id_;
  std::string user_;
  std::string password_;
};

template <typename T, typename S, typename Buffer, typename Container>
Clickhouse<T, S, Buffer, Container>::Clickhouse(
  std::string name,
  logger::Logger logger,
  std::shared_ptr<args::Args> args,
  std::string message_name,
  std::string table_name)
    : name_{std::move(name)},
      logger_{std::move(logger)},
      adapter_{std::make_shared<Adapter>(logger_)},
      args_{std::move(args)} {
  try {
    auto root = toml::find((*args_)(), name_);
    host_ = toml::find(root, "host").as_string();
    database_name_ = toml::find(root, "database").as_string();
    table_name_ = toml::find(root, "table").as_string();
    message_name_ = toml::find(root, "message").as_string();
    query_id_ = "";
    user_ = toml::find(root, "user").as_string();
    password_ = toml::find(root, "password").as_string();
    grpc_channel_ = S{host_}();
    grpc_client_ = clickhouse::grpc::ClickHouse::NewStub(grpc_channel_);
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s}", ex.what());
    _Exit(EXIT_FAILURE);
  }

  query_ = fmt::format(
    "INSERT INTO {:s}.{:s} SETTINGS "
    "format_schema='{:s}:{:s}' FORMAT Protobuf",
    database_name_,
    table_name,
    table_name,
    message_name);
}

template <typename T, typename S, typename Buffer, typename Container>
auto Clickhouse<T, S, Buffer, Container>::Write(
  const Container& container) noexcept -> void {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;

  try {
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

    if (const auto status =
          grpc_client_->ExecuteQuery(&context, query_info_, &result);
        status.error_code()) {
      LOG_FATAL(logger_, "GRPC error {:s}", status.error_message());
      _Exit(EXIT_FAILURE);
    }

    if (result.has_exception()) {
      LOG_FATAL(logger_, "ClickHouse error {:s}", result.exception().display_text());
      _Exit(EXIT_FAILURE);
    }
    LOG_INFO(logger_, "{:s}: wrote {:d} rows of type {:s} to clickhouse", name_, container.size(), typeid(T).name());
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s} at {:s}:{:d}\n", ex.what(), __FILE__, __LINE__);
    _Exit(EXIT_FAILURE);
  }
}

template <typename T, typename S, typename Buffer, typename Container>
auto Clickhouse<T, S, Buffer, Container>::Select(
  const std::string& table,
  const std::vector<std::string>& fields) noexcept
  -> std::string {
  using namespace google::protobuf::util;

  clickhouse::grpc::QueryInfo request;
  request.set_query(
    fmt::format("SELECT {} FROM {}", boost::join(fields, ", "), table));

  clickhouse::grpc::Result response;
  grpc::ClientContext context;

  if (const auto status =
        grpc_client_->ExecuteQuery(&context, request, &response);
      status.error_code()) {
    LOG_FATAL(logger_, "GRPC error {:s}", status.error_message());
    _Exit(EXIT_FAILURE);
  }

  if (response.has_exception()) {
    LOG_FATAL(logger_, "ClickHouse error {:s}", response.exception().display_text());
    _Exit(EXIT_FAILURE);
  }

  return response.output();
}

}// namespace mdh::cluster::db

static std::string randomDecimalString() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 9);

  std::string decimalString;
  decimalString.reserve(7); // Резервируем память для строки

  for (int i = 0; i < 6; ++i) {
    decimalString += (char)('0' + dis(gen)); // Генерируем случайную цифру и добавляем ее к строке
  }

  // Добавляем десятичный разделитель
  decimalString.insert(decimalString.begin() + 2, '.');

  return decimalString;
}


// Функция для генерации случайной даты
static std::string randomDate() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 28);

  int day = dis(gen);
  int month = dis(gen);
  int year = dis(gen);

  return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
}

// Функция для генерации случайного числа от 0 до max
static int64_t randomInt(int64_t max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, max);

  return dis(gen);
}

// Функция для генерации случайной строки определенной длины
std::string randomString(int length) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis('a', 'z');

  std::string randomString;
  randomString.reserve(length);

  for (int i = 0; i < length; ++i) {
    randomString += (char)dis(gen); // Генерируем случайный символ и добавляем его к строке
  }

  return randomString;
}

int main() {
  using namespace mdh::cluster;

  const auto logger = spdlog::default_logger();

  const auto args = std::make_shared<args::Args>(logger, "config.toml");

  if (!args) {
    _Exit(EXIT_FAILURE);
  }

  const auto ob = std::make_unique<db::Clickhouse<OrderBook>>(
    "clickhouse",
    logger,
    args,
    "OrderBook",
    "OrderBookTable");

  /*ob->Write({
    OrderBook{
      .timestamp = Clock::now(),
      .symbol = "USD/RUB",
      .level = 1,
      .size = dec::decimal6{1'000'000},
      .price = dec::decimal6{100},
      .side = mdh::Side::kBid
    },
    OrderBook{
      .timestamp = Clock::now(),
      .symbol = "USD/RUB",
      .level = 2,
      .size = dec::decimal6{3'000'000},
      .price = dec::decimal6{99},
      .side = mdh::Side::kBid
    },
    OrderBook{
      .timestamp = Clock::now(),
      .symbol = "USD/RUB",
      .level = 1,
      .size = dec::decimal6{1'000'000},
      .price = dec::decimal6{99},
      .side = mdh::Side::kAsk
    },
    OrderBook{
      .timestamp = Clock::now(),
      .symbol = "USD/RUB",
      .level = 2,
      .size = dec::decimal6{3'000'000},
      .price = dec::decimal6{98},
      .side = mdh::Side::kAsk
    }
  });*/

  const auto als = std::make_unique<db::Clickhouse<AutoLayoffStrategy>>(
      "clickhouse",
      logger,
      args,
      "AutoLayoffStrategy",
      "AutoLayoffStrategyTable");

  /*als->Write({
    AutoLayoffStrategy{
      .timestamp = Clock::now(),
      .strategy_name = "strategy",
      .currency = "USD",
      .currency_pair = "USD/RUB",
      .state = "open",
      .paused = "unpaused",
      .paused_reasons = ""
    }
  });*/

  ClientOrders orders;

  // Инициализация всех полей структуры
  orders.timestamp = Clock::now();
  orders.allocation_number = randomInt(std::numeric_limits<int64_t>::max());
  orders.auto_amount = dec::decimal6(randomDecimalString());
  orders.avg_price_executed_near = dec::decimal6(randomDecimalString());
  orders.avg_trd_price_executed_near = dec::decimal6(randomDecimalString());
  orders.gtc_cancel_timestamp = dec::decimal6(randomDecimalString());
  orders.ilp_trade_id = randomInt(std::numeric_limits<int64_t>::max());
  orders.last_base_qty_executed_near = dec::decimal6(randomDecimalString());
  orders.last_price_executed_near = dec::decimal6(randomDecimalString());
  orders.last_trd_price_executed_near = dec::decimal6(randomDecimalString());
  orders.manual_amount = dec::decimal6(randomDecimalString());
  orders.order_base_quantity_far = dec::decimal6(randomDecimalString());
  orders.order_base_quantity_near = dec::decimal6(randomDecimalString());
  orders.order_price_far = dec::decimal6(randomDecimalString());
  orders.order_price_near = dec::decimal6(randomDecimalString());
  orders.order_term_quantity_far = dec::decimal6(randomDecimalString());
  orders.order_term_quantity_near = dec::decimal6(randomDecimalString());
  orders.qty_base_executed_near = dec::decimal6(randomDecimalString());
  orders.qty_base_remaining_near = dec::decimal6(randomDecimalString());
  orders.submit_timestamp = dec::decimal6(randomDecimalString());
  orders.update_time = dec::decimal6(randomDecimalString());
  orders.acceptance = randomString(10);
  orders.accepted_by = randomString(10);
  orders.allocations = randomString(10);
  orders.client_user_id = randomString(10);
  orders.currency = randomString(3);
  orders.database_id = randomString(10);
  orders.delivery_type = randomString(10);
  orders.executed_by = randomString(10);
  orders.execution = randomString(10);
  orders.extra_params = randomString(10);
  orders.has_ilp_trade_id = randomString(10);
  orders.id = randomString(10);
  orders.is_final = randomString(10);
  orders.manual_book = randomString(10);
  orders.message = randomString(10);
  orders.netting_option = randomString(10);
  orders.owner = randomString(10);
  orders.session = randomString(10);
  orders.state = randomString(10);
  orders.strategy_state = randomString(10);
  orders.time_in_force = randomString(10);
  orders.transport = randomString(10);
  orders.cri_check_id = randomString(10);
  orders.base_currency = randomString(3);
  orders.client_account = randomString(10);
  orders.client_order_id = randomString(10);
  orders.efx_order_id = randomString(10);
  orders.far_tenor = randomString(10);
  orders.far_value_date = randomDate();
  orders.fixing_date = randomDate();
  orders.fixing_source = randomString(10);
  orders.near_tenor = randomString(10);
  orders.near_value_date = randomDate();
  orders.product = randomString(10);
  orders.settlement_currency = randomString(3);  // Здесь генерируем случайную строку длиной 3
  orders.side = randomString(4);  // Генерируем случайную строку длиной 4
  orders.source = randomString(5);  // Генерируем случайную строку длиной 5
  orders.strategy = randomString(6);  // Генерируем случайную строку длиной 6
  orders.sub_status = randomString(7);  // Генерируем случайную строку длиной 7
  orders.symbol = randomString(8);  // Генерируем случайную строку длиной 8
  orders.term_currency = randomString(3);  // Здесь генерируем случайную строку длиной 3
  orders.tier = randomString(4);  // Генерируем случайную строку длиной 4
  orders.type = randomString(5);  // Генерируем случайную строку длиной 5

  /*db::Clickhouse<ClientOrders>(
    "clickhouse",
    logger,
    args,
    "ClientOrders",
    "ClientOrdersTable").Write({orders});*/

  ClientTrades trades;
  trades.timestamp = Clock::now();
  trades.base_currency = randomString(3);
  trades.client_account = randomString(10);
  trades.client_order_id = randomString(10);
  trades.efx_order_id = randomString(10);
  trades.far_tenor = randomString(10);
  trades.far_value_date = randomDate();
  trades.fixing_date = randomDate();
  trades.fixing_source = randomString(10);
  trades.near_tenor = randomString(10);
  trades.near_value_date = randomDate();
  trades.product = randomString(10);
  trades.settlement_currency = randomString(3);  // Здесь генерируем случайную строку длиной 3
  trades.side = randomString(4);  // Генерируем случайную строку длиной 4
  trades.source = randomString(5);  // Генерируем случайную строку длиной 5
  trades.strategy = randomString(6);  // Генерируем случайную строку длиной 6
  trades.sub_status = randomString(7);  // Генерируем случайную строку длиной 7
  trades.symbol = randomString(8);  // Генерируем случайную строку длиной 8
  trades.term_currency = randomString(3);  // Здесь генерируем случайную строку длиной 3
  trades.tier = randomString(4);  // Генерируем случайную строку длиной 4
  trades.type = randomString(5);  // Генерируем случайную строку длиной 5
  trades.execute_timestamp = dec::decimal6(randomDecimalString());
  trades.price_executed_far = dec::decimal6(randomDecimalString());
  trades.price_executed_near = dec::decimal6(randomDecimalString());
  trades.quantity_base_executed_near = dec::decimal6(randomDecimalString());
  trades.quantity_term_executed_near = dec::decimal6(randomDecimalString());
  trades.swap_points = dec::decimal6(randomDecimalString());
  trades.trader_price = dec::decimal6(randomDecimalString());
  trades.trader_price_modified_timestamp = dec::decimal6(randomDecimalString());
  trades.book = randomString(5);  // Генерируем случайную строку длиной 5
  trades.execution_id = randomString(5);  // Генерируем случайную строку длиной 5
  trades.is_reciprocal = randomString(5);  // Генерируем случайную строку длиной 5
  trades.quoted_by = randomString(5);  // Генерируем случайную строку длиной 5
  trades.quote_type = randomString(5);  // Генерируем случайную строку длиной 5
  trades.trader_price_modified_by = randomString(5);  // Генерируем случайную строку длиной 5

  /*db::Clickhouse<ClientTrades>(
    "clickhouse",
    logger,
    args,
    "ClientTrades",
    "ClientTradesTable").Write({trades});*/

  CorePriceFiltered cpf;
  cpf.timestamp = Clock::now();
  cpf.id = 100500;
  cpf.symbol = "USDRUB";
  cpf.min_spread = dec::decimal6(randomDecimalString());
  cpf.sharp_move_period = dec::decimal6(randomDecimalString());
  cpf.sharp_move_diff = dec::decimal6(randomDecimalString());
  cpf.volatility_period = dec::decimal6(randomDecimalString());
  cpf.volatility_interval = dec::decimal6(randomDecimalString());
  cpf.volatility_sensitivity = dec::decimal6(randomDecimalString());
  cpf.max_spread = dec::decimal6(randomDecimalString());
  cpf.decay_parameter = dec::decimal6(randomDecimalString());

  /*db::Clickhouse<CorePriceFiltered>(
    "clickhouse",
    logger,
    args,
    "CorePriceFiltered",
    "CorePriceFilteredTable").Write({cpf});*/

  FadsMarkup fads_markup{};
  fads_markup.timestamp = Clock::now();
  fads_markup.id = 100500;
  fads_markup.volume_band = 12345;
  fads_markup.symbol = "USDRUB";
  fads_markup.tier = "RMKV";
  fads_markup.client = "Vasya";
  fads_markup.tenor = "TOM";
  fads_markup.strategy = "STRATEGY - KUPI I ZABEY HUI";
  fads_markup.enabled = "false";
  fads_markup.updated_by = "trader Petya";
  fads_markup.bid_spd = dec::decimal6(randomDecimalString());
  fads_markup.ask_spd = dec::decimal6(randomDecimalString());
  fads_markup.bid_bp = dec::decimal6(randomDecimalString());
  fads_markup.ask_bp = dec::decimal6(randomDecimalString());
  fads_markup.updated_at = dec::decimal6(randomDecimalString());

  /*db::Clickhouse<FadsMarkup>(
    "clickhouse",
    logger,
    args,
    "FadsMarkup",
    "FadsMarkupTable").Write({fads_markup});*/

  std::cout
    << "SELECT result OrderBook:\n"
    << ob->Select("OrderBookTable"s, {"*"})
    << std::endl;

  std::cout
    << "SELECT result AutoLayoffStrategy:\n"
    << ob->Select("AutoLayoffStrategyTable"s, {"*"})
    << std::endl;

  std::cout
    << "SELECT result ClientOrders:\n"
    << ob->Select("ClientOrdersTable"s, {"*"})
    << std::endl;

  std::cout
    << "SELECT result ClientTrades:\n"
    << ob->Select("ClientTradesTable"s, {"*"})
    << std::endl;

  std::cout
    << "SELECT result CorePriceFiltered:\n"
    << ob->Select("CorePriceFilteredTable"s, {"*"})
    << std::endl;

  std::cout
    << "SELECT result FadsMarkup:\n"
    << ob->Select("FadsMarkupTable"s, {"*"})
    << std::endl;
}