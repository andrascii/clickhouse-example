#pragma once

#include <currency_pnl.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE CurrencyPnlTable (
  timestamp DateTime,
  position Decimal(6, 6),
  cost Decimal(6, 6),
  position_value Decimal(6, 6),
  pnl Decimal(6, 6),
  unrealised_pnl Decimal(6, 6),
  realised_pnl Decimal(6, 6),
  realised_desk_pnl Decimal(6, 6),
  realised_sales_pnl Decimal(6, 6),
  currency String,
  last_trade_id String,
  book String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, currency)
 * */

struct CurrencyPnl {
  TimePoint timestamp;
  dec::decimal6 position;
  dec::decimal6 cost;
  dec::decimal6 position_value;
  dec::decimal6 pnl;
  dec::decimal6 unrealised_pnl;
  dec::decimal6 realised_pnl;
  dec::decimal6 realised_desk_pnl;
  dec::decimal6 realised_sales_pnl;
  std::string currency;
  std::string last_trade_id;
  std::string book;
};

template <>
struct mdh::cluster::adapter::Adapter<CurrencyPnl> {
  inline constexpr static auto name = "CurrencyPnl";
  using Type = mdh::CurrencyPnl;

  auto operator()(const ::CurrencyPnl& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::CurrencyPnl {
    ::CurrencyPnl result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.position = dec::decimal6{src.position()};
    result.cost = dec::decimal6{src.cost()};
    result.position_value = dec::decimal6{src.position_value()};
    result.pnl = dec::decimal6{src.pnl()};
    result.unrealised_pnl = dec::decimal6{src.unrealised_pnl()};
    result.realised_pnl = dec::decimal6{src.realised_pnl()};
    result.realised_desk_pnl = dec::decimal6{src.realised_desk_pnl()};
    result.realised_sales_pnl = dec::decimal6{src.realised_sales_pnl()};
    result.currency = src.currency();
    result.last_trade_id = src.last_trade_id();
    result.book = src.book();
    return result;
  }
};