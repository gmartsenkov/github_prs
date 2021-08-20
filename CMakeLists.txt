cmake_minimum_required(VERSION 3.0)

project(github_pull_requests C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(LCD1602_FILES "libs/LCD1602/lcd1602.c")
include_directories(libs/LCD1602)

add_executable(${PROJECT_NAME} 
    main.c pull_request.c display.c ${LCD1602_FILES}
)

add_library(display
    display.c 
)
target_include_directories(display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})