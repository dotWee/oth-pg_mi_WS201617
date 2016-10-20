cmake_minimum_required(VERSION 3.6)
project(task_00_division-durch-2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES task_00_division-durch-2.c task_00_division-durch-2.c)
add_executable(task_00_division-durch-2 ${SOURCE_FILES})