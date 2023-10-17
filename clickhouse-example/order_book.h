#pragma once

#include <order_book.pb.h>
#include <decimal-for-cpp/decimal.h>
#include <date/date.h>
#include "mdh/cluster/adapter/ProtobufAdapter.h"
#include "types.h"

/*

 CREATE TABLE OrderBookTable (
  timestamp DateTime64(6, 'Europe/Moscow'),
  symbol String,
  level UInt64,
  size Decimal(38, 18),
  price Decimal(38, 18),
  side Enum8('kBid' = 0, 'kAsk' = 1)
) ENGINE = MergeTree() PRIMARY KEY (timestamp, symbol);

 */

struct OrderBook {
  TimePoint timestamp;
  std::string symbol;
  uint64_t level;
  dec::decimal6 size;
  dec::decimal6 price;
  mdh::Side side;
};

template <>
struct mdh::cluster::adapter::Adapter<OrderBook> {
  inline constexpr static auto name = "OrderBook";
  using Type = mdh::OrderBook;

  auto operator()(const ::OrderBook& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_symbol(src.symbol);
    res.set_level(src.level);
    res.set_size(toString(src.size));
    res.set_price(toString(src.price));
    res.set_side(src.side);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::OrderBook {
    ::OrderBook result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.symbol = src.symbol();
    result.level = src.level();
    result.size = dec::decimal6{src.size()};
    result.price = dec::decimal6{src.price()};
    result.side = src.side();
    return result;
  }
};