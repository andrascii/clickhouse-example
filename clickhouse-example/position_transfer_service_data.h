#pragma once

#include <position_transfer_service_data.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

// primary key - timestamp

struct PositionTransferServiceData {
  TimePoint timestamp;
  dec::decimal6 base_amount;
  dec::decimal6 term_amount;
  dec::decimal6 timestamp_original;
  std::string symbol;
  std::string term_currency;
  std::string to_book;
  std::string base_currency;
  std::string from_book;
  std::string comment;
  std::string trade_id;
};

template <>
struct mdh::cluster::adapter::Adapter<PositionTransferServiceData> {
  inline constexpr static auto name = "PositionTransferServiceData";
  using Type = mdh::PositionTransferServiceData;

  auto operator()(const ::PositionTransferServiceData& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_base_amount(toString(src.base_amount));
    res.set_term_amount(toString(src.term_amount));
    res.set_timestamp_original(toString(src.timestamp_original));
    res.set_symbol(src.symbol);
    res.set_term_currency(src.term_currency);
    res.set_to_book(src.to_book);
    res.set_base_currency(src.base_currency);
    res.set_from_book(src.from_book);
    res.set_comment(src.comment);
    res.set_trade_id(src.trade_id);
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::PositionTransferServiceData {
    ::PositionTransferServiceData result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.base_amount = dec::decimal6{src.base_amount()};
    result.term_amount = dec::decimal6{src.term_amount()};
    result.timestamp_original = dec::decimal6{src.timestamp_original()};
    result.symbol = src.symbol();
    result.term_currency = src.term_currency();
    result.to_book = src.to_book();
    result.base_currency = src.base_currency();
    result.from_book = src.from_book();
    result.comment = src.comment();
    result.trade_id = src.trade_id();
    return result;
  }
};