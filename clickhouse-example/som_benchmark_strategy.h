#pragma once

#include <som_benchmark_stragtegy.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

// primary key [timestamp]

struct SomBenchmarkStrategy {
  TimePoint timestamp;
  int64_t state_time_update;
  int64_t cumulative_unhedged_threshold;
  int64_t id;
  int64_t stop_loss_threshold;
  int64_t volume;
  int64_t target_to_b_volume;
  int64_t benchmark_volume;

  dec::decimal6 internal_price;
  dec::decimal6 price_change_threshold;
  dec::decimal6 base_position;
  dec::decimal6 target_lp_to_b_bid;
  dec::decimal6 price;
  dec::decimal6 target_lp_to_b_ask;
  dec::decimal6 max_distance_from_target_to_b_for_submit;
  dec::decimal6 timeout_between_orders;
  dec::decimal6 min_distance_to_opposite_target_to_b;
  dec::decimal6 position_holding_time;
  dec::decimal6 benchmark_price;
  dec::decimal6 pnl;
  dec::decimal6 cumulative_unhedged_cost;
  dec::decimal6 term_position;
  dec::decimal6 max_distance_from_target_to_b_for_amend;
  dec::decimal6 margin_to_benchmark;
  dec::decimal6 hedge_slippage;

  std::string symbol;
  std::string cutoff_time;
  std::string state;
  std::string target_lp_tenor;
  std::string benchmark;
  std::string status;
  std::string som_name;
  std::string start_time;
  std::string paused_reasons;
  std::string strategy_name;
  std::string side;
  std::string target_lp;
  std::string user;
};

template <>
struct mdh::cluster::adapter::Adapter<SomBenchmarkStrategy> {
  inline constexpr static auto name = "SomBenchmarkStrategy";
  using Type = mdh::SomBenchmarkStrategy;

  auto operator()(const ::SomBenchmarkStrategy& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_state_time_update(src.state_time_update);
    res.set_cumulative_unhedged_threshold(src.cumulative_unhedged_threshold);
    res.set_id(src.id);
    res.set_stop_loss_threshold(src.stop_loss_threshold);
    res.set_volume(src.volume);
    res.set_target_to_b_volume(src.target_to_b_volume);
    res.set_benchmark_volume(src.benchmark_volume);

    res.set_internal_price(toString(src.internal_price));
    res.set_price_change_threshold(toString(src.price_change_threshold));
    res.set_base_position(toString(src.base_position));
    res.set_target_lp_to_b_bid(toString(src.target_lp_to_b_bid));
    res.set_price(toString(src.price));
    res.set_target_lp_to_b_ask(toString(src.target_lp_to_b_ask));
    res.set_max_distance_from_target_to_b_for_submit(toString(src.max_distance_from_target_to_b_for_submit));
    res.set_timeout_between_orders(toString(src.timeout_between_orders));
    res.set_min_distance_to_opposite_target_to_b(toString(src.min_distance_to_opposite_target_to_b));
    res.set_position_holding_time(toString(src.position_holding_time));
    res.set_benchmark_price(toString(src.benchmark_price));
    res.set_pnl(toString(src.pnl));
    res.set_cumulative_unhedged_cost(toString(src.cumulative_unhedged_cost));
    res.set_term_position(toString(src.term_position));
    res.set_max_distance_from_target_to_b_for_amend(toString(src.max_distance_from_target_to_b_for_amend));
    res.set_margin_to_benchmark(toString(src.margin_to_benchmark));
    res.set_hedge_slippage(toString(src.hedge_slippage));

    res.set_symbol(src.symbol);
    res.set_cutoff_time(src.cutoff_time);
    res.set_state(src.state);
    res.set_target_lp_tenor(src.target_lp_tenor);
    res.set_benchmark(src.benchmark);
    res.set_status(src.status);
    res.set_som_name(src.som_name);
    res.set_start_time(src.start_time);
    res.set_paused_reasons(src.paused_reasons);
    res.set_strategy_name(src.strategy_name);
    res.set_side(src.side);
    res.set_target_lp(src.target_lp);
    res.set_user(src.user);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::SomBenchmarkStrategy {
    ::SomBenchmarkStrategy result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.state_time_update = src.state_time_update();
    result.cumulative_unhedged_threshold = src.cumulative_unhedged_threshold();
    result.id = src.id();
    result.stop_loss_threshold = src.stop_loss_threshold();
    result.volume = src.volume();
    result.target_to_b_volume = src.target_to_b_volume();
    result.benchmark_volume = src.benchmark_volume();

    result.internal_price = dec::decimal6{src.internal_price()};
    result.price_change_threshold = dec::decimal6{src.price_change_threshold()};
    result.base_position = dec::decimal6{src.base_position()};
    result.target_lp_to_b_bid = dec::decimal6{src.target_lp_to_b_bid()};
    result.price = dec::decimal6{src.price()};
    result.target_lp_to_b_ask = dec::decimal6{src.target_lp_to_b_ask()};
    result.max_distance_from_target_to_b_for_submit = dec::decimal6{src.max_distance_from_target_to_b_for_submit()};
    result.timeout_between_orders = dec::decimal6{src.timeout_between_orders()};
    result.min_distance_to_opposite_target_to_b = dec::decimal6{src.min_distance_to_opposite_target_to_b()};
    result.position_holding_time = dec::decimal6{src.position_holding_time()};
    result.benchmark_price = dec::decimal6{src.benchmark_price()};
    result.pnl = dec::decimal6{src.pnl()};
    result.cumulative_unhedged_cost = dec::decimal6{src.cumulative_unhedged_cost()};
    result.term_position = dec::decimal6{src.term_position()};
    result.max_distance_from_target_to_b_for_amend = dec::decimal6{src.max_distance_from_target_to_b_for_amend()};
    result.margin_to_benchmark = dec::decimal6{src.margin_to_benchmark()};
    result.hedge_slippage = dec::decimal6{src.hedge_slippage()};

    result.symbol = src.symbol();
    result.cutoff_time = src.cutoff_time();
    result.state = src.state();
    result.target_lp_tenor = src.target_lp_tenor();
    result.benchmark = src.benchmark();
    result.status = src.status();
    result.som_name = src.som_name();
    result.start_time = src.start_time();
    result.paused_reasons = src.paused_reasons();
    result.strategy_name = src.strategy_name();
    result.side = src.side();
    result.target_lp = src.target_lp();
    result.user = src.user();
    return result;
  }
};