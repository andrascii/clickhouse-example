#pragma once

#include <tca_trades.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE TcaTradesTable (
  timestamp DateTime,
  id Int64,
  timestamp_original Decimal6(6, 6),
  client_orders_client_order_id String,
  client_orders_database_id String,
  extra_params String,
  price Decimal6(6, 6),
  quantity Decimal6(6, 6),
  ilp_trades_id Int64,
  sor_child_order_id Int64,
  client_trades_execution_id String,
  manual_execution String,
  order_final String,
  symbol String,
  venue String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 * */
namespace mdh::dvc {
struct TcaTrades {
  TimePoint timestamp;
  int64_t id;
  Decimal6 timestamp_original;
  std::string client_orders_client_order_id;
  std::string client_orders_database_id;
  std::string extra_params;
  Decimal6 price;
  Decimal6 quantity;
  int64_t ilp_trades_id;
  int64_t sor_child_order_id;
  std::string client_trades_execution_id;
  std::string manual_execution;
  std::string order_final;
  std::string symbol;
  std::string venue;

  friend bool operator==(const TcaTrades& lhs, const TcaTrades& rhs) { return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.timestamp_original == rhs.timestamp_original && lhs.client_orders_client_order_id == rhs.client_orders_client_order_id && lhs.client_orders_database_id == rhs.client_orders_database_id && lhs.extra_params == rhs.extra_params && lhs.price == rhs.price && lhs.quantity == rhs.quantity && lhs.ilp_trades_id == rhs.ilp_trades_id && lhs.sor_child_order_id == rhs.sor_child_order_id && lhs.client_trades_execution_id == rhs.client_trades_execution_id && lhs.manual_execution == rhs.manual_execution && lhs.order_final == rhs.order_final && lhs.symbol == rhs.symbol && lhs.venue == rhs.venue; }

  friend bool operator!=(const TcaTrades& lhs, const TcaTrades& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const TcaTrades& obj) {
    std::size_t seed = 0x7B76E858;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.timestamp_original);
    boost::hash_combine(seed, obj.client_orders_client_order_id);
    boost::hash_combine(seed, obj.client_orders_database_id);
    boost::hash_combine(seed, obj.extra_params);
    boost::hash_combine(seed, obj.price);
    boost::hash_combine(seed, obj.quantity);
    boost::hash_combine(seed, obj.ilp_trades_id);
    boost::hash_combine(seed, obj.sor_child_order_id);
    boost::hash_combine(seed, obj.client_trades_execution_id);
    boost::hash_combine(seed, obj.manual_execution);
    boost::hash_combine(seed, obj.order_final);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.venue);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const TcaTrades& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " timestamp_original: " << obj.timestamp_original
           << " client_orders_client_order_id: " << obj.client_orders_client_order_id
           << " client_orders_database_id: " << obj.client_orders_database_id
           << " extra_params: " << obj.extra_params
           << " price: " << obj.price
           << " quantity: " << obj.quantity
           << " ilp_trades_id: " << obj.ilp_trades_id
           << " sor_child_order_id: " << obj.sor_child_order_id
           << " client_trades_execution_id: " << obj.client_trades_execution_id
           << " manual_execution: " << obj.manual_execution
           << " order_final: " << obj.order_final
           << " symbol: " << obj.symbol
           << " venue: " << obj.venue;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::TcaTrades> {
  inline constexpr static auto name = "TcaTrades";
  using Type = dvc::protobuf::TcaTrades;

  auto operator()(const dvc::TcaTrades& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_timestamp_original(toString(src.timestamp_original));
    res.set_client_orders_client_order_id(src.client_orders_client_order_id);
    res.set_client_orders_database_id(src.client_orders_database_id);
    res.set_extra_params(src.extra_params);
    res.set_price(toString(src.price));
    res.set_quantity(toString(src.quantity));
    res.set_ilp_trades_id(src.ilp_trades_id);
    res.set_sor_child_order_id(src.sor_child_order_id);
    res.set_client_trades_execution_id(src.client_trades_execution_id);
    res.set_manual_execution(src.manual_execution);
    res.set_order_final(src.order_final);
    res.set_symbol(src.symbol);
    res.set_venue(src.venue);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> dvc::TcaTrades {
    using namespace mdh::dvc;
    TcaTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.timestamp_original = Decimal6{src.timestamp_original()};
    result.client_orders_client_order_id = src.client_orders_client_order_id();
    result.client_orders_database_id = src.client_orders_database_id();
    result.extra_params = src.extra_params();
    result.price = Decimal6{src.price()};
    result.quantity = Decimal6{src.quantity()};
    result.ilp_trades_id = src.ilp_trades_id();
    result.sor_child_order_id = src.sor_child_order_id();
    result.client_trades_execution_id = src.client_trades_execution_id();
    result.manual_execution = src.manual_execution();
    result.order_final = src.order_final();
    result.symbol = src.symbol();
    result.venue = src.venue();
    return result;
  }
};
