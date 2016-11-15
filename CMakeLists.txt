cmake_minimum_required(VERSION 3.6)
project(pg_mi_praktomat)

add_subdirectory(pg_mi_exercises)
add_subdirectory(pg_mi_praktomat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")