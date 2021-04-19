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
        int score = 0;
        for (int i = 0; i < BOARDSIZE; ++i) {
            if (game->board[i] == 0) {
                game->board[i] = game->currentPlayer;
                if (isGameOver(game->board)) {
                    *box = i;
                    return *box;
                } else {
                    int depth = 0;
                    int boxScore = scoreBoxes(game->board, game->currentPlayer * -1, depth, box, game->humanToken);
                    if (game->currentPlayer == 1) {
                        if (boxScore >= score) {
                            score = boxScore;
                            *box = i;
                        }
                    } else {
                        if (boxScore <= score) {
                            score = boxScore;
                            *box = i;
                        }
                    }
                }
                game->board[i] = 0;
            }
        }
    }
    return *box;
}

int scoreBoxes(int *board, int player, int depth, int *box, int human) {
    if (isGameOver(board)) {
        int boxScore = scoreBox(board, player, depth);
        return boxScore * player;
    } else {
        depth++;
        int score = 0;
        for (int i = 0; i < BOARDSIZE; ++i) {
            if (board[i] == 0) {
                board[i] = player;
                int boxScore = scoreBoxes(board, -1 * player, depth, box, human);
                if (player == 1) {
                    if (boxScore < score) {
                        score = boxScore;
                    }
                } else {
                    if (boxScore > score) {
                        score = boxScore;
                    }
                }
                board[i] = 0;
            }
        }
        return score;
    }
}

int scoreBox(int *board, int player, int depth) {
    if (isWin(board)) {
        return (10 - depth);
    } else { return 0; }
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