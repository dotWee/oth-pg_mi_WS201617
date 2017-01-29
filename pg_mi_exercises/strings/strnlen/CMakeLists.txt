cmake_minimum_required(VERSION 3.6)
project(strnlen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c main.c)
add_executable(strnlen ${SOURCE_FILES})