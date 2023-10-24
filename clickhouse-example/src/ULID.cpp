#include <mdh/cluster/ULID.h>
namespace mdh::cluster {
UlidGenerator::UlidGenerator() {
  ulid_generator_init(&generator_, ULID_SECURE);
}

auto UlidGenerator::operator()() noexcept -> Type {
  static constexpr auto buffer_size = 27;
  char buffer[buffer_size];
  ulid_generate(&generator_, buffer);
  return buffer;
}
}
