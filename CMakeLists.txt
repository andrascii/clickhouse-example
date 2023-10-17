cmake_minimum_required(VERSION 3.16)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

option(USE_CLANG "Enables using clang as a compiler" ON)
option(BUILD_TESTS "Enables building tests project" OFF)

#
# by default on UNIX systems we are using clang compiler
#
if (UNIX AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_CXX_COMPILER_ID MATCHES "AppleClang" AND USE_CLANG)
  set(CMAKE_C_COMPILER "clang")
  set(CMAKE_CXX_COMPILER "clang++")
endif()

set(THIS_TARGET_NAME clickhouse-example)
project(${THIS_TARGET_NAME})

#
# adding another one path to find .cmake files
#
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#
# adding settings for cl/clang compiler (depends on which compiler actully used)
#
include(clang_options)
include(msvc_set_target_options)
include(add_clang_format)

message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)
find_package(spdlog REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)
find_package(date CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(toml11 CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(tomlplusplus REQUIRED IMPORTED_TARGET tomlplusplus)

find_path(DECIMAL_FOR_CPP_INCLUDE_DIRS "decimal-for-cpp/decimal.h")

#
# C++ compiler settings
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# adding targets
#
add_subdirectory(proto)
add_subdirectory(clickhouse-example)

#
# collecting sources to register them for reformat by clang-format utility
#
foreach(CONCRETE_TARGET IN ITEMS clickhouse-example)
  get_property(SOURCES TARGET ${CONCRETE_TARGET} PROPERTY SOURCES_PROPERTY)
  list(APPEND REFORMAT_SOURCES ${SOURCES})
endforeach()

# creating target 'reformat' to trigger calling clang-format utility for each source/header file in the project
#
add_clang_format(
        TARGET_NAME reformat
        SOURCES_LIST ${REFORMAT_SOURCES}
)
