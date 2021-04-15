#include <stdio.h>
#include "CuTest.h"
#include "../src/main.h"
#include "../src/game.h"
#include "../src/player.h"
#include <string.h>
#include "test.h"
#include <stdlib.h>

//for(int i = 0; i < 9; i++) { printf("i = %d and box = %d", i, board[i]);}

struct gameStatus game;

void initTestGame(struct gameStatus *game, int boardSize, int human) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->board = malloc(boardSize * sizeof(int));
    game->humanToken = human;
}

void tearDownTestGame() {
    free(game.board);
}

void TestPlayerPosition(CuTest *tc) {
    printf("Player Position: \n");
    char littleX[] = "x";
    int expectedx = 1;
    int resultx = assign_player(littleX);
    CuAssertIntEquals(tc, expectedx, resultx);

    char bigX[] = "X";
    int expectedX = 1;
    int resultX = assign_player(bigX);
    CuAssertIntEquals(tc, expectedX, resultX);

    char littleO[] = "o";
    int expectedo = 2;
    int resulto = assign_player(littleO);
    CuAssertIntEquals(tc, expectedo, resulto);

    char bigO[] = "O";
    int expectedO = 2;
    int resultO = assign_player(bigO);
    CuAssertIntEquals(tc, expectedO, resultO);
}

void TestPlayerCurrent(CuTest *tc) {
    printf("Player Current: \n");
    int game_start = 0;
    int expected = 1;
    int result = set_current_player(game_start);
    CuAssertIntEquals(tc, expected, result);

    int last_player1 = 1;
    int expected2 = 2;
    int result2 = set_current_player(last_player1);
    CuAssertIntEquals(tc, expected2, result2);

    int last_player2 = 2;
    int expected1 = 1;
    int result1 = set_current_player(last_player2);
    CuAssertIntEquals(tc, expected1, result1);
    tearDownTestGame();
}

void TestRunGame(CuTest *tc) {
    printf("Run Game: \n");
//    struct gameStatus game;
    initTestGame(&game, 9, 1);
//    int board[9];
//    game.board = board;
    game.humanToken = 1;
    game.currentPlayer = 1;
    game.winner = 0;
    game.board[0] = 1;
    game.board[1] = 1;
    game.board[2] = 1;
    CuAssertIntEquals(tc, 0, game.winner);
    run_game(&game);
    CuAssertIntEquals(tc, 1, game.winner);
    tearDownTestGame();
}

void TestEmptyBoardNotGameOver(CuTest *tc) {
    printf("Not Game Over: \n");
//    struct gameStatus game;
    initTestGame(&game, 9, 1);
    CuAssertTrue(tc, !isGameOver(game.board));
    tearDownTestGame();
}

void TestCatsGameOver(CuTest *tc) {
    printf("Cat's Game: \n");
//    struct gameStatus game;
    initTestGame(&game, 9, 1);
    game.board[4] = 1;
    game.board[0] = 2;
    game.board[6] = 1;
    game.board[2] = 2;
    game.board[1] = 1;
    game.board[3] = 2;
    game.board[5] = 1;
    game.board[7] = 2;
    game.board[8] = 1;
    CuAssertTrue(tc, (isGameOver(game.board) == 1));
    tearDownTestGame();
}

void TestOneBoxFilledBoardNOTWin(CuTest *tc) {
    printf("One Box Board: \n");
//    struct gameStatus game;
//    int *board = game.board;
    for (int i = 0; i < 9; i++) { game.board[i] = 0; }
    initTestGame(&game, 9, 1);
    game.board[0] = 1;

    CuAssertTrue(tc, !isWin(game.board));
    tearDownTestGame();
}

void TestOneRowMixedNOTWin(CuTest *tc) {
    printf("One Mixed Row: \n");
//    struct gameStatus game;
//    int *board = game.board;
    initTestGame(&game, 9, 1);
    game.board[1] = 1;
    game.board[2] = 2;
    game.board[3] = 1;
    CuAssertTrue(tc, (isWin(game.board) != 1));
    tearDownTestGame();
}

void TestGameOverXWinsTopRow(CuTest *tc) {
    printf("X Wins Top Row: \n");
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    game.board[1] = 1;
    game.board[2] = 1;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    CuAssertIntEquals(tc, 1, game.winner);
    tearDownTestGame();
}

void TestGameOverOWinsLastColumn(CuTest *tc) {
    printf("O Wins Last Column: \n");
//    struct gameStatus game;
//    int *board = game.board;
//    struct gameStatus game;
    initTestGame(&game, 9, 1);
    game.currentPlayer = 2;
    game.board[2] = 2;
    game.board[5] = 2;
    game.board[8] = 2;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    CuAssertIntEquals(tc, 2, game.winner);
    tearDownTestGame();
}

void TestHumanTurn(CuTest *tc) {
    printf("Human Turn: \n");
//    struct gameStatus game;
    game.humanToken = 1;
    game.currentPlayer = 1;
    game.winner = 0;
    play_game(&game);
    CuAssertIntEquals(tc, 2, game.humanToken);
    CuAssertIntEquals(tc, 2, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[0]);
    CuAssertIntEquals(tc, 0, game.board[1]);
    CuAssertIntEquals(tc, 0, game.board[2]);
    CuAssertIntEquals(tc, 0, game.board[3]);
    CuAssertIntEquals(tc, 0, game.winner);
    tearDownTestGame();
}


CuSuite *GetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestPlayerPosition);
    SUITE_ADD_TEST(suite, TestPlayerCurrent);
//    SUITE_ADD_TEST(suite, TestRunGame);
    SUITE_ADD_TEST(suite, TestEmptyBoardNotGameOver);
    SUITE_ADD_TEST(suite, TestCatsGameOver);
    SUITE_ADD_TEST(suite, TestOneBoxFilledBoardNOTWin);
    SUITE_ADD_TEST(suite, TestOneRowMixedNOTWin);
    SUITE_ADD_TEST(suite, TestGameOverXWinsTopRow);
    SUITE_ADD_TEST(suite, TestGameOverOWinsLastColumn);
//    SUITE_ADD_TEST(suite, TestHumanTurn);
//    SUITE_ADD_TEST(suite, TestOneRowXsISWin);
//    SUITE_ADD_TEST(suite, TestOneColumnOsISWin);
//    SUITE_ADD_TEST(suite, TestLtTopToRtBotXsISWin);
//    SUITE_ADD_TEST(suite, TestRtTopToLtBotOsISWin);
    return suite;
}


