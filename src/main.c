#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "messages.h"

struct gameStatus;

void initGame(struct gameStatus *game);
int promptHuman();

int sendPrompt() {
    char input;//, piece[32];
    offerPosition(&input);
    return parseSelection(&input);
}

int promptHuman() {
    int human = sendPrompt();
  return human;
}

void initGame(struct gameStatus *game) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = promptHuman();
}

int main() {
    struct gameStatus game;
    printf("hello");
    setSrand();
    initGame(&game);
    run_game(&game);
    printWinner(game.winner, game.humanToken);
    free(game.board);
}

