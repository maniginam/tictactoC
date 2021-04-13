cmake_minimum_required(VERSION 3.19)
project(tictactoc C)

set(CMAKE_C_STANDARD 99)

add_executable(tictactoc main.c player.c player.h main.h)