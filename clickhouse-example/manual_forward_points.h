#pragma once

#include <manual_forward_points.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

// primary key - timestamp

struct ManualForwardPoints {
  TimePoint timestamp;
  int64_t id;
  int64_t bid_size;
  int64_t ask_size;
  int64_t alert_id;
  int64_t days_maturity;
  dec::decimal6 mat_date_ts;
  dec::decimal6 bid_price;
  dec::decimal6 ask_price;
  dec::decimal6 refday_bid;
  dec::decimal6 refday_ask;
  std::string source;
  std::string enabled;
  std::string mat_date;
  std::string indicative;
  std::string start_date;
  std::string bid_out_of_range;
  std::string ask_out_of_range;
};

template <>
struct mdh::cluster::adapter::Adapter<ManualForwardPoints> {
  inline constexpr static auto name = "ManualForwardPoints";
  using Type = mdh::ManualForwardPoints;

  auto operator()(const ::ManualForwardPoints& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_id(src.id);
    res.set_bid_size(src.bid_size);
    res.set_ask_size(src.ask_size);
    res.set_alert_id(src.alert_id);
    res.set_days_maturity(src.days_maturity);
    res.set_mat_date_ts(toString(src.mat_date_ts));
    res.set_bid_price(toString(src.bid_price));
    res.set_ask_price(toString(src.ask_price));
    res.set_refday_bid(toString(src.refday_bid));
    res.set_refday_ask(toString(src.refday_ask));
    res.set_source(src.source);
    res.set_enabled(src.enabled);
    res.set_mat_date(src.mat_date);
    res.set_indicative(src.indicative);
    res.set_start_date(src.start_date);
    res.set_bid_out_of_range(src.bid_out_of_range);
    res.set_ask_out_of_range(src.ask_out_of_range);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::ManualForwardPoints {
    ::ManualForwardPoints result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.bid_size = src.bid_size();
    result.ask_size = src.ask_size();
    result.alert_id = src.alert_id();
    result.days_maturity = src.days_maturity();
    result.mat_date_ts = dec::decimal6{src.mat_date_ts()};
    result.bid_price = dec::decimal6{src.bid_price()};
    result.ask_price = dec::decimal6{src.ask_price()};
    result.refday_bid = dec::decimal6{src.refday_bid()};
    result.refday_ask = dec::decimal6{src.refday_ask()};
    result.source = src.source();
    result.enabled = src.enabled();
    result.mat_date = src.mat_date();
    result.indicative = src.indicative();
    result.start_date = src.start_date();
    result.bid_out_of_range = src.bid_out_of_range();
    result.ask_out_of_range = src.ask_out_of_range();
    return result;
  }
};