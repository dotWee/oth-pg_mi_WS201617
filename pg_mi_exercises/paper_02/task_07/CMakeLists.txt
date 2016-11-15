cmake_minimum_required(VERSION 3.6)
project(paper_02_task_07)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c main.c)
add_executable(paper_02_task_07 ${SOURCE_FILES})