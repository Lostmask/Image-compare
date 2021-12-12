cmake_minimum_required(VERSION 3.1)
project(image_compare)
set(CXX_STANDARD C++17)

enable_testing()
include(GoogleTest)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ,${gtest_SOURCE_DIR}, ${OpenCV_INCLUDE_DIRS})

find_package( OpenCV REQUIRED)

add_executable(image_compare main.cpp)
add_executable(run_tests tests.cpp)

target_link_libraries(run_tests gtest gtest_main ${OpenCV_LIBS} Threads::Threads)
target_link_libraries(image_compare ${OpenCV_LIBS} Threads::Threads)

gtest_add_tests(TARGET run_tests)
