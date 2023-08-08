cmake_minimum_required(VERSION 3.22)
project(BinRTOS C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB_RECURSE SOURCES "kernel/*.*" "test/*.*")

add_executable(BinRTOS ${SOURCES})
