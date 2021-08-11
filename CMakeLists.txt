cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(
  Ckmeans_1d_dp
  VERSION 1.0
  LANGUAGES CXX
)

message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

set(headers
    src/precision.h
    src/within_cluster.h
    src/EWL2_within_cluster.h
    src/EWL2.h
    src/Ckmeans.1d.dp.h
)

set(sources
    src/weighted_select_levels.cpp
    src/select_levels.cpp
    src/fill_SMAWK.cpp
    src/fill_quadratic.cpp
    src/fill_log_linear.cpp
    src/dynamic_prog.cpp
    src/EWL2_fill_SMAWK.cpp
    src/EWL2_fill_quadratic.cpp
    src/EWL2_fill_log_linear.cpp
    src/EWL2_dynamic_prog.cpp
    src/Ckmeans.1d.dp.cpp
)

add_library(${PROJECT_NAME} SHARED ${headers} ${sources})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "Ckmeans_1d_dp")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
