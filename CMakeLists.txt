cmake_minimum_required(VERSION 3.19)
project(tictactoC VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(tictactoC tictactoC/main.c tictactoC/game.c tictactoC/game.h tictactoC/messages.c tictactoC/messages.h)
add_executable(tictactoCTests ./tests/AllTests.c ./tests/CuTest.c ./tests/tests.c ./tests/game-test.c ./tests/game-test.h ./tests/messages-test.c ./tests/messages-test.h ./tests/helper.c ./tests/helper.h tictactoC/game.c tictactoC/game.h tictactoC/messages.c tictactoC/messages.h)

configure_file(tictactoCConfig.h.in tictactoCConfig.h)

target_include_directories(tictactoC PUBLIC
        "${PROJECT_BINARY_DIR}"
        )