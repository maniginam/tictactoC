#include <stdio.h>
#include "main.h"
#include "game.h"
#include "player.h"
#include <string.h>

struct gameStatus initGame(struct gameStatus *game);
void printWinner(struct gameStatus *game);
char *promptHuman();

int main() {
    struct gameStatus game;
    game = initGame(&game);
    run_game(&game);
    printWinner(&game);
}

struct gameStatus initGame(struct gameStatus *game) {
    game->currentPlayer = "X";
    game->winner = NULL;
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

char *promptHuman() {
    int human = sendPrompt();
    if(human == 1) {
        return "X";
    } else {
        return "O";
    }
}




