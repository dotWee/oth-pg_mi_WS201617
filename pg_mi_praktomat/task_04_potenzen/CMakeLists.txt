cmake_minimum_required(VERSION 3.6)
project(task_04_potenzen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES task_04_potenzen.c task_04_potenzen.c)
add_executable(task_04_potenzen ${SOURCE_FILES})