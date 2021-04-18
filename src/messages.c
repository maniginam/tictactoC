#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "messages.h"


int parseSelection(char *input) {
    if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0) {
        return 1;
    } else { return -1; }
}

int offerPosition(char *input) {
    printf("X or O?\n");
//    fgets(input, 32, stdin);
    scanf("%s", input);
    return parseSelection(input);
}

void drawBoard(int *board) {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) { printf("\n"); }
        if (board[i] == 1) { printf(" %s ", "X"); }
        else if (board[i] == -1) { printf(" %s ", "O"); }
        else { printf(" %d ", i); }
    }
    printf("\n");
}

void promptForBox(int *board, int *box) {
    char input[sizeof(int)];
    printf("It's your turn.\n Select a Box 0-8\n");
//    fgets(input, sizeof(int), stdin);
    scanf("%s", input);
    int selection = atoi(input);
    if (validBox(input) && boxOpen(board, selection)) {
        *box = atoi(input);
    } else {
        printf("Not Valid Box");
        promptForBox(box, board);
    }
}

int boxOpen(int *board, int box) {
    if (board[box] == 0)
        return 1;
    else return 0;
}
int validBox(char input[4]) {
    int valid = false;
    if (strcmp("0", input) == 1) {
        valid = 1;
    } else {
        for (int i = 1; i < 9; i++) {
            if (atoi(input) == i) {
                valid = 1;
            }
        }
    }
    return valid;
}

void printWinner(int winner, int human) {
    if (winner == human) {
        printf("You Win!");
    } else if (winner == 0) {
        printf("Cat's Game!");
    } else {
        printf("Computer Wins!");
    }
}