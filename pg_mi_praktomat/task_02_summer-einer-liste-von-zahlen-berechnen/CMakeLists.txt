cmake_minimum_required(VERSION 3.6)
project(task_00_division-durch-2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES calculatesum.c calculatesum.c)
add_executable(task_02_summer-einer-liste-von-zahlen-berechnen ${SOURCE_FILES})