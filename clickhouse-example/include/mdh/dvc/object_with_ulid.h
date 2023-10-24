#pragma once
#include <mdh/cluster/ULID.h>
#include <mdh/dvc/types.h>

namespace mdh::dvc {
template <typename T>
struct ObjectWithUlid : T {

  ObjectWithUlid() = default;

  //
  explicit ObjectWithUlid(T&& object)
    : T{std::forward<T>(object)},
      id{cluster::UlidGenerator{}()} { }

  //
  explicit ObjectWithUlid(const T& object)
    : T{object},
      id{cluster::UlidGenerator{}()} {}

  //
  ObjectWithUlid<T>& operator=(const T& object) {
    this->object = object;
    this->id = cluster::UlidGenerator{}();
    return *this;
  }

  //
  ObjectWithUlid<T>& operator=(T&& object) {
    this->object = std::move(object);
    this->id = cluster::UlidGenerator{}();
    return *this;
  }

  ObjectWithUlid(const ObjectWithUlid& other)
    : T{other},
      id{other.id} { }

  ObjectWithUlid(ObjectWithUlid&& other) noexcept
    : T{std::move(other)},
      id{std::move(other.id)} { }

  ObjectWithUlid& operator=(const ObjectWithUlid& other) {
    if (this == &other) { return *this; }
    T::operator=(other);
    id = other.id;
    return *this;
  }

  ObjectWithUlid& operator=(ObjectWithUlid&& other) noexcept {
    if (this == &other) { return *this; }
    T::operator=(std::move(other));
    id = std::move(other.id);
    return *this;
  }

  ~ObjectWithUlid() = default;

  friend std::ostream& operator<<(std::ostream& os, const ObjectWithUlid& obj) {
    return os
           << "id: " << obj.id << ' '
           << static_cast<const T&>(obj);
  }

  friend bool operator==(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return std::tie(static_cast<const T&>(lhs), lhs.id) == std::tie(static_cast<const T&>(rhs), rhs.id); }

  friend bool operator!=(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return !(lhs == rhs); }

  friend bool operator<(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return std::tie(static_cast<const T&>(lhs), lhs.id) < std::tie(static_cast<const T&>(rhs), rhs.id); }

  friend bool operator<=(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return !(rhs < lhs); }

  friend bool operator>(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return rhs < lhs; }

  friend bool operator>=(const ObjectWithUlid& lhs, const ObjectWithUlid& rhs) { return !(lhs < rhs); }

  friend std::size_t hash_value(const ObjectWithUlid& obj) {
    std::size_t seed = 0x19F19DC6;
    boost::hash_combine(seed, static_cast<const T&>(obj));
    boost::hash_combine(seed, obj.id);
    return seed;
  }

  std::string id;
};
}
