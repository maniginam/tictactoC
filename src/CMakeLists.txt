cmake_minimum_required(VERSION 3.19)
project(tictactoc)

set(CMAKE_C_STANDARD 99)

add_executable(tictactoc main.c game.c game.h messages.c messages.h)
