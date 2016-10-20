cmake_minimum_required(VERSION 3.6)
project(pg_mi_praktomat)

add_subdirectory(task_00_buchstaben-zaehlen)
add_subdirectory(task_00_division-durch-2)
add_subdirectory(task_01_ermittle-das-maximum)
add_subdirectory(task_02_summer-einer-liste-von-zahlen-berechnen)
add_subdirectory(task_03_mittelwert-berechnen)
add_subdirectory(task_04_potenzen)
add_subdirectory(task_05_wurzel-ziehen)
add_subdirectory(task_08_sortieren-einer-liste-von-zahlen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")