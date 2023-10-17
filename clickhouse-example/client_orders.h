#pragma once

#include <client_orders.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE IF NOT EXISTS ClientOrdersTable (
  timestamp DateTime64(6, 'Europe/Moscow'),
  allocation_number Int64,
  auto_amount Decimal(38, 18),
  avg_price_executed_near Decimal(38, 18),
  avg_trd_price_executed_near Decimal(38, 18),
  gtc_cancel_timestamp Decimal(38, 18),
  ilp_trade_id Int64,
  last_base_qty_executed_near Decimal(38, 18),
  last_price_executed_near Decimal(38, 18),
  last_trd_price_executed_near Decimal(38, 18),
  manual_amount Decimal(38, 18),
  order_base_quantity_far Decimal(38, 18),
  order_base_quantity_near Decimal(38, 18),
  order_price_far Decimal(38, 18),
  order_price_near Decimal(38, 18),
  order_term_quantity_far Decimal(38, 18),
  order_term_quantity_near Decimal(38, 18),
  qty_base_executed_near Decimal(38, 18),
  qty_base_remaining_near Decimal(38, 18),
  submit_timestamp Decimal(38, 18),
  update_time Decimal(38, 18),
  acceptance String,
  accepted_by String,
  allocations String,
  client_user_id String,
  currency String,
  database_id String,
  delivery_type String,
  executed_by String,
  execution String,
  extra_params String,
  has_ilp_trade_id String,
  id String,
  is_final String,
  manual_book String,
  message String,
  netting_option String,
  owner String,
  session String,
  state String,
  strategy_state String,
  time_in_force String,
  transport String,
  cri_check_id String,
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
  type String
) ENGINE = MergeTree()
PRIMARY KEY(timestamp, efx_order_id, update_time);
 */

struct ClientOrders {
  TimePoint timestamp;
  int64_t allocation_number;
  dec::decimal6 auto_amount; // decimal
  dec::decimal6 avg_price_executed_near; // decimal
  dec::decimal6 avg_trd_price_executed_near; // decimal
  dec::decimal6 gtc_cancel_timestamp; // decimal
  int64_t ilp_trade_id;
  dec::decimal6 last_base_qty_executed_near; // decimal
  dec::decimal6 last_price_executed_near; // decimal
  dec::decimal6 last_trd_price_executed_near; // decimal
  dec::decimal6 manual_amount; // decimal
  dec::decimal6 order_base_quantity_far; // decimal
  dec::decimal6 order_base_quantity_near; // decimal
  dec::decimal6 order_price_far; // decimal
  dec::decimal6 order_price_near; // decimal
  dec::decimal6 order_term_quantity_far; // decimal
  dec::decimal6 order_term_quantity_near; // decimal
  dec::decimal6 qty_base_executed_near; // decimal
  dec::decimal6 qty_base_remaining_near; // decimal
  dec::decimal6 submit_timestamp; // decimal
  dec::decimal6 update_time; // decimal
  std::string acceptance;
  std::string accepted_by;
  std::string allocations;
  std::string client_user_id;
  std::string currency;
  std::string database_id;
  std::string delivery_type;
  std::string executed_by;
  std::string execution;
  std::string extra_params;
  std::string has_ilp_trade_id;
  std::string id;
  std::string is_final;
  std::string manual_book;
  std::string message;
  std::string netting_option;
  std::string owner;
  std::string session;
  std::string state;
  std::string strategy_state;
  std::string time_in_force;
  std::string transport;
  std::string cri_check_id;
  // ClientOrders/ClientTrades common fields
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
};

template <>
struct mdh::cluster::adapter::Adapter<ClientOrders> {
  inline constexpr static auto name = "ClientOrders";
  using Type = mdh::ClientOrders;

