cmake_minimum_required(VERSION 3.19)
project(tictactoc_tests C)

set(CMAKE_C_STANDARD 99)

add_executable(tests AllTests.c CuTest.c tests.c ../src/game.c ../src/game.h ../src/messages.c ../src/messages.h)
