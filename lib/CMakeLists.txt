cmake_minimum_required(VERSION 3.12)
project(base4-lib VERSION 2.0.0)

add_library(base4 src/base4.cpp include/wtlgo/base4.hpp)
target_compile_features(base4 PUBLIC cxx_std_11)
target_include_directories(base4 PRIVATE include/wtlgo)
target_include_directories(base4 INTERFACE include)
set_target_properties(base4 PROPERTIES
    PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/wtlgo/base4.hpp
)