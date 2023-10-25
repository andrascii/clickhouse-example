#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include "sor_child_order.pb.h"
#include "types.h"

namespace mdh::dvc {

struct SorChildOrder final {
  bool operator==(const SorChildOrder& rhs) const {
    return timestamp == rhs.timestamp &&
           id == rhs.id &&
           parent_order_id == rhs.parent_order_id &&
           provider_id == rhs.provider_id &&
           timestamp_orig == rhs.timestamp_orig &&
           term_quantity_executed == rhs.term_quantity_executed &&
           quantity_executed == rhs.quantity_executed &&
           price_executed == rhs.price_executed &&
           order_time_stamp == rhs.order_time_stamp &&
           quantity == rhs.quantity &&
           limit_price == rhs.limit_price &&
           forward_points_adjustment == rhs.forward_points_adjustment &&
           extra_params_str == rhs.extra_params_str &&
           state == rhs.state &&
           time_in_force == rhs.time_in_force &&
           side == rhs.side &&
           status == rhs.status &&
           broker_md_sent_time == rhs.broker_md_sent_time &&
           efx_send_time == rhs.efx_send_time &&
           efx_recv_time == rhs.efx_recv_time &&
           exch_recv_time == rhs.exch_recv_time &&
           exch_send_time == rhs.exch_send_time &&
           symbol == rhs.symbol &&
           order_id == rhs.order_id &&
           settlement == rhs.settlement &&
           cl_ord_id == rhs.cl_ord_id &&
           provider_name == rhs.provider_name &&
           settlement_date == rhs.settlement_date &&
           lp_ord_id == rhs.lp_ord_id &&
           strategy == rhs.strategy;
  }

  bool operator!=(const SorChildOrder& rhs) const {
    return !(rhs == *this);
  }

  TimePoint timestamp;
  int64_t id;
  int64_t parent_order_id;
  int64_t provider_id;

  Decimal6 timestamp_orig; // decimal
  Decimal6 term_quantity_executed; // decimal
  Decimal6 quantity_executed; // decimal
  Decimal6 price_executed; // decimal
  Decimal6 order_time_stamp; // decimal
  Decimal6 quantity; // decimal
  Decimal6 limit_price; // decimal
  Decimal6 forward_points_adjustment; // decimal

  std::string extra_params_str;
  std::string state;
  std::string time_in_force;
  std::string side;
  std::string status;
  std::string broker_md_sent_time;
  std::string efx_send_time;
  std::string efx_recv_time;
  std::string exch_recv_time;
  std::string exch_send_time;
  std::string symbol;
  std::string order_id;
  std::string settlement;
  std::string cl_ord_id;
  std::string provider_name;
  std::string settlement_date;
  std::string lp_ord_id;
  std::string strategy;
};

} // namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::SorChildOrder> {
  inline constexpr static auto name = "AutoLayoffStrategy";
  using Type = dvc::protobuf::SorChildOrder;

  Type operator()(const dvc::SorChildOrder& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_id(src.id);
    res.set_parent_order_id(src.parent_order_id);
    res.set_provider_id(src.provider_id);

    res.set_timestamp_orig(toString(src.timestamp_orig));
    res.set_term_quantity_executed(toString(src.term_quantity_executed));
    res.set_quantity_executed(toString(src.quantity_executed));
    res.set_price_executed(toString(src.price_executed));
    res.set_order_time_stamp(toString(src.order_time_stamp));
    res.set_quantity(toString(src.quantity));
    res.set_limit_price(toString(src.limit_price));
    res.set_forward_points_adjustment(toString(src.forward_points_adjustment));

    res.set_extra_params_str(src.extra_params_str);
    res.set_state(src.state);
    res.set_time_in_force(src.time_in_force);
    res.set_side(src.side);
    res.set_status(src.status);
    res.set_broker_md_sent_time(src.broker_md_sent_time);
    res.set_efx_send_time(src.efx_send_time);
    res.set_efx_recv_time(src.efx_recv_time);
    res.set_exch_recv_time(src.exch_recv_time);
    res.set_exch_send_time(src.exch_send_time);
    res.set_symbol(src.symbol);
    res.set_order_id(src.order_id);
    res.set_settlement(src.settlement);
    res.set_cl_ord_id(src.cl_ord_id);
    res.set_provider_name(src.provider_name);
    res.set_settlement_date(src.settlement_date);
    res.set_lp_ord_id(src.lp_ord_id);
    res.set_strategy(src.strategy);

    return res;
  }

  dvc::SorChildOrder operator()(const Type& src) const noexcept {
    dvc::SorChildOrder result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.id = src.id();
    result.parent_order_id = src.parent_order_id();
    result.provider_id = src.provider_id();
    
    result.timestamp_orig = dvc::Decimal6{src.timestamp_orig()};
    result.term_quantity_executed = dvc::Decimal6{src.term_quantity_executed()};
    result.quantity_executed = dvc::Decimal6{src.quantity_executed()};
    result.price_executed = dvc::Decimal6{src.price_executed()};
    result.order_time_stamp = dvc::Decimal6{src.order_time_stamp()};
    result.quantity = dvc::Decimal6{src.quantity()};
    result.limit_price = dvc::Decimal6{src.limit_price()};
    result.forward_points_adjustment = dvc::Decimal6{src.forward_points_adjustment()};
    
    result.extra_params_str = src.extra_params_str();
    result.state = src.state();
    result.time_in_force = src.time_in_force();
    result.side = src.side();
    result.status = src.status();
    result.broker_md_sent_time = src.broker_md_sent_time();
    result.efx_send_time = src.efx_send_time();
    result.efx_recv_time = src.efx_recv_time();
    result.exch_recv_time = src.exch_recv_time();
    result.exch_send_time = src.exch_send_time();
    result.symbol = src.symbol();
    result.order_id = src.order_id();
    result.settlement = src.settlement();
    result.cl_ord_id = src.cl_ord_id();
    result.provider_name = src.provider_name();
    result.settlement_date = src.settlement_date();
    result.lp_ord_id = src.lp_ord_id();
    result.strategy = src.strategy();

    return result;
  }
};
