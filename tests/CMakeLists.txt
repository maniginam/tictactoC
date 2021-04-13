cmake_minimum_required(VERSION 3.19)
project(tictactoc_tests C)

set(CMAKE_C_STANDARD 99)

add_executable(tests AllTests.c CuTest.c tests.c)
#add_test(tests test.c player.h)