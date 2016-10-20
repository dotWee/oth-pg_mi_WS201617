cmake_minimum_required(VERSION 3.6)
project(task_05_wurzel-ziehen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES getsquareroot.c getsquareroot.c)
add_executable(task_05_wurzel-ziehen ${SOURCE_FILES})