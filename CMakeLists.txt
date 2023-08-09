cmake_minimum_required(VERSION 3.22)
project(BinRTOS C)

set(CMAKE_C_STANDARD 11)

include_directories(inc config)

file(GLOB_RECURSE SOURCES "src/*.*" "test/*.*")

add_executable(BinRTOS ${SOURCES})
