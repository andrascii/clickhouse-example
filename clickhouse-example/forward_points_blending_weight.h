#pragma once

#include <forward_points_blending_weight.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

// primary key [timestamp, id]

struct ForwardPointsBlendingWeight {
  TimePoint timestamp;
  int64_t id;
  dec::decimal6 weight;
  std::string symbol;
  std::string tenor;
  std::string source;
  std::string points_type;
};

template <>
struct mdh::cluster::adapter::Adapter<ForwardPointsBlendingWeight> {
  inline constexpr static auto name = "ForwardPointsBlendingWeight";
  using Type = mdh::ForwardPointsBlendingWeight;

  auto operator()(const ::ForwardPointsBlendingWeight& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::ForwardPointsBlendingWeight {
    ::ForwardPointsBlendingWeight result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.weight = dec::decimal6{src.weight()};
    result.symbol = src.symbol();
    result.tenor = src.tenor();
    result.source = src.source();
    result.points_type = src.points_type();
    return result;
  }
};