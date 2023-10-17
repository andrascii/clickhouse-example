#pragma once

#include <fads_markup.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

/*
CREATE TABLE FadsMarkupTable (
  timestamp DateTime,
  id Int64,
  volume_band Int64,
  bid_spd Decimal(38, 18),
  ask_spd Decimal(38, 18),
  bid_bp Decimal(38, 18),
  ask_bp Decimal(38, 18),
  updated_at Decimal(38, 18),
  symbol String,
  tier String,
  client String,
  tenor String,
  strategy String,
  enabled String,
  updated_by String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id);
 */

struct FadsMarkup {
  TimePoint timestamp;
  int64_t id;
  int64_t volume_band;
  dec::decimal6 bid_spd;
  dec::decimal6 ask_spd;
  dec::decimal6 bid_bp;
  dec::decimal6 ask_bp;
  dec::decimal6 updated_at;
  std::string symbol;
  std::string tier;
  std::string client;
  std::string tenor;
  std::string strategy;
  std::string enabled;
  std::string updated_by;
};

template <>
struct mdh::cluster::adapter::Adapter<FadsMarkup> {
  inline constexpr static auto name = "FadsMarkup";
  using Type = mdh::FadsMarkup;

  auto operator()(const ::FadsMarkup& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_volume_band(src.volume_band);
    res.set_symbol(src.symbol);
    res.set_tier(src.tier);
    res.set_client(src.client);
    res.set_tenor(src.tenor);
    res.set_strategy(src.strategy);
    res.set_enabled(src.enabled);
    res.set_updated_by(src.updated_by);
    res.set_bid_spd(toString(src.bid_spd));
    res.set_ask_spd(toString(src.ask_spd));
    res.set_bid_bp(toString(src.bid_bp));
    res.set_ask_bp(toString(src.ask_bp));
    res.set_updated_at(toString(src.updated_at));
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::FadsMarkup {
    ::FadsMarkup result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.volume_band = src.volume_band();
    result.symbol = src.symbol();
    result.tier = src.tier();
    result.client = src.client();
    result.tenor = src.tenor();
    result.strategy = src.strategy();
    result.enabled = src.enabled();
    result.updated_by = src.updated_by();
    result.bid_spd = dec::decimal6{src.bid_spd()};
    result.ask_spd = dec::decimal6{src.ask_spd()};
    result.bid_bp = dec::decimal6{src.bid_bp()};
    result.ask_bp = dec::decimal6{src.ask_bp()};
    result.updated_at = dec::decimal6{src.updated_at()};
    return result;
  }
};