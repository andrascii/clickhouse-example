#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>
#include <tca_orders.pb.h>

/*
CREATE TABLE TcaOrdersTable (
  timestamp DateTime,
  id Int64,
  timestamp_original Decimal6(6, 6),
  client_orders_client_order_id String,
  client_orders_database_id String,
  extra_params String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 * */

namespace mdh::dvc {
struct TcaOrders {
  TimePoint timestamp;
  int64_t id;
  Decimal6 timestamp_original;
  std::string client_orders_client_order_id;
  std::string client_orders_database_id;
  std::string extra_params;

  friend bool operator==(const TcaOrders& lhs, const TcaOrders& rhs) { return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.timestamp_original == rhs.timestamp_original && lhs.client_orders_client_order_id == rhs.client_orders_client_order_id && lhs.client_orders_database_id == rhs.client_orders_database_id && lhs.extra_params == rhs.extra_params; }

  friend bool operator!=(const TcaOrders& lhs, const TcaOrders& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const TcaOrders& obj) {
    std::size_t seed = 0x41A4047C;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.timestamp_original);
    boost::hash_combine(seed, obj.client_orders_client_order_id);
    boost::hash_combine(seed, obj.client_orders_database_id);
    boost::hash_combine(seed, obj.extra_params);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const TcaOrders& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " timestamp_original: " << obj.timestamp_original
           << " client_orders_client_order_id: " << obj.client_orders_client_order_id
           << " client_orders_database_id: " << obj.client_orders_database_id
           << " extra_params: " << obj.extra_params;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::TcaOrders> {
  inline constexpr static auto name = "TcaOrders";
  using Type = dvc::protobuf::TcaOrders;

  auto operator()(const dvc::TcaOrders& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_timestamp_original(toString(src.timestamp_original));
    res.set_client_orders_client_order_id(src.client_orders_client_order_id);
    res.set_client_orders_database_id(src.client_orders_database_id);
    res.set_extra_params(src.extra_params);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> dvc::TcaOrders {
    using namespace mdh::dvc;
    TcaOrders result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.timestamp_original = Decimal6{src.timestamp_original()};
    result.client_orders_client_order_id = src.client_orders_client_order_id();
    result.client_orders_database_id = src.client_orders_database_id();
    result.extra_params = src.extra_params();
    return result;
  }
};
