#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>
#include <order_book.pb.h>

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
enum class Side {
  kBid,
  kAsk
};

inline std::ostream& operator<<(std::ostream& os, Side side) {
  switch (side) {
    case Side::kBid:
      os << "bid";
      break;
    case Side::kAsk:
      os << "ask";
      break;
    default:;
  }
  return os;
}

struct OrderBook {
  TimePoint timestamp;
  std::string symbol;
  uint64_t level;
  Decimal6 size;
  Decimal6 price;
  Side side;

  friend bool operator==(const OrderBook& lhs, const OrderBook& rhs) { return lhs.timestamp == rhs.timestamp && lhs.symbol == rhs.symbol && lhs.level == rhs.level && lhs.size == rhs.size && lhs.price == rhs.price && lhs.side == rhs.side; }

  friend bool operator!=(const OrderBook& lhs, const OrderBook& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const OrderBook& obj) {
    std::size_t seed = 0x741310EC;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.level);
    boost::hash_combine(seed, obj.size);
    boost::hash_combine(seed, obj.price);
    boost::hash_combine(seed, obj.side);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const OrderBook& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " symbol: " << obj.symbol
           << " level: " << obj.level
           << " size: " << obj.size
           << " price: " << obj.price
           << " side: " << obj.side;
  }
};
}// namespace mdh::dvc
template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::OrderBook> {
  inline constexpr static auto name = "OrderBook";
  using Type = dvc::protobuf::OrderBook;

  auto operator()(const dvc::OrderBook& src) const noexcept -> Type;

  auto operator()(const Type& src) const noexcept -> dvc::OrderBook;
};

inline auto mdh::cluster::adapter::Adapter<mdh::dvc::OrderBook>::operator()(const dvc::OrderBook& src) const noexcept -> Type {
  Type res;
  res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
  res.set_symbol(src.symbol);
  res.set_level(src.level);
  res.set_size(toString(src.size));
  res.set_price(toString(src.price));
  switch (src.side) {
    case dvc::Side::kBid:
      res.set_side(dvc::protobuf::Side::kBid);
      break;
    case dvc::Side::kAsk:
      res.set_side(dvc::protobuf::Side::kBid);
      break;
  }
  return res;
}

inline auto mdh::cluster::adapter::Adapter<mdh::dvc::OrderBook>::operator()(const Type& src) const noexcept -> dvc::OrderBook {
  using namespace mdh::dvc;
  OrderBook result{};
  std::stringstream stream{src.timestamp()};
  stream >> date::parse("%Y-%m-%d %T", result.timestamp);
  result.symbol = src.symbol();
  result.level = src.level();
  result.size = Decimal6{src.size()};
  result.price = Decimal6{src.price()};
  switch (src.side()) {
    case protobuf::kBid:
      result.side = Side::kBid;
      break;
    case protobuf::kAsk:
      result.side = Side::kAsk;
      break;
    case protobuf::Side_INT_MIN_SENTINEL_DO_NOT_USE_:
    case protobuf::Side_INT_MAX_SENTINEL_DO_NOT_USE_:
    default: abort();
  }
  return result;
}
