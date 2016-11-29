cmake_minimum_required(VERSION 3.6)
project(paper_03_task_06v2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

add_library(paper_03_task_06v2_Map libs/map.c)

set(SOURCE_FILES_TEST libs/map_test.c)
add_executable(paper_03_task_06v2_test ${SOURCE_FILES_TEST})
target_link_libraries(paper_03_task_06v2_test paper_03_task_06v2_Map)

set(SOURCE_FILES main.c main.c)
add_executable(paper_03_task_06v2 ${SOURCE_FILES})
target_link_libraries(paper_03_task_06v2 paper_03_task_06v2_Map)
add_dependencies(paper_03_task_06v2 paper_03_task_06v2_test)