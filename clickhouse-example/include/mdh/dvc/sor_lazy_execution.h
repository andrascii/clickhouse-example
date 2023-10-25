#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include "sor_lazy_execution.pb.h"
#include "types.h"

namespace mdh::dvc {

struct SorLazyExecution final {
  bool operator==(const SorLazyExecution& rhs) const {
    return timestamp == rhs.timestamp &&
           fill_number == rhs.fill_number &&
           quantity == rhs.quantity &&
           price == rhs.price &&
           timestamp_orig == rhs.timestamp_orig &&
           exec_id == rhs.exec_id &&
           order_id == rhs.order_id;
  }

  bool operator!=(const SorLazyExecution& rhs) const {
    return !(rhs == *this);
  }

  TimePoint timestamp;
  int64_t fill_number;

  Decimal6 quantity;
  Decimal6 price;
  Decimal6 timestamp_orig;

  std::string exec_id; // may be set as int64?
  std::string order_id; // may be set as int64?
};

} // namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::SorLazyExecution> {
  inline constexpr static auto name = "SorLazyExecution";
  using Type = dvc::protobuf::SorLazyExecution;

  Type operator()(const dvc::SorLazyExecution& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_fill_number(src.fill_number);

    res.set_quantity(toString(src.quantity));
    res.set_price(toString(src.price));
    res.set_timestamp_orig(toString(src.timestamp_orig));

    res.set_exec_id(src.exec_id);
    res.set_order_id(src.order_id);

    return res;
  }

  dvc::SorLazyExecution operator()(const Type& src) const noexcept {
    dvc::SorLazyExecution result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.fill_number = src.fill_number();
    result.quantity = dvc::Decimal6{src.quantity()};
    result.price = dvc::Decimal6{src.price()};
    result.timestamp_orig = dvc::Decimal6{src.timestamp_orig()};
    result.exec_id = src.exec_id();
    result.order_id = src.order_id();

    return result;
  }
};
