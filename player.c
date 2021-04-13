#include <stdio.h>
#include <string.h>
#include "player.h"

int askPlayer() {
    char input[32];
    int player;
    printf("X or O?\n");
    scanf("%s", input);
    player = setPlayer(input);
    if(player == 1) {
        printf("You go first");
    } else {
        printf("Computer goes first");
    }
    return player;

}

int setPlayer(char *input) {
    if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0) {
        return 1;
    } else {
        return 2;
    }
}