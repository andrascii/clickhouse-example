#pragma once
#include <toml.hpp>

namespace mdh::cluster {
class Args final {
public:
  Args() = delete;

  explicit Args(std::filesystem::path const &path);

  auto operator()() const noexcept -> toml::value;

private:
  toml::value values_;
};

}
