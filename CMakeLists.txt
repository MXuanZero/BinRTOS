cmake_minimum_required(VERSION 3.22)
project(BinRTOS C)

set(CMAKE_C_STANDARD 11)

include_directories(config inc memory)

file(GLOB_RECURSE SOURCES "memory/*.*" "src/*.*" "test/*.*")

add_executable(BinRTOS ${SOURCES})
