cmake_minimum_required(VERSION 3.12)
project(base4_lib VERSION 0.0.1)

add_library(base4 src/base4.cpp include/wtlgo/base4.hpp)
target_compile_features(base4 PRIVATE cxx_std_11)
target_include_directories(base4 PRIVATE include/wtlgo)
target_include_directories(base4 INTERFACE include)
