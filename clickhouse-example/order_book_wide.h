#pragma once

#include <order_book_wide.pb.h>
#include <decimal-for-cpp/decimal.h>
#include "types.h"

// primary key [timestamp]

struct OrderBookWide {
  TimePoint timestamp;
  std::string symbol;

  dec::decimal6 bid_size1;
  dec::decimal6 bid_price1;
  dec::decimal6 ask_size1;
  dec::decimal6 ask_price1;

  dec::decimal6 bid_size2;
  dec::decimal6 bid_price2;
  dec::decimal6 ask_size2;
  dec::decimal6 ask_price2;

  dec::decimal6 bid_size3;
  dec::decimal6 bid_price3;
  dec::decimal6 ask_size3;
  dec::decimal6 ask_price3;

  dec::decimal6 bid_size4;
  dec::decimal6 bid_price4;
  dec::decimal6 ask_size4;
  dec::decimal6 ask_price4;

  dec::decimal6 bid_size5;
  dec::decimal6 bid_price5;
  dec::decimal6 ask_size5;
  dec::decimal6 ask_price5;

  dec::decimal6 bid_size6;
  dec::decimal6 bid_price6;
  dec::decimal6 ask_size6;
  dec::decimal6 ask_price6;

  dec::decimal6 bid_size7;
  dec::decimal6 bid_price7;
  dec::decimal6 ask_size7;
  dec::decimal6 ask_price7;

  dec::decimal6 bid_size8;
  dec::decimal6 bid_price8;
  dec::decimal6 ask_size8;
  dec::decimal6 ask_price8;

  dec::decimal6 bid_size9;
  dec::decimal6 bid_price9;
  dec::decimal6 ask_size9;
  dec::decimal6 ask_price9;

  dec::decimal6 bid_size10;
  dec::decimal6 bid_price10;
  dec::decimal6 ask_size10;
  dec::decimal6 ask_price10;

  dec::decimal6 bid_size11;
  dec::decimal6 bid_price11;
  dec::decimal6 ask_size11;
  dec::decimal6 ask_price11;

  dec::decimal6 bid_size12;
  dec::decimal6 bid_price12;
  dec::decimal6 ask_size12;
  dec::decimal6 ask_price12;

  dec::decimal6 bid_size13;
  dec::decimal6 bid_price13;
  dec::decimal6 ask_size13;
  dec::decimal6 ask_price13;

  dec::decimal6 bid_size14;
  dec::decimal6 bid_price14;
  dec::decimal6 ask_size14;
  dec::decimal6 ask_price14;

  dec::decimal6 bid_size15;
  dec::decimal6 bid_price15;
  dec::decimal6 ask_size15;
  dec::decimal6 ask_price15;

  dec::decimal6 bid_size16;
  dec::decimal6 bid_price16;
  dec::decimal6 ask_size16;
  dec::decimal6 ask_price16;

  dec::decimal6 bid_size17;
  dec::decimal6 bid_price17;
  dec::decimal6 ask_size17;
  dec::decimal6 ask_price17;

  dec::decimal6 bid_size18;
  dec::decimal6 bid_price18;
  dec::decimal6 ask_size18;
  dec::decimal6 ask_price18;

  dec::decimal6 bid_size19;
  dec::decimal6 bid_price19;
  dec::decimal6 ask_size19;
  dec::decimal6 ask_price19;

  dec::decimal6 bid_size20;
  dec::decimal6 bid_price20;
  dec::decimal6 ask_size20;
  dec::decimal6 ask_price20;
};

template <>
struct mdh::cluster::adapter::Adapter<OrderBookWide> {
  inline constexpr static auto name = "OrderBookWide";
  using Type = mdh::OrderBookWide;

