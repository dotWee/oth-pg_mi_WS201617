cmake_minimum_required(VERSION 3.6)
project(task_07_zeichenketten-ersetzen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES str_replace.c str_replace.c)
add_executable(task_07_zeichenketten-ersetzen ${SOURCE_FILES})