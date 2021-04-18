#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../src/ai.h"
#include "../src/game.h"
#include "../src/messages.h"

struct gameStatus game;
int box;

void initTestGame(struct gameStatus *game, int human) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = human;
    game->board = malloc(9 * sizeof(int));
    for (int i = 0; i < 9; i++) { game->board[i] = 0; }
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
    int expectedo = -1;
    int resulto = parseSelection(littleO);
    CuAssertIntEquals(tc, expectedo, resulto);

    char bigO[] = "O";
    int expectedO = -1;
    int resultO = parseSelection(bigO);
    CuAssertIntEquals(tc, expectedO, resultO);
}

void TestEmptyBoardNotGameOver(CuTest *tc) {
    printf("Not Game Over: \n");
    initTestGame(&game, 1);
    CuAssertTrue(tc, !isGameOver(game.board));
    tearDownTestGame();
}

void TestOneBoxFilledBoardNOTWin(CuTest *tc) {
    printf("One Box Board: \n");
    initTestGame(&game, 1);
    game.board[0] = 1;
    CuAssertTrue(tc, !isWin(game.board));
    CuAssertTrue(tc, !isFull(game.board));
    tearDownTestGame();
}

void TestOneRowMixedNOTWin(CuTest *tc) {
    printf("One Mixed Row: \n");
    initTestGame(&game, 1);
    game.board[0] = 1;
    game.board[1] = -1;
    game.board[2] = 1;
    CuAssertTrue(tc, (isWin(game.board) != 1));
    CuAssertTrue(tc, (isFull(game.board) != 1));
    CuAssertTrue(tc, (isGameOver(game.board) != 1));
    tearDownTestGame();
}

void TestCatsGameOver(CuTest *tc) {
    printf("Cat's Game: \n");
    initTestGame(&game, 1);
    game.board[4] = 1;
    game.board[0] = -1;
    game.board[6] = 1;
    game.board[2] = -1;
    game.board[1] = 1;
    game.board[3] = -1;
    game.board[5] = 1;
    game.board[7] = -1;
    game.board[8] = 1;
    CuAssertTrue(tc, (isGameOver(game.board) == 1));
    tearDownTestGame();
}

void TestGameOverXWinsTopRow(CuTest *tc) {
    printf("X Wins Top Row: \n");
    initTestGame(&game, 1);
    game.board[0] = 1;
    game.board[1] = 1;
    game.board[2] = 1;
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    tearDownTestGame();
}

