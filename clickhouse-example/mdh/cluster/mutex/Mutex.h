#pragma once
#include <mutex>
namespace mdh::cluster::mutex {
class Mutex final {
 public:
  auto lock() -> void;

  auto unlock() -> void;

 private:
  std::mutex mutex_;
};

inline auto Mutex::lock() -> void { return mutex_.lock(); }
inline auto Mutex::unlock() -> void { return mutex_.unlock(); }

}// namespace mdh::cluster::mutex