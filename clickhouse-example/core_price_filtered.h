#pragma once

#include <core_price_filtered.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE CorePriceFilteredTable (
  timestamp DateTime,
  id Int64,
  symbol String,
  min_spread Decimal(38, 18),
  sharp_move_period Decimal(38, 18),
  sharp_move_diff Decimal(38, 18),
  volatility_period Decimal(38, 18),
  volatility_interval Decimal(38, 18),
  volatility_sensitivity Decimal(38, 18),
  max_spread Decimal(38, 18),
  decay_parameter Decimal(38, 18)
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id)
 */

struct CorePriceFiltered {
  TimePoint timestamp;
  int64_t id;
  std::string symbol;
  dec::decimal6 min_spread;
  dec::decimal6 sharp_move_period;
  dec::decimal6 sharp_move_diff;
  dec::decimal6 volatility_period;
  dec::decimal6 volatility_interval;
  dec::decimal6 volatility_sensitivity;
  dec::decimal6 max_spread;
  dec::decimal6 decay_parameter;
};

template <>
struct mdh::cluster::adapter::Adapter<CorePriceFiltered> {
  inline constexpr static auto name = "CorePriceFiltered";
  using Type = mdh::CorePriceFiltered;

  auto operator()(const ::CorePriceFiltered& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::CorePriceFiltered {
    ::CorePriceFiltered result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.symbol = src.symbol();
    result.min_spread = dec::decimal6{src.min_spread()};
    result.sharp_move_period = dec::decimal6{src.sharp_move_period()};
    result.sharp_move_diff = dec::decimal6{src.sharp_move_diff()};
    result.volatility_period = dec::decimal6{src.volatility_period()};
    result.volatility_interval = dec::decimal6{src.volatility_interval()};
    result.volatility_sensitivity = dec::decimal6{src.volatility_sensitivity()};
    result.max_spread = dec::decimal6{src.max_spread()};
    result.decay_parameter = dec::decimal6{src.decay_parameter()};
    return result;
  }
};