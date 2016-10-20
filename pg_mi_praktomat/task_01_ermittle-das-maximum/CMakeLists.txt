cmake_minimum_required(VERSION 3.6)
project(task_01_ermittle-das-maximum)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES getmax.c getmax.c)
add_executable(task_01_ermittle-das-maximum ${SOURCE_FILES})