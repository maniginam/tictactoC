#include <stdio.h>
#include <string.h>
#include "player.h"

int ask_player() {
    char input[32];
    int player;
    printf("X or O?\n");
    scanf("%s", input);
    player = assign_player(input);
    if (player == 1) {
        printf("You go first");
    } else {
        printf("Computer goes first");
    }
    return player;
}

int assign_player(char *input) {
    if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0) {
        return 1;
    } else {
        return 2;
    }
}

int set_current_player(int last_player) {
    switch (last_player) {
        case 1 :
            return 2;
            break;
        default :
            return 1;

    }
}