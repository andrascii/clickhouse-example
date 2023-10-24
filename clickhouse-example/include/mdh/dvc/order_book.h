#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/object_with_ulid.h>
#include <mdh/dvc/types.h>

#include <ostream>


/*

 CREATE TABLE OrderBookTable (
  timestamp DateTime64(6, 'Europe/Moscow'),
  symbol String,
  level UInt64,
  size Decimal6(38, 18),
  price Decimal6(38, 18),
  side Enum8('kBid' = 0, 'kAsk' = 1)
) ENGINE = MergeTree() PRIMARY KEY (timestamp, symbol);

 */

namespace mdh::dvc {

struct OrderBook {
  TimePoint timestamp;
  std::string symbol;
  uint64_t level;
  Decimal6 bid_price;
  Decimal6 bid_size;
  Decimal6 ask_price;
  Decimal6 ask_size;

  friend bool operator==(const OrderBook& lhs, const OrderBook& rhs) { return std::tie(lhs.timestamp, lhs.symbol, lhs.level, lhs.bid_price, lhs.bid_size, lhs.ask_price, lhs.ask_size) == std::tie(rhs.timestamp, rhs.symbol, rhs.level, rhs.bid_price, rhs.bid_size, rhs.ask_price, rhs.ask_size); }
  friend bool operator!=(const OrderBook& lhs, const OrderBook& rhs) { return !(lhs == rhs); }

  friend std::ostream& operator<<(std::ostream& os, const OrderBook& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " symbol: " << obj.symbol
           << " level: " << obj.level
           << " bid_price: " << obj.bid_price
           << " bid_size: " << obj.bid_size
           << " ask_price: " << obj.ask_price
           << " ask_size: " << obj.ask_size;
  }

  friend std::size_t hash_value(const OrderBook& obj) {
    std::size_t seed = 0x16850EF7;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.level);
    boost::hash_combine(seed, obj.bid_price);
    boost::hash_combine(seed, obj.bid_size);
    boost::hash_combine(seed, obj.ask_price);
    boost::hash_combine(seed, obj.ask_size);
    return seed;
  }
};

using OrderBookWithUlid = ObjectWithUlid<OrderBook>;
}// namespace mdh::dvc
template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::OrderBookWithUlid> {
  inline constexpr static auto name = "OrderBook";
  using Type = dvc::protobuf::OrderBook;

  auto operator()(const dvc::OrderBookWithUlid& src) const noexcept -> Type;

  auto operator()(const Type& src) const noexcept -> dvc::OrderBookWithUlid;
};

inline auto mdh::cluster::adapter::Adapter<mdh::dvc::OrderBookWithUlid>::operator()(const dvc::OrderBookWithUlid& src) const noexcept -> Type {
  Type res;
  res.set_id(src.id);
  res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
  res.set_symbol(src.symbol);
  res.set_level(src.level);
  res.set_symbol(src.symbol);
  res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
  res.set_level(src.level);
  res.set_bid_price(toString(src.bid_price));
  res.set_bid_size(toString(src.bid_size));
  res.set_ask_price(toString(src.ask_price));
  res.set_ask_size(toString(src.ask_size));
  return res;
}

inline auto mdh::cluster::adapter::Adapter<mdh::dvc::OrderBookWithUlid>::operator()(const Type& src) const noexcept -> dvc::OrderBookWithUlid {
  using namespace mdh::dvc;
  using namespace std::chrono;
  OrderBookWithUlid dst;
  dst.id = src.id();
  dst.symbol = src.symbol();
  std::stringstream stream{src.timestamp()};
  stream >> parse("%Y-%m-%d %T", dst.timestamp);
  dst.level = src.level();
  dst.bid_price = Decimal6{src.bid_price()};
  dst.bid_size = Decimal6{src.bid_size()};
  dst.ask_price = Decimal6{src.ask_price()};
  dst.ask_size = Decimal6{src.ask_size()};
  return dst;
}
