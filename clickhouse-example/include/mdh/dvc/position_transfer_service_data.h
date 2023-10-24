#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>
#include <position_transfer_service_data.pb.h>

// primary key - timestamp

namespace mdh::dvc {
struct PositionTransferServiceData {
  TimePoint timestamp;
  Decimal6 base_amount;
  Decimal6 term_amount;
  Decimal6 timestamp_original;
  std::string symbol;
  std::string term_currency;
  std::string to_book;
  std::string base_currency;
  std::string from_book;
  std::string comment;
  std::string trade_id;

  friend bool operator==(const PositionTransferServiceData& lhs, const PositionTransferServiceData& rhs) { return lhs.timestamp == rhs.timestamp && lhs.base_amount == rhs.base_amount && lhs.term_amount == rhs.term_amount && lhs.timestamp_original == rhs.timestamp_original && lhs.symbol == rhs.symbol && lhs.term_currency == rhs.term_currency && lhs.to_book == rhs.to_book && lhs.base_currency == rhs.base_currency && lhs.from_book == rhs.from_book && lhs.comment == rhs.comment && lhs.trade_id == rhs.trade_id; }

  friend bool operator!=(const PositionTransferServiceData& lhs, const PositionTransferServiceData& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const PositionTransferServiceData& obj) {
    std::size_t seed = 0x15612FED;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.base_amount);
    boost::hash_combine(seed, obj.term_amount);
    boost::hash_combine(seed, obj.timestamp_original);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.term_currency);
    boost::hash_combine(seed, obj.to_book);
    boost::hash_combine(seed, obj.base_currency);
    boost::hash_combine(seed, obj.from_book);
    boost::hash_combine(seed, obj.comment);
    boost::hash_combine(seed, obj.trade_id);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const PositionTransferServiceData& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " base_amount: " << obj.base_amount
           << " term_amount: " << obj.term_amount
           << " timestamp_original: " << obj.timestamp_original
           << " symbol: " << obj.symbol
           << " term_currency: " << obj.term_currency
           << " to_book: " << obj.to_book
           << " base_currency: " << obj.base_currency
           << " from_book: " << obj.from_book
           << " comment: " << obj.comment
           << " trade_id: " << obj.trade_id;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::PositionTransferServiceData> {
  inline constexpr static auto name = "PositionTransferServiceData";
  using Type = dvc::protobuf::PositionTransferServiceData;

  auto operator()(const dvc::PositionTransferServiceData& src) const noexcept -> Type {
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

  auto operator()(const Type& src) const noexcept -> dvc::PositionTransferServiceData {
    using namespace mdh::dvc;
    PositionTransferServiceData result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.base_amount = Decimal6{src.base_amount()};
    result.term_amount = Decimal6{src.term_amount()};
    result.timestamp_original = Decimal6{src.timestamp_original()};
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
