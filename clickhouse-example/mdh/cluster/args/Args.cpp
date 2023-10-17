#include "Args.h"

#include <toml/parser.hpp>

namespace mdh::cluster::args {
Args::Args(logger::Logger logger, const std::filesystem::path& path)
    : logger_{std::move(logger)} {
  try {
    values_ = toml::parse(path);
  } catch (const std::exception& ex) {
    LOG_FATAL(logger_, "{:s}", ex.what());
    _Exit(EXIT_FAILURE);
  }
}

auto Args::operator()() const noexcept -> toml::value { return values_; }
}// namespace mdh::cluster::args
