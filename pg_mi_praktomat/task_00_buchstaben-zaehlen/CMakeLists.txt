cmake_minimum_required(VERSION 3.6)
project(task_00_buchstaben-zaehlen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES charcounter.c charcounter.c)
add_executable(task_00_buchstaben-zaehlen ${SOURCE_FILES})