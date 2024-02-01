cmake_minimum_required(VERSION 3.20.0)

set(lib xlog)
set(${lib}_libtype PUBLIC PARENT_SCOPE)

file(GLOB SRCSH "./*.h")
add_library(${lib} ${${lib}_libtype} ${SRCSH})
set_target_properties(${lib} PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(${lib} INTERFACE zephyr_interface)
target_link_libraries(${lib} PUBLIC xdts)
target_link_libraries(${lib} PUBLIC xglob)
target_include_directories(${lib} INTERFACE ./)
