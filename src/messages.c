#include <stdio.h>
#include <string.h>
#include "messages.h"


int parseSelection(char *input) {
    if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0) {
        return 1;
    } else { return 2; }
}

int offerPosition(char *input) {
    printf("X or O?\n");
//    fgets(input, 32, stdin);
    scanf("%s", input);
    return parseSelection(input);
}

void drawBoard(int *board) {
    for(int i = 0; i < 9; i++) {
        if(i > 0 && i % 3 == 0) { printf("\n"); }
        if(board[i] == 1) { printf (" %s ", "X"); }
        else if(board[i] == 2) { printf (" %s ", "O"); }
        else { printf(" %d ", i); }
    }
    printf("\n");
}

void promptForBox(int *box) {
    char input[sizeof(int)];
    printf("It's your turn.\n Select a Box 0-8\n");
    fgets(input, sizeof(int), stdin);
    sscanf(input, "%d", box);
}