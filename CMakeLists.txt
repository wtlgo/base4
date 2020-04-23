cmake_minimum_required(VERSION 3.12)
project(base4 VERSION 2.0.0)

add_subdirectory(lib)
add_subdirectory(bin)

install(
    TARGETS base4 base4-bin
    LIBRARY DESTINATION lib/wtlgo COMPONENT Runtime
    ARCHIVE DESTINATION lib/wtlgo COMPONENT Development
    PUBLIC_HEADER DESTINATION include/wtlgo COMPONENT Development
)