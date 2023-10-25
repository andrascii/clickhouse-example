#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include "strategy_config.pb.h"
#include "types.h"

namespace mdh::dvc {

struct StrategyConfig final {
  bool operator==(const StrategyConfig& rhs) const {
    return timestamp == rhs.timestamp &&
           id == rhs.id &&
           value_type == rhs.value_type &&
           value == rhs.value &&
           key == rhs.key &&
           strategy == rhs.strategy &&
           parameter == rhs.parameter &&
           description == rhs.description &&
           editable == rhs.editable &&
           display == rhs.display &&
           updated_by == rhs.updated_by &&
           updated_at == rhs.updated_at;
  }

  bool operator!=(const StrategyConfig& rhs) const {
    return !(rhs == *this);
  }

  TimePoint timestamp;
  int64_t id;

  std::string value_type;
  std::string value;
  std::string key;
  std::string strategy;
  std::string parameter;
  std::string description;
  std::string editable;
  std::string display;
  std::string updated_by;

  int64_t updated_at;
};

} // namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::StrategyConfig> {
  inline constexpr static auto name = "StrategyConfig";
  using Type = dvc::protobuf::StrategyConfig;

  Type operator()(const dvc::StrategyConfig& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_id(src.id);

    res.set_value_type(src.value_type);
    res.set_value(src.value);
    res.set_key(src.key);
    res.set_strategy(src.strategy);
    res.set_parameter(src.parameter);
    res.set_description(src.description);
    res.set_editable(src.editable);
    res.set_display(src.display);
    res.set_updated_by(src.updated_by);

    res.set_updated_at(src.updated_at);

    return res;
  }

  dvc::StrategyConfig operator()(const Type& src) const noexcept {
    dvc::StrategyConfig result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.id = src.id();

    result.value_type = src.value_type();
    result.value = src.value();
    result.key = src.key();
    result.strategy = src.strategy();
    result.parameter = src.parameter();
    result.description = src.description();
    result.editable = src.editable();
    result.display = src.display();
    result.updated_by = src.updated_by();

    result.updated_at = src.updated_at();

    return result;
  }
};