  auto operator()(const ::OrderBookWide& src) const noexcept -> Type {
    Type res;
    res.set_timestamp(date::format("%Y-%m-%d %T", src.timestamp));
    res.set_symbol(src.symbol);

    res.set_bid_size1(toString(src.bid_size1));
    res.set_bid_price1(toString(src.bid_price1));
    res.set_ask_size1(toString(src.ask_size1));
    res.set_ask_price1(toString(src.ask_price1));

    res.set_bid_size2(toString(src.bid_size2));
    res.set_bid_price2(toString(src.bid_price2));
    res.set_ask_size2(toString(src.ask_size2));
    res.set_ask_price2(toString(src.ask_price2));

    res.set_bid_size3(toString(src.bid_size3));
    res.set_bid_price3(toString(src.bid_price3));
    res.set_ask_size3(toString(src.ask_size3));
    res.set_ask_price3(toString(src.ask_price3));

    res.set_bid_size4(toString(src.bid_size4));
    res.set_bid_price4(toString(src.bid_price4));
    res.set_ask_size4(toString(src.ask_size4));
    res.set_ask_price4(toString(src.ask_price4));

    res.set_bid_size5(toString(src.bid_size5));
    res.set_bid_price5(toString(src.bid_price5));
    res.set_ask_size5(toString(src.ask_size5));
    res.set_ask_price5(toString(src.ask_price5));

    res.set_bid_size6(toString(src.bid_size6));
    res.set_bid_price6(toString(src.bid_price6));
    res.set_ask_size6(toString(src.ask_size6));
    res.set_ask_price6(toString(src.ask_price6));

    res.set_bid_size7(toString(src.bid_size7));
    res.set_bid_price7(toString(src.bid_price7));
    res.set_ask_size7(toString(src.ask_size7));
    res.set_ask_price7(toString(src.ask_price7));

    res.set_bid_size8(toString(src.bid_size8));
    res.set_bid_price8(toString(src.bid_price8));
    res.set_ask_size8(toString(src.ask_size8));
    res.set_ask_price8(toString(src.ask_price8));

    res.set_bid_size9(toString(src.bid_size9));
    res.set_bid_price9(toString(src.bid_price9));
    res.set_ask_size9(toString(src.ask_size9));
    res.set_ask_price9(toString(src.ask_price9));

    res.set_bid_size10(toString(src.bid_size10));
    res.set_bid_price10(toString(src.bid_price10));
    res.set_ask_size10(toString(src.ask_size10));
    res.set_ask_price10(toString(src.ask_price10));

    res.set_bid_size11(toString(src.bid_size11));
    res.set_bid_price11(toString(src.bid_price11));
    res.set_ask_size11(toString(src.ask_size11));
    res.set_ask_price11(toString(src.ask_price11));

    res.set_bid_size12(toString(src.bid_size12));
    res.set_bid_price12(toString(src.bid_price12));
    res.set_ask_size12(toString(src.ask_size12));
    res.set_ask_price12(toString(src.ask_price12));

    res.set_bid_size13(toString(src.bid_size13));
    res.set_bid_price13(toString(src.bid_price13));
    res.set_ask_size13(toString(src.ask_size13));
    res.set_ask_price13(toString(src.ask_price13));

    res.set_bid_size14(toString(src.bid_size14));
    res.set_bid_price14(toString(src.bid_price14));
    res.set_ask_size14(toString(src.ask_size14));
    res.set_ask_price14(toString(src.ask_price14));

    res.set_bid_size15(toString(src.bid_size15));
    res.set_bid_price15(toString(src.bid_price15));
    res.set_ask_size15(toString(src.ask_size15));
    res.set_ask_price15(toString(src.ask_price15));

    res.set_bid_size16(toString(src.bid_size16));
    res.set_bid_price16(toString(src.bid_price16));
    res.set_ask_size16(toString(src.ask_size16));
    res.set_ask_price16(toString(src.ask_price16));

    res.set_bid_size17(toString(src.bid_size17));
    res.set_bid_price17(toString(src.bid_price17));
    res.set_ask_size17(toString(src.ask_size17));
    res.set_ask_price17(toString(src.ask_price17));

    res.set_bid_size18(toString(src.bid_size18));
    res.set_bid_price18(toString(src.bid_price18));
    res.set_ask_size18(toString(src.ask_size18));
    res.set_ask_price18(toString(src.ask_price18));

    res.set_bid_size19(toString(src.bid_size19));
    res.set_bid_price19(toString(src.bid_price19));
    res.set_ask_size19(toString(src.ask_size19));
    res.set_ask_price19(toString(src.ask_price19));

    res.set_bid_size20(toString(src.bid_size20));
    res.set_bid_price20(toString(src.bid_price20));
    res.set_ask_size20(toString(src.ask_size20));
    res.set_ask_price20(toString(src.ask_price20));
    
    return res;
  }

  auto operator()(const Type& src) const noexcept -> ::OrderBookWide {
    ::OrderBookWide result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);

    result.bid_size1 = dec::decimal6{src.bid_size1()};
    result.bid_price1 = dec::decimal6{src.bid_price1()};
    result.ask_size1 = dec::decimal6{src.ask_size1()};
    result.ask_price1 = dec::decimal6{src.ask_price1()};

    result.bid_size2 = dec::decimal6{src.bid_size2()};
    result.bid_price2 = dec::decimal6{src.bid_price2()};
    result.ask_size2 = dec::decimal6{src.ask_size2()};
    result.ask_price2 = dec::decimal6{src.ask_price2()};

    result.bid_size3 = dec::decimal6{src.bid_size3()};
    result.bid_price3 = dec::decimal6{src.bid_price3()};
    result.ask_size3 = dec::decimal6{src.ask_size3()};
    result.ask_price3 = dec::decimal6{src.ask_price3()};

