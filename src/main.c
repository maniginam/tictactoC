#include <stdio.h>
#include "main.h"
#include "game.h"
#include "player.h"
#include <string.h>

struct gameStatus initGame(struct gameStatus *game);
void printWinner(struct gameStatus *game);
int promptHuman();

int main() {
    struct gameStatus game;
    game = initGame(&game);
    run_game(&game);
    printWinner(&game);
}

struct gameStatus initGame(struct gameStatus *game) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = promptHuman(game);
    return *game;
}

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




