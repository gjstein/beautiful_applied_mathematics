cmake_minimum_required (VERSION 2.8)


# CMake & C++ properties
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

enable_testing()

add_subdirectory(src)
