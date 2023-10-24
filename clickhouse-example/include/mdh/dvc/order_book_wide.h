#pragma once

#include <mdh/cluster/adapter/ProtobufAdapter.h>
#include <mdh/dvc/types.h>
#include <order_book_wide.pb.h>

// primary key [timestamp]

namespace mdh::dvc {
struct OrderBookWide {
  TimePoint timestamp;
  std::string symbol;

  Decimal6 bid_size1;
  Decimal6 bid_price1;
  Decimal6 ask_size1;
  Decimal6 ask_price1;

  Decimal6 bid_size2;
  Decimal6 bid_price2;
  Decimal6 ask_size2;
  Decimal6 ask_price2;

  Decimal6 bid_size3;
  Decimal6 bid_price3;
  Decimal6 ask_size3;
  Decimal6 ask_price3;

  Decimal6 bid_size4;
  Decimal6 bid_price4;
  Decimal6 ask_size4;
  Decimal6 ask_price4;

  Decimal6 bid_size5;
  Decimal6 bid_price5;
  Decimal6 ask_size5;
  Decimal6 ask_price5;

  Decimal6 bid_size6;
  Decimal6 bid_price6;
  Decimal6 ask_size6;
  Decimal6 ask_price6;

  Decimal6 bid_size7;
  Decimal6 bid_price7;
  Decimal6 ask_size7;
  Decimal6 ask_price7;

  Decimal6 bid_size8;
  Decimal6 bid_price8;
  Decimal6 ask_size8;
  Decimal6 ask_price8;

  Decimal6 bid_size9;
  Decimal6 bid_price9;
  Decimal6 ask_size9;
  Decimal6 ask_price9;

  Decimal6 bid_size10;
  Decimal6 bid_price10;
  Decimal6 ask_size10;
  Decimal6 ask_price10;

  Decimal6 bid_size11;
  Decimal6 bid_price11;
  Decimal6 ask_size11;
  Decimal6 ask_price11;

  Decimal6 bid_size12;
  Decimal6 bid_price12;
  Decimal6 ask_size12;
  Decimal6 ask_price12;

  Decimal6 bid_size13;
  Decimal6 bid_price13;
  Decimal6 ask_size13;
  Decimal6 ask_price13;

  Decimal6 bid_size14;
  Decimal6 bid_price14;
  Decimal6 ask_size14;
  Decimal6 ask_price14;

  Decimal6 bid_size15;
  Decimal6 bid_price15;
  Decimal6 ask_size15;
  Decimal6 ask_price15;

  Decimal6 bid_size16;
  Decimal6 bid_price16;
  Decimal6 ask_size16;
  Decimal6 ask_price16;

  Decimal6 bid_size17;
  Decimal6 bid_price17;
  Decimal6 ask_size17;
  Decimal6 ask_price17;

  Decimal6 bid_size18;
  Decimal6 bid_price18;
  Decimal6 ask_size18;
  Decimal6 ask_price18;

  Decimal6 bid_size19;
  Decimal6 bid_price19;
  Decimal6 ask_size19;
  Decimal6 ask_price19;

  Decimal6 bid_size20;
  Decimal6 bid_price20;
  Decimal6 ask_size20;
  Decimal6 ask_price20;

  Decimal6 bid_size21;
  Decimal6 bid_price21;
  Decimal6 ask_size21;
  Decimal6 ask_price21;

  Decimal6 bid_size22;
  Decimal6 bid_price22;
  Decimal6 ask_size22;
  Decimal6 ask_price22;

  Decimal6 bid_size23;
  Decimal6 bid_price23;
  Decimal6 ask_size23;
  Decimal6 ask_price23;

  Decimal6 bid_size24;
  Decimal6 bid_price24;
  Decimal6 ask_size24;
  Decimal6 ask_price24;

  Decimal6 bid_size25;
  Decimal6 bid_price25;
  Decimal6 ask_size25;
  Decimal6 ask_price25;

  Decimal6 bid_size26;
  Decimal6 bid_price26;
  Decimal6 ask_size26;
  Decimal6 ask_price26;

  Decimal6 bid_size27;
  Decimal6 bid_price27;
  Decimal6 ask_size27;
  Decimal6 ask_price27;

  Decimal6 bid_size28;
  Decimal6 bid_price28;
  Decimal6 ask_size28;
  Decimal6 ask_price28;

  Decimal6 bid_size29;
  Decimal6 bid_price29;
  Decimal6 ask_size29;
  Decimal6 ask_price29;

  Decimal6 bid_size30;
  Decimal6 bid_price30;
  Decimal6 ask_size30;
  Decimal6 ask_price30;

  Decimal6 bid_size31;
  Decimal6 bid_price31;
  Decimal6 ask_size31;
  Decimal6 ask_price31;

  Decimal6 bid_size32;
  Decimal6 bid_price32;
  Decimal6 ask_size32;
  Decimal6 ask_price32;

  Decimal6 bid_size33;
  Decimal6 bid_price33;
  Decimal6 ask_size33;
  Decimal6 ask_price33;

  Decimal6 bid_size34;
  Decimal6 bid_price34;
  Decimal6 ask_size34;
  Decimal6 ask_price34;

  Decimal6 bid_size35;
  Decimal6 bid_price35;
  Decimal6 ask_size35;
  Decimal6 ask_price35;

  Decimal6 bid_size36;
  Decimal6 bid_price36;
  Decimal6 ask_size36;
  Decimal6 ask_price36;

  Decimal6 bid_size37;
  Decimal6 bid_price37;
  Decimal6 ask_size37;
  Decimal6 ask_price37;

  Decimal6 bid_size38;
  Decimal6 bid_price38;
  Decimal6 ask_size38;
  Decimal6 ask_price38;

  Decimal6 bid_size39;
  Decimal6 bid_price39;
  Decimal6 ask_size39;
  Decimal6 ask_price39;

  Decimal6 bid_size40;
  Decimal6 bid_price40;
  Decimal6 ask_size40;
  Decimal6 ask_price40;

  Decimal6 bid_size41;
  Decimal6 bid_price41;
  Decimal6 ask_size41;
  Decimal6 ask_price41;

  Decimal6 bid_size42;
  Decimal6 bid_price42;
  Decimal6 ask_size42;
  Decimal6 ask_price42;

  Decimal6 bid_size43;
  Decimal6 bid_price43;
  Decimal6 ask_size43;
  Decimal6 ask_price43;

  Decimal6 bid_size44;
  Decimal6 bid_price44;
  Decimal6 ask_size44;
  Decimal6 ask_price44;

  Decimal6 bid_size45;
  Decimal6 bid_price45;
  Decimal6 ask_size45;
  Decimal6 ask_price45;

  Decimal6 bid_size46;
  Decimal6 bid_price46;
  Decimal6 ask_size46;
  Decimal6 ask_price46;

  Decimal6 bid_size47;
  Decimal6 bid_price47;
  Decimal6 ask_size47;
  Decimal6 ask_price47;

  Decimal6 bid_size48;
  Decimal6 bid_price48;
  Decimal6 ask_size48;
  Decimal6 ask_price48;

  Decimal6 bid_size49;
  Decimal6 bid_price49;
  Decimal6 ask_size49;
  Decimal6 ask_price49;

  Decimal6 bid_size50;
  Decimal6 bid_price50;
  Decimal6 ask_size50;
  Decimal6 ask_price50;

