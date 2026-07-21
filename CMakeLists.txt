cmake_minimum_required(VERSION 3.10)
project(DataStructureTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_executable(run_tests
    tests/test_queue.cpp
    tests/test_heap.cpp
    tests/test_binary_tree.cpp
)

target_link_libraries(run_tests
    gtest_main
)

add_test(NAME AllTests COMMAND run_tests)
