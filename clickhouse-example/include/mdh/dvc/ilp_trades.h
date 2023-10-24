#pragma once

#include <ilp_trades.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE ILpTradesTable (
  timestamp DateTime,
  id Int64,
  trade_timestamp Decimal6(6, 6),
  price Decimal6(6, 6),
  quantity Decimal6(6, 6),
  symbol String,
  aggressive_side String,
  sell_order_id String,
  sell_order_type String,
  buy_order_id String,
  buy_order_type String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id, trade_timestamp)
 * */

namespace mdh::dvc {
struct ILpTrades {
  TimePoint timestamp;
  int64_t id;
  Decimal6 trade_timestamp;
  Decimal6 price;
  Decimal6 quantity;
  std::string symbol;
  std::string aggressive_side;
  std::string sell_order_id;
  std::string sell_order_type;
  std::string buy_order_id;
  std::string buy_order_type;

  friend bool operator==(const ILpTrades& lhs, const ILpTrades& rhs) {
    return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.trade_timestamp == rhs.trade_timestamp && lhs.price == rhs.price && lhs.quantity == rhs.quantity && lhs.symbol == rhs.symbol && lhs.aggressive_side == rhs.aggressive_side && lhs.sell_order_id == rhs.sell_order_id && lhs.sell_order_type == rhs.sell_order_type && lhs.buy_order_id == rhs.buy_order_id && lhs.buy_order_type == rhs.buy_order_type;
  }

  friend bool operator!=(const ILpTrades& lhs, const ILpTrades& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const ILpTrades& obj) {
    std::size_t seed = 0x0433E805;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.trade_timestamp);
    boost::hash_combine(seed, obj.price);
    boost::hash_combine(seed, obj.quantity);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.aggressive_side);
    boost::hash_combine(seed, obj.sell_order_id);
    boost::hash_combine(seed, obj.sell_order_type);
    boost::hash_combine(seed, obj.buy_order_id);
    boost::hash_combine(seed, obj.buy_order_type);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const ILpTrades& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " trade_timestamp: " << obj.trade_timestamp
           << " price: " << obj.price
           << " quantity: " << obj.quantity
           << " symbol: " << obj.symbol
           << " aggressive_side: " << obj.aggressive_side
           << " sell_order_id: " << obj.sell_order_id
           << " sell_order_type: " << obj.sell_order_type
           << " buy_order_id: " << obj.buy_order_id
           << " buy_order_type: " << obj.buy_order_type;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::ILpTrades> {
  inline constexpr static auto name = "ILpTrades";
  using Type = dvc::protobuf::ILpTrades;

  Type operator()(const dvc::ILpTrades& src) const noexcept {
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

  dvc::ILpTrades operator()(const Type& src) const noexcept {
    using namespace mdh::dvc;
    ILpTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.trade_timestamp = Decimal6{src.trade_timestamp()};
    result.price = Decimal6{src.price()};
    result.quantity = Decimal6{src.quantity()};
    result.symbol = src.symbol();
    result.aggressive_side = src.aggressive_side();
    result.sell_order_id = src.sell_order_id();
    result.sell_order_type = src.sell_order_type();
    result.buy_order_id = src.buy_order_id();
    result.buy_order_type = src.buy_order_type();
    return result;
  }
};
