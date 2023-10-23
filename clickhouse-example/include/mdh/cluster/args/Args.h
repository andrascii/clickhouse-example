#pragma once
#include <mdh/cluster/log/Logger.h>
#include <toml.hpp>

namespace mdh::cluster {
class Args final {
public:
  Args() = delete;

  explicit Args(logger::Logger logger, const std::filesystem::path& path);

  auto operator()() const noexcept -> toml::value;

private:
  logger::Logger logger_;
  toml::value values_;
};
}// namespace mdh::cluster::args