  friend bool operator==(const OrderBookWide& lhs, const OrderBookWide& rhs) { return lhs.timestamp == rhs.timestamp && lhs.symbol == rhs.symbol && lhs.bid_size1 == rhs.bid_size1 && lhs.bid_price1 == rhs.bid_price1 && lhs.ask_size1 == rhs.ask_size1 && lhs.ask_price1 == rhs.ask_price1 && lhs.bid_size2 == rhs.bid_size2 && lhs.bid_price2 == rhs.bid_price2 && lhs.ask_size2 == rhs.ask_size2 && lhs.ask_price2 == rhs.ask_price2 && lhs.bid_size3 == rhs.bid_size3 && lhs.bid_price3 == rhs.bid_price3 && lhs.ask_size3 == rhs.ask_size3 && lhs.ask_price3 == rhs.ask_price3 && lhs.bid_size4 == rhs.bid_size4 && lhs.bid_price4 == rhs.bid_price4 && lhs.ask_size4 == rhs.ask_size4 && lhs.ask_price4 == rhs.ask_price4 && lhs.bid_size5 == rhs.bid_size5 && lhs.bid_price5 == rhs.bid_price5 && lhs.ask_size5 == rhs.ask_size5 && lhs.ask_price5 == rhs.ask_price5 && lhs.bid_size6 == rhs.bid_size6 && lhs.bid_price6 == rhs.bid_price6 && lhs.ask_size6 == rhs.ask_size6 && lhs.ask_price6 == rhs.ask_price6 && lhs.bid_size7 == rhs.bid_size7 && lhs.bid_price7 == rhs.bid_price7 && lhs.ask_size7 == rhs.ask_size7 && lhs.ask_price7 == rhs.ask_price7 && lhs.bid_size8 == rhs.bid_size8 && lhs.bid_price8 == rhs.bid_price8 && lhs.ask_size8 == rhs.ask_size8 && lhs.ask_price8 == rhs.ask_price8 && lhs.bid_size9 == rhs.bid_size9 && lhs.bid_price9 == rhs.bid_price9 && lhs.ask_size9 == rhs.ask_size9 && lhs.ask_price9 == rhs.ask_price9 && lhs.bid_size10 == rhs.bid_size10 && lhs.bid_price10 == rhs.bid_price10 && lhs.ask_size10 == rhs.ask_size10 && lhs.ask_price10 == rhs.ask_price10 && lhs.bid_size11 == rhs.bid_size11 && lhs.bid_price11 == rhs.bid_price11 && lhs.ask_size11 == rhs.ask_size11 && lhs.ask_price11 == rhs.ask_price11 && lhs.bid_size12 == rhs.bid_size12 && lhs.bid_price12 == rhs.bid_price12 && lhs.ask_size12 == rhs.ask_size12 && lhs.ask_price12 == rhs.ask_price12 && lhs.bid_size13 == rhs.bid_size13 && lhs.bid_price13 == rhs.bid_price13 && lhs.ask_size13 == rhs.ask_size13 && lhs.ask_price13 == rhs.ask_price13 && lhs.bid_size14 == rhs.bid_size14 && lhs.bid_price14 == rhs.bid_price14 && lhs.ask_size14 == rhs.ask_size14 && lhs.ask_price14 == rhs.ask_price14 && lhs.bid_size15 == rhs.bid_size15 && lhs.bid_price15 == rhs.bid_price15 && lhs.ask_size15 == rhs.ask_size15 && lhs.ask_price15 == rhs.ask_price15 && lhs.bid_size16 == rhs.bid_size16 && lhs.bid_price16 == rhs.bid_price16 && lhs.ask_size16 == rhs.ask_size16 && lhs.ask_price16 == rhs.ask_price16 && lhs.bid_size17 == rhs.bid_size17 && lhs.bid_price17 == rhs.bid_price17 && lhs.ask_size17 == rhs.ask_size17 && lhs.ask_price17 == rhs.ask_price17 && lhs.bid_size18 == rhs.bid_size18 && lhs.bid_price18 == rhs.bid_price18 && lhs.ask_size18 == rhs.ask_size18 && lhs.ask_price18 == rhs.ask_price18 && lhs.bid_size19 == rhs.bid_size19 && lhs.bid_price19 == rhs.bid_price19 && lhs.ask_size19 == rhs.ask_size19 && lhs.ask_price19 == rhs.ask_price19 && lhs.bid_size20 == rhs.bid_size20 && lhs.bid_price20 == rhs.bid_price20 && lhs.ask_size20 == rhs.ask_size20 && lhs.ask_price20 == rhs.ask_price20 && lhs.bid_size21 == rhs.bid_size21 && lhs.bid_price21 == rhs.bid_price21 && lhs.ask_size21 == rhs.ask_size21 && lhs.ask_price21 == rhs.ask_price21 && lhs.bid_size22 == rhs.bid_size22 && lhs.bid_price22 == rhs.bid_price22 && lhs.ask_size22 == rhs.ask_size22 && lhs.ask_price22 == rhs.ask_price22 && lhs.bid_size23 == rhs.bid_size23 && lhs.bid_price23 == rhs.bid_price23 && lhs.ask_size23 == rhs.ask_size23 && lhs.ask_price23 == rhs.ask_price23 && lhs.bid_size24 == rhs.bid_size24 && lhs.bid_price24 == rhs.bid_price24 && lhs.ask_size24 == rhs.ask_size24 && lhs.ask_price24 == rhs.ask_price24 && lhs.bid_size25 == rhs.bid_size25 && lhs.bid_price25 == rhs.bid_price25 && lhs.ask_size25 == rhs.ask_size25 && lhs.ask_price25 == rhs.ask_price25 && lhs.bid_size26 == rhs.bid_size26 && lhs.bid_price26 == rhs.bid_price26 && lhs.ask_size26 == rhs.ask_size26 && lhs.ask_price26 == rhs.ask_price26 && lhs.bid_size27 == rhs.bid_size27 && lhs.bid_price27 == rhs.bid_price27 && lhs.ask_size27 == rhs.ask_size27 && lhs.ask_price27 == rhs.ask_price27 && lhs.bid_size28 == rhs.bid_size28 && lhs.bid_price28 == rhs.bid_price28 && lhs.ask_size28 == rhs.ask_size28 && lhs.ask_price28 == rhs.ask_price28 && lhs.bid_size29 == rhs.bid_size29 && lhs.bid_price29 == rhs.bid_price29 && lhs.ask_size29 == rhs.ask_size29 && lhs.ask_price29 == rhs.ask_price29 && lhs.bid_size30 == rhs.bid_size30 && lhs.bid_price30 == rhs.bid_price30 && lhs.ask_size30 == rhs.ask_size30 && lhs.ask_price30 == rhs.ask_price30 && lhs.bid_size31 == rhs.bid_size31 && lhs.bid_price31 == rhs.bid_price31 && lhs.ask_size31 == rhs.ask_size31 && lhs.ask_price31 == rhs.ask_price31 && lhs.bid_size32 == rhs.bid_size32 && lhs.bid_price32 == rhs.bid_price32 && lhs.ask_size32 == rhs.ask_size32 && lhs.ask_price32 == rhs.ask_price32 && lhs.bid_size33 == rhs.bid_size33 && lhs.bid_price33 == rhs.bid_price33 && lhs.ask_size33 == rhs.ask_size33 && lhs.ask_price33 == rhs.ask_price33 && lhs.bid_size34 == rhs.bid_size34 && lhs.bid_price34 == rhs.bid_price34 && lhs.ask_size34 == rhs.ask_size34 && lhs.ask_price34 == rhs.ask_price34 && lhs.bid_size35 == rhs.bid_size35 && lhs.bid_price35 == rhs.bid_price35 && lhs.ask_size35 == rhs.ask_size35 && lhs.ask_price35 == rhs.ask_price35 && lhs.bid_size36 == rhs.bid_size36 && lhs.bid_price36 == rhs.bid_price36 && lhs.ask_size36 == rhs.ask_size36 && lhs.ask_price36 == rhs.ask_price36 && lhs.bid_size37 == rhs.bid_size37 && lhs.bid_price37 == rhs.bid_price37 && lhs.ask_size37 == rhs.ask_size37 && lhs.ask_price37 == rhs.ask_price37 && lhs.bid_size38 == rhs.bid_size38 && lhs.bid_price38 == rhs.bid_price38 && lhs.ask_size38 == rhs.ask_size38 && lhs.ask_price38 == rhs.ask_price38 && lhs.bid_size39 == rhs.bid_size39 && lhs.bid_price39 == rhs.bid_price39 && lhs.ask_size39 == rhs.ask_size39 && lhs.ask_price39 == rhs.ask_price39 && lhs.bid_size40 == rhs.bid_size40 && lhs.bid_price40 == rhs.bid_price40 && lhs.ask_size40 == rhs.ask_size40 && lhs.ask_price40 == rhs.ask_price40 && lhs.bid_size41 == rhs.bid_size41 && lhs.bid_price41 == rhs.bid_price41 && lhs.ask_size41 == rhs.ask_size41 && lhs.ask_price41 == rhs.ask_price41 && lhs.bid_size42 == rhs.bid_size42 && lhs.bid_price42 == rhs.bid_price42 && lhs.ask_size42 == rhs.ask_size42 && lhs.ask_price42 == rhs.ask_price42 && lhs.bid_size43 == rhs.bid_size43 && lhs.bid_price43 == rhs.bid_price43 && lhs.ask_size43 == rhs.ask_size43 && lhs.ask_price43 == rhs.ask_price43 && lhs.bid_size44 == rhs.bid_size44 && lhs.bid_price44 == rhs.bid_price44 && lhs.ask_size44 == rhs.ask_size44 && lhs.ask_price44 == rhs.ask_price44 && lhs.bid_size45 == rhs.bid_size45 && lhs.bid_price45 == rhs.bid_price45 && lhs.ask_size45 == rhs.ask_size45 && lhs.ask_price45 == rhs.ask_price45 && lhs.bid_size46 == rhs.bid_size46 && lhs.bid_price46 == rhs.bid_price46 && lhs.ask_size46 == rhs.ask_size46 && lhs.ask_price46 == rhs.ask_price46 && lhs.bid_size47 == rhs.bid_size47 && lhs.bid_price47 == rhs.bid_price47 && lhs.ask_size47 == rhs.ask_size47 && lhs.ask_price47 == rhs.ask_price47 && lhs.bid_size48 == rhs.bid_size48 && lhs.bid_price48 == rhs.bid_price48 && lhs.ask_size48 == rhs.ask_size48 && lhs.ask_price48 == rhs.ask_price48 && lhs.bid_size49 == rhs.bid_size49 && lhs.bid_price49 == rhs.bid_price49 && lhs.ask_size49 == rhs.ask_size49 && lhs.ask_price49 == rhs.ask_price49 && lhs.bid_size50 == rhs.bid_size50 && lhs.bid_price50 == rhs.bid_price50 && lhs.ask_size50 == rhs.ask_size50 && lhs.ask_price50 == rhs.ask_price50; }

