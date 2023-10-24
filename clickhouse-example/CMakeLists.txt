cmake_minimum_required(VERSION 3.16)

include(make_executable_sanitized_target)

set(THIS_TARGET_NAME clickhouse-example)
project(${THIS_TARGET_NAME})

#
# C++ compiler settings
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# precompiled header
#
set(PRECOMPILED_HEADER "include/mdh/dvc/stdafx.h")

#
# deps include directories
#
list(APPEND ADDITIONAL_INCLUDE_DIRECTORIES "${DECIMAL_FOR_CPP_INCLUDE_DIRS}")

#
# deps
#
list(APPEND DEPS Boost::boost)
list(APPEND DEPS gRPC::grpc)
list(APPEND DEPS gRPC::grpc++)
list(APPEND DEPS protobuf::libprotobuf)
list(APPEND DEPS PkgConfig::tomlplusplus)
list(APPEND DEPS toml11::toml11)
list(APPEND DEPS spdlog::spdlog)
list(APPEND DEPS proto)

#
# collecting sources and headers
#
file(GLOB_RECURSE CPP_SOURCES_LIST "*.cpp")
file(GLOB_RECURSE C_SOURCES_LIST "*.c")
file(GLOB_RECURSE HEADERS_LIST "*.h")

message(STATUS "CPP_SOURCES_LIST: ${CPP_SOURCES_LIST}")

#
# creating target
#
add_executable(${THIS_TARGET_NAME} ${HEADERS_LIST} ${CPP_SOURCES_LIST} ${C_SOURCES_LIST})

#
# adding include directories to created target
#
target_include_directories(
  ${THIS_TARGET_NAME} PUBLIC
  ${ADDITIONAL_INCLUDE_DIRECTORIES}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}
)

#
# adding sources property to target
#
set_property(
  TARGET ${THIS_TARGET_NAME}
  PROPERTY SOURCES_PROPERTY ${HEADERS_LIST} ${CPP_SOURCES_LIST}
)

#
# adding precompiled header
#
#target_precompile_headers(${THIS_TARGET_NAME} PRIVATE ${PRECOMPILED_HEADER})

#
# linking this target with other targets
#
target_link_libraries(${THIS_TARGET_NAME} PUBLIC ${DEPS})

#
# creating sanitized version of this target to check UB
#
#make_executable_sanitized_target(
#  TARGET_NAME ${THIS_TARGET_NAME}-sanitized
#  SOURCES ${CPP_SOURCES_LIST}
#  HEADERS ${HEADERS_LIST}
#  DEPS ${DEPS}
#  PRECOMPILED_HEADER ${PRECOMPILED_HEADER}
#)
