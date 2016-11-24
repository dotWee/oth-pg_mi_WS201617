cmake_minimum_required(VERSION 3.6)
project(paper_03_task_05)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

add_library(MyFunctions libs/functions.c)

set(SOURCE_FILES_TEST libs/functions_test.c)
add_executable(paper_03_task_05_test ${SOURCE_FILES_TEST})
target_link_libraries(paper_03_task_05_test MyFunctions)

set(SOURCE_FILES main.c main.c)
add_executable(paper_03_task_05 ${SOURCE_FILES})
target_link_libraries(paper_03_task_05 MyFunctions)
add_dependencies(paper_03_task_05 paper_03_task_05_test)