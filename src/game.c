#include <stdbool.h>
#include <stdlib.h>
#include "game.h"
#include "messages.h"

#include <printf.h>
#include <strings.h>

#define WINS { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }  { 2, 4 6 } }

void setSrand() { srand(time(0)); }

int BOARDSIZE = 9;

int nextPlayer(int playerCurrent);

void makeBestMove(struct gameStatus *game, int *box);

int isEmpty(int *board);

void pickCorner(int *box);

void scoreBoxes(int *board, int player, int depth, int *scores);

void run_game(struct gameStatus *game) {
    game->board = malloc(BOARDSIZE * sizeof(int));
    while (!isGameOver(game->board)) {
        int box;
        drawBoard(game->board);
        getBox(game, &box);
        play_game(game, &box);
    }
    drawBoard(game->board);
}

void play_game(struct gameStatus *game, int *box) {
    game->board[*box] = game->currentPlayer;
    if (isWin(game->board)) {
        game->winner = game->currentPlayer;
    } else { game->currentPlayer = nextPlayer(game->currentPlayer); }
}

void getBox(struct gameStatus *game, int *box) {
    if (game->currentPlayer == game->humanToken) {
        promptForBox(box);
    } else { makeBestMove(game, box); }
}

void makeBestMove(struct gameStatus *game, int *box) {
    if (isEmpty(game->board)) {
        pickCorner(box);
    } else {
        int *scores = malloc(BOARDSIZE * sizeof(int));
        scoreBoxes(game->board, game->currentPlayer, 0, scores);
        if (game->currentPlayer == 1) { maxBox(scores, box); }
        free(scores);
    }
}

void maxBox(int *scores, int *box) {
    for (int i = 0; i < 9; ++i) {
        printf("score %i = %i\n", i, scores[i]);
    }
    int max = -10;
    for (int i = 0; i < BOARDSIZE; i++) {
        if (scores[i] && scores[i] > max) {
            max = scores[i];
            *box = i;
        }
    }
}

void minBox(int *scores, int *box) {
    for (int i = 0; i < 9; ++i) {
        printf("score %i = %i\n", i, scores[i]);
    }
    int min = 10;
    for (int i = 0; i < BOARDSIZE; i++) {
        if (scores[i] && scores[i] < min) {
            min = scores[i];
            *box = i;
        }
    }
}

void scoreBoxes(int *board, int player, int depth, int *scores) {
    for (int i = 0; i < BOARDSIZE; i++) {
        if (!board[i]) {
            int *scoreBoard = malloc(BOARDSIZE * sizeof(int));
            memcpy(scoreBoard, board, BOARDSIZE);
            scoreBoard[i] = player;
            if (isWin(scoreBoard)) {
                scores[i] = 10;
//                scores[i] = scoreBox(player, depth);
                free(scoreBoard);
            } //else if(isFull(scoreBoard)) {
            //scores[i] = 0;
            //}
        }
    }
}

void pickCorner(int *box) {
    int corners[4] = {0, 2, 6, 8};
    int r = (rand() % 4);
    *box = corners[r];
}

int nextPlayer(int playerCurrent) {
    if (playerCurrent == 1) { return 2; }
    else { return 1; }
}

int isGameOver(int *board) {
    if (isWin(board) || isFull(board)) {
        return true;
    } else { return false; }
}


int isWin(int *board) {
    int win = false;
//    for (int i = 0; i < 9; i++) { printf("i = %d and box = %d\n", i, board[i]); }
    if (board[4]) { //&& (board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6] || board[4] == board[1] && board[4] == board[7] || board[4] == board[3] && board[4] == board[5])) {
        if (board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6] ||
            board[4] == board[1] && board[4] == board[7] || board[4] == board[3] && board[4] == board[5]) {
            win = true;
        }
    } else if (board[0]) { // && (board[0] == board[1] && board[0] == board[2] || board[0] == board[3] && board[0] == board[6])) {
        if (board[0] == board[1] && board[0] == board[2] || board[0] == board[3] && board[0] == board[6]) {
            win = true;
        }
    } else if (board[8]) { // && (board[8] == board[2] && board[8] == board[5] || board[8] == board[7] && board[8] == board[6])) {
        if (board[8] == board[2] && board[8] == board[5] || board[8] == board[7] && board[8] == board[6]) {
            win = true;
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
        if (board[box] != 0) { playedBoxes++; }
    }
    if (!playedBoxes) { return true; }
    else return false;
}