cmake_minimum_required(VERSION 3.17)
project(ElaborateLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME}_test tests/main.cpp)

target_link_libraries(${PROJECT_NAME}_test m)
target_link_libraries(${PROJECT_NAME}_test gtest)

add_subdirectory(elb)
target_link_libraries(${PROJECT_NAME}_test elb_numeric)
