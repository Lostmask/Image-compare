cmake_minimum_required(VERSION 3.1)
project(image_compare)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

enable_testing()
include(GoogleTest)
find_library(GTest REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include ,${gtest_SOURCE_DIR}, ${OpenCV_INCLUDE_DIRS})

add_executable(image_compare main.cpp imagecompare.cpp)
add_executable(run_tests tests.cpp imagecompare.cpp)

target_link_libraries(run_tests gtest gtest_main ${OpenCV_LIBS} Threads::Threads)
target_link_libraries(image_compare ${OpenCV_LIBS} Threads::Threads)

gtest_add_tests(TARGET run_tests)
