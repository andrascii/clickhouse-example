#include "NullMutex.h"

namespace mdh::cluster::mutex {
auto NullMutex::lock() -> void {}
auto NullMutex::unlock() -> void {}
}// namespace mdh::cluster::mutex