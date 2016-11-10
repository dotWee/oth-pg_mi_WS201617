cmake_minimum_required(VERSION 3.6)
project(task_06_zeichen-ersetzen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES ersetze.c ersetze.c)
add_executable(task_06_zeichen-ersetzen ${SOURCE_FILES})