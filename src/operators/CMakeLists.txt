cmake_minimum_required (VERSION 2.8.11)
project (operators)

include_directories("src")

set(SOURCE_FILES src/diff.cc)
set(TEST_FILES test/operators_test.cc)

# GTest inclusion
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Build test files
add_executable(operators_test ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(operators_test
    ${GTEST_LIBRARIES}
)
add_test(NAME operators_test COMMAND operators_test)

