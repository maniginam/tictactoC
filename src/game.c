#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"

#define WINS { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }  { 2, 4 6 } }

void run_game(struct gameStatus *game) {

    while (!isGameOver(game->board)) {
        play_game(game);
    }

    if (isWin(game->board)) {
        game->winner = game->currentPlayer;
    }
}

void play_game(struct gameStatus *game) {

}

int isGameOver(int *board) {
    if (isWin(board) || isBoardFull(board)) {
        return true;
    } else { return false; }
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

int isWin(int *board) {
    int win = false;
    for (int i = 0; i < 9; i++) { printf("i = %d and box = %d\n", i, board[i]); }
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




//int boxes[3] = {4, 0, 8};
//    for (int i = 0; i < 3; i++) {
//        if (board[i]) {
//            switch (i) {
//                case 4:
//                    if (board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6] || board[4] == board[1] && board[4] == board[7] || board[4] == board[3] && board[4] == board[5]) {
//                        win = true;
//                        break;
//                    }
//                case 0:
//                    if (board[0] == board[1] && board[0] == board[2] || board[0] == board[3] && board[0] == board[6]) {
//                        win = true;
//                        break;
//                    }
//                case 8:
//                    if (board[8] == board[2] && board[8] == board[5] || board[8] == board[7] && board[8] == board[6]) {
//                        win = true;
//                        break;
//                    }
//            }
//        }
//    }