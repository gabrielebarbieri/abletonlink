cmake_minimum_required(VERSION 2.8.12)
project(abletonlink)

include(lib/link/AbletonLinkConfig.cmake)

set(SOURCE_DIR "abletonlink")

# Generate Python module
add_subdirectory(lib/pybind11)
pybind11_add_module(abletonlink ${SOURCES} "${SOURCE_DIR}/bindings.cpp")

target_link_libraries(abletonlink PRIVATE Ableton::Link)
