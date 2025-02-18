cmake_minimum_required(VERSION 3.10)
project(my_solver)

file(GLOB SOURCES "src/*.cc")
add_executable(solver ${SOURCES})

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
