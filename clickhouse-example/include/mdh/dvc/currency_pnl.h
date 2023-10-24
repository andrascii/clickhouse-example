#pragma once

#include <currency_pnl.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE CurrencyPnlTable (
  timestamp DateTime,
  position Decimal6(6, 6),
  cost Decimal6(6, 6),
  position_value Decimal6(6, 6),
  pnl Decimal6(6, 6),
  unrealised_pnl Decimal6(6, 6),
  realised_pnl Decimal6(6, 6),
  realised_desk_pnl Decimal6(6, 6),
  realised_sales_pnl Decimal6(6, 6),
  currency String,
  last_trade_id String,
  book String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, currency)
 * */

namespace mdh::dvc {
struct CurrencyPnl {
  TimePoint timestamp;
  Decimal6 position;
  Decimal6 cost;
  Decimal6 position_value;
  Decimal6 pnl;
  Decimal6 unrealised_pnl;
  Decimal6 realised_pnl;
  Decimal6 realised_desk_pnl;
  Decimal6 realised_sales_pnl;
  std::string currency;
  std::string last_trade_id;
  std::string book;

  friend bool operator==(const CurrencyPnl& lhs, const CurrencyPnl& rhs) { return lhs.timestamp == rhs.timestamp && lhs.position == rhs.position && lhs.cost == rhs.cost && lhs.position_value == rhs.position_value && lhs.pnl == rhs.pnl && lhs.unrealised_pnl == rhs.unrealised_pnl && lhs.realised_pnl == rhs.realised_pnl && lhs.realised_desk_pnl == rhs.realised_desk_pnl && lhs.realised_sales_pnl == rhs.realised_sales_pnl && lhs.currency == rhs.currency && lhs.last_trade_id == rhs.last_trade_id && lhs.book == rhs.book; }

  friend bool operator!=(const CurrencyPnl& lhs, const CurrencyPnl& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const CurrencyPnl& obj) {
    std::size_t seed = 0x1C26B255;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.position);
    boost::hash_combine(seed, obj.cost);
    boost::hash_combine(seed, obj.position_value);
    boost::hash_combine(seed, obj.pnl);
    boost::hash_combine(seed, obj.unrealised_pnl);
    boost::hash_combine(seed, obj.realised_pnl);
    boost::hash_combine(seed, obj.realised_desk_pnl);
    boost::hash_combine(seed, obj.realised_sales_pnl);
    boost::hash_combine(seed, obj.currency);
    boost::hash_combine(seed, obj.last_trade_id);
    boost::hash_combine(seed, obj.book);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const CurrencyPnl& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " position: " << obj.position
           << " cost: " << obj.cost
           << " position_value: " << obj.position_value
           << " pnl: " << obj.pnl
           << " unrealised_pnl: " << obj.unrealised_pnl
           << " realised_pnl: " << obj.realised_pnl
           << " realised_desk_pnl: " << obj.realised_desk_pnl
           << " realised_sales_pnl: " << obj.realised_sales_pnl
           << " currency: " << obj.currency
           << " last_trade_id: " << obj.last_trade_id
           << " book: " << obj.book;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::CurrencyPnl> {
  inline constexpr static auto name = "CurrencyPnl";
  using Type = mdh::dvc::protobuf::CurrencyPnl;

  auto operator()(const mdh::dvc::CurrencyPnl& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_position(toString(src.position));
    res.set_cost(toString(src.cost));
    res.set_position_value(toString(src.position_value));
    res.set_pnl(toString(src.pnl));
    res.set_unrealised_pnl(toString(src.unrealised_pnl));
    res.set_realised_pnl(toString(src.realised_pnl));
    res.set_realised_desk_pnl(toString(src.realised_desk_pnl));
    res.set_realised_sales_pnl(toString(src.realised_sales_pnl));
    res.set_currency(src.currency);
    res.set_last_trade_id(src.last_trade_id);
    res.set_book(src.book);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> mdh::dvc::CurrencyPnl {
    using namespace mdh::dvc;
    mdh::dvc::CurrencyPnl result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.position = Decimal6{src.position()};
    result.cost = Decimal6{src.cost()};
    result.position_value = Decimal6{src.position_value()};
    result.pnl = Decimal6{src.pnl()};
    result.unrealised_pnl = Decimal6{src.unrealised_pnl()};
    result.realised_pnl = Decimal6{src.realised_pnl()};
    result.realised_desk_pnl = Decimal6{src.realised_desk_pnl()};
    result.realised_sales_pnl = Decimal6{src.realised_sales_pnl()};
    result.currency = src.currency();
    result.last_trade_id = src.last_trade_id();
    result.book = src.book();
    return result;
  }
};