  friend bool operator!=(const OrderBookWide& lhs, const OrderBookWide& rhs) { return !(lhs == rhs); }

  friend std::size_t hash_value(const OrderBookWide& obj) {
    std::size_t seed = 0x5D7074D2;
    boost::hash_combine(seed, obj.timestamp);
    boost::hash_combine(seed, obj.symbol);
    boost::hash_combine(seed, obj.bid_size1);
    boost::hash_combine(seed, obj.bid_price1);
    boost::hash_combine(seed, obj.ask_size1);
    boost::hash_combine(seed, obj.ask_price1);
    boost::hash_combine(seed, obj.bid_size2);
    boost::hash_combine(seed, obj.bid_price2);
    boost::hash_combine(seed, obj.ask_size2);
    boost::hash_combine(seed, obj.ask_price2);
    boost::hash_combine(seed, obj.bid_size3);
    boost::hash_combine(seed, obj.bid_price3);
    boost::hash_combine(seed, obj.ask_size3);
    boost::hash_combine(seed, obj.ask_price3);
    boost::hash_combine(seed, obj.bid_size4);
    boost::hash_combine(seed, obj.bid_price4);
    boost::hash_combine(seed, obj.ask_size4);
    boost::hash_combine(seed, obj.ask_price4);
    boost::hash_combine(seed, obj.bid_size5);
    boost::hash_combine(seed, obj.bid_price5);
    boost::hash_combine(seed, obj.ask_size5);
    boost::hash_combine(seed, obj.ask_price5);
    boost::hash_combine(seed, obj.bid_size6);
    boost::hash_combine(seed, obj.bid_price6);
    boost::hash_combine(seed, obj.ask_size6);
    boost::hash_combine(seed, obj.ask_price6);
    boost::hash_combine(seed, obj.bid_size7);
    boost::hash_combine(seed, obj.bid_price7);
    boost::hash_combine(seed, obj.ask_size7);
    boost::hash_combine(seed, obj.ask_price7);
    boost::hash_combine(seed, obj.bid_size8);
    boost::hash_combine(seed, obj.bid_price8);
    boost::hash_combine(seed, obj.ask_size8);
    boost::hash_combine(seed, obj.ask_price8);
    boost::hash_combine(seed, obj.bid_size9);
    boost::hash_combine(seed, obj.bid_price9);
    boost::hash_combine(seed, obj.ask_size9);
    boost::hash_combine(seed, obj.ask_price9);
    boost::hash_combine(seed, obj.bid_size10);
    boost::hash_combine(seed, obj.bid_price10);
    boost::hash_combine(seed, obj.ask_size10);
    boost::hash_combine(seed, obj.ask_price10);
    boost::hash_combine(seed, obj.bid_size11);
    boost::hash_combine(seed, obj.bid_price11);
    boost::hash_combine(seed, obj.ask_size11);
    boost::hash_combine(seed, obj.ask_price11);
    boost::hash_combine(seed, obj.bid_size12);
    boost::hash_combine(seed, obj.bid_price12);
    boost::hash_combine(seed, obj.ask_size12);
    boost::hash_combine(seed, obj.ask_price12);
    boost::hash_combine(seed, obj.bid_size13);
    boost::hash_combine(seed, obj.bid_price13);
    boost::hash_combine(seed, obj.ask_size13);
    boost::hash_combine(seed, obj.ask_price13);
    boost::hash_combine(seed, obj.bid_size14);
    boost::hash_combine(seed, obj.bid_price14);
    boost::hash_combine(seed, obj.ask_size14);
    boost::hash_combine(seed, obj.ask_price14);
    boost::hash_combine(seed, obj.bid_size15);
    boost::hash_combine(seed, obj.bid_price15);
    boost::hash_combine(seed, obj.ask_size15);
    boost::hash_combine(seed, obj.ask_price15);
    boost::hash_combine(seed, obj.bid_size16);
    boost::hash_combine(seed, obj.bid_price16);
    boost::hash_combine(seed, obj.ask_size16);
    boost::hash_combine(seed, obj.ask_price16);
    boost::hash_combine(seed, obj.bid_size17);
    boost::hash_combine(seed, obj.bid_price17);
    boost::hash_combine(seed, obj.ask_size17);
    boost::hash_combine(seed, obj.ask_price17);
    boost::hash_combine(seed, obj.bid_size18);
    boost::hash_combine(seed, obj.bid_price18);
    boost::hash_combine(seed, obj.ask_size18);
    boost::hash_combine(seed, obj.ask_price18);
    boost::hash_combine(seed, obj.bid_size19);
    boost::hash_combine(seed, obj.bid_price19);
    boost::hash_combine(seed, obj.ask_size19);
    boost::hash_combine(seed, obj.ask_price19);
    boost::hash_combine(seed, obj.bid_size20);
    boost::hash_combine(seed, obj.bid_price20);
    boost::hash_combine(seed, obj.ask_size20);
    boost::hash_combine(seed, obj.ask_price20);
    boost::hash_combine(seed, obj.bid_size21);
    boost::hash_combine(seed, obj.bid_price21);
    boost::hash_combine(seed, obj.ask_size21);
    boost::hash_combine(seed, obj.ask_price21);
    boost::hash_combine(seed, obj.bid_size22);
    boost::hash_combine(seed, obj.bid_price22);
    boost::hash_combine(seed, obj.ask_size22);
    boost::hash_combine(seed, obj.ask_price22);
    boost::hash_combine(seed, obj.bid_size23);
    boost::hash_combine(seed, obj.bid_price23);
    boost::hash_combine(seed, obj.ask_size23);
    boost::hash_combine(seed, obj.ask_price23);
    boost::hash_combine(seed, obj.bid_size24);
    boost::hash_combine(seed, obj.bid_price24);
    boost::hash_combine(seed, obj.ask_size24);
    boost::hash_combine(seed, obj.ask_price24);
    boost::hash_combine(seed, obj.bid_size25);
    boost::hash_combine(seed, obj.bid_price25);
    boost::hash_combine(seed, obj.ask_size25);
    boost::hash_combine(seed, obj.ask_price25);
    boost::hash_combine(seed, obj.bid_size26);
    boost::hash_combine(seed, obj.bid_price26);
    boost::hash_combine(seed, obj.ask_size26);
    boost::hash_combine(seed, obj.ask_price26);
    boost::hash_combine(seed, obj.bid_size27);
    boost::hash_combine(seed, obj.bid_price27);
    boost::hash_combine(seed, obj.ask_size27);
    boost::hash_combine(seed, obj.ask_price27);
    boost::hash_combine(seed, obj.bid_size28);
    boost::hash_combine(seed, obj.bid_price28);
    boost::hash_combine(seed, obj.ask_size28);
    boost::hash_combine(seed, obj.ask_price28);
    boost::hash_combine(seed, obj.bid_size29);
    boost::hash_combine(seed, obj.bid_price29);
    boost::hash_combine(seed, obj.ask_size29);
    boost::hash_combine(seed, obj.ask_price29);
    boost::hash_combine(seed, obj.bid_size30);
    boost::hash_combine(seed, obj.bid_price30);
    boost::hash_combine(seed, obj.ask_size30);
    boost::hash_combine(seed, obj.ask_price30);
    boost::hash_combine(seed, obj.bid_size31);
    boost::hash_combine(seed, obj.bid_price31);
    boost::hash_combine(seed, obj.ask_size31);
    boost::hash_combine(seed, obj.ask_price31);
    boost::hash_combine(seed, obj.bid_size32);
    boost::hash_combine(seed, obj.bid_price32);
    boost::hash_combine(seed, obj.ask_size32);
    boost::hash_combine(seed, obj.ask_price32);
    boost::hash_combine(seed, obj.bid_size33);
    boost::hash_combine(seed, obj.bid_price33);
    boost::hash_combine(seed, obj.ask_size33);
    boost::hash_combine(seed, obj.ask_price33);
    boost::hash_combine(seed, obj.bid_size34);
    boost::hash_combine(seed, obj.bid_price34);
    boost::hash_combine(seed, obj.ask_size34);
    boost::hash_combine(seed, obj.ask_price34);
    boost::hash_combine(seed, obj.bid_size35);
    boost::hash_combine(seed, obj.bid_price35);
    boost::hash_combine(seed, obj.ask_size35);
    boost::hash_combine(seed, obj.ask_price35);
    boost::hash_combine(seed, obj.bid_size36);
    boost::hash_combine(seed, obj.bid_price36);
    boost::hash_combine(seed, obj.ask_size36);
    boost::hash_combine(seed, obj.ask_price36);
    boost::hash_combine(seed, obj.bid_size37);
    boost::hash_combine(seed, obj.bid_price37);
    boost::hash_combine(seed, obj.ask_size37);
    boost::hash_combine(seed, obj.ask_price37);
    boost::hash_combine(seed, obj.bid_size38);
    boost::hash_combine(seed, obj.bid_price38);
    boost::hash_combine(seed, obj.ask_size38);
    boost::hash_combine(seed, obj.ask_price38);
    boost::hash_combine(seed, obj.bid_size39);
    boost::hash_combine(seed, obj.bid_price39);
    boost::hash_combine(seed, obj.ask_size39);
    boost::hash_combine(seed, obj.ask_price39);
    boost::hash_combine(seed, obj.bid_size40);
    boost::hash_combine(seed, obj.bid_price40);
    boost::hash_combine(seed, obj.ask_size40);
    boost::hash_combine(seed, obj.ask_price40);
    boost::hash_combine(seed, obj.bid_size41);
    boost::hash_combine(seed, obj.bid_price41);
    boost::hash_combine(seed, obj.ask_size41);
    boost::hash_combine(seed, obj.ask_price41);
    boost::hash_combine(seed, obj.bid_size42);
    boost::hash_combine(seed, obj.bid_price42);
    boost::hash_combine(seed, obj.ask_size42);
    boost::hash_combine(seed, obj.ask_price42);
    boost::hash_combine(seed, obj.bid_size43);
    boost::hash_combine(seed, obj.bid_price43);
    boost::hash_combine(seed, obj.ask_size43);
    boost::hash_combine(seed, obj.ask_price43);
    boost::hash_combine(seed, obj.bid_size44);
    boost::hash_combine(seed, obj.bid_price44);
    boost::hash_combine(seed, obj.ask_size44);
    boost::hash_combine(seed, obj.ask_price44);
    boost::hash_combine(seed, obj.bid_size45);
    boost::hash_combine(seed, obj.bid_price45);
    boost::hash_combine(seed, obj.ask_size45);
    boost::hash_combine(seed, obj.ask_price45);
    boost::hash_combine(seed, obj.bid_size46);
    boost::hash_combine(seed, obj.bid_price46);
    boost::hash_combine(seed, obj.ask_size46);
    boost::hash_combine(seed, obj.ask_price46);
    boost::hash_combine(seed, obj.bid_size47);
    boost::hash_combine(seed, obj.bid_price47);
    boost::hash_combine(seed, obj.ask_size47);
    boost::hash_combine(seed, obj.ask_price47);
    boost::hash_combine(seed, obj.bid_size48);
    boost::hash_combine(seed, obj.bid_price48);
    boost::hash_combine(seed, obj.ask_size48);
    boost::hash_combine(seed, obj.ask_price48);
    boost::hash_combine(seed, obj.bid_size49);
    boost::hash_combine(seed, obj.bid_price49);
    boost::hash_combine(seed, obj.ask_size49);
    boost::hash_combine(seed, obj.ask_price49);
    boost::hash_combine(seed, obj.bid_size50);
    boost::hash_combine(seed, obj.bid_price50);
    boost::hash_combine(seed, obj.ask_size50);
    boost::hash_combine(seed, obj.ask_price50);
    return seed;
  }

