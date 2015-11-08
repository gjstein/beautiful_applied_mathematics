cmake_minimum_required (VERSION 2.8)
project (operators)

# Set include directory
include_directories("src")

# Store files
file(GLOB SOURCE_FILES src/*.cc)
file(GLOB HEADER_FILES src/*.h)
file(GLOB TEST_FILES test/*.cc)

# GTest inclusion
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Build test files
add_executable(${PROJECT_NAME}_test ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}_test
    ${GTEST_LIBRARIES}
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test --gtest_color=yes)

# Create library
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})

