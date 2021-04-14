#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"

#define WINS { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }  { 2, 4 6 } }

void run_game(struct gameStatus *game) {
    int *board = game->board;
    while (gameOver(&board) == 0 || game->winner !=0) {
        play_game(game);
    }
}


void play_game(struct gameStatus *game) {
//    if (isWinner(game)) {
//        game->winner = game->currentPlayer;
//    }

    game->winner = 1;
}

int gameOver(int *board[9]) {
    //TODO: DON'T FORGET TO ADD FN FOR FULL BOARD!!
    if (isWinner(board)) {
        return 1;
    } else
        return 0;
}

int isWinner(int *board[9]) {
//    int *board[9];
//    *board = *game->board;
    int win = 0;

    if (board[4]) {
        if (board[4] == board[0] && board[4] == board[8] || board[4] == board[2] && board[4] == board[6]
            || board[4] == board[1] && board[4] == board[7] || board[4] == board[3] && board[4] == board[5]) {
            win = 1;
        } else if (board[0]) {
            if (board[0] == board[1] && board[0] == board[2] || board[0] == board[3] && board[0] == board[6]) {
                win = 1;
            }
        } else if (board[8]) {
            if (board[8] == board[2] && board[8] == board[5] || board[8] == board[7] && board[8] == board[6]) {
                win = 1;
            }
        }
    }
    return win;

}




