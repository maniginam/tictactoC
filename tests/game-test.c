#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "game-test.h"
#include "helper.h"
#include "../src/game.h"
#include "../src/messages.h"

int isBoxGood, corners[4] = {0, 2, 6, 8};

void confirmCornerBox() {
    for (int i = 0; i < 4; i++) {
        if (box == corners[i]) { isBoxGood = 1; }
    }
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
    makeCatsGame();
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

void TestComputerEmptyBoard(CuTest *tc) {
    printf("Computer Turn X\n");
    initTestGame(&game, -1);
    getBox(&game, &box);
    play_game(&game, &box);
    confirmCornerBox();
    CuAssertTrue(tc, isBoxGood);
    CuAssertIntEquals(tc, -1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[box]);
    tearDownTestGame();
}

void TestBoxScore(CuTest *tc) {
    int xBoard[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    int oBoard[9] = {-1, -1, -1, 0, 0, 0, 0, 0, 0};
    int catBoard[9] = {-1, 1, -1, 1, 1, -1, 1, -1, 1};

    printf("Cats Game Box Score\n");
    CuAssertIntEquals(tc, 0, scoreBox(catBoard, 0));

    printf("X Win This Move Box Score\n");
    CuAssertIntEquals(tc, 10, scoreBox(xBoard, 0));

    printf("O Win This Move Box Score\n");
    CuAssertIntEquals(tc, 10, scoreBox(oBoard, 0));

    printf("X Win 2 Moves out Box Score\n");
    CuAssertIntEquals(tc, 8, scoreBox(xBoard, 2));
}

void TestComputerOneBoxLeft(CuTest *tc) {
    printf("Computer One Box Left\n");
    initTestGame(&game, -1);
    getBox(&game, &box);
    play_game(&game, &box);
    confirmCornerBox();
    CuAssertTrue(tc, isBoxGood);
    CuAssertIntEquals(tc, -1, game.currentPlayer);
    CuAssertIntEquals(tc, 1, game.board[box]);
    tearDownTestGame();
}

void TestScoresOneBoxLeft(CuTest *tc) {
    printf("Scores One Box Left\n");
    initTestGame(&game, -1);
    getTestBoard(game.board);
    game.board[3] = 0;
    int score = scoreBoxes(game.board, 1, 0);
    CuAssertIntEquals(tc, 0, score);
    tearDownTestGame();
}

void TestScoresTwoBoxesLeft(CuTest *tc) {
    printf("Scores Two Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 9, scores[3]);
    CuAssertIntEquals(tc, 0, scores[5]);
    tearDownTestGame();
}

void TestScoresThreeBoxesLeft(CuTest *tc) {
    printf("Scores Three Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = 1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 0, scores[2]);
    CuAssertIntEquals(tc, -9, scores[3]);
    CuAssertIntEquals(tc, -9, scores[5]);
    tearDownTestGame();
}

void TestScoresThreeBoxesLeftWMistake(CuTest *tc) {
    printf("Scores Three Boxes Left w Mistake\n");
    initTestGame(&game, 1);
    game.currentPlayer = 1;
    getTestBoard(game.board);
    game.board[2] = -1;
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[6] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, -9, scores[3]);
    CuAssertIntEquals(tc, -9, scores[5]);
    CuAssertIntEquals(tc, 10, scores[6]);
    tearDownTestGame();
}

void TestScoresFourBoxesLeft(CuTest *tc) {
    printf("Scores Four Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    game.board[6] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 9, scores[3]);
    CuAssertIntEquals(tc, 9, scores[5]);
    CuAssertIntEquals(tc, 9, scores[2]);
    CuAssertIntEquals(tc, 0, scores[6]);
    tearDownTestGame();
}

void TestScoresFiveBoxesLeft(CuTest *tc) {
    printf("Scores Five Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = 1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    game.board[6] = 0;
    game.board[7] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, -9, scores[3]);
    CuAssertIntEquals(tc, -9, scores[5]);
    CuAssertIntEquals(tc, -9, scores[2]);
    CuAssertIntEquals(tc, -9, scores[6]);
    CuAssertIntEquals(tc, 0, scores[7]);
    tearDownTestGame();
}

void TestScoresSixBoxesLeft(CuTest *tc) {
    printf("Scores Six Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    game.board[6] = 0;
    game.board[7] = 0;
    game.board[1] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 0, scores[3]);
    CuAssertIntEquals(tc, 0, scores[5]);
    CuAssertIntEquals(tc, 7, scores[2]);
    CuAssertIntEquals(tc, 7, scores[6]);
    CuAssertIntEquals(tc, 0, scores[7]);
    CuAssertIntEquals(tc, 0, scores[1]);
    tearDownTestGame();
}

void TestScoresSevenBoxesLeft(CuTest *tc) {
    printf("Scores Seven Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = 1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    game.board[6] = 0;
    game.board[7] = 0;
    game.board[1] = 0;
    game.board[8] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 0, scores[3]);
    CuAssertIntEquals(tc, 0, scores[5]);
    CuAssertIntEquals(tc, 0, scores[2]);
    CuAssertIntEquals(tc, 0, scores[6]);
    CuAssertIntEquals(tc, 0, scores[7]);
    CuAssertIntEquals(tc, 0, scores[1]);
    CuAssertIntEquals(tc, 0, scores[8]);
    tearDownTestGame();
}

void TestScoresEightBoxesLeft(CuTest *tc) {
    printf("Scores Eight Boxes Left\n");
    initTestGame(&game, 1);
    game.currentPlayer = -1;
    getTestBoard(game.board);
    game.board[3] = 0;
    game.board[5] = 0;
    game.board[2] = 0;
    game.board[6] = 0;
    game.board[7] = 0;
    game.board[1] = 0;
    game.board[8] = 0;
    game.board[4] = 0;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 5, scores[3]);
    CuAssertIntEquals(tc, 5, scores[5]);
    CuAssertIntEquals(tc, 5, scores[2]);
    CuAssertIntEquals(tc, 5, scores[6]);
    CuAssertIntEquals(tc, 5, scores[7]);
    CuAssertIntEquals(tc, 5, scores[1]);
    CuAssertIntEquals(tc, 5, scores[8]);
    CuAssertIntEquals(tc, 0, scores[4]);
    tearDownTestGame();
}

void TestShouldTakeWin(CuTest *tc) {
    printf("Scores Five Boxes Left\n");
    initTestGame(&game, -1);
    game.currentPlayer = 1;
    game.board[0] = 1;
    game.board[1] = -1;
    game.board[2] = -1;
    game.board[6] = -1;
    game.board[8] = 1;
    int scores[9];

    for (int i = 0; i < 9; ++i) {
        if (game.board[i] == 0) {
            game.board[i] = game.currentPlayer;
            scores[i] = scoreBoxes(game.board, game.currentPlayer * -1, 0);
            game.board[i] = 0;
        }
    }
    CuAssertIntEquals(tc, 10, scores[4]);
    CuAssertIntEquals(tc, -9, scores[3]);
    CuAssertIntEquals(tc, -9, scores[5]);
    CuAssertIntEquals(tc, -9, scores[7]);
    box = makeBestMove(&game);
    CuAssertIntEquals(tc, 4, box);
    tearDownTestGame();
}
