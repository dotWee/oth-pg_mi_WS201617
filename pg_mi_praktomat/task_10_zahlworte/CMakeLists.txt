cmake_minimum_required(VERSION 3.6)
project(task_10_zahlworte)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES solution.c solution.c)
add_executable(task_10_zahlworte ${SOURCE_FILES})