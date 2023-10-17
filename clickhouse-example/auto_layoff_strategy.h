#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <chrono>
#include <date/date.h>
#include <auto_layoff_strategy.pb.h>
#include "types.h"

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

struct AutoLayoffStrategy final {
  TimePoint timestamp;
  std::string strategy_name;
  std::string currency;
  std::string currency_pair;
  std::string state;
  std::string paused;
  std::string paused_reasons;
};

template <>
struct mdh::cluster::adapter::Adapter<AutoLayoffStrategy> {
  inline constexpr static auto name = "AutoLayoffStrategy";
  using Type = mdh::AutoLayoffStrategy;

  auto operator()(const ::AutoLayoffStrategy& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::AutoLayoffStrategy {
    ::AutoLayoffStrategy result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.strategy_name = src.strategy_name();
    result.currency = src.currency();
    result.currency_pair = src.currency_pair();
    result.state = src.state();
    result.paused = src.paused();
    result.paused_reasons = src.paused_reasons();
    return result;
  }
};