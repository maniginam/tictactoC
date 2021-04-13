#include <stdio.h>
#include "CuTest.h"
#include "../src/player.h"
#include <string.h>

void TestPlayerPosition (CuTest *tc) {
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

void TestPlayerCurrent (CuTest *tc) {
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
}


CuSuite* GetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestPlayerPosition);
    SUITE_ADD_TEST(suite, TestPlayerCurrent);
    return suite;
}


