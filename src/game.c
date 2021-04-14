#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"

bool isWinner(char *board[9]);

void checkForWin(char board, int box);

void run_game(struct gameStatus *game) {
    while(!game->winner)
    {
        play_game(game);
    }
}

void play_game(struct gameStatus *game) {
//    if(isWinner(game->board)) {
//
//    }

    game->winner = "X";
}

//bool checkForWin(char board, int box) {
//
//}
//
//bool isWinner(char board) {
//    for(int i = 0; i < 5; i++)
//        checkForWin(board, i);
//}
