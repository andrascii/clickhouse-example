#pragma once

#if defined(SPDLOG_ACTIVE_LEVEL)
#undef SPDLOG_ACTIVE_LEVEL
#endif  // defined(SPDLOG_ACTIVE_LEVEL)
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include <spdlog/formatter.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bin_to_hex.h>
#include <spdlog/fmt/std.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(spdlog::default_logger(), __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(spdlog::default_logger(), __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_INFO(spdlog::default_logger(), __VA_ARGS__)
#define LOG_WARNING(...) SPDLOG_LOGGER_WARN(spdlog::default_logger(), __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(spdlog::default_logger(), __VA_ARGS__)
#define LOG_FATAL(...) SPDLOG_LOGGER_CRITICAL(spdlog::default_logger(), __VA_ARGS__)
/*
#define LOG_TRACE(spdlog::default_logger(), ...) SPDLOG_LOGGER_TRACE(spdlog::default_logger(), __VA_ARGS__)
#define LOG_DEBUG(spdlog::default_logger(), ...) SPDLOG_LOGGER_DEBUG(spdlog::default_logger(), __VA_ARGS__)
#define LOG_INFO(spdlog::default_logger(), ...) SPDLOG_LOGGER_INFO(spdlog::default_logger(), __VA_ARGS__)
#define LOG_WARNING(spdlog::default_logger(), ...) SPDLOG_LOGGER_WARN(spdlog::default_logger(), __VA_ARGS__)
#define LOG_ERROR(spdlog::default_logger(), ...) SPDLOG_LOGGER_ERROR(spdlog::default_logger(), __VA_ARGS__)
#define LOG_FATAL(spdlog::default_logger(), ...) SPDLOG_LOGGER_CRITICAL(spdlog::default_logger(), __VA_ARGS__)
*/

namespace mdh::cluster {
using Logger = std::shared_ptr<spdlog::logger>;

auto InitLogger(std::string const &name) -> void;
}
