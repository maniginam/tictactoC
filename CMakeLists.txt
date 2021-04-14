cmake_minimum_required(VERSION 3.19)
project(tictactoc C)

set(CMAKE_C_STANDARD 99)

add_executable(tictactoc src/main.c src/player.c src/player.h src/main.h src/game.c src/game.h)