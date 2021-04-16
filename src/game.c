#include <stdbool.h>
#include <stdlib.h>
#include "game.h"
#include "messages.h"

#include <printf.h>
#define WINS { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }  { 2, 4 6 } }

void setSrand() { srand(time(0)); }

int nextPlayer(int playerCurrent);

void makeBestMove(int *board, int *box);

int isEmpty(int *board);

void pickCorner(int *box);

void run_game(struct gameStatus *game) {
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
    printf("box = %i and piece = %i\n", *box, game->board[*box]);
    if (isWin(game->board)) {
        game->winner = game->currentPlayer;
    } else { game->currentPlayer = nextPlayer(game->currentPlayer); }
}

void getBox(struct gameStatus *game, int *box) {
    if(game->currentPlayer == game->humanToken) {
        promptForBox(box);
    } else makeBestMove(game->board, box);
}

void makeBestMove(int *board, int *box) {
    if (isEmpty(board)) {
        pickCorner(box); }
}

void pickCorner(int *box) {
    int corners[4] = { 0, 2, 6, 8 };
    int r = (rand() % 4);
    *box = corners[r];
}

int nextPlayer(int playerCurrent) {
    if (playerCurrent == 1) { return 2; }
    else { return 1; }
}

int isGameOver(int *board) {
    if (isWin(board) || isBoardFull(board)) {
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

int isBoardFull(int *board) {
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