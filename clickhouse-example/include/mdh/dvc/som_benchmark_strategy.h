#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>
#include <som_benchmark_strategy.pb.h>

// primary key [timestamp]

namespace mdh::dvc {
struct SomBenchmarkStrategy {
  TimePoint timestamp;
  int64_t state_time_update;
  int64_t cumulative_unhedged_threshold;
  int64_t id;
  int64_t stop_loss_threshold;
  int64_t volume;
  int64_t target_to_b_volume;
  int64_t benchmark_volume;

  Decimal6 internal_price;
  Decimal6 price_change_threshold;
  Decimal6 base_position;
  Decimal6 target_lp_to_b_bid;
  Decimal6 price;
  Decimal6 target_lp_to_b_ask;
  Decimal6 max_distance_from_target_to_b_for_submit;
  Decimal6 timeout_between_orders;
  Decimal6 min_distance_to_opposite_target_to_b;
  Decimal6 position_holding_time;
  Decimal6 benchmark_price;
  Decimal6 pnl;
  Decimal6 cumulative_unhedged_cost;
  Decimal6 term_position;
  Decimal6 max_distance_from_target_to_b_for_amend;
  Decimal6 margin_to_benchmark;
  Decimal6 hedge_slippage;

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

  friend bool operator==(const SomBenchmarkStrategy& lhs, const SomBenchmarkStrategy& rhs) { return lhs.timestamp == rhs.timestamp && lhs.state_time_update == rhs.state_time_update && lhs.cumulative_unhedged_threshold == rhs.cumulative_unhedged_threshold && lhs.id == rhs.id && lhs.stop_loss_threshold == rhs.stop_loss_threshold && lhs.volume == rhs.volume && lhs.target_to_b_volume == rhs.target_to_b_volume && lhs.benchmark_volume == rhs.benchmark_volume && lhs.internal_price == rhs.internal_price && lhs.price_change_threshold == rhs.price_change_threshold && lhs.base_position == rhs.base_position && lhs.target_lp_to_b_bid == rhs.target_lp_to_b_bid && lhs.price == rhs.price && lhs.target_lp_to_b_ask == rhs.target_lp_to_b_ask && lhs.max_distance_from_target_to_b_for_submit == rhs.max_distance_from_target_to_b_for_submit && lhs.timeout_between_orders == rhs.timeout_between_orders && lhs.min_distance_to_opposite_target_to_b == rhs.min_distance_to_opposite_target_to_b && lhs.position_holding_time == rhs.position_holding_time && lhs.benchmark_price == rhs.benchmark_price && lhs.pnl == rhs.pnl && lhs.cumulative_unhedged_cost == rhs.cumulative_unhedged_cost && lhs.term_position == rhs.term_position && lhs.max_distance_from_target_to_b_for_amend == rhs.max_distance_from_target_to_b_for_amend && lhs.margin_to_benchmark == rhs.margin_to_benchmark && lhs.hedge_slippage == rhs.hedge_slippage && lhs.symbol == rhs.symbol && lhs.cutoff_time == rhs.cutoff_time && lhs.state == rhs.state && lhs.target_lp_tenor == rhs.target_lp_tenor && lhs.benchmark == rhs.benchmark && lhs.status == rhs.status && lhs.som_name == rhs.som_name && lhs.start_time == rhs.start_time && lhs.paused_reasons == rhs.paused_reasons && lhs.strategy_name == rhs.strategy_name && lhs.side == rhs.side && lhs.target_lp == rhs.target_lp && lhs.user == rhs.user; }

