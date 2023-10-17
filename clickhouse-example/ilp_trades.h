#pragma once

#include <ilp_trades.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE ILpTradesTable (
  timestamp DateTime,
  id Int64,
  trade_timestamp Decimal(6, 6),
  price Decimal(6, 6),
  quantity Decimal(6, 6),
  symbol String,
  aggressive_side String,
  sell_order_id String,
  sell_order_type String,
  buy_order_id String,
  buy_order_type String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id, trade_timestamp)
 * */

struct ILpTrades {
  TimePoint timestamp;
  int64_t id;
  dec::decimal6 trade_timestamp;
  dec::decimal6 price;
  dec::decimal6 quantity;
  std::string symbol;
  std::string aggressive_side;
  std::string sell_order_id;
  std::string sell_order_type;
  std::string buy_order_id;
  std::string buy_order_type;
};

template <>
struct mdh::cluster::adapter::Adapter<ILpTrades> {
  inline constexpr static auto name = "ILpTrades";
  using Type = mdh::ILpTrades;

  auto operator()(const ::ILpTrades& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_trade_timestamp(toString(src.trade_timestamp));
    res.set_price(toString(src.price));
    res.set_quantity(toString(src.quantity));
    res.set_symbol(src.symbol);
    res.set_aggressive_side(src.aggressive_side);
    res.set_sell_order_id(src.sell_order_id);
    res.set_sell_order_type(src.sell_order_type);
    res.set_buy_order_id(src.buy_order_id);
    res.set_buy_order_type(src.buy_order_type);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::ILpTrades {
    ::ILpTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.trade_timestamp = dec::decimal6{src.trade_timestamp()};
    result.price = dec::decimal6{src.price()};
    result.quantity = dec::decimal6{src.quantity()};
    result.symbol = src.symbol();
    result.aggressive_side = src.aggressive_side();
    result.sell_order_id = src.sell_order_id();
    result.sell_order_type = src.sell_order_type();
    result.buy_order_id = src.buy_order_id();
    result.buy_order_type = src.buy_order_type();
    return result;
  }
};