#pragma once

#include <auto_layoff_strategy.pb.h>
#include <date/date.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*

CREATE TABLE AutoLayoffStrategyTable (
  timestamp DateTime64(6, 'Europe/Moscow'),
  strategy_name String,
  currency String,
  currency_pair String,
  state String,
  paused String,
  paused_reasons String
) ENGINE = MergeTree() PRIMARY KEY(timestamp, currency_pair);

 */
namespace mdh::dvc {
struct AutoLayoffStrategy final {
  TimePoint timestamp;
  std::string strategy_name;
  std::string currency;
  std::string currency_pair;
  std::string state;
  std::string paused;
  std::string paused_reasons;

  friend bool operator==(const AutoLayoffStrategy& lhs, const AutoLayoffStrategy& rhs) { return lhs.timestamp == rhs.timestamp && lhs.strategy_name == rhs.strategy_name && lhs.currency == rhs.currency && lhs.currency_pair == rhs.currency_pair && lhs.state == rhs.state && lhs.paused == rhs.paused && lhs.paused_reasons == rhs.paused_reasons; }

  friend bool operator!=(const AutoLayoffStrategy& lhs, const AutoLayoffStrategy& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const AutoLayoffStrategy& obj) {
    std::size_t seed = 0x2A06C3F7;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.strategy_name);
    boost::hash_combine(seed, obj.currency);
    boost::hash_combine(seed, obj.currency_pair);
    boost::hash_combine(seed, obj.state);
    boost::hash_combine(seed, obj.paused);
    boost::hash_combine(seed, obj.paused_reasons);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const AutoLayoffStrategy& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " strategy_name: " << obj.strategy_name
           << " currency: " << obj.currency
           << " currency_pair: " << obj.currency_pair
           << " state: " << obj.state
           << " paused: " << obj.paused
           << " paused_reasons: " << obj.paused_reasons;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::AutoLayoffStrategy> {
  inline constexpr static auto name = "AutoLayoffStrategy";
  using Type = dvc::protobuf::AutoLayoffStrategy;

  Type operator()(const dvc::AutoLayoffStrategy& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_strategy_name(src.strategy_name);
    res.set_currency(src.currency);
    res.set_currency_pair(src.currency_pair);
    res.set_state(src.state);
    res.set_paused(src.paused);
    res.set_paused_reasons(src.paused_reasons);
    return res;
  }

  dvc::AutoLayoffStrategy operator()(const Type& src) const noexcept {
    dvc::AutoLayoffStrategy result{};
    std::stringstream stream{src.timestamp()};
    stream >> parse("%Y-%m-%d %T", result.timestamp);
    result.strategy_name = src.strategy_name();
    result.currency = src.currency();
    result.currency_pair = src.currency_pair();
    result.state = src.state();
    result.paused = src.paused();
    result.paused_reasons = src.paused_reasons();
    return result;
  }
};
