#pragma once

#include <google/protobuf/util/delimited_message_util.h>
#include <mdh/cluster/log/Logger.h>
#include <mdh/cluster/mutex/Mutex.h>

#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <cstdlib>

namespace mdh::cluster::adapter {

template <typename T>
struct Adapter;

namespace detail {

template <typename, typename = void>
struct HasType : std::false_type {};

template <typename T>
struct HasType<T, std::void_t<typename T::Type>> : std::true_type {};

}// namespace detail

template <
  typename T,
  typename Buffer = std::vector<char>,
  typename Container = std::vector<T>,
  typename = std::enable_if<detail::HasType<Adapter<T>>::value>>
class ProtobufAdapter {
 public:
  static_assert(
    std::is_default_constructible_v<T>,
    "T must have default constructor");

  static_assert(
    detail::HasType<Adapter<T>>::value,
    "no Adapter for a class");

  using Destination = typename Adapter<T>::Type;

  static_assert(
    std::is_default_constructible_v<Destination>,
    "Destination must have default constructor");

  ProtobufAdapter() = delete;

  explicit ProtobufAdapter(logger::Logger logger);

  [[nodiscard]] auto operator()(const T& object) noexcept -> Buffer;

  [[nodiscard]] auto operator()(const Container& container) noexcept -> Buffer;

  [[nodiscard]] auto operator()(const Buffer& buffer) noexcept -> T;

  [[nodiscard]] auto operator()() const noexcept -> std::string;

 private:
  logger::Logger logger_;
  Adapter<T> converter_;
};

template <typename T, typename Buffer, typename Container, typename T0>
ProtobufAdapter<T, Buffer, Container, T0>::ProtobufAdapter(
  logger::Logger logger)
    : logger_{std::move(logger)} {}

template <typename T, typename Buffer, typename Container, typename T0>
auto ProtobufAdapter<T, Buffer, Container, T0>::operator()(
  const T& object) noexcept -> Buffer {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;
  try {
    Buffer buffer;
    {
      auto stream = filtering_ostream{};
      stream.push(back_insert_device(buffer));
      converter_(object).SerializeToOstream(&stream);
    }
    return buffer;
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s} while converting {:s} to buffer", ex.what(), typeid(T).name());
    _Exit(EXIT_FAILURE);
  }
}

template <typename T, typename Buffer, typename Container, typename T0>
auto ProtobufAdapter<T, Buffer, Container, T0>::operator()(
  const Container& container) noexcept -> Buffer {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;
  try {
    Buffer buffer;
    auto stream = filtering_ostream{};
    stream.push(back_insert_device(buffer));
    std::for_each(
      begin(container),
      end(container),
      [&, this](const T& object) {
        if (!SerializeDelimitedToOstream(converter_(object), &stream)) {
          LOG_FATAL(
            logger_,
            "SerializeDelimitedToOstream failed at {:s}:{:d}",
            __FILE__,
            __LINE__);
          _Exit(EXIT_FAILURE);
        }
      });
    return buffer;
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s} while converting {:s} to buffer", ex.what(), typeid(T).name());
    _Exit(EXIT_FAILURE);
  }
}

template <typename T, typename Buffer, typename Container, typename T0>
auto ProtobufAdapter<T, Buffer, Container, T0>::operator()(
  const Buffer& buffer) noexcept -> T {
  try {
    Destination result;
    result.ParseFromArray(buffer.data(), static_cast<int>(buffer.size()));
    return converter_(result);
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s} while converting buffer to {:s}", ex.what(), typeid(T).name());
    _Exit(EXIT_FAILURE);
  }
}

template <typename T, typename Buffer, typename Container, typename T0>
auto ProtobufAdapter<T, Buffer, Container, T0>::operator()() const noexcept
  -> std::string {
  return Adapter<T>::name;
}
}// namespace mdh::cluster::adapter
