cmake_minimum_required(VERSION 3.6)
project(paper_05_task_02)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c main.c)
add_executable(paper_05_task_02 ${SOURCE_FILES})