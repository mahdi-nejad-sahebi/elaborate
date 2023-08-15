cmake_minimum_required(VERSION 3.0)
project(ElaborateLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}_test tests/main.cpp)

add_subdirectory(elb)
#include_directories(
target_link_libraries(${PROJECT_NAME}_test elb_numeric)
