#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include "sor_lazy_order.pb.h"
#include "types.h"

namespace mdh::dvc {

struct SorLazyOrder final {
  bool operator==(const SorLazyOrder& rhs) const {
    return timestamp == rhs.timestamp &&
           side == rhs.side &&
           state == rhs.state &&
           quantity == rhs.quantity &&
           limit_price == rhs.limit_price &&
           spread == rhs.spread &&
           cum_qty == rhs.cum_qty &&
           leaves_qty == rhs.leaves_qty &&
           last_price == rhs.last_price &&
           last_qty == rhs.last_qty &&
           average_price == rhs.average_price &&
           creation_time == rhs.creation_time &&
           modification_time == rhs.modification_time &&
           update_time == rhs.update_time &&
           order_id == rhs.order_id &&
           trader_book == rhs.trader_book &&
           symbol == rhs.symbol &&
           benchmark == rhs.benchmark &&
           placed_by == rhs.placed_by &&
           cancelled_by == rhs.cancelled_by;
  }

  bool operator!=(const SorLazyOrder& rhs) const {
    return !(rhs == *this);
  }

  TimePoint timestamp;
  int64_t side;
  int64_t state;

  Decimal6 quantity;
  Decimal6 limit_price;
  Decimal6 spread;
  Decimal6 cum_qty;
  Decimal6 leaves_qty;
  Decimal6 last_price;
  Decimal6 last_qty;
  Decimal6 average_price;
  Decimal6 creation_time;
  Decimal6 modification_time;
  Decimal6 update_time;

  std::string order_id;
  std::string trader_book;
  std::string symbol;
  std::string benchmark;
  std::string placed_by;
  std::string cancelled_by;
};

} // namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::SorLazyOrder> {
  inline constexpr static auto name = "SorLazyOrder";
  using Type = dvc::protobuf::SorLazyOrder;

  Type operator()(const dvc::SorLazyOrder& src) const noexcept {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));

    res.set_side(src.side);
    res.set_state(src.state);

    res.set_quantity(toString(src.quantity));
    res.set_limit_price(toString(src.limit_price));
    res.set_spread(toString(src.spread));
    res.set_cum_qty(toString(src.cum_qty));
    res.set_leaves_qty(toString(src.leaves_qty));
    res.set_last_price(toString(src.last_price));
    res.set_last_qty(toString(src.last_qty));
    res.set_average_price(toString(src.average_price));
    res.set_creation_time(toString(src.creation_time));
    res.set_modification_time(toString(src.modification_time));
    res.set_update_time(toString(src.update_time));

    res.set_order_id(src.order_id);
    res.set_trader_book(src.trader_book);
    res.set_symbol(src.symbol);
    res.set_benchmark(src.benchmark);
    res.set_placed_by(src.placed_by);
    res.set_cancelled_by(src.cancelled_by);

    return res;
  }

  dvc::SorLazyOrder operator()(const Type& src) const noexcept {
    dvc::SorLazyOrder result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.side = src.side();
    result.state = src.state();
    result.quantity = dvc::Decimal6{src.quantity()};
    result.limit_price = dvc::Decimal6{src.limit_price()};
    result.spread = dvc::Decimal6{src.spread()};
    result.cum_qty = dvc::Decimal6{src.cum_qty()};
    result.leaves_qty = dvc::Decimal6{src.leaves_qty()};
    result.last_price = dvc::Decimal6{src.last_price()};
    result.last_qty = dvc::Decimal6{src.last_qty()};
    result.average_price = dvc::Decimal6{src.average_price()};
    result.creation_time = dvc::Decimal6{src.creation_time()};
    result.modification_time = dvc::Decimal6{src.modification_time()};
    result.update_time = dvc::Decimal6{src.update_time()};
    result.order_id = src.order_id();
    result.trader_book = src.trader_book();
    result.symbol = src.symbol();
    result.benchmark = src.benchmark();
    result.placed_by = src.placed_by();
    result.cancelled_by = src.cancelled_by();

    return result;
  }
};
