#pragma once
#include <string>

extern "C" {
#include <ulid/ulid.h>
}

namespace mdh::cluster {
class UlidGenerator final {
public:
  using Type = std::string;

  UlidGenerator();

  auto operator()() noexcept -> Type;

private:
  ulid_generator generator_;
};
}
