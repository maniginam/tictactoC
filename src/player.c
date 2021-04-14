#include <stdio.h>
#include <string.h>
#include "player.h"

int sendPrompt() {
    char input[8];//, piece[32];
    printf("X or O?\n");
//    fgets(input, 32, stdin);
    scanf("%s", input);
    int player = assign_player(input);
    if (player == 1) {
        printf("You go first\n");
    } else {
        printf("Computer goes first\n");
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
    if(last_player == 1) {
        return 2;
    } else {
        return 1;
    }
}