  auto operator()(const ::ClientOrders& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_allocation_number(src.allocation_number);
    res.set_auto_amount(toString(src.auto_amount));
    res.set_avg_price_executed_near(toString(src.avg_price_executed_near));
    res.set_avg_trd_price_executed_near(toString(src.avg_trd_price_executed_near));
    res.set_gtc_cancel_timestamp(toString(src.gtc_cancel_timestamp));
    res.set_ilp_trade_id(src.ilp_trade_id);
    res.set_last_base_qty_executed_near(toString(src.last_base_qty_executed_near));
    res.set_last_price_executed_near(toString(src.last_price_executed_near));
    res.set_last_trd_price_executed_near(toString(src.last_trd_price_executed_near));
    res.set_manual_amount(toString(src.manual_amount));
    res.set_order_base_quantity_far(toString(src.order_base_quantity_far));
    res.set_order_base_quantity_near(toString(src.order_base_quantity_near));
    res.set_order_price_far(toString(src.order_price_far));
    res.set_order_price_near(toString(src.order_price_near));
    res.set_order_term_quantity_far(toString(src.order_term_quantity_far));
    res.set_order_term_quantity_near(toString(src.order_term_quantity_near));
    res.set_qty_base_executed_near(toString(src.qty_base_executed_near));
    res.set_qty_base_remaining_near(toString(src.qty_base_remaining_near));
    res.set_submit_timestamp(toString(src.submit_timestamp));
    res.set_update_time(toString(src.update_time));
    res.set_acceptance(src.acceptance);
    res.set_accepted_by(src.accepted_by);
    res.set_allocations(src.allocations);
    res.set_client_user_id(src.client_user_id);
    res.set_currency(src.currency);
    res.set_database_id(src.database_id);
    res.set_delivery_type(src.delivery_type);
    res.set_executed_by(src.executed_by);
    res.set_execution(src.execution);
    res.set_extra_params(src.extra_params);
    res.set_has_ilp_trade_id(src.has_ilp_trade_id);
    res.set_id(src.id);
    res.set_is_final(src.is_final);
    res.set_manual_book(src.manual_book);
    res.set_message(src.message);
    res.set_netting_option(src.netting_option);
    res.set_owner(src.owner);
    res.set_session(src.session);
    res.set_state(src.state);
    res.set_strategy_state(src.strategy_state);
    res.set_time_in_force(src.time_in_force);
    res.set_transport(src.transport);
    res.set_cri_check_id(src.cri_check_id);
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
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::ClientOrders {
    ::ClientOrders result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.allocation_number = src.allocation_number();
    result.auto_amount = dec::decimal6{src.auto_amount()};
    result.avg_price_executed_near = dec::decimal6{src.avg_price_executed_near()};
    result.avg_trd_price_executed_near = dec::decimal6{src.avg_trd_price_executed_near()};
    result.gtc_cancel_timestamp = dec::decimal6{src.gtc_cancel_timestamp()};
    result.ilp_trade_id = src.ilp_trade_id();
    result.last_base_qty_executed_near = dec::decimal6{src.last_base_qty_executed_near()};
    result.last_price_executed_near = dec::decimal6{src.last_price_executed_near()};
    result.last_trd_price_executed_near = dec::decimal6{src.last_trd_price_executed_near()};
    result.manual_amount = dec::decimal6{src.manual_amount()};
    result.order_base_quantity_far = dec::decimal6{src.order_base_quantity_far()};
    result.order_base_quantity_near = dec::decimal6{src.order_base_quantity_near()};
    result.order_price_far = dec::decimal6{src.order_price_far()};
    result.order_price_near = dec::decimal6{src.order_price_near()};
    result.order_term_quantity_far = dec::decimal6{src.order_term_quantity_far()};
    result.order_term_quantity_near = dec::decimal6{src.order_term_quantity_near()};
    result.qty_base_executed_near = dec::decimal6{src.qty_base_executed_near()};
    result.qty_base_remaining_near = dec::decimal6{src.qty_base_remaining_near()};
    result.submit_timestamp = dec::decimal6{src.submit_timestamp()};
    result.update_time = dec::decimal6{src.update_time()};
    result.acceptance = src.acceptance();
    result.accepted_by = src.accepted_by();
    result.allocations = src.allocations();
    result.client_user_id = src.client_user_id();
    result.currency = src.currency();
    result.database_id = src.database_id();
    result.delivery_type = src.delivery_type();
    result.executed_by = src.executed_by();
    result.execution = src.execution();
    result.extra_params = src.extra_params();
    result.has_ilp_trade_id = src.has_ilp_trade_id();
    result.id = src.id();
    result.is_final = src.is_final();
    result.manual_book = src.manual_book();
    result.message = src.message();
    result.netting_option = src.netting_option();
    result.owner = src.owner();
    result.session = src.session();
    result.state = src.state();
    result.strategy_state = src.strategy_state();
    result.time_in_force = src.time_in_force();
    result.transport = src.transport();
    result.cri_check_id = src.cri_check_id();
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
    return result;
  }
};