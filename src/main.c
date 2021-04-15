#include <stdio.h>
#include "main.h"
#include "game.h"
#include "player.h"
#include <string.h>
#include <stdlib.h>

struct gameStatus;
const int BOARDSIZE = 9;

void initGame(struct gameStatus *game, int boardSize);
void printWinner(struct gameStatus *game);
int promptHuman();

void printWinner(struct gameStatus *game) {
    if(game->winner == game->humanToken) {
        printf("You Win!");
    } else {
        printf("Computer Wins!");
    }
}

int promptHuman() {
    int human = sendPrompt();
  return human;
}

int main() {
    struct gameStatus game;
    initGame(&game, BOARDSIZE);
    run_game(&game);
    printWinner(&game);
}

void initGame(struct gameStatus *game, int boardSize) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->board = malloc(boardSize * sizeof(int));
    game->humanToken = promptHuman();
}


