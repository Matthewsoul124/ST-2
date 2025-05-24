cmake_minimum_required(VERSION 3.10)
project(circle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(circle
    src/circle.cpp
    src/tasks.cpp
)

add_executable(tests test/tests.cpp)
target_link_libraries(tests circle gtest gtest_main)

include(CTest)
enable_testing()
add_test(NAME tests COMMAND tests)
