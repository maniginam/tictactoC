#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "messages-test.h"
#include "../tictactoC/messages.h"

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

void TestHumanBoxChoice(CuTest *tc) {
    CuAssertTrue(tc, validBox(7));
    CuAssertTrue(tc, !validBox(10));
}

void TestBoxisOpen(CuTest *tc) {
    int board[9] = {1, 0, -1, 0, 0, 0, 0, 0, 0,};
    CuAssertTrue(tc, boxOpen(board, 4));
    CuAssertTrue(tc, !boxOpen(board, 0));
    CuAssertTrue(tc, !boxOpen(board, 2));
}