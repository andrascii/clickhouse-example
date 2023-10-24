#pragma once

#include <core_price_filtered.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE CorePriceFilteredTable (
  timestamp DateTime,
  id Int64,
  symbol String,
  min_spread Decimal6(38, 18),
  sharp_move_period Decimal6(38, 18),
  sharp_move_diff Decimal6(38, 18),
  volatility_period Decimal6(38, 18),
  volatility_interval Decimal6(38, 18),
  volatility_sensitivity Decimal6(38, 18),
  max_spread Decimal6(38, 18),
  decay_parameter Decimal6(38, 18)
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 */
namespace mdh::dvc {
struct CorePriceFiltered {
  TimePoint timestamp;
  int64_t id;
  std::string symbol;
  Decimal6 min_spread;
  Decimal6 sharp_move_period;
  Decimal6 sharp_move_diff;
  Decimal6 volatility_period;
  Decimal6 volatility_interval;
  Decimal6 volatility_sensitivity;
  Decimal6 max_spread;
  Decimal6 decay_parameter;

  friend bool operator==(const CorePriceFiltered& lhs, const CorePriceFiltered& rhs) { return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.symbol == rhs.symbol && lhs.min_spread == rhs.min_spread && lhs.sharp_move_period == rhs.sharp_move_period && lhs.sharp_move_diff == rhs.sharp_move_diff && lhs.volatility_period == rhs.volatility_period && lhs.volatility_interval == rhs.volatility_interval && lhs.volatility_sensitivity == rhs.volatility_sensitivity && lhs.max_spread == rhs.max_spread && lhs.decay_parameter == rhs.decay_parameter; }

  friend bool operator!=(const CorePriceFiltered& lhs, const CorePriceFiltered& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const CorePriceFiltered& obj) {
    std::size_t seed = 0x6F9CA21B;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.min_spread);
    boost::hash_combine(seed, obj.sharp_move_period);
    boost::hash_combine(seed, obj.sharp_move_diff);
    boost::hash_combine(seed, obj.volatility_period);
    boost::hash_combine(seed, obj.volatility_interval);
    boost::hash_combine(seed, obj.volatility_sensitivity);
    boost::hash_combine(seed, obj.max_spread);
    boost::hash_combine(seed, obj.decay_parameter);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const CorePriceFiltered& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " symbol: " << obj.symbol
           << " min_spread: " << obj.min_spread
           << " sharp_move_period: " << obj.sharp_move_period
           << " sharp_move_diff: " << obj.sharp_move_diff
           << " volatility_period: " << obj.volatility_period
           << " volatility_interval: " << obj.volatility_interval
           << " volatility_sensitivity: " << obj.volatility_sensitivity
           << " max_spread: " << obj.max_spread
           << " decay_parameter: " << obj.decay_parameter;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::CorePriceFiltered> {
  inline constexpr static auto name = "CorePriceFiltered";
  using Type = dvc::protobuf::CorePriceFiltered;

  auto operator()(const dvc::CorePriceFiltered& src) const noexcept -> Type;

  auto operator()(const Type& src) const noexcept -> dvc::CorePriceFiltered {
    using namespace mdh::dvc;
    CorePriceFiltered result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.symbol = src.symbol();
    result.min_spread = Decimal6{src.min_spread()};
    result.sharp_move_period = Decimal6{src.sharp_move_period()};
    result.sharp_move_diff = Decimal6{src.sharp_move_diff()};
    result.volatility_period = Decimal6{src.volatility_period()};
    result.volatility_interval = Decimal6{src.volatility_interval()};
    result.volatility_sensitivity = Decimal6{src.volatility_sensitivity()};
    result.max_spread = Decimal6{src.max_spread()};
    result.decay_parameter = Decimal6{src.decay_parameter()};
    return result;
  }
};

inline auto mdh::cluster::adapter::Adapter<mdh::dvc::CorePriceFiltered>::operator()(const dvc::CorePriceFiltered& src) const noexcept -> Type {
  Type res;
  res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
  res.set_id(src.id);
  res.set_symbol(src.symbol);
  res.set_min_spread(toString(src.min_spread));
  res.set_sharp_move_period(toString(src.sharp_move_period));
  res.set_sharp_move_diff(toString(src.sharp_move_diff));
  res.set_volatility_period(toString(src.volatility_period));
  res.set_volatility_interval(toString(src.volatility_interval));
  res.set_volatility_sensitivity(toString(src.volatility_sensitivity));
  res.set_max_spread(toString(src.max_spread));
  res.set_decay_parameter(toString(src.decay_parameter));
  return res;
}
