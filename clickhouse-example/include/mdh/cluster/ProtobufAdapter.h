#pragma once
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <google/protobuf/util/delimited_message_util.h>
#include <mdh/cluster/Buffer.h>
#include <mdh/cluster/Logger.h>
#include <mdh/cluster/Tools.h>

namespace mdh::cluster {

template <typename Src>
struct Adapter;

template <typename T>
concept HasAdapterDefined = requires {
  typename std::type_identity<typename Adapter<T>::Dst>;
  std::is_class_v<typename Adapter<T>::Dst>;
};

template <typename Src>
concept AdapterHasCallableOperator = requires(Adapter<Src> t, Src const &src) {
  { t(src) } noexcept -> std::same_as<typename Adapter<Src>::Dst>;
};

template <typename Src>
concept AdapterHasCallableReverseOperator =
  requires(Adapter<Src> t, typename Adapter<Src>::Dst const &src) {
    { t(src) } noexcept -> std::same_as<Src>;
  };

/**
 * \brief
 * \tparam Src
 */
template <typename Src>
class ProtobufAdapter final {
  static_assert(DefaultCopyAndMove<Src>);
  static_assert(HasAdapterDefined<Src>);
  static_assert(AdapterHasCallableOperator<Src>);
  static_assert(AdapterHasCallableReverseOperator<Src>);

  using Source = Src;
  using Destination = typename Adapter<Src>::Dst;

public:
  auto operator()(Source const &object) const noexcept -> Buffer;

  auto operator()(Buffer const &src) const noexcept -> Source;

private:
  Adapter<Source> trait_;
};

template <typename Src>
class ProtobufContainerAdapter final {
  static_assert(DefaultCopyAndMove<Src>);
  static_assert(HasAdapterDefined<Src>);
  static_assert(AdapterHasCallableOperator<Src>);
  static_assert(AdapterHasCallableReverseOperator<Src>);

  using Source = Src;
  using Destination = typename Adapter<Source>::Dst;

public:
  auto operator()(Buffer const &src) const noexcept -> std::vector<Source>;

  auto operator()(std::vector<Source> const &container) -> Buffer;

private:
  Adapter<Source> trait_;
};

template <typename Src>
auto ProtobufAdapter<Src>::operator()(Source const &object) const noexcept -> Buffer {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;
  try {
    Buffer buffer;
    {
      auto stream = filtering_ostream{};
      stream.push(back_insert_device(buffer));
      trait_(object).SerializeToOstream(&stream);
    }
    return buffer;
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s} while converting {:s} to buffer", ex.what(), typeid(Source).name());
    _Exit(EXIT_FAILURE);
  }
}

template <typename Src>
auto ProtobufAdapter<Src>::operator()(Buffer const &src) const noexcept -> Source {
  try {
    Destination result;
    result.ParseFromArray(src.data(), static_cast<int>(src.size()));
    return trait_(result);
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s} while converting buffer to {:s}", ex.what(), typeid(Source).name());
    _Exit(EXIT_FAILURE);
  }
}

template <typename Source>
auto ProtobufContainerAdapter<Source>::operator()(
  Buffer const &src
) const noexcept -> std::vector<Source> {
  return {};
}

template <typename Source>
auto ProtobufContainerAdapter<Source>::operator()(std::vector<Source> const &container) -> Buffer {
  using namespace boost::iostreams;
  using namespace google::protobuf::util;
  try {
    Buffer buffer;
    {
      auto stream = filtering_ostream{};
      stream.push(back_insert_device(buffer));
      std::for_each(
        begin(container),
        end(container),
        [&, this](Source const &object) {
          if (!SerializeDelimitedToOstream(trait_(object), &stream)) {
            LOG_FATAL("SerializeDelimitedToOstream failed at {:s}:{:d}", __FILE__, __LINE__);
            _Exit(EXIT_FAILURE);
          }
        }
      );
    }
    return buffer;
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s} while converting {:s} to buffer", ex.what(), typeid(Source).name());
    _Exit(EXIT_FAILURE);
  }
}
} // namespace mdh::cluster