  friend bool operator!=(const SomBenchmarkStrategy& lhs, const SomBenchmarkStrategy& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const SomBenchmarkStrategy& obj) {
    std::size_t seed = 0x1C349F11;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.state_time_update);
    boost::hash_combine(seed, obj.cumulative_unhedged_threshold);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.stop_loss_threshold);
    boost::hash_combine(seed, obj.volume);
    boost::hash_combine(seed, obj.target_to_b_volume);
    boost::hash_combine(seed, obj.benchmark_volume);
    boost::hash_combine(seed, obj.internal_price);
    boost::hash_combine(seed, obj.price_change_threshold);
    boost::hash_combine(seed, obj.base_position);
    boost::hash_combine(seed, obj.target_lp_to_b_bid);
    boost::hash_combine(seed, obj.price);
    boost::hash_combine(seed, obj.target_lp_to_b_ask);
    boost::hash_combine(seed, obj.max_distance_from_target_to_b_for_submit);
    boost::hash_combine(seed, obj.timeout_between_orders);
    boost::hash_combine(seed, obj.min_distance_to_opposite_target_to_b);
    boost::hash_combine(seed, obj.position_holding_time);
    boost::hash_combine(seed, obj.benchmark_price);
    boost::hash_combine(seed, obj.pnl);
    boost::hash_combine(seed, obj.cumulative_unhedged_cost);
    boost::hash_combine(seed, obj.term_position);
    boost::hash_combine(seed, obj.max_distance_from_target_to_b_for_amend);
    boost::hash_combine(seed, obj.margin_to_benchmark);
    boost::hash_combine(seed, obj.hedge_slippage);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.cutoff_time);
    boost::hash_combine(seed, obj.state);
    boost::hash_combine(seed, obj.target_lp_tenor);
    boost::hash_combine(seed, obj.benchmark);
    boost::hash_combine(seed, obj.status);
    boost::hash_combine(seed, obj.som_name);
    boost::hash_combine(seed, obj.start_time);
    boost::hash_combine(seed, obj.paused_reasons);
    boost::hash_combine(seed, obj.strategy_name);
    boost::hash_combine(seed, obj.side);
    boost::hash_combine(seed, obj.target_lp);
    boost::hash_combine(seed, obj.user);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const SomBenchmarkStrategy& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " state_time_update: " << obj.state_time_update
           << " cumulative_unhedged_threshold: " << obj.cumulative_unhedged_threshold
           << " id: " << obj.id
           << " stop_loss_threshold: " << obj.stop_loss_threshold
           << " volume: " << obj.volume
           << " target_to_b_volume: " << obj.target_to_b_volume
           << " benchmark_volume: " << obj.benchmark_volume
           << " internal_price: " << obj.internal_price
           << " price_change_threshold: " << obj.price_change_threshold
           << " base_position: " << obj.base_position
           << " target_lp_to_b_bid: " << obj.target_lp_to_b_bid
           << " price: " << obj.price
           << " target_lp_to_b_ask: " << obj.target_lp_to_b_ask
           << " max_distance_from_target_to_b_for_submit: " << obj.max_distance_from_target_to_b_for_submit
           << " timeout_between_orders: " << obj.timeout_between_orders
           << " min_distance_to_opposite_target_to_b: " << obj.min_distance_to_opposite_target_to_b
           << " position_holding_time: " << obj.position_holding_time
           << " benchmark_price: " << obj.benchmark_price
           << " pnl: " << obj.pnl
           << " cumulative_unhedged_cost: " << obj.cumulative_unhedged_cost
           << " term_position: " << obj.term_position
           << " max_distance_from_target_to_b_for_amend: " << obj.max_distance_from_target_to_b_for_amend
           << " margin_to_benchmark: " << obj.margin_to_benchmark
           << " hedge_slippage: " << obj.hedge_slippage
           << " symbol: " << obj.symbol
           << " cutoff_time: " << obj.cutoff_time
           << " state: " << obj.state
           << " target_lp_tenor: " << obj.target_lp_tenor
           << " benchmark: " << obj.benchmark
           << " status: " << obj.status
           << " som_name: " << obj.som_name
           << " start_time: " << obj.start_time
           << " paused_reasons: " << obj.paused_reasons
           << " strategy_name: " << obj.strategy_name
           << " side: " << obj.side
           << " target_lp: " << obj.target_lp
           << " user: " << obj.user;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::SomBenchmarkStrategy> {
  inline constexpr static auto name = "SomBenchmarkStrategy";
  using Type = dvc::protobuf::SomBenchmarkStrategy;

  auto operator()(const mdh::dvc::SomBenchmarkStrategy& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> dvc::SomBenchmarkStrategy {
    using namespace mdh::dvc;

    dvc::SomBenchmarkStrategy result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.state_time_update = src.state_time_update();
    result.cumulative_unhedged_threshold = src.cumulative_unhedged_threshold();
    result.id = src.id();
    result.stop_loss_threshold = src.stop_loss_threshold();
    result.volume = src.volume();
    result.target_to_b_volume = src.target_to_b_volume();
    result.benchmark_volume = src.benchmark_volume();

    result.internal_price = Decimal6{src.internal_price()};
    result.price_change_threshold = Decimal6{src.price_change_threshold()};
    result.base_position = Decimal6{src.base_position()};
    result.target_lp_to_b_bid = Decimal6{src.target_lp_to_b_bid()};
    result.price = Decimal6{src.price()};
    result.target_lp_to_b_ask = Decimal6{src.target_lp_to_b_ask()};
    result.max_distance_from_target_to_b_for_submit = Decimal6{src.max_distance_from_target_to_b_for_submit()};
    result.timeout_between_orders = Decimal6{src.timeout_between_orders()};
    result.min_distance_to_opposite_target_to_b = Decimal6{src.min_distance_to_opposite_target_to_b()};
    result.position_holding_time = Decimal6{src.position_holding_time()};
    result.benchmark_price = Decimal6{src.benchmark_price()};
    result.pnl = Decimal6{src.pnl()};
    result.cumulative_unhedged_cost = Decimal6{src.cumulative_unhedged_cost()};
    result.term_position = Decimal6{src.term_position()};
    result.max_distance_from_target_to_b_for_amend = Decimal6{src.max_distance_from_target_to_b_for_amend()};
    result.margin_to_benchmark = Decimal6{src.margin_to_benchmark()};
    result.hedge_slippage = Decimal6{src.hedge_slippage()};

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
