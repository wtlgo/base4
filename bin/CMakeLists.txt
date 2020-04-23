cmake_minimum_required(VERSION 3.12)
project(base4-bin VERSION 1.1.0)

add_executable(base4-bin src/main.cpp)
target_compile_features(base4-bin PUBLIC cxx_std_11)
target_link_libraries(base4-bin PUBLIC base4)
set_target_properties(base4-bin PROPERTIES OUTPUT_NAME base4)