void TestGameOverOWinsLastColumn(CuTest *tc) {
    printf("O Wins Last Column: \n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    game.board[2] = -1;
    game.board[5] = -1;
    game.board[8] = -1;
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    tearDownTestGame();
}

void TestDiagLtTopToRtBotXISWin(CuTest *tc) {
    printf("X Wins Diag 048: \n");
    initTestGame(&game, 1);
    game.board[0] = 1;
    game.board[4] = 1;
    game.board[8] = 1;
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    tearDownTestGame();
}

void TestDiagRtTopToLtBotOISWin(CuTest *tc) {
    printf("O Wins Diag 246: \n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    game.board[2] = -1;
    game.board[4] = -1;
    game.board[6] = -1;
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    tearDownTestGame();
}

void TestHumanTurnX(CuTest *tc) {
    printf("Human Turn X: \n");
    box = 0;
    initTestGame(&game, 1);
    play_game(&game, &box);
    CuAssertIntEquals(tc, 1, game.humanToken);
    CuAssertIntEquals(tc, -1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[0]);
    CuAssertIntEquals(tc, 0, game.board[1]);
    CuAssertIntEquals(tc, 0, game.winner);
    tearDownTestGame();
}

void TestHumanTurnO(CuTest *tc) {
    printf("Human Turn O: \n");
    box = 4;
    initTestGame(&game, 1);
    game.humanToken = -1;
    game.board[0] = 1;
    game.currentPlayer = -1;
    play_game(&game, &box);
    CuAssertIntEquals(tc, -1, game.humanToken);
    CuAssertIntEquals(tc, 1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[0]);
    CuAssertIntEquals(tc, 0, game.board[1]);
    CuAssertIntEquals(tc, -1, game.board[4]);
    CuAssertIntEquals(tc, 0, game.winner);
    tearDownTestGame();
}

void TestHumanXWin(CuTest *tc) {
    printf("Human Wins as X: \n");
    box = 2;
    initTestGame(&game, 1);
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
    initTestGame(&game, 1);
    game.board[4] = -1;
    game.board[5] = -1;
    game.currentPlayer = -1;
    play_game(&game, &box);
    CuAssertIntEquals(tc, -1, game.board[3]);
    CuAssertTrue(tc, isGameOver(game.board));
    CuAssertTrue(tc, isWin(game.board));
    CuAssertIntEquals(tc, -1, game.winner);
    tearDownTestGame();
}

int isBoxGood, corners[4] = { 0, 2, 6, 8 };
void confirmCornerBox() {
    for (int i = 0; i < 4; i++) {
        if (box == corners[i]) { isBoxGood = 1; }
    }
}

void TestComputerTurnX(CuTest *tc) {
    printf("Computer Turn X\n");
    initTestGame(&game, 1);
    game.humanToken = -1;
    getBox(&game, &box);
    play_game(&game, &box);
    confirmCornerBox();
    CuAssertTrue(tc, isBoxGood);
    CuAssertIntEquals(tc, -1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[box]);
    tearDownTestGame();
}

void TestComputerTurnO(CuTest *tc) {
    printf("Computer Turn O\n");
    initTestGame(&game, 1);
    game.humanToken = 1;
    game.currentPlayer = -1;
    game.board[0] = 1;
    getBox(&game, &box);
    play_game(&game, &box);
    confirmCornerBox();
    CuAssertTrue(tc, isBoxGood);
    CuAssertIntEquals(tc, 1, game.currentPlayer);
    CuAssertIntEquals(tc, -1, game.board[box]);
    tearDownTestGame();
}

void TestBoxScore(CuTest *tc) {
    int xBoard[9] = { 1, 1, 1, 0 , 0, 0, 0, 0, 0 };
    int oBoard[9] = { -1, -1, -1, 0 , 0, 0, 0, 0, 0 };
    int catBoard[9] = { -1, 1, -1, 1 , 1, -1, 1, -1, 1 };

    printf("Cats Game Box Score\n");
    CuAssertIntEquals(tc, 0, scoreBox(catBoard, 1, 0));

    printf("X Win This Move Box Score\n");
    CuAssertIntEquals(tc, 10, scoreBox(xBoard, 1, 0));

    printf("O Win This Move Box Score\n");
    CuAssertIntEquals(tc, -10, scoreBox(oBoard, -1, 0));

    printf("X Win 2 Moves out Box Score\n");
    CuAssertIntEquals(tc, -8, scoreBox(xBoard, -1, 2));
}


void ComputerTakesWin(CuTest *tc) {
    printf("Computer Takes Win\n");
    initTestGame(&game, 1);
    game.humanToken = 1;
    game.currentPlayer = -1;
    game.board[0] = -1;
    game.board[1] = -1;
    getBox(&game, &box);
    play_game(&game, &box);
    CuAssertIntEquals(tc, 2, box);
    CuAssertIntEquals(tc, -1, game.winner);
    CuAssertTrue(tc, isWin(game.board));
    CuAssertTrue(tc, isGameOver(game.board));
    tearDownTestGame();
}

void HumanMightWin(CuTest *tc) {
    printf("Human Might Win\n");
    initTestGame(&game, 1);
    game.humanToken = 1;
    game.currentPlayer = -1;
    game.board[0] = 1;
    game.board[1] = 1;
    getBox(&game, &box);
    play_game(&game, &box);
    CuAssertIntEquals(tc, 2, box);
    CuAssertIntEquals(tc, 0, game.winner);
    CuAssertTrue(tc, !isWin(game.board));
    CuAssertTrue(tc, !isGameOver(game.board));
    tearDownTestGame();
}

void ComputerShouldNotTakeCenterBox(CuTest *tc) {
    printf("Computer Takes Center\n");
    initTestGame(&game, 1);
    game.humanToken = 1;
    game.currentPlayer = -1;
    game.board[0] = 1;
    getBox(&game, &box);
    play_game(&game, &box);
    CuAssertTrue(tc, box != 4);
    CuAssertTrue(tc, !isWin(game.board));
    CuAssertTrue(tc, !isGameOver(game.board));
    tearDownTestGame();
}

CuSuite *GetSuite() {
    CuSuite *suite = CuSuiteNew();
    setSrand();
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
    SUITE_ADD_TEST(suite, TestComputerTurnX);
    SUITE_ADD_TEST(suite, TestComputerTurnO);
    SUITE_ADD_TEST(suite, TestBoxScore);
    SUITE_ADD_TEST(suite, ComputerTakesWin);
    SUITE_ADD_TEST(suite, HumanMightWin);
    SUITE_ADD_TEST(suite, ComputerShouldNotTakeCenterBox);
//    SUITE_ADD_TEST(suite, );
//    SUITE_ADD_TEST(suite, );
    return suite;
}


