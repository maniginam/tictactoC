#ifndef TICTACTOC_GAME_TEST_H
#define TICTACTOC_GAME_TEST_H
#include "CuTest.h"

struct gameStatus game;
int box;

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
void confirmCornerBox();
void TestComputerEmptyBoard(CuTest *tc);
void TestScoresOneBoxLeft(CuTest *tc);
void TestScoresTwoBoxesLeft(CuTest *tc);
void TestScoresThreeBoxesLeft(CuTest *tc);
void TestScoresFourBoxesLeft(CuTest *tc);
void TestScoresFiveBoxesLeft(CuTest *tc);



void TestBoxScore(CuTest *tc);
void ComputerTakesWin(CuTest *tc);
void HumanMightWin(CuTest *tc);
void ComputerShouldNOTTakeCenterOrCornerBox(CuTest *tc);
void ComputerSHOULDTakeCenterBox(CuTest *tc);
void ComputerDoesNotChooseAlreadyPlayedBox(CuTest *tc);
void TestBoxScoresOneBoxLeft(CuTest *tc);
void TestBoxScoresTwoBoxLeft(CuTest *tc);
void TestBoxScores78Left(CuTest *tc);


#endif //TICTACTOC_GAME_TEST_H
