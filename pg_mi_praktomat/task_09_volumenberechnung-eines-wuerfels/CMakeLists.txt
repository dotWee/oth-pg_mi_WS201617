cmake_minimum_required(VERSION 3.6)
project(task_09_volumenberechnung-eines-wuerfels)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c main.c)
add_executable(task_09_volumenberechnung-eines-wuerfels ${SOURCE_FILES})