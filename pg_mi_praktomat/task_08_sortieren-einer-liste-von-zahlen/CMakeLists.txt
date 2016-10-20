cmake_minimum_required(VERSION 3.6)
project(task_08_sortieren-einer-liste-von-zahlen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES sortieren.c sortieren.c)
add_executable(task_08_sortieren-einer-liste-von-zahlen ${SOURCE_FILES})