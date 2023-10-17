#pragma once

#include <tca_orders.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE TcaOrdersTable (
  timestamp DateTime,
  id Int64,
  timestamp_original Decimal(6, 6),
  client_orders_client_order_id String,
  client_orders_database_id String,
  extra_params String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 * */

struct TcaOrders {
  TimePoint timestamp;
  int64_t id;
  dec::decimal6 timestamp_original;
  std::string client_orders_client_order_id;
  std::string client_orders_database_id;
  std::string extra_params;
};

template <>
struct mdh::cluster::adapter::Adapter<TcaOrders> {
  inline constexpr static auto name = "TcaOrders";
  using Type = mdh::TcaOrders;

  auto operator()(const ::TcaOrders& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_timestamp_original(toString(src.timestamp_original));
    res.set_client_orders_client_order_id(src.client_orders_client_order_id);
    res.set_client_orders_database_id(src.client_orders_database_id);
    res.set_extra_params(src.extra_params);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::TcaOrders {
    ::TcaOrders result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.timestamp_original = dec::decimal6{src.timestamp_original()};
    result.client_orders_client_order_id = src.client_orders_client_order_id();
    result.client_orders_database_id = src.client_orders_database_id();
    result.extra_params = src.extra_params();
    return result;
  }
};