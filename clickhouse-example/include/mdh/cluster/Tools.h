#pragma once
#include <tuple>
#include <type_traits>
#include <variant>
#include <boost/container_hash/hash.hpp>

namespace mdh::cluster {
template <class T>
using Invoke = typename T::type;

template <class C, class I, class E>
using If = Invoke<std::conditional<C{}, I, E>>;

template <class T>
struct Id {
};

struct Empty {
};

template <class A, class B>
struct Base : A, B {
};

template <class B, class...>
struct AreUniqueImpl;

template <class B>
struct AreUniqueImpl<B> : std::true_type {
};

template <class B, class T, class... U>
struct AreUniqueImpl<B, T, U...>
  : If<std::is_base_of<Id<T>, B>, std::false_type, AreUniqueImpl<Base<B, Id<T>>, U...>> {
};

template <class... T>
struct AreUnique : AreUniqueImpl<Empty, T...> {
};

template <typename T, typename Tuple>
struct HasType;

template <typename T>
struct HasType<T, std::tuple<>> : std::false_type {
};

template <typename T, typename U, typename... Ts>
struct HasType<T, std::tuple<U, Ts...>> : HasType<T, std::tuple<Ts...>> {
};

template <typename T, typename... Ts>
struct HasType<T, std::tuple<T, Ts...>> : std::true_type {
};

template <class T, class Tuple>
struct Index {
  static_assert(!std::is_same_v<Tuple, std::tuple<>>, "could not find T in given tuple");
  static constexpr int value = 0;
};

template <class T, class... Types>
struct Index<T, std::tuple<T, Types...>> {
  static constexpr int value = 0;
};

template <class T, class U, class... Types>
struct Index<T, std::tuple<U, Types...>> {
  static int constexpr value = 1 + Index<T, std::tuple<Types...>>::value;
};

template <typename... Args>
concept Hashable = (std::is_same_v<decltype(boost::hash<Args>{}), boost::hash<Args>> && ...);

template <typename T>
concept HasEqualityOperator = requires(T a, T b) {
  { a == b } -> std::convertible_to<bool>;
  { a != b } -> std::convertible_to<bool>;
};

template <typename... Args>
concept Comparable = (HasEqualityOperator<Args> && ...);

template <typename T>
concept HasDefaultCopyMoveConstructors = std::is_default_constructible_v<T> &&
  std::is_copy_constructible_v<T> && std::is_move_constructible_v<T>;

template <typename T>
concept HasCopyMoveOperators = std::is_copy_assignable_v<T> && std::is_move_assignable_v<T>;

template <typename... Args>
concept DefaultCopyAndMove =
  (HasDefaultCopyMoveConstructors<Args> && ...) && (HasCopyMoveOperators<Args> && ...);

template <typename T, typename ValueType>
concept IterableContainerOf = requires(T t) {
  typename std::decay_t<decltype(*std::begin(t))>;
  requires std::is_same_v<std::decay_t<decltype(*std::begin(t))>, ValueType>;
};

template <typename T, typename... Args>
concept IsVariantOf = std::is_same_v<T, std::variant<Args...>>;

template <std::size_t I>
struct VisitImpl final {
  template <typename T, typename Callable>
  static auto DoVisit(T const &tuple, size_t index, Callable callable) -> void {
    if (index == I - 1) {
      return callable(std::get<I - 1>(tuple));
    }
    return VisitImpl<I - 1>::DoVisit(tuple, index, callable);
  }
};

template <>
struct VisitImpl<0> final {
  template <typename T, typename Callable>
  static auto DoVisit(T const &tuple, size_t index, Callable callable) -> void {
    assert(false);
  }
};

template <typename Callable, typename... Ts>
auto Visit(std::tuple<Ts...> const &tuple, size_t index, Callable callable) -> void {
  return VisitImpl<sizeof...(Ts)>::DoVisit(tuple, index, callable);
}

template <typename Callable, typename... Ts>
auto Visit(std::tuple<Ts...> &tuple, size_t index, Callable callable) -> void {
  return VisitImpl<sizeof...(Ts)>::DoVisit(tuple, index, callable);
}

}
