#pragma once

#include <client_trades.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

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
  execute_timestamp Decimal6(38, 18),
  price_executed_far Decimal6(38, 18),
  price_executed_near Decimal6(38, 18),
  quantity_base_executed_near Decimal6(38, 18),
  quantity_term_executed_near Decimal6(38, 18),
  swap_points Decimal6(38, 18),
  trader_price Decimal6(38, 18),
  trader_price_modified_timestamp Decimal6(38, 18),
  book String,
  execution_id String,
  is_reciprocal String,
  quoted_by String,
  quote_type String,
  trader_price_modified_by String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, execute_timestamp, execution_id)
 */

namespace mdh::dvc {
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
  Decimal6 execute_timestamp;
  Decimal6 price_executed_far;
  Decimal6 price_executed_near;
  Decimal6 quantity_base_executed_near;
  Decimal6 quantity_term_executed_near;
  Decimal6 swap_points;
  Decimal6 trader_price;
  Decimal6 trader_price_modified_timestamp;
  std::string book;
  std::string execution_id;
  std::string is_reciprocal;
  std::string quoted_by;
  std::string quote_type;
  std::string trader_price_modified_by;

  friend bool operator==(const ClientTrades& lhs, const ClientTrades& rhs) { return lhs.timestamp == rhs.timestamp && lhs.base_currency == rhs.base_currency && lhs.client_account == rhs.client_account && lhs.client_order_id == rhs.client_order_id && lhs.efx_order_id == rhs.efx_order_id && lhs.far_tenor == rhs.far_tenor && lhs.far_value_date == rhs.far_value_date && lhs.fixing_date == rhs.fixing_date && lhs.fixing_source == rhs.fixing_source && lhs.near_tenor == rhs.near_tenor && lhs.near_value_date == rhs.near_value_date && lhs.product == rhs.product && lhs.settlement_currency == rhs.settlement_currency && lhs.side == rhs.side && lhs.source == rhs.source && lhs.strategy == rhs.strategy && lhs.sub_status == rhs.sub_status && lhs.symbol == rhs.symbol && lhs.term_currency == rhs.term_currency && lhs.tier == rhs.tier && lhs.type == rhs.type && lhs.execute_timestamp == rhs.execute_timestamp && lhs.price_executed_far == rhs.price_executed_far && lhs.price_executed_near == rhs.price_executed_near && lhs.quantity_base_executed_near == rhs.quantity_base_executed_near && lhs.quantity_term_executed_near == rhs.quantity_term_executed_near && lhs.swap_points == rhs.swap_points && lhs.trader_price == rhs.trader_price && lhs.trader_price_modified_timestamp == rhs.trader_price_modified_timestamp && lhs.book == rhs.book && lhs.execution_id == rhs.execution_id && lhs.is_reciprocal == rhs.is_reciprocal && lhs.quoted_by == rhs.quoted_by && lhs.quote_type == rhs.quote_type && lhs.trader_price_modified_by == rhs.trader_price_modified_by; }

