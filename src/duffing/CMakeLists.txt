cmake_minimum_required (VERSION 2.8)
project (duffing)


# Include directories + library includes
include_directories("src"
  ${operators_SOURCE_DIR}/src
  ${utilities_SOURCE_DIR}/src
  ${EIGEN3_INCLUDE_DIR})

# Store files
file(GLOB SOURCE_FILES src/*.cc)
file(GLOB HEADER_FILES src/*.h)
file(GLOB TEST_FILES test/*.cc)

# Build executables
add_executable(duffing ${SOURCE_FILES})
target_link_libraries(duffing utilities operators)

