cmake_minimum_required(VERSION 3.6)
project(task_03_mittelwert-berechnen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES calculateavg.c calculateavg.c)
add_executable(task_03_mittelwert-berechnen ${SOURCE_FILES})