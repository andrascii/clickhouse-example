#pragma once

#include <currency_pair_specs.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

/*
CREATE TABLE CurrencyPairSpecsTable (
  timestamp DateTime,
  symbol String,
  symbol_type String,
  display_precision_multiplier Int64,
  minor_decimals Int64,
  display_decimals Int64,
  display_small_quantity_indicator Int64,
  price_precision Int64,
  additional_pip_precision Int64,
  display_figure_decimals Int64,
  price_precision_swap Int64,
  display_large_quantity_indicator Int64,
  spot_adjustment_precision Int64,
  ref_rate_offset Int64,
  forward_adjustment_precision Int64,
  display_rate_check_difference Decimal6(6, 6),
  reuter_default_scaling Decimal6(6, 6),
  display_large_spread_indicator Decimal6(6, 6)
) ENGINE = MergeTree() PRIMARY KEY (timestamp)
 * */

namespace mdh::dvc {
struct CurrencyPairSpecs {
  TimePoint timestamp;
  std::string symbol;
  std::string symbol_type;
  int64_t display_precision_multiplier;
  int64_t minor_decimals;
  int64_t display_decimals;
  int64_t display_small_quantity_indicator;
  int64_t price_precision;
  int64_t additional_pip_precision;
  int64_t display_figure_decimals;
  int64_t price_precision_swap;
  int64_t display_large_quantity_indicator;
  int64_t spot_adjustment_precision;
  int64_t ref_rate_offset;
  int64_t forward_adjustment_precision;
  Decimal6 display_rate_check_difference;
  Decimal6 reuter_default_scaling;
  Decimal6 display_large_spread_indicator;

  friend bool operator==(const CurrencyPairSpecs& lhs, const CurrencyPairSpecs& rhs) { return lhs.timestamp == rhs.timestamp && lhs.symbol == rhs.symbol && lhs.symbol_type == rhs.symbol_type && lhs.display_precision_multiplier == rhs.display_precision_multiplier && lhs.minor_decimals == rhs.minor_decimals && lhs.display_decimals == rhs.display_decimals && lhs.display_small_quantity_indicator == rhs.display_small_quantity_indicator && lhs.price_precision == rhs.price_precision && lhs.additional_pip_precision == rhs.additional_pip_precision && lhs.display_figure_decimals == rhs.display_figure_decimals && lhs.price_precision_swap == rhs.price_precision_swap && lhs.display_large_quantity_indicator == rhs.display_large_quantity_indicator && lhs.spot_adjustment_precision == rhs.spot_adjustment_precision && lhs.ref_rate_offset == rhs.ref_rate_offset && lhs.forward_adjustment_precision == rhs.forward_adjustment_precision && lhs.display_rate_check_difference == rhs.display_rate_check_difference && lhs.reuter_default_scaling == rhs.reuter_default_scaling && lhs.display_large_spread_indicator == rhs.display_large_spread_indicator; }

