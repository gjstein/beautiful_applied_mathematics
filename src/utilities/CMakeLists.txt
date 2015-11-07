cmake_minimum_required (VERSION 2.8)
project (utilities)

include_directories("src")

set(SOURCE_FILES src/gnuplot.cc)
set(TEST_FILES test/gnuplot_test.cc)


# Check if gnuplot installed
find_package(Gnuplot)
if(NOT GNUPLOT_FOUND)
  message(WARNING "Gnuplot not found")
endif(NOT GNUPLOT_FOUND)

# GTest inclusion
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Build tests
add_executable(utilities_test ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(utilities_test
    ${GTEST_LIBRARIES}
)
add_test(NAME utilities_test COMMAND utilities_test --gtest_color=yes)
