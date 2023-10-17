#pragma once
namespace mdh::cluster::mutex {
class NullMutex final {
 public:
  static auto lock() -> void;

  static auto unlock() -> void;
};
}// namespace mdh::cluster::mutex