#ifndef TICTACTOC_GAME_TEST_H
#define TICTACTOC_GAME_TEST_H
#include "CuTest.h"

struct gameStatus game;

void TestPlayerPosition(CuTest *tc);
void TestHumanBoxChoice(CuTest *tc);
void TestBoxisOpen(CuTest *tc);
void TestEmptyBoardNotGameOver(CuTest *tc);
void TestOneBoxFilledBoardNOTWin(CuTest *tc);
void TestOneRowMixedNOTWin(CuTest *tc);
void TestCatsGameOver(CuTest *tc);
void TestGameOverXWinsTopRow(CuTest *tc);
void TestGameOverOWinsLastColumn(CuTest *tc);
void TestDiagLtTopToRtBotXISWin(CuTest *tc);
void TestDiagRtTopToLtBotOISWin(CuTest *tc);
void TestHumanTurnX(CuTest *tc);
void TestHumanTurnO(CuTest *tc);
void TestHumanXWin(CuTest *tc);
void TestComputerOWin(CuTest *tc);
void TestBoxScore(CuTest *tc);
void TestComputerEmptyBoard(CuTest *tc);
void TestScoresOneBoxLeft(CuTest *tc);
void TestScoresTwoBoxesLeft(CuTest *tc);
void TestScoresThreeBoxesLeft(CuTest *tc);
void TestScoresThreeBoxesLeftWMistake(CuTest *tc);
void TestScoresFourBoxesLeft(CuTest *tc);
void TestScoresFiveBoxesLeft(CuTest *tc);
void TestScoresSixBoxesLeft(CuTest *tc);
void TestScoresSevenBoxesLeft(CuTest *tc);
void TestScoresEightBoxesLeft(CuTest *tc);
void TestShouldTakeWin(CuTest *tc);



#endif //TICTACTOC_GAME_TEST_H
