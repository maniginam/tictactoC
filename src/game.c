#include <stdbool.h>
#include <stdlib.h>
#include "game.h"
#include "messages.h"
#include <printf.h>


int wins[9][3] = {{0, 1, 2},
                  {3, 4, 5},
                  {6, 7, 8},
                  {0, 3, 6},
                  {1, 4, 7},
                  {2, 5, 8},
                  {0, 4, 8},
                  {2, 4, 6}};

void setSrand() { srand(time(0)); }

int BOARDSIZE = 9;

int makeBestMove(struct gameStatus *game, int *box);

int isEmpty(int *board);

void pickCorner(int *box);

void run_game(struct gameStatus *game) {
    game->board = malloc(BOARDSIZE * sizeof(int));
    while (!isGameOver(game->board)) {
        int box;
        getBox(game, &box);
        play_game(game, &box);
        if (game->currentPlayer == game->humanToken) {
            drawBoard(game->board);
        }
    }
}

void play_game(struct gameStatus *game, int *box) {
    game->board[*box] = game->currentPlayer;
    if (isWin(game->board)) {
        game->winner = game->currentPlayer;
    } else { game->currentPlayer = -1 * game->currentPlayer; }
}

void getBox(struct gameStatus *game, int *box) {
    if (game->currentPlayer == game->humanToken) {
        promptForBox(game->board, box);
    } else { *box = makeBestMove(game, box); }
}

int makeBestMove(struct gameStatus *game, int *box) {
    if (isEmpty(game->board)) {
        pickCorner(box);
    } else {
    }
    return *box;
}


int scoreBoxes(int *board, int player, int depth, int *box, int human) {
    int score = 10;
    for (int i = 0; i < BOARDSIZE; ++i) {
        int boxScore;
        if (board[i] == 0) {
            board[i] = player;
            if (isGameOver(board)) {
                if (isWin(board)) {
                    score = (10 - depth) * player;
                } else {
                    score = 0;
                }
            } else {
                boxScore = scoreBoxes(board, player * -1, depth++, box, human);
                if (player == -1) {
                    if (boxScore < score) {
                        score = boxScore;
                    }
                } else {
                    if (boxScore > score) {
<<<<<<< HEAD
=======
                        printf("hello");
>>>>>>> refs/remotes/origin/main
                        score = boxScore;
                    }
                }
            }
            board[i] = 0;
        }
    }
    return score;
}

int scoreBox(int *board, int depth) {
    if (isWin(board)) {
        return (10 - depth);
    } else { return 0; }
}

int maxBox(int *scores) {
    int max = scores[0];
    for (int i = 1; i < BOARDSIZE; i++) {
        if (scores[i] != 1 && scores[i] != -1 && scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

int minBox(int *scores) {
//    for (int i = 0; i < 9; ++i) {
//        printf("score %i = %i\n", i, scores[i]);
//    }
    int min = scores[0];
    for (int i = 1; i < BOARDSIZE; i++) {
        if (scores[i] != 1 && scores[i] != -1 && scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

void pickCorner(int *box) {
    int corners[4] = {0, 2, 6, 8};
    int r = (rand() % 4);
    *box = corners[r];
}

int isGameOver(int *board) {
    if (isWin(board) || isFull(board)) {
        return true;
    } else { return false; }
}

int isWin(int *board) {
    int win = false;
    for (int i = 0; i < BOARDSIZE - 1; ++i) {
        int box1 = board[wins[i][0]];
        int box2 = board[wins[i][1]];
        int box3 = board[wins[i][2]];
        if (box1 != 0 && box1 == box2 && box1 == box3) {
            win = true;
            i = BOARDSIZE;
        }
    }
    return win;
}

int isFull(int *board) {
    int boxes = 0;
    int playedBoxes = 0;
    for (int box = 0; box < 9; box++) {
        boxes++;
        if (board[box] != 0) { playedBoxes++; }
    }
    if (boxes == playedBoxes)
        return true;
    else return false;
}

int isEmpty(int *board) {
    int playedBoxes = 0;
    for (int box = 0; box < 9; box++) {
        if (board[box] != 0) {
            playedBoxes++;
        }
    }
    if (!playedBoxes) { return true; }
    else return false;
}