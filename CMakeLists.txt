cmake_minimum_required(VERSION 3.12)
project(base4 VERSION 2.1.0)

add_subdirectory(lib)
add_subdirectory(bin)

install(
    TARGETS base4 base4-bin
    LIBRARY DESTINATION lib/wtlgo COMPONENT Runtime
    ARCHIVE DESTINATION lib/wtlgo COMPONENT Development
    RUNTIME DESTINATION bin COMPONENT Runtime
    PUBLIC_HEADER DESTINATION include/wtlgo COMPONENT Development
)