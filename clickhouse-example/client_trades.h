#pragma once

#include <client_trades.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE ClientTradesTable (
  timestamp DateTime64(6, 'Europe/Moscow'),
  base_currency String,
  client_account String,
  client_order_id String,
  efx_order_id String,
  far_tenor String,
  far_value_date String,
  fixing_date String,
  fixing_source String,
  near_tenor String,
  near_value_date String,
  product String,
  settlement_currency String,
  side String,
  source String,
  strategy String,
  sub_status String,
  symbol String,
  term_currency String,
  tier String,
  type String,
  execute_timestamp Decimal(38, 18),
  price_executed_far Decimal(38, 18),
  price_executed_near Decimal(38, 18),
  quantity_base_executed_near Decimal(38, 18),
  quantity_term_executed_near Decimal(38, 18),
  swap_points Decimal(38, 18),
  trader_price Decimal(38, 18),
  trader_price_modified_timestamp Decimal(38, 18),
  book String,
  execution_id String,
  is_reciprocal String,
  quoted_by String,
  quote_type String,
  trader_price_modified_by String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, execute_timestamp, execution_id)
 */

struct ClientTrades {
  TimePoint timestamp;
  std::string base_currency;
  std::string client_account;
  std::string client_order_id;
  std::string efx_order_id;
  std::string far_tenor;
  std::string far_value_date;
  std::string fixing_date;
  std::string fixing_source;
  std::string near_tenor;
  std::string near_value_date;
  std::string product;
  std::string settlement_currency;
  std::string side;
  std::string source;
  std::string strategy;
  std::string sub_status;
  std::string symbol;
  std::string term_currency;
  std::string tier;
  std::string type;
  dec::decimal6 execute_timestamp;
  dec::decimal6 price_executed_far;
  dec::decimal6 price_executed_near;
  dec::decimal6 quantity_base_executed_near;
  dec::decimal6 quantity_term_executed_near;
  dec::decimal6 swap_points;
  dec::decimal6 trader_price;
  dec::decimal6 trader_price_modified_timestamp;
  std::string book;
  std::string execution_id;
  std::string is_reciprocal;
  std::string quoted_by;
  std::string quote_type;
  std::string trader_price_modified_by;
};

template <>
struct mdh::cluster::adapter::Adapter<ClientTrades> {
  inline constexpr static auto name = "ClientTrades";
  using Type = mdh::ClientTrades;

  auto operator()(const ::ClientTrades& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_base_currency(src.base_currency);
    res.set_client_account(src.client_account);
    res.set_client_order_id(src.client_order_id);
    res.set_efx_order_id(src.efx_order_id);
    res.set_far_tenor(src.far_tenor);
    res.set_far_value_date(src.far_value_date);
    res.set_fixing_date(src.fixing_date);
    res.set_fixing_source(src.fixing_source);
    res.set_near_tenor(src.near_tenor);
    res.set_near_value_date(src.near_value_date);
    res.set_product(src.product);
    res.set_settlement_currency(src.settlement_currency);
    res.set_side(src.side);
    res.set_source(src.source);
    res.set_strategy(src.strategy);
    res.set_sub_status(src.sub_status);
    res.set_symbol(src.symbol);
    res.set_term_currency(src.term_currency);
    res.set_tier(src.tier);
    res.set_type(src.type);
    res.set_execute_timestamp(toString(src.execute_timestamp));
    res.set_price_executed_far(toString(src.price_executed_far));
    res.set_price_executed_near(toString(src.price_executed_near));
    res.set_quantity_base_executed_near(toString(src.quantity_base_executed_near));
    res.set_quantity_term_executed_near(toString(src.quantity_term_executed_near));
    res.set_swap_points(toString(src.swap_points));
    res.set_trader_price(toString(src.trader_price));
    res.set_trader_price_modified_timestamp(toString(src.trader_price_modified_timestamp));
    res.set_book(src.book);
    res.set_execution_id(src.execution_id);
    res.set_is_reciprocal(src.is_reciprocal);
    res.set_quoted_by(src.quoted_by);
    res.set_quote_type(src.quote_type);
    res.set_trader_price_modified_by(src.trader_price_modified_by);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::ClientTrades {
    ::ClientTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.base_currency = src.base_currency();
    result.client_account = src.client_account();
    result.client_order_id = src.client_order_id();
    result.efx_order_id = src.efx_order_id();
    result.far_tenor = src.far_tenor();
    result.far_value_date = src.far_value_date();
    result.fixing_date = src.fixing_date();
    result.fixing_source = src.fixing_source();
    result.near_tenor = src.near_tenor();
    result.near_value_date = src.near_value_date();
    result.product = src.product();
    result.settlement_currency = src.settlement_currency();
    result.side = src.side();
    result.source = src.source();
    result.strategy = src.strategy();
    result.sub_status = src.sub_status();
    result.symbol = src.symbol();
    result.term_currency = src.term_currency();
    result.tier = src.tier();
    result.type = src.type();
    result.execute_timestamp = dec::decimal6(src.execute_timestamp());
    result.price_executed_far = dec::decimal6(src.price_executed_far());
    result.price_executed_near = dec::decimal6(src.price_executed_near());
    result.quantity_base_executed_near = dec::decimal6(src.quantity_base_executed_near());
    result.quantity_term_executed_near = dec::decimal6(src.quantity_term_executed_near());
    result.swap_points = dec::decimal6(src.swap_points());
    result.trader_price = dec::decimal6(src.trader_price());
    result.trader_price_modified_timestamp = dec::decimal6(src.trader_price_modified_timestamp());
    result.book = src.book();
    result.execution_id = src.execution_id();
    result.is_reciprocal = src.is_reciprocal();
    result.quoted_by = src.quoted_by();
    result.quote_type = src.quote_type();
    result.trader_price_modified_by = src.trader_price_modified_by();
    return result;
  }
};