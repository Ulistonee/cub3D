cmake_minimum_required(VERSION 3.17)
project(cub3D C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3D main.c parser/parser.c)