  friend std::size_t hash_value(const ClientTrades& obj) {
    std::size_t seed = 0x0C35CEE7;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.base_currency);
    boost::hash_combine(seed, obj.client_account);
    boost::hash_combine(seed, obj.client_order_id);
    boost::hash_combine(seed, obj.efx_order_id);
    boost::hash_combine(seed, obj.far_tenor);
    boost::hash_combine(seed, obj.far_value_date);
    boost::hash_combine(seed, obj.fixing_date);
    boost::hash_combine(seed, obj.fixing_source);
    boost::hash_combine(seed, obj.near_tenor);
    boost::hash_combine(seed, obj.near_value_date);
    boost::hash_combine(seed, obj.product);
    boost::hash_combine(seed, obj.settlement_currency);
    boost::hash_combine(seed, obj.side);
    boost::hash_combine(seed, obj.source);
    boost::hash_combine(seed, obj.strategy);
    boost::hash_combine(seed, obj.sub_status);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.term_currency);
    boost::hash_combine(seed, obj.tier);
    boost::hash_combine(seed, obj.type);
    boost::hash_combine(seed, obj.execute_timestamp);
    boost::hash_combine(seed, obj.price_executed_far);
    boost::hash_combine(seed, obj.price_executed_near);
    boost::hash_combine(seed, obj.quantity_base_executed_near);
    boost::hash_combine(seed, obj.quantity_term_executed_near);
    boost::hash_combine(seed, obj.swap_points);
    boost::hash_combine(seed, obj.trader_price);
    boost::hash_combine(seed, obj.trader_price_modified_timestamp);
    boost::hash_combine(seed, obj.book);
    boost::hash_combine(seed, obj.execution_id);
    boost::hash_combine(seed, obj.is_reciprocal);
    boost::hash_combine(seed, obj.quoted_by);
    boost::hash_combine(seed, obj.quote_type);
    boost::hash_combine(seed, obj.trader_price_modified_by);
    return seed;
  }

  friend bool operator!=(const ClientTrades& lhs, const ClientTrades& rhs) { return !(lhs == rhs); }

  friend std::ostream& operator<<(std::ostream& os, const ClientTrades& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " base_currency: " << obj.base_currency
           << " client_account: " << obj.client_account
           << " client_order_id: " << obj.client_order_id
           << " efx_order_id: " << obj.efx_order_id
           << " far_tenor: " << obj.far_tenor
           << " far_value_date: " << obj.far_value_date
           << " fixing_date: " << obj.fixing_date
           << " fixing_source: " << obj.fixing_source
           << " near_tenor: " << obj.near_tenor
           << " near_value_date: " << obj.near_value_date
           << " product: " << obj.product
           << " settlement_currency: " << obj.settlement_currency
           << " side: " << obj.side
           << " source: " << obj.source
           << " strategy: " << obj.strategy
           << " sub_status: " << obj.sub_status
           << " symbol: " << obj.symbol
           << " term_currency: " << obj.term_currency
           << " tier: " << obj.tier
           << " type: " << obj.type
           << " execute_timestamp: " << obj.execute_timestamp
           << " price_executed_far: " << obj.price_executed_far
           << " price_executed_near: " << obj.price_executed_near
           << " quantity_base_executed_near: " << obj.quantity_base_executed_near
           << " quantity_term_executed_near: " << obj.quantity_term_executed_near
           << " swap_points: " << obj.swap_points
           << " trader_price: " << obj.trader_price
           << " trader_price_modified_timestamp: " << obj.trader_price_modified_timestamp
           << " book: " << obj.book
           << " execution_id: " << obj.execution_id
           << " is_reciprocal: " << obj.is_reciprocal
           << " quoted_by: " << obj.quoted_by
           << " quote_type: " << obj.quote_type
           << " trader_price_modified_by: " << obj.trader_price_modified_by;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::ClientTrades> {
  inline constexpr static auto name = "ClientTrades";
  using Type = dvc::protobuf::ClientTrades;

  auto operator()(const dvc::ClientTrades& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> dvc::ClientTrades {
    using namespace mdh::dvc;
    ClientTrades result{};
    std::stringstream stream{src.timestamp()};
    stream >> parse("%Y-%m-%d %T", result.timestamp);
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
    result.execute_timestamp = Decimal6(src.execute_timestamp());
    result.price_executed_far = Decimal6(src.price_executed_far());
    result.price_executed_near = Decimal6(src.price_executed_near());
    result.quantity_base_executed_near = Decimal6(src.quantity_base_executed_near());
    result.quantity_term_executed_near = Decimal6(src.quantity_term_executed_near());
    result.swap_points = Decimal6(src.swap_points());
    result.trader_price = Decimal6(src.trader_price());
    result.trader_price_modified_timestamp = Decimal6(src.trader_price_modified_timestamp());
    result.book = src.book();
    result.execution_id = src.execution_id();
    result.is_reciprocal = src.is_reciprocal();
    result.quoted_by = src.quoted_by();
    result.quote_type = src.quote_type();
    result.trader_price_modified_by = src.trader_price_modified_by();
    return result;
  }
};
