#include <chrono>
#include <mdh/cluster/Logger.h>

namespace mdh::cluster {
auto InitLogger(std::string const &name) -> void {
  using namespace std::chrono;
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>(name, 23, 59));
  auto const logger = std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
  spdlog::flush_every(seconds(1));
  register_logger(logger);
}
}
