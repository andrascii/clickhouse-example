#pragma once

#include <tca_trades.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE TcaTradesTable (
  timestamp DateTime,
  id Int64,
  timestamp_original Decimal(6, 6),
  client_orders_client_order_id String,
  client_orders_database_id String,
  extra_params String,
  price Decimal(6, 6),
  quantity Decimal(6, 6),
  ilp_trades_id Int64,
  sor_child_order_id Int64,
  client_trades_execution_id String,
  manual_execution String,
  order_final String,
  symbol String,
  venue String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 * */

struct TcaTrades {
  TimePoint timestamp;
  int64_t id;
  dec::decimal6 timestamp_original;
  std::string client_orders_client_order_id;
  std::string client_orders_database_id;
  std::string extra_params;
  dec::decimal6 price;
  dec::decimal6 quantity;
  int64_t ilp_trades_id;
  int64_t sor_child_order_id;
  std::string client_trades_execution_id;
  std::string manual_execution;
  std::string order_final;
  std::string symbol;
  std::string venue;
};

template <>
struct mdh::cluster::adapter::Adapter<TcaTrades> {
  inline constexpr static auto name = "TcaTrades";
  using Type = mdh::TcaTrades;

  auto operator()(const ::TcaTrades& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::TcaTrades {
    ::TcaTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.timestamp_original = dec::decimal6{src.timestamp_original()};
    result.client_orders_client_order_id = src.client_orders_client_order_id();
    result.client_orders_database_id = src.client_orders_database_id();
    result.extra_params = src.extra_params();
    result.price = dec::decimal6{src.price()};
    result.quantity = dec::decimal6{src.quantity()};
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