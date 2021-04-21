#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "game-test.h"
#include "helper.h"
#include "messages-test.h"
#include "../src/game.h"
#include "../src/messages.h"

struct gameStatus game;

CuSuite *GetSuite() {
    CuSuite *suite = CuSuiteNew();
    setSrand();
    SUITE_ADD_TEST(suite, TestPlayerPosition);
    SUITE_ADD_TEST(suite, TestHumanBoxChoice);
    SUITE_ADD_TEST(suite, TestBoxisOpen);
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
    SUITE_ADD_TEST(suite, TestComputerEmptyBoard);
    SUITE_ADD_TEST(suite, TestScoresOneBoxLeft);
    SUITE_ADD_TEST(suite, TestScoresTwoBoxesLeft);
    SUITE_ADD_TEST(suite, TestScoresThreeBoxesLeft);
    SUITE_ADD_TEST(suite, TestScoresFourBoxesLeft);
//    SUITE_ADD_TEST(suite, TestScoresFiveBoxesLeft);

//    SUITE_ADD_TEST(suite, TestBoxScore);
//    SUITE_ADD_TEST(suite, TestBoxScoresTwoBoxLeft);
//    SUITE_ADD_TEST(suite, TestBoxScores78Left);
//    SUITE_ADD_TEST(suite, ComputerTakesWin);
//    SUITE_ADD_TEST(suite, HumanMightWin);
//    SUITE_ADD_TEST(suite, ComputerShouldNOTTakeCenterOrCornerBox);
//    SUITE_ADD_TEST(suite, ComputerSHOULDTakeCenterBox);
//    SUITE_ADD_TEST(suite, ComputerDoesNotChooseAlreadyPlayedBox);
    //    SUITE_ADD_TEST(suite, );
    //    SUITE_ADD_TEST(suite, );
    return suite;
}


