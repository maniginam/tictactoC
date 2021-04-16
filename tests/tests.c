#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../src/game.h"
#include "../src/messages.h"

struct gameStatus game;
int box;

void initTestGame(struct gameStatus *game, int boardSize, int human) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = human;
    game->board = malloc(boardSize * sizeof(int));
    for(int i = 0; i < 9; i++) { game->board[i] = 0; }
}

void tearDownTestGame() {
    free(game.board);
}

void TestPlayerPosition(CuTest *tc) {
    printf("Player Position: \n");
    char littleX[] = "x";
    int expectedx = 1;
    int resultx = parseSelection(littleX);
    CuAssertIntEquals(tc, expectedx, resultx);

    char bigX[] = "X";
    int expectedX = 1;
    int resultX = parseSelection(bigX);
    CuAssertIntEquals(tc, expectedX, resultX);

    char littleO[] = "o";
    int expectedo = 2;
    int resulto = parseSelection(littleO);
    CuAssertIntEquals(tc, expectedo, resulto);

    char bigO[] = "O";
    int expectedO = 2;
    int resultO = parseSelection(bigO);
    CuAssertIntEquals(tc, expectedO, resultO);
}

void TestEmptyBoardNotGameOver(CuTest *tc) {
    printf("Not Game Over: \n");
    initTestGame(&game, 9, 1);
    CuAssertTrue(tc, !isGameOver(game.board));
    tearDownTestGame();
}

void TestOneBoxFilledBoardNOTWin(CuTest *tc) {
    printf("One Box Board: \n");
    for (int i = 0; i < 9; i++) { game.board[i] = 0; }
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    CuAssertTrue(tc, !isWin(game.board));
    CuAssertTrue(tc, !isBoardFull(game.board));
    tearDownTestGame();
}

void TestOneRowMixedNOTWin(CuTest *tc) {
    printf("One Mixed Row: \n");
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    game.board[1] = 2;
    game.board[2] = 1;
    CuAssertTrue(tc, (isWin(game.board) != 1));
    CuAssertTrue(tc, (isBoardFull(game.board) != 1));
    CuAssertTrue(tc, (isGameOver(game.board) != 1));
    tearDownTestGame();
}

void TestCatsGameOver(CuTest *tc) {
    printf("Cat's Game: \n");
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



void TestGameOverXWinsTopRow(CuTest *tc) {
    printf("X Wins Top Row: \n");
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    game.board[1] = 1;
    game.board[2] = 1;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
//    CuAssertIntEquals(tc, 1, game.winner);
    tearDownTestGame();
}

void TestGameOverOWinsLastColumn(CuTest *tc) {
    printf("O Wins Last Column: \n");
    initTestGame(&game, 9, 1);
    game.currentPlayer = 2;
    game.board[2] = 2;
    game.board[5] = 2;
    game.board[8] = 2;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
//    CuAssertIntEquals(tc, 2, game.winner);
    tearDownTestGame();
}

void TestDiagLtTopToRtBotXISWin(CuTest *tc) {
    printf("X Wins Diag 048: \n");
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    game.board[4] = 1;
    game.board[8] = 1;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
//    CuAssertIntEquals(tc, 1, game.winner);
    tearDownTestGame();
}

void TestDiagRtTopToLtBotOISWin(CuTest *tc) {
    printf("O Wins Diag 246: \n");
    initTestGame(&game, 9, 1);
    game.currentPlayer = 2;
    game.board[2] = 2;
    game.board[4] = 2;
    game.board[6] = 2;
    run_game(&game);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
//    CuAssertIntEquals(tc, 2, game.winner);
    tearDownTestGame();
}

void TestHumanTurnX(CuTest *tc) {
    printf("Human Turn X: \n");
    box = 0;
    initTestGame(&game, 9, 1);
    play_game(&game, &box);
    CuAssertIntEquals(tc, 1, game.humanToken);
    CuAssertIntEquals(tc, 2, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[0]);
    CuAssertIntEquals(tc, 0, game.board[1]);
    CuAssertIntEquals(tc, 0, game.winner);
    tearDownTestGame();
}

void TestHumanTurnO(CuTest *tc) {
    printf("Human Turn O: \n");
    box = 4;
    initTestGame(&game, 9, 1);
    game.humanToken = 2;
    game.board[0] = 1;
    game.currentPlayer = 2;
    play_game(&game, &box);
    CuAssertIntEquals(tc, 2, game.humanToken);
    CuAssertIntEquals(tc, 1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[0]);
    CuAssertIntEquals(tc, 0, game.board[1]);
    CuAssertIntEquals(tc, 2, game.board[4]);
    CuAssertIntEquals(tc, 0, game.winner);
    tearDownTestGame();
}

void TestHumanXWin(CuTest *tc) {
    printf("Human Wins as X: \n");
    box = 2;
    initTestGame(&game, 9, 1);
    game.board[0] = 1;
    game.board[1] = 1;
    play_game(&game, &box);
    CuAssertIntEquals(tc, 1, game.board[2]);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    CuAssertIntEquals(tc, 1, game.winner);
    tearDownTestGame();
}

void TestComputerOWin(CuTest *tc) {
    printf("Computer Wins as O: \n");
    box = 3;
    initTestGame(&game, 9, 1);
    game.board[4] = 2;
    game.board[5] = 2;
    game.currentPlayer = 2;
    play_game(&game, &box);
    CuAssertIntEquals(tc, 2, game.board[3]);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    CuAssertIntEquals(tc, 2, game.winner);
    tearDownTestGame();
}

CuSuite *GetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestPlayerPosition);
    SUITE_ADD_TEST(suite, TestEmptyBoardNotGameOver);
    SUITE_ADD_TEST(suite, TestOneBoxFilledBoardNOTWin);
    SUITE_ADD_TEST(suite, TestOneRowMixedNOTWin);
    SUITE_ADD_TEST(suite, TestCatsGameOver);
    SUITE_ADD_TEST(suite, TestGameOverXWinsTopRow);
    SUITE_ADD_TEST(suite, TestGameOverOWinsLastColumn);
    SUITE_ADD_TEST(suite, TestDiagLtTopToRtBotXISWin);
    SUITE_ADD_TEST(suite, TestDiagRtTopToLtBotOISWin);
    SUITE_ADD_TEST(suite, TestHumanTurnX);
    SUITE_ADD_TEST(suite, TestHumanTurnO);
    SUITE_ADD_TEST(suite, TestHumanXWin);
    SUITE_ADD_TEST(suite, TestComputerOWin);
    return suite;
}


