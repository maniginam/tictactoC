#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "messages.h"

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

int sendPrompt() {
    char input;//, piece[32];
    offerPosition(&input);
    return parseSelection(&input);
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
    game->currentPlayer = 2;
    game->winner = 0;
    game->board = malloc(boardSize * sizeof(int));
    game->humanToken = promptHuman();
}


