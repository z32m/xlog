cmake_minimum_required(VERSION 3.20.0)

set(lib xlog)

file(GLOB SRCSH "./*.h")
add_library(${lib} INTERFACE ${SRCSH})
target_link_libraries(${lib} INTERFACE zephyr_interface)
target_include_directories(${lib} INTERFACE ./)
