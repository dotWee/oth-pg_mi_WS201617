cmake_minimum_required(VERSION 3.6)
project(paper_04_task_01)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})

add_definitions(${GTK2_CFLAGS_OTHER})

set(SOURCE_FILES main.c main.c)
add_executable(paper_04_task_01 ${SOURCE_FILES})
target_link_libraries(paper_04_task_01 ${GTK2_LIBRARIES})