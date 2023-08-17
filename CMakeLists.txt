cmake_minimum_required(VERSION 3.0)
project(ElaborateLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME}_test tests/main.cpp)
target_link_libraries(${PROJECT_NAME}_test m)

add_subdirectory(elb)
target_link_libraries(${PROJECT_NAME}_test elb_numeric)