  friend std::ostream& operator<<(std::ostream& os, const OrderBookWide& obj) {
    return os
           << "timestamp: " << obj.timestamp
           << " symbol: " << obj.symbol
           << " bid_size1: " << obj.bid_size1
           << " bid_price1: " << obj.bid_price1
           << " ask_size1: " << obj.ask_size1
           << " ask_price1: " << obj.ask_price1
           << " bid_size2: " << obj.bid_size2
           << " bid_price2: " << obj.bid_price2
           << " ask_size2: " << obj.ask_size2
           << " ask_price2: " << obj.ask_price2
           << " bid_size3: " << obj.bid_size3
           << " bid_price3: " << obj.bid_price3
           << " ask_size3: " << obj.ask_size3
           << " ask_price3: " << obj.ask_price3
           << " bid_size4: " << obj.bid_size4
           << " bid_price4: " << obj.bid_price4
           << " ask_size4: " << obj.ask_size4
           << " ask_price4: " << obj.ask_price4
           << " bid_size5: " << obj.bid_size5
           << " bid_price5: " << obj.bid_price5
           << " ask_size5: " << obj.ask_size5
           << " ask_price5: " << obj.ask_price5
           << " bid_size6: " << obj.bid_size6
           << " bid_price6: " << obj.bid_price6
           << " ask_size6: " << obj.ask_size6
           << " ask_price6: " << obj.ask_price6
           << " bid_size7: " << obj.bid_size7
           << " bid_price7: " << obj.bid_price7
           << " ask_size7: " << obj.ask_size7
           << " ask_price7: " << obj.ask_price7
           << " bid_size8: " << obj.bid_size8
           << " bid_price8: " << obj.bid_price8
           << " ask_size8: " << obj.ask_size8
           << " ask_price8: " << obj.ask_price8
           << " bid_size9: " << obj.bid_size9
           << " bid_price9: " << obj.bid_price9
           << " ask_size9: " << obj.ask_size9
           << " ask_price9: " << obj.ask_price9
           << " bid_size10: " << obj.bid_size10
           << " bid_price10: " << obj.bid_price10
           << " ask_size10: " << obj.ask_size10
           << " ask_price10: " << obj.ask_price10
           << " bid_size11: " << obj.bid_size11
           << " bid_price11: " << obj.bid_price11
           << " ask_size11: " << obj.ask_size11
           << " ask_price11: " << obj.ask_price11
           << " bid_size12: " << obj.bid_size12
           << " bid_price12: " << obj.bid_price12
           << " ask_size12: " << obj.ask_size12
           << " ask_price12: " << obj.ask_price12
           << " bid_size13: " << obj.bid_size13
           << " bid_price13: " << obj.bid_price13
           << " ask_size13: " << obj.ask_size13
           << " ask_price13: " << obj.ask_price13
           << " bid_size14: " << obj.bid_size14
           << " bid_price14: " << obj.bid_price14
           << " ask_size14: " << obj.ask_size14
           << " ask_price14: " << obj.ask_price14
           << " bid_size15: " << obj.bid_size15
           << " bid_price15: " << obj.bid_price15
           << " ask_size15: " << obj.ask_size15
           << " ask_price15: " << obj.ask_price15
           << " bid_size16: " << obj.bid_size16
           << " bid_price16: " << obj.bid_price16
           << " ask_size16: " << obj.ask_size16
           << " ask_price16: " << obj.ask_price16
           << " bid_size17: " << obj.bid_size17
           << " bid_price17: " << obj.bid_price17
           << " ask_size17: " << obj.ask_size17
           << " ask_price17: " << obj.ask_price17
           << " bid_size18: " << obj.bid_size18
           << " bid_price18: " << obj.bid_price18
           << " ask_size18: " << obj.ask_size18
           << " ask_price18: " << obj.ask_price18
           << " bid_size19: " << obj.bid_size19
           << " bid_price19: " << obj.bid_price19
           << " ask_size19: " << obj.ask_size19
           << " ask_price19: " << obj.ask_price19
           << " bid_size20: " << obj.bid_size20
           << " bid_price20: " << obj.bid_price20
           << " ask_size20: " << obj.ask_size20
           << " ask_price20: " << obj.ask_price20
           << " bid_size21: " << obj.bid_size21
           << " bid_price21: " << obj.bid_price21
           << " ask_size21: " << obj.ask_size21
           << " ask_price21: " << obj.ask_price21
           << " bid_size22: " << obj.bid_size22
           << " bid_price22: " << obj.bid_price22
           << " ask_size22: " << obj.ask_size22
           << " ask_price22: " << obj.ask_price22
           << " bid_size23: " << obj.bid_size23
           << " bid_price23: " << obj.bid_price23
           << " ask_size23: " << obj.ask_size23
           << " ask_price23: " << obj.ask_price23
           << " bid_size24: " << obj.bid_size24
           << " bid_price24: " << obj.bid_price24
           << " ask_size24: " << obj.ask_size24
           << " ask_price24: " << obj.ask_price24
           << " bid_size25: " << obj.bid_size25
           << " bid_price25: " << obj.bid_price25
           << " ask_size25: " << obj.ask_size25
           << " ask_price25: " << obj.ask_price25
           << " bid_size26: " << obj.bid_size26
           << " bid_price26: " << obj.bid_price26
           << " ask_size26: " << obj.ask_size26
           << " ask_price26: " << obj.ask_price26
           << " bid_size27: " << obj.bid_size27
           << " bid_price27: " << obj.bid_price27
           << " ask_size27: " << obj.ask_size27
           << " ask_price27: " << obj.ask_price27
           << " bid_size28: " << obj.bid_size28
           << " bid_price28: " << obj.bid_price28
           << " ask_size28: " << obj.ask_size28
           << " ask_price28: " << obj.ask_price28
           << " bid_size29: " << obj.bid_size29
           << " bid_price29: " << obj.bid_price29
           << " ask_size29: " << obj.ask_size29
           << " ask_price29: " << obj.ask_price29
           << " bid_size30: " << obj.bid_size30
           << " bid_price30: " << obj.bid_price30
           << " ask_size30: " << obj.ask_size30
           << " ask_price30: " << obj.ask_price30
           << " bid_size31: " << obj.bid_size31
           << " bid_price31: " << obj.bid_price31
           << " ask_size31: " << obj.ask_size31
           << " ask_price31: " << obj.ask_price31
           << " bid_size32: " << obj.bid_size32
           << " bid_price32: " << obj.bid_price32
           << " ask_size32: " << obj.ask_size32
           << " ask_price32: " << obj.ask_price32
           << " bid_size33: " << obj.bid_size33
           << " bid_price33: " << obj.bid_price33
           << " ask_size33: " << obj.ask_size33
           << " ask_price33: " << obj.ask_price33
           << " bid_size34: " << obj.bid_size34
           << " bid_price34: " << obj.bid_price34
           << " ask_size34: " << obj.ask_size34
           << " ask_price34: " << obj.ask_price34
           << " bid_size35: " << obj.bid_size35
           << " bid_price35: " << obj.bid_price35
           << " ask_size35: " << obj.ask_size35
           << " ask_price35: " << obj.ask_price35
           << " bid_size36: " << obj.bid_size36
           << " bid_price36: " << obj.bid_price36
           << " ask_size36: " << obj.ask_size36
           << " ask_price36: " << obj.ask_price36
           << " bid_size37: " << obj.bid_size37
           << " bid_price37: " << obj.bid_price37
           << " ask_size37: " << obj.ask_size37
           << " ask_price37: " << obj.ask_price37
           << " bid_size38: " << obj.bid_size38
           << " bid_price38: " << obj.bid_price38
           << " ask_size38: " << obj.ask_size38
           << " ask_price38: " << obj.ask_price38
           << " bid_size39: " << obj.bid_size39
           << " bid_price39: " << obj.bid_price39
           << " ask_size39: " << obj.ask_size39
           << " ask_price39: " << obj.ask_price39
           << " bid_size40: " << obj.bid_size40
           << " bid_price40: " << obj.bid_price40
           << " ask_size40: " << obj.ask_size40
           << " ask_price40: " << obj.ask_price40
           << " bid_size41: " << obj.bid_size41
           << " bid_price41: " << obj.bid_price41
           << " ask_size41: " << obj.ask_size41
           << " ask_price41: " << obj.ask_price41
           << " bid_size42: " << obj.bid_size42
           << " bid_price42: " << obj.bid_price42
           << " ask_size42: " << obj.ask_size42
           << " ask_price42: " << obj.ask_price42
           << " bid_size43: " << obj.bid_size43
           << " bid_price43: " << obj.bid_price43
           << " ask_size43: " << obj.ask_size43
           << " ask_price43: " << obj.ask_price43
           << " bid_size44: " << obj.bid_size44
           << " bid_price44: " << obj.bid_price44
           << " ask_size44: " << obj.ask_size44
           << " ask_price44: " << obj.ask_price44
           << " bid_size45: " << obj.bid_size45
           << " bid_price45: " << obj.bid_price45
           << " ask_size45: " << obj.ask_size45
           << " ask_price45: " << obj.ask_price45
           << " bid_size46: " << obj.bid_size46
           << " bid_price46: " << obj.bid_price46
           << " ask_size46: " << obj.ask_size46
           << " ask_price46: " << obj.ask_price46
           << " bid_size47: " << obj.bid_size47
           << " bid_price47: " << obj.bid_price47
           << " ask_size47: " << obj.ask_size47
           << " ask_price47: " << obj.ask_price47
           << " bid_size48: " << obj.bid_size48
           << " bid_price48: " << obj.bid_price48
           << " ask_size48: " << obj.ask_size48
           << " ask_price48: " << obj.ask_price48
           << " bid_size49: " << obj.bid_size49
           << " bid_price49: " << obj.bid_price49
           << " ask_size49: " << obj.ask_size49
           << " ask_price49: " << obj.ask_price49
           << " bid_size50: " << obj.bid_size50
           << " bid_price50: " << obj.bid_price50
           << " ask_size50: " << obj.ask_size50
           << " ask_price50: " << obj.ask_price50;
  }
};
}// namespace mdh::dvc

template <>
struct mdh::cluster::adapter::Adapter<mdh::dvc::OrderBookWide> {
  inline constexpr static auto name = "OrderBookWide";
  using Type = dvc::protobuf::OrderBookWide;

  auto operator()(const dvc::OrderBookWide& src) const noexcept -> Type {
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
    res.set_bid_size21(toString(src.bid_size21));
    res.set_bid_price21(toString(src.bid_price21));
    res.set_ask_size21(toString(src.ask_size21));
    res.set_ask_price21(toString(src.ask_price21));
    res.set_bid_size22(toString(src.bid_size22));
    res.set_bid_price22(toString(src.bid_price22));
    res.set_ask_size22(toString(src.ask_size22));
    res.set_ask_price22(toString(src.ask_price22));
    res.set_bid_size23(toString(src.bid_size23));
    res.set_bid_price23(toString(src.bid_price23));
    res.set_ask_size23(toString(src.ask_size23));
    res.set_ask_price23(toString(src.ask_price23));
    res.set_bid_size24(toString(src.bid_size24));
    res.set_bid_price24(toString(src.bid_price24));
    res.set_ask_size24(toString(src.ask_size24));
    res.set_ask_price24(toString(src.ask_price24));
    res.set_bid_size25(toString(src.bid_size25));
    res.set_bid_price25(toString(src.bid_price25));
    res.set_ask_size25(toString(src.ask_size25));
    res.set_ask_price25(toString(src.ask_price25));
    res.set_bid_size26(toString(src.bid_size26));
    res.set_bid_price26(toString(src.bid_price26));
    res.set_ask_size26(toString(src.ask_size26));
    res.set_ask_price26(toString(src.ask_price26));
    res.set_bid_size27(toString(src.bid_size27));
    res.set_bid_price27(toString(src.bid_price27));
    res.set_ask_size27(toString(src.ask_size27));
    res.set_ask_price27(toString(src.ask_price27));
    res.set_bid_size28(toString(src.bid_size28));
    res.set_bid_price28(toString(src.bid_price28));
    res.set_ask_size28(toString(src.ask_size28));
    res.set_ask_price28(toString(src.ask_price28));
    res.set_bid_size29(toString(src.bid_size29));
    res.set_bid_price29(toString(src.bid_price29));
    res.set_ask_size29(toString(src.ask_size29));
    res.set_ask_price29(toString(src.ask_price29));
    res.set_bid_size30(toString(src.bid_size30));
    res.set_bid_price30(toString(src.bid_price30));
    res.set_ask_size30(toString(src.ask_size30));
    res.set_ask_price30(toString(src.ask_price30));
    res.set_bid_size31(toString(src.bid_size31));
    res.set_bid_price31(toString(src.bid_price31));
    res.set_ask_size31(toString(src.ask_size31));
    res.set_ask_price31(toString(src.ask_price31));
    res.set_bid_size32(toString(src.bid_size32));
    res.set_bid_price32(toString(src.bid_price32));
    res.set_ask_size32(toString(src.ask_size32));
    res.set_ask_price32(toString(src.ask_price32));
    res.set_bid_size33(toString(src.bid_size33));
    res.set_bid_price33(toString(src.bid_price33));
    res.set_ask_size33(toString(src.ask_size33));
    res.set_ask_price33(toString(src.ask_price33));
    res.set_bid_size34(toString(src.bid_size34));
    res.set_bid_price34(toString(src.bid_price34));
    res.set_ask_size34(toString(src.ask_size34));
    res.set_ask_price34(toString(src.ask_price34));
    res.set_bid_size35(toString(src.bid_size35));
    res.set_bid_price35(toString(src.bid_price35));
    res.set_ask_size35(toString(src.ask_size35));
    res.set_ask_price35(toString(src.ask_price35));
    res.set_bid_size36(toString(src.bid_size36));
    res.set_bid_price36(toString(src.bid_price36));
    res.set_ask_size36(toString(src.ask_size36));
    res.set_ask_price36(toString(src.ask_price36));
    res.set_bid_size37(toString(src.bid_size37));
    res.set_bid_price37(toString(src.bid_price37));
    res.set_ask_size37(toString(src.ask_size37));
    res.set_ask_price37(toString(src.ask_price37));
    res.set_bid_size38(toString(src.bid_size38));
    res.set_bid_price38(toString(src.bid_price38));
    res.set_ask_size38(toString(src.ask_size38));
    res.set_ask_price38(toString(src.ask_price38));
    res.set_bid_size39(toString(src.bid_size39));
    res.set_bid_price39(toString(src.bid_price39));
    res.set_ask_size39(toString(src.ask_size39));
    res.set_ask_price39(toString(src.ask_price39));
    res.set_bid_size40(toString(src.bid_size40));
    res.set_bid_price40(toString(src.bid_price40));
    res.set_ask_size40(toString(src.ask_size40));
    res.set_ask_price40(toString(src.ask_price40));
    res.set_bid_size41(toString(src.bid_size41));
    res.set_bid_price41(toString(src.bid_price41));
    res.set_ask_size41(toString(src.ask_size41));
    res.set_ask_price41(toString(src.ask_price41));
    res.set_bid_size42(toString(src.bid_size42));
    res.set_bid_price42(toString(src.bid_price42));
    res.set_ask_size42(toString(src.ask_size42));
    res.set_ask_price42(toString(src.ask_price42));
    res.set_bid_size43(toString(src.bid_size43));
    res.set_bid_price43(toString(src.bid_price43));
    res.set_ask_size43(toString(src.ask_size43));
    res.set_ask_price43(toString(src.ask_price43));
    res.set_bid_size44(toString(src.bid_size44));
    res.set_bid_price44(toString(src.bid_price44));
    res.set_ask_size44(toString(src.ask_size44));
    res.set_ask_price44(toString(src.ask_price44));
    res.set_bid_size45(toString(src.bid_size45));
    res.set_bid_price45(toString(src.bid_price45));
    res.set_ask_size45(toString(src.ask_size45));
    res.set_ask_price45(toString(src.ask_price45));
    res.set_bid_size46(toString(src.bid_size46));
    res.set_bid_price46(toString(src.bid_price46));
    res.set_ask_size46(toString(src.ask_size46));
    res.set_ask_price46(toString(src.ask_price46));
    res.set_bid_size47(toString(src.bid_size47));
    res.set_bid_price47(toString(src.bid_price47));
    res.set_ask_size47(toString(src.ask_size47));
    res.set_ask_price47(toString(src.ask_price47));
    res.set_bid_size48(toString(src.bid_size48));
    res.set_bid_price48(toString(src.bid_price48));
    res.set_ask_size48(toString(src.ask_size48));
    res.set_ask_price48(toString(src.ask_price48));
    res.set_bid_size49(toString(src.bid_size49));
    res.set_bid_price49(toString(src.bid_price49));
    res.set_ask_size49(toString(src.ask_size49));
    res.set_ask_price49(toString(src.ask_price49));
    res.set_bid_size50(toString(src.bid_size50));
    res.set_bid_price50(toString(src.bid_price50));
    res.set_ask_size50(toString(src.ask_size50));
    res.set_ask_price50(toString(src.ask_price50));
    return res;
  }

  auto operator()(const Type& src) const noexcept -> dvc::OrderBookWide {
    using namespace mdh::dvc;
    OrderBookWide result{};
    std::stringstream stream{src.timestamp()};
    stream >> date::parse("%Y-%m-%d %T", result.timestamp);
    result.bid_size1 = Decimal6{src.bid_size1()};
    result.bid_price1 = Decimal6{src.bid_price1()};
    result.ask_size1 = Decimal6{src.ask_size1()};
    result.ask_price1 = Decimal6{src.ask_price1()};
    result.bid_size2 = Decimal6{src.bid_size2()};
    result.bid_price2 = Decimal6{src.bid_price2()};
    result.ask_size2 = Decimal6{src.ask_size2()};
    result.ask_price2 = Decimal6{src.ask_price2()};
    result.bid_size3 = Decimal6{src.bid_size3()};
    result.bid_price3 = Decimal6{src.bid_price3()};
    result.ask_size3 = Decimal6{src.ask_size3()};
    result.ask_price3 = Decimal6{src.ask_price3()};
    result.bid_size4 = Decimal6{src.bid_size4()};
    result.bid_price4 = Decimal6{src.bid_price4()};
    result.ask_size4 = Decimal6{src.ask_size4()};
    result.ask_price4 = Decimal6{src.ask_price4()};
    result.bid_size5 = Decimal6{src.bid_size5()};
    result.bid_price5 = Decimal6{src.bid_price5()};
    result.ask_size5 = Decimal6{src.ask_size5()};
    result.ask_price5 = Decimal6{src.ask_price5()};
    result.bid_size6 = Decimal6{src.bid_size6()};
    result.bid_price6 = Decimal6{src.bid_price6()};
    result.ask_size6 = Decimal6{src.ask_size6()};
    result.ask_price6 = Decimal6{src.ask_price6()};
    result.bid_size7 = Decimal6{src.bid_size7()};
    result.bid_price7 = Decimal6{src.bid_price7()};
    result.ask_size7 = Decimal6{src.ask_size7()};
    result.ask_price7 = Decimal6{src.ask_price7()};
    result.bid_size8 = Decimal6{src.bid_size8()};
    result.bid_price8 = Decimal6{src.bid_price8()};
    result.ask_size8 = Decimal6{src.ask_size8()};
    result.ask_price8 = Decimal6{src.ask_price8()};
    result.bid_size9 = Decimal6{src.bid_size9()};
    result.bid_price9 = Decimal6{src.bid_price9()};
    result.ask_size9 = Decimal6{src.ask_size9()};
    result.ask_price9 = Decimal6{src.ask_price9()};
    result.bid_size10 = Decimal6{src.bid_size10()};
    result.bid_price10 = Decimal6{src.bid_price10()};
    result.ask_size10 = Decimal6{src.ask_size10()};
    result.ask_price10 = Decimal6{src.ask_price10()};
    result.bid_size11 = Decimal6{src.bid_size11()};
    result.bid_price11 = Decimal6{src.bid_price11()};
    result.ask_size11 = Decimal6{src.ask_size11()};
    result.ask_price11 = Decimal6{src.ask_price11()};
    result.bid_size12 = Decimal6{src.bid_size12()};
    result.bid_price12 = Decimal6{src.bid_price12()};
    result.ask_size12 = Decimal6{src.ask_size12()};
    result.ask_price12 = Decimal6{src.ask_price12()};
    result.bid_size13 = Decimal6{src.bid_size13()};
    result.bid_price13 = Decimal6{src.bid_price13()};
    result.ask_size13 = Decimal6{src.ask_size13()};
    result.ask_price13 = Decimal6{src.ask_price13()};
    result.bid_size14 = Decimal6{src.bid_size14()};
    result.bid_price14 = Decimal6{src.bid_price14()};
    result.ask_size14 = Decimal6{src.ask_size14()};
    result.ask_price14 = Decimal6{src.ask_price14()};
    result.bid_size15 = Decimal6{src.bid_size15()};
    result.bid_price15 = Decimal6{src.bid_price15()};
    result.ask_size15 = Decimal6{src.ask_size15()};
    result.ask_price15 = Decimal6{src.ask_price15()};
    result.bid_size16 = Decimal6{src.bid_size16()};
    result.bid_price16 = Decimal6{src.bid_price16()};
    result.ask_size16 = Decimal6{src.ask_size16()};
    result.ask_price16 = Decimal6{src.ask_price16()};
    result.bid_size17 = Decimal6{src.bid_size17()};
    result.bid_price17 = Decimal6{src.bid_price17()};
    result.ask_size17 = Decimal6{src.ask_size17()};
    result.ask_price17 = Decimal6{src.ask_price17()};
    result.bid_size18 = Decimal6{src.bid_size18()};
    result.bid_price18 = Decimal6{src.bid_price18()};
    result.ask_size18 = Decimal6{src.ask_size18()};
    result.ask_price18 = Decimal6{src.ask_price18()};
    result.bid_size19 = Decimal6{src.bid_size19()};
    result.bid_price19 = Decimal6{src.bid_price19()};
    result.ask_size19 = Decimal6{src.ask_size19()};
    result.ask_price19 = Decimal6{src.ask_price19()};
    result.bid_size20 = Decimal6{src.bid_size20()};
    result.bid_price20 = Decimal6{src.bid_price20()};
    result.ask_size20 = Decimal6{src.ask_size20()};
    result.ask_price20 = Decimal6{src.ask_price20()};
    result.bid_size21 = Decimal6{src.bid_size21()};
    result.bid_price21 = Decimal6{src.bid_price21()};
    result.ask_size21 = Decimal6{src.ask_size21()};
    result.ask_price21 = Decimal6{src.ask_price21()};
    result.bid_size22 = Decimal6{src.bid_size22()};
    result.bid_price22 = Decimal6{src.bid_price22()};
    result.ask_size22 = Decimal6{src.ask_size22()};
    result.ask_price22 = Decimal6{src.ask_price22()};
    result.bid_size23 = Decimal6{src.bid_size23()};
    result.bid_price23 = Decimal6{src.bid_price23()};
    result.ask_size23 = Decimal6{src.ask_size23()};
    result.ask_price23 = Decimal6{src.ask_price23()};
    result.bid_size24 = Decimal6{src.bid_size24()};
    result.bid_price24 = Decimal6{src.bid_price24()};
    result.ask_size24 = Decimal6{src.ask_size24()};
    result.ask_price24 = Decimal6{src.ask_price24()};
    result.bid_size25 = Decimal6{src.bid_size25()};
    result.bid_price25 = Decimal6{src.bid_price25()};
    result.ask_size25 = Decimal6{src.ask_size25()};
    result.ask_price25 = Decimal6{src.ask_price25()};
    result.bid_size26 = Decimal6{src.bid_size26()};
    result.bid_price26 = Decimal6{src.bid_price26()};
    result.ask_size26 = Decimal6{src.ask_size26()};
    result.ask_price26 = Decimal6{src.ask_price26()};
    result.bid_size27 = Decimal6{src.bid_size27()};
    result.bid_price27 = Decimal6{src.bid_price27()};
    result.ask_size27 = Decimal6{src.ask_size27()};
    result.ask_price27 = Decimal6{src.ask_price27()};
    result.bid_size28 = Decimal6{src.bid_size28()};
    result.bid_price28 = Decimal6{src.bid_price28()};
    result.ask_size28 = Decimal6{src.ask_size28()};
    result.ask_price28 = Decimal6{src.ask_price28()};
    result.bid_size29 = Decimal6{src.bid_size29()};
    result.bid_price29 = Decimal6{src.bid_price29()};
    result.ask_size29 = Decimal6{src.ask_size29()};
    result.ask_price29 = Decimal6{src.ask_price29()};
    result.bid_size30 = Decimal6{src.bid_size30()};
    result.bid_price30 = Decimal6{src.bid_price30()};
    result.ask_size30 = Decimal6{src.ask_size30()};
    result.ask_price30 = Decimal6{src.ask_price30()};
    result.bid_size31 = Decimal6{src.bid_size31()};
    result.bid_price31 = Decimal6{src.bid_price31()};
    result.ask_size31 = Decimal6{src.ask_size31()};
    result.ask_price31 = Decimal6{src.ask_price31()};
    result.bid_size32 = Decimal6{src.bid_size32()};
    result.bid_price32 = Decimal6{src.bid_price32()};
    result.ask_size32 = Decimal6{src.ask_size32()};
    result.ask_price32 = Decimal6{src.ask_price32()};
    result.bid_size33 = Decimal6{src.bid_size33()};
    result.bid_price33 = Decimal6{src.bid_price33()};
    result.ask_size33 = Decimal6{src.ask_size33()};
    result.ask_price33 = Decimal6{src.ask_price33()};
    result.bid_size34 = Decimal6{src.bid_size34()};
    result.bid_price34 = Decimal6{src.bid_price34()};
    result.ask_size34 = Decimal6{src.ask_size34()};
    result.ask_price34 = Decimal6{src.ask_price34()};
    result.bid_size35 = Decimal6{src.bid_size35()};
    result.bid_price35 = Decimal6{src.bid_price35()};
    result.ask_size35 = Decimal6{src.ask_size35()};
    result.ask_price35 = Decimal6{src.ask_price35()};
    result.bid_size36 = Decimal6{src.bid_size36()};
    result.bid_price36 = Decimal6{src.bid_price36()};
    result.ask_size36 = Decimal6{src.ask_size36()};
    result.ask_price36 = Decimal6{src.ask_price36()};
    result.bid_size37 = Decimal6{src.bid_size37()};
    result.bid_price37 = Decimal6{src.bid_price37()};
    result.ask_size37 = Decimal6{src.ask_size37()};
    result.ask_price37 = Decimal6{src.ask_price37()};
    result.bid_size38 = Decimal6{src.bid_size38()};
    result.bid_price38 = Decimal6{src.bid_price38()};
    result.ask_size38 = Decimal6{src.ask_size38()};
    result.ask_price38 = Decimal6{src.ask_price38()};
    result.bid_size39 = Decimal6{src.bid_size39()};
    result.bid_price39 = Decimal6{src.bid_price39()};
    result.ask_size39 = Decimal6{src.ask_size39()};
    result.ask_price39 = Decimal6{src.ask_price39()};
    result.bid_size40 = Decimal6{src.bid_size40()};
    result.bid_price40 = Decimal6{src.bid_price40()};
    result.ask_size40 = Decimal6{src.ask_size40()};
    result.ask_price40 = Decimal6{src.ask_price40()};
    result.bid_size41 = Decimal6{src.bid_size41()};
    result.bid_price41 = Decimal6{src.bid_price41()};
    result.ask_size41 = Decimal6{src.ask_size41()};
    result.ask_price41 = Decimal6{src.ask_price41()};
    result.bid_size42 = Decimal6{src.bid_size42()};
    result.bid_price42 = Decimal6{src.bid_price42()};
    result.ask_size42 = Decimal6{src.ask_size42()};
    result.ask_price42 = Decimal6{src.ask_price42()};
    result.bid_size43 = Decimal6{src.bid_size43()};
    result.bid_price43 = Decimal6{src.bid_price43()};
    result.ask_size43 = Decimal6{src.ask_size43()};
    result.ask_price43 = Decimal6{src.ask_price43()};
    result.bid_size44 = Decimal6{src.bid_size44()};
    result.bid_price44 = Decimal6{src.bid_price44()};
    result.ask_size44 = Decimal6{src.ask_size44()};
    result.ask_price44 = Decimal6{src.ask_price44()};
    result.bid_size45 = Decimal6{src.bid_size45()};
    result.bid_price45 = Decimal6{src.bid_price45()};
    result.ask_size45 = Decimal6{src.ask_size45()};
    result.ask_price45 = Decimal6{src.ask_price45()};
    result.bid_size46 = Decimal6{src.bid_size46()};
    result.bid_price46 = Decimal6{src.bid_price46()};
    result.ask_size46 = Decimal6{src.ask_size46()};
    result.ask_price46 = Decimal6{src.ask_price46()};
    result.bid_size47 = Decimal6{src.bid_size47()};
    result.bid_price47 = Decimal6{src.bid_price47()};
    result.ask_size47 = Decimal6{src.ask_size47()};
    result.ask_price47 = Decimal6{src.ask_price47()};
    result.bid_size48 = Decimal6{src.bid_size48()};
    result.bid_price48 = Decimal6{src.bid_price48()};
    result.ask_size48 = Decimal6{src.ask_size48()};
    result.ask_price48 = Decimal6{src.ask_price48()};
    result.bid_size49 = Decimal6{src.bid_size49()};
    result.bid_price49 = Decimal6{src.bid_price49()};
    result.ask_size49 = Decimal6{src.ask_size49()};
    result.ask_price49 = Decimal6{src.ask_price49()};
    result.bid_size50 = Decimal6{src.bid_size50()};
    result.bid_price50 = Decimal6{src.bid_price50()};
    result.ask_size50 = Decimal6{src.ask_size50()};
    result.ask_price50 = Decimal6{src.ask_price50()};
    return result;
  }
};
