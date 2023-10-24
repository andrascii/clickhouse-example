#pragma once

#include <manual_forward_points.pb.h>
#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>

// primary key - timestamp

namespace mdh::dvc {
struct ManualForwardPoints {
  TimePoint timestamp;
  int64_t id;
  int64_t bid_size;
  int64_t ask_size;
  int64_t alert_id;
  int64_t days_maturity;
  Decimal6 mat_date_ts;
  Decimal6 bid_price;
  Decimal6 ask_price;
  Decimal6 refday_bid;
  Decimal6 refday_ask;
  std::string source;
  std::string enabled;
  std::string mat_date;
  std::string indicative;
  std::string start_date;
  std::string bid_out_of_range;
  std::string ask_out_of_range;

  friend bool operator==(const ManualForwardPoints& lhs, const ManualForwardPoints& rhs) { return lhs.timestamp == rhs.timestamp && lhs.id == rhs.id && lhs.bid_size == rhs.bid_size && lhs.ask_size == rhs.ask_size && lhs.alert_id == rhs.alert_id && lhs.days_maturity == rhs.days_maturity && lhs.mat_date_ts == rhs.mat_date_ts && lhs.bid_price == rhs.bid_price && lhs.ask_price == rhs.ask_price && lhs.refday_bid == rhs.refday_bid && lhs.refday_ask == rhs.refday_ask && lhs.source == rhs.source && lhs.enabled == rhs.enabled && lhs.mat_date == rhs.mat_date && lhs.indicative == rhs.indicative && lhs.start_date == rhs.start_date && lhs.bid_out_of_range == rhs.bid_out_of_range && lhs.ask_out_of_range == rhs.ask_out_of_range; }

  friend bool operator!=(const ManualForwardPoints& lhs, const ManualForwardPoints& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const ManualForwardPoints& obj) {
    std::size_t seed = 0x49A90163;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.id);
    boost::hash_combine(seed, obj.bid_size);
    boost::hash_combine(seed, obj.ask_size);
    boost::hash_combine(seed, obj.alert_id);
    boost::hash_combine(seed, obj.days_maturity);
    boost::hash_combine(seed, obj.mat_date_ts);
    boost::hash_combine(seed, obj.bid_price);
    boost::hash_combine(seed, obj.ask_price);
    boost::hash_combine(seed, obj.refday_bid);
    boost::hash_combine(seed, obj.refday_ask);
    boost::hash_combine(seed, obj.source);
    boost::hash_combine(seed, obj.enabled);
    boost::hash_combine(seed, obj.mat_date);
    boost::hash_combine(seed, obj.indicative);
    boost::hash_combine(seed, obj.start_date);
    boost::hash_combine(seed, obj.bid_out_of_range);
    boost::hash_combine(seed, obj.ask_out_of_range);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const ManualForwardPoints& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " id: " << obj.id
           << " bid_size: " << obj.bid_size
           << " ask_size: " << obj.ask_size
           << " alert_id: " << obj.alert_id
           << " days_maturity: " << obj.days_maturity
           << " mat_date_ts: " << obj.mat_date_ts
           << " bid_price: " << obj.bid_price
           << " ask_price: " << obj.ask_price
           << " refday_bid: " << obj.refday_bid
           << " refday_ask: " << obj.refday_ask
           << " source: " << obj.source
           << " enabled: " << obj.enabled
           << " mat_date: " << obj.mat_date
           << " indicative: " << obj.indicative
           << " start_date: " << obj.start_date
           << " bid_out_of_range: " << obj.bid_out_of_range
           << " ask_out_of_range: " << obj.ask_out_of_range;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::ManualForwardPoints> {
  inline constexpr static auto name = "ManualForwardPoints";
  using Type = dvc::protobuf::ManualForwardPoints;

  auto operator()(const dvc::ManualForwardPoints& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> dvc::ManualForwardPoints {
    using namespace mdh::dvc;
    ManualForwardPoints result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.id = src.id();
    result.bid_size = src.bid_size();
    result.ask_size = src.ask_size();
    result.alert_id = src.alert_id();
    result.days_maturity = src.days_maturity();
    result.mat_date_ts = Decimal6{src.mat_date_ts()};
    result.bid_price = Decimal6{src.bid_price()};
    result.ask_price = Decimal6{src.ask_price()};
    result.refday_bid = Decimal6{src.refday_bid()};
    result.refday_ask = Decimal6{src.refday_ask()};
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