    result.bid_size4 = dec::decimal6{src.bid_size4()};
    result.bid_price4 = dec::decimal6{src.bid_price4()};
    result.ask_size4 = dec::decimal6{src.ask_size4()};
    result.ask_price4 = dec::decimal6{src.ask_price4()};

    result.bid_size5 = dec::decimal6{src.bid_size5()};
    result.bid_price5 = dec::decimal6{src.bid_price5()};
    result.ask_size5 = dec::decimal6{src.ask_size5()};
    result.ask_price5 = dec::decimal6{src.ask_price5()};

    result.bid_size6 = dec::decimal6{src.bid_size6()};
    result.bid_price6 = dec::decimal6{src.bid_price6()};
    result.ask_size6 = dec::decimal6{src.ask_size6()};
    result.ask_price6 = dec::decimal6{src.ask_price6()};

    result.bid_size7 = dec::decimal6{src.bid_size7()};
    result.bid_price7 = dec::decimal6{src.bid_price7()};
    result.ask_size7 = dec::decimal6{src.ask_size7()};
    result.ask_price7 = dec::decimal6{src.ask_price7()};

    result.bid_size8 = dec::decimal6{src.bid_size8()};
    result.bid_price8 = dec::decimal6{src.bid_price8()};
    result.ask_size8 = dec::decimal6{src.ask_size8()};
    result.ask_price8 = dec::decimal6{src.ask_price8()};

    result.bid_size9 = dec::decimal6{src.bid_size9()};
    result.bid_price9 = dec::decimal6{src.bid_price9()};
    result.ask_size9 = dec::decimal6{src.ask_size9()};
    result.ask_price9 = dec::decimal6{src.ask_price9()};

    result.bid_size10 = dec::decimal6{src.bid_size10()};
    result.bid_price10 = dec::decimal6{src.bid_price10()};
    result.ask_size10 = dec::decimal6{src.ask_size10()};
    result.ask_price10 = dec::decimal6{src.ask_price10()};

    result.bid_size11 = dec::decimal6{src.bid_size11()};
    result.bid_price11 = dec::decimal6{src.bid_price11()};
    result.ask_size11 = dec::decimal6{src.ask_size11()};
    result.ask_price11 = dec::decimal6{src.ask_price11()};

    result.bid_size12 = dec::decimal6{src.bid_size12()};
    result.bid_price12 = dec::decimal6{src.bid_price12()};
    result.ask_size12 = dec::decimal6{src.ask_size12()};
    result.ask_price12 = dec::decimal6{src.ask_price12()};

    result.bid_size13 = dec::decimal6{src.bid_size13()};
    result.bid_price13 = dec::decimal6{src.bid_price13()};
    result.ask_size13 = dec::decimal6{src.ask_size13()};
    result.ask_price13 = dec::decimal6{src.ask_price13()};

    result.bid_size14 = dec::decimal6{src.bid_size14()};
    result.bid_price14 = dec::decimal6{src.bid_price14()};
    result.ask_size14 = dec::decimal6{src.ask_size14()};
    result.ask_price14 = dec::decimal6{src.ask_price14()};

    result.bid_size15 = dec::decimal6{src.bid_size15()};
    result.bid_price15 = dec::decimal6{src.bid_price15()};
    result.ask_size15 = dec::decimal6{src.ask_size15()};
    result.ask_price15 = dec::decimal6{src.ask_price15()};

    result.bid_size16 = dec::decimal6{src.bid_size16()};
    result.bid_price16 = dec::decimal6{src.bid_price16()};
    result.ask_size16 = dec::decimal6{src.ask_size16()};
    result.ask_price16 = dec::decimal6{src.ask_price16()};

    result.bid_size17 = dec::decimal6{src.bid_size17()};
    result.bid_price17 = dec::decimal6{src.bid_price17()};
    result.ask_size17 = dec::decimal6{src.ask_size17()};
    result.ask_price17 = dec::decimal6{src.ask_price17()};

    result.bid_size18 = dec::decimal6{src.bid_size18()};
    result.bid_price18 = dec::decimal6{src.bid_price18()};
    result.ask_size18 = dec::decimal6{src.ask_size18()};
    result.ask_price18 = dec::decimal6{src.ask_price18()};

    result.bid_size19 = dec::decimal6{src.bid_size19()};
    result.bid_price19 = dec::decimal6{src.bid_price19()};
    result.ask_size19 = dec::decimal6{src.ask_size19()};
    result.ask_price19 = dec::decimal6{src.ask_price19()};

    result.bid_size20 = dec::decimal6{src.bid_size20()};
    result.bid_price20 = dec::decimal6{src.bid_price20()};
    result.ask_size20 = dec::decimal6{src.ask_size20()};
    result.ask_price20 = dec::decimal6{src.ask_price20()};

    return result;
  }
};