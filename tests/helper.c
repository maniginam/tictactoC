#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"
#include "../src/game.h"
#include "helper.h"

struct gameStatus game;

void initTestGame(struct gameStatus *game, int human) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = human;
    game->board = malloc(9 * sizeof(int));
    for (int i = 0; i < 9; i++) { game->board[i] = 0; }
}

void tearDownTestGame() {
    free(game.board);
}

void makeCatsGame() {
    game.board[4] = 1;
    game.board[0] = -1;
    game.board[6] = 1;
    game.board[2] = -1;
    game.board[1] = 1;
    game.board[3] = -1;
    game.board[5] = 1;
    game.board[7] = -1;
    game.board[8] = 1;
}