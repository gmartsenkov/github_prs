cmake_minimum_required(VERSION 3.12)

project(tests C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(lib/googletest)
add_subdirectory(../ display)
add_executable(${PROJECT_NAME}
    display_test.cpp
)

target_link_libraries(${PROJECT_NAME} gtest_main display)

include(GoogleTest)
gtest_discover_tests(tests)