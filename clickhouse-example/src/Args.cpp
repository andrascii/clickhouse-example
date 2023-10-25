#include <mdh/cluster/Args.h>
#include <mdh/cluster/Logger.h>

namespace mdh::cluster {
Args::Args(std::filesystem::path const &path) {
  try {
    values_ = toml::parse(path);
  } catch (std::exception const &ex) {
    LOG_FATAL("{:s}", ex.what());
    _Exit(EXIT_FAILURE);
  }
}

auto Args::operator()() const noexcept -> toml::value {
  return values_;
}

}
