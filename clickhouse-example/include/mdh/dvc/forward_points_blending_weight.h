#pragma once

#include <forward_points_blending_weight.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

// primary key [timestamp, id]

namespace mdh::dvc {
struct ForwardPointsBlendingWeight {
  TimePoint timestamp;
  int64_t id;
  Decimal6 weight;
  std::string symbol;
  std::string tenor;
  std::string source;
  std::string points_type;

  friend bool operator==(const ForwardPointsBlendingWeight& lhs, const ForwardPointsBlendingWeight& rhs) { return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.weight == rhs.weight && lhs.symbol == rhs.symbol && lhs.tenor == rhs.tenor && lhs.source == rhs.source && lhs.points_type == rhs.points_type; }

  friend bool operator!=(const ForwardPointsBlendingWeight& lhs, const ForwardPointsBlendingWeight& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const ForwardPointsBlendingWeight& obj) {
    std::size_t seed = 0x2B115095;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.weight);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.tenor);
    boost::hash_combine(seed, obj.source);
    boost::hash_combine(seed, obj.points_type);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const ForwardPointsBlendingWeight& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " weight: " << obj.weight
           << " symbol: " << obj.symbol
           << " tenor: " << obj.tenor
           << " source: " << obj.source
           << " points_type: " << obj.points_type;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::ForwardPointsBlendingWeight> {
  inline constexpr static auto name = "ForwardPointsBlendingWeight";
  using Type = dvc::protobuf::ForwardPointsBlendingWeight;

  auto operator()(const dvc::ForwardPointsBlendingWeight& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_weight(toString(src.weight));
    res.set_id(src.id);
    res.set_symbol(src.symbol);
    res.set_tenor(src.tenor);
    res.set_source(src.source);
    res.set_points_type(src.points_type);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> dvc::ForwardPointsBlendingWeight {
    using namespace mdh::dvc;
    ForwardPointsBlendingWeight result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.weight = Decimal6{src.weight()};
    result.symbol = src.symbol();
    result.tenor = src.tenor();
    result.source = src.source();
    result.points_type = src.points_type();
    return result;
  }
};
