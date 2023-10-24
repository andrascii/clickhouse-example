#pragma once

#include <fads_markup.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE FadsMarkupTable (
  timestamp DateTime,
  id Int64,
  volume_band Int64,
  bid_spd Decimal6(38, 18),
  ask_spd Decimal6(38, 18),
  bid_bp Decimal6(38, 18),
  ask_bp Decimal6(38, 18),
  updated_at Decimal6(38, 18),
  symbol String,
  tier String,
  client String,
  tenor String,
  strategy String,
  enabled String,
  updated_by String
) ENGINE = MergeTree() PRIMARY KEY (timestamp, id);
 */

namespace mdh::dvc {
struct FadsMarkup {
  TimePoint timestamp;
  int64_t id;
  int64_t volume_band;
  Decimal6 bid_spd;
  Decimal6 ask_spd;
  Decimal6 bid_bp;
  Decimal6 ask_bp;
  Decimal6 updated_at;
  std::string symbol;
  std::string tier;
  std::string client;
  std::string tenor;
  std::string strategy;
  std::string enabled;
  std::string updated_by;

  friend bool operator==(const FadsMarkup& lhs, const FadsMarkup& rhs) {
    return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.volume_band == rhs.volume_band && lhs.bid_spd == rhs.bid_spd && lhs.ask_spd == rhs.ask_spd && lhs.bid_bp == rhs.bid_bp && lhs.ask_bp == rhs.ask_bp && lhs.updated_at == rhs.updated_at && lhs.symbol == rhs.symbol && lhs.tier == rhs.tier && lhs.client == rhs.client && lhs.tenor == rhs.tenor && lhs.strategy == rhs.strategy && lhs.enabled == rhs.enabled && lhs.updated_by == rhs.updated_by;
  }

  friend bool operator!=(const FadsMarkup& lhs, const FadsMarkup& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const FadsMarkup& obj) {
    std::size_t seed = 0x359ECE60;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.volume_band);
    boost::hash_combine(seed, obj.bid_spd);
    boost::hash_combine(seed, obj.ask_spd);
    boost::hash_combine(seed, obj.bid_bp);
    boost::hash_combine(seed, obj.ask_bp);
    boost::hash_combine(seed, obj.updated_at);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.tier);
    boost::hash_combine(seed, obj.client);
    boost::hash_combine(seed, obj.tenor);
    boost::hash_combine(seed, obj.strategy);
    boost::hash_combine(seed, obj.enabled);
    boost::hash_combine(seed, obj.updated_by);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const FadsMarkup& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " volume_band: " << obj.volume_band
           << " bid_spd: " << obj.bid_spd
           << " ask_spd: " << obj.ask_spd
           << " bid_bp: " << obj.bid_bp
           << " ask_bp: " << obj.ask_bp
           << " updated_at: " << obj.updated_at
           << " symbol: " << obj.symbol
           << " tier: " << obj.tier
           << " client: " << obj.client
           << " tenor: " << obj.tenor
           << " strategy: " << obj.strategy
           << " enabled: " << obj.enabled
           << " updated_by: " << obj.updated_by;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::FadsMarkup> {
  inline constexpr static auto name = "FadsMarkup";
  using Type = dvc::protobuf::FadsMarkup;

  auto operator()(const dvc::FadsMarkup& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> dvc::FadsMarkup {
    using namespace mdh::dvc;
    FadsMarkup result{};
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
    result.bid_spd = Decimal6{src.bid_spd()};
    result.ask_spd = Decimal6{src.ask_spd()};
    result.bid_bp = Decimal6{src.bid_bp()};
    result.ask_bp = Decimal6{src.ask_bp()};
    result.updated_at = Decimal6{src.updated_at()};
    return result;
  }
};
