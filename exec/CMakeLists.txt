cmake_minimum_required(VERSION 3.12)
project(base4_app VERSION 0.0.2)

add_executable(b4 src/main.cpp)
target_link_libraries(b4 PUBLIC base4)
