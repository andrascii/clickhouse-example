#pragma once

#include <currency_pair_specs.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

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
  display_rate_check_difference Decimal(6, 6),
  reuter_default_scaling Decimal(6, 6),
  display_large_spread_indicator Decimal(6, 6)
) ENGINE = MergeTree() PRIMARY KEY (timestamp)
 * */

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
  dec::decimal6 display_rate_check_difference;
  dec::decimal6 reuter_default_scaling;
  dec::decimal6 display_large_spread_indicator;
};

template <>
struct mdh::cluster::adapter::Adapter<CurrencyPnl> {
  inline constexpr static auto name = "CurrencyPnl";
  using Type = mdh::CurrencyPnl;

  auto operator()(const ::CurrencyPnl& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> ::CurrencyPnl {
    ::CurrencyPnl result{};
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

    result.display_rate_check_difference = dec::decimal6{src.display_rate_check_difference()};
    result.reuter_default_scaling = dec::decimal6{src.reuter_default_scaling()};
    result.display_large_spread_indicator = dec::decimal6{src.display_large_spread_indicator()};
    return result;
  }
};