#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include "sor_execution.pb.h"
#include "types.h"

namespace mdh::dvc {

// primary key - TIMESTAMP, ID, TIMESTAMP_ORIG

struct SorExecution final {
  bool operator==(const SorExecution& rhs) const {
    return timestamp == rhs.timestamp &&
           id == rhs.id &&
           child_order_id == rhs.child_order_id &&
           rate == rhs.rate &&
           amount == rhs.amount &&
           timestamp_orig == rhs.timestamp_orig &&
           efx_send_time == rhs.efx_send_time &&
           efx_recv_time == rhs.efx_recv_time &&
           exch_recv_time == rhs.exch_recv_time &&
           exch_send_time == rhs.exch_send_time &&
           side == rhs.side &&
           transaction_time == rhs.transaction_time &&
           sending_time == rhs.sending_time &&
           exec_id == rhs.exec_id &&
           counter_party == rhs.counter_party &&
           trade_id == rhs.trade_id;
  }

  bool operator!=(const SorExecution& rhs) const {
    return !(rhs == *this);
  }

  TimePoint timestamp;
  int64_t id;
  int64_t child_order_id;

  Decimal6 rate;
  Decimal6 amount;
  Decimal6 timestamp_orig;

  std::string efx_send_time;
  std::string efx_recv_time;
  std::string exch_recv_time;
  std::string exch_send_time;
  std::string side;
  std::string transaction_time;
  std::string sending_time;
  std::string exec_id;
  std::string counter_party;
  std::string trade_id;
};

} // namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::SorExecution> {
  inline constexpr static auto name = "SorExecution";
  using Type = dvc::protobuf::SorExecution;

  Type operator()(const dvc::SorExecution& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_id(src.id);
    res.set_child_order_id(src.child_order_id);

    res.set_rate(toString(src.rate));
    res.set_amount(toString(src.amount));
    res.set_timestamp_orig(toString(src.timestamp_orig));

    res.set_efx_send_time(src.efx_send_time);
    res.set_efx_recv_time(src.efx_recv_time);
    res.set_exch_recv_time(src.exch_recv_time);
    res.set_exch_send_time(src.exch_send_time);
    res.set_side(src.side);
    res.set_transaction_time(src.transaction_time);
    res.set_sending_time(src.sending_time);
    res.set_exec_id(src.exec_id);
    res.set_counter_party(src.counter_party);
    res.set_trade_id(src.trade_id);

    return res;
  }

  dvc::SorExecution operator()(const Type& src) const noexcept {
    dvc::SorExecution result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.id = src.id();
    result.child_order_id = src.child_order_id();
    result.rate = dvc::Decimal6{src.rate()};
    result.amount = dvc::Decimal6{src.amount()};
    result.timestamp_orig = dvc::Decimal6{src.timestamp_orig()};
    result.efx_send_time = src.efx_send_time();
    result.efx_recv_time = src.efx_recv_time();
    result.exch_recv_time = src.exch_recv_time();
    result.exch_send_time = src.exch_send_time();
    result.side = src.side();
    result.transaction_time = src.transaction_time();
    result.sending_time = src.sending_time();
    result.exec_id = src.exec_id();
    result.counter_party = src.counter_party();
    result.trade_id = src.trade_id();

    return result;
  }
};
