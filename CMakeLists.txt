cmake_minimum_required(VERSION 3.0)
project(TargemTestTask LANGUAGES C CXX)
set(PROJECT_NAME TargemTestTask)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

add_executable(${PROJECT_NAME} src/main.cpp includes/String.hpp src/String.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/input.txt
    $<TARGET_FILE_DIR:${PROJECT_NAME}>)

