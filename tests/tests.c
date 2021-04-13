#include <stdio.h>
#include "CuTest.h"
#include "../player.h"
#include <string.h>

void TestPlayer (CuTest *tc) {
    char littleX[] = "x";
    int expectedx = 1;
    int resultx = setPlayer(littleX);
    CuAssertIntEquals(tc, expectedx, resultx);

    char bigX[] = "X";
    int expectedX = 1;
    int resultX = setPlayer(bigX);
    CuAssertIntEquals(tc, expectedX, resultX);

    char littleO[] = "o";
    int expectedo = 2;
    int resulto = setPlayer(littleO);
    CuAssertIntEquals(tc, expectedo, resulto);

    char bigO[] = "O";
    int expectedO = 2;
    int resultO = setPlayer(bigO);
    CuAssertIntEquals(tc, expectedO, resultO);
}


CuSuite* GetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestPlayer);
    return suite;
}


