#pragma once
#include <decimal-for-cpp/decimal.h>

#include <chrono>
#include <boost/functional/hash.hpp>
#include <date/date.h>

namespace mdh::dvc {
using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Decimal6 = dec::decimal6;
}// namespace mdh::dvc

template <>
struct boost::hash<mdh::dvc::TimePoint> {
  auto operator()(mdh::dvc::TimePoint tp) const noexcept -> std::size_t { return 0; }
};

template <>
struct boost::hash<mdh::dvc::Decimal6> {
  auto operator()(mdh::dvc::Decimal6 decimal) const noexcept -> std::size_t { return 0; }
};
