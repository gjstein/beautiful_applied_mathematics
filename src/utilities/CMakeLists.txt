cmake_minimum_required (VERSION 2.8)
project (utilities)

# Set include directory
include_directories("src")

# Store files
file(GLOB SOURCE_FILES src/${PROJECT_NAME}/*.cc)
file(GLOB HEADER_FILES src/${PROJECT_NAME}/*.h)
file(GLOB TEST_FILES test/*.cc)


# Check if gnuplot installed
find_package(Gnuplot)
if(NOT GNUPLOT_FOUND)
  message(WARNING "Gnuplot not found")
endif(NOT GNUPLOT_FOUND)

# GTest inclusion
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Build tests
add_executable(${PROJECT_NAME}_test ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}_test
    ${GTEST_LIBRARIES}
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test --gtest_color=yes)

# Create library
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
