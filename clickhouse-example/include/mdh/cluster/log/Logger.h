#pragma once

#if defined(SPDLOG_ACTIVE_LEVEL)
#undef SPDLOG_ACTIVE_LEVEL
#endif// defined(SPDLOG_ACTIVE_LEVEL)
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include <spdlog/fmt/bin_to_hex.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/formatter.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <format>

#define LOG_TRACE(logger, ...) SPDLOG_LOGGER_TRACE(logger, __VA_ARGS__)
#define LOG_DEBUG(logger, ...) SPDLOG_LOGGER_DEBUG(logger, __VA_ARGS__)
#define LOG_INFO(logger, ...) SPDLOG_LOGGER_INFO(logger, __VA_ARGS__)
#define LOG_WARNING(logger, ...) SPDLOG_LOGGER_WARN(logger, __VA_ARGS__)
#define LOG_ERROR(logger, ...) SPDLOG_LOGGER_ERROR(logger, __VA_ARGS__)
#define LOG_FATAL(logger, ...) SPDLOG_LOGGER_CRITICAL(logger, __VA_ARGS__)

namespace mdh::cluster::logger {
using Logger = std::shared_ptr<spdlog::logger>;
}