  friend bool operator!=(const CurrencyPairSpecs& lhs, const CurrencyPairSpecs& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const CurrencyPairSpecs& obj) {
    std::size_t seed = 0x4C10B7CE;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.symbol_type);
    boost::hash_combine(seed, obj.display_precision_multiplier);
    boost::hash_combine(seed, obj.minor_decimals);
    boost::hash_combine(seed, obj.display_decimals);
    boost::hash_combine(seed, obj.display_small_quantity_indicator);
    boost::hash_combine(seed, obj.price_precision);
    boost::hash_combine(seed, obj.additional_pip_precision);
    boost::hash_combine(seed, obj.display_figure_decimals);
    boost::hash_combine(seed, obj.price_precision_swap);
    boost::hash_combine(seed, obj.display_large_quantity_indicator);
    boost::hash_combine(seed, obj.spot_adjustment_precision);
    boost::hash_combine(seed, obj.ref_rate_offset);
    boost::hash_combine(seed, obj.forward_adjustment_precision);
    boost::hash_combine(seed, obj.display_rate_check_difference);
    boost::hash_combine(seed, obj.reuter_default_scaling);
    boost::hash_combine(seed, obj.display_large_spread_indicator);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const CurrencyPairSpecs& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " symbol: " << obj.symbol
           << " symbol_type: " << obj.symbol_type
           << " display_precision_multiplier: " << obj.display_precision_multiplier
           << " minor_decimals: " << obj.minor_decimals
           << " display_decimals: " << obj.display_decimals
           << " display_small_quantity_indicator: " << obj.display_small_quantity_indicator
           << " price_precision: " << obj.price_precision
           << " additional_pip_precision: " << obj.additional_pip_precision
           << " display_figure_decimals: " << obj.display_figure_decimals
           << " price_precision_swap: " << obj.price_precision_swap
           << " display_large_quantity_indicator: " << obj.display_large_quantity_indicator
           << " spot_adjustment_precision: " << obj.spot_adjustment_precision
           << " ref_rate_offset: " << obj.ref_rate_offset
           << " forward_adjustment_precision: " << obj.forward_adjustment_precision
           << " display_rate_check_difference: " << obj.display_rate_check_difference
           << " reuter_default_scaling: " << obj.reuter_default_scaling
           << " display_large_spread_indicator: " << obj.display_large_spread_indicator;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::CurrencyPairSpecs> {
  inline constexpr static auto name = "CurrencyPnl";
  using Type = dvc::protobuf::CurrencyPairSpecs;

  auto operator()(const dvc::CurrencyPairSpecs& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_symbol(src.symbol);
    res.set_symbol_type(src.symbol_type);
    res.set_display_precision_multiplier(src.display_precision_multiplier);
    res.set_minor_decimals(src.minor_decimals);
    res.set_display_decimals(src.display_decimals);
    res.set_display_small_quantity_indicator(src.display_small_quantity_indicator);
    res.set_price_precision(src.price_precision);
    res.set_additional_pip_precision(src.additional_pip_precision);
    res.set_display_figure_decimals(src.display_figure_decimals);
    res.set_price_precision_swap(src.price_precision_swap);
    res.set_display_large_quantity_indicator(src.display_large_quantity_indicator);
    res.set_spot_adjustment_precision(src.spot_adjustment_precision);
    res.set_ref_rate_offset(src.ref_rate_offset);
    res.set_forward_adjustment_precision(src.forward_adjustment_precision);

    res.set_display_rate_check_difference(toString(src.display_rate_check_difference));
    res.set_reuter_default_scaling(toString(src.reuter_default_scaling));
    res.set_display_large_spread_indicator(toString(src.display_large_spread_indicator));
    return res;
  }

  auto operator()(const Type& src) const noexcept -> dvc::CurrencyPairSpecs {
    using namespace mdh::dvc;
    CurrencyPairSpecs result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.symbol = src.symbol();
    result.symbol_type = src.symbol_type();
    result.display_precision_multiplier = src.display_precision_multiplier();
    result.minor_decimals = src.minor_decimals();
    result.display_decimals = src.display_decimals();
    result.display_small_quantity_indicator = src.display_small_quantity_indicator();
    result.price_precision = src.price_precision();
    result.additional_pip_precision = src.additional_pip_precision();
    result.display_figure_decimals = src.display_figure_decimals();
    result.price_precision_swap = src.price_precision_swap();
    result.display_large_quantity_indicator = src.display_large_quantity_indicator();
    result.spot_adjustment_precision = src.spot_adjustment_precision();
    result.ref_rate_offset = src.ref_rate_offset();
    result.forward_adjustment_precision = src.forward_adjustment_precision();

    result.display_rate_check_difference = Decimal6{src.display_rate_check_difference()};
    result.reuter_default_scaling = Decimal6{src.reuter_default_scaling()};
    result.display_large_spread_indicator = Decimal6{src.display_large_spread_indicator()};
    return result;
  }
};
