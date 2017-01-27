cmake_minimum_required(VERSION 3.6)
project(strcat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c main.c)
add_executable(strcat ${SOURCE_FILES})