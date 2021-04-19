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
    int selection;
    if(scanf("%d", &selection) != 1) { printf("Not valid entry\n"); }
    if (validBox(selection) && boxOpen(board, selection)) {
        *box = selection;
    } else {
        printf("Not Valid Box\n");
        promptForBox(box, board);
    }
}

int boxOpen(int *board, int box) {
    if (board[box] == 0)
        return 1;
    else return 0;
}

int validBox(int selection) {
    int valid = false;
    char *board[9] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",};
//    int board[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8,};
    for (int i = 0; i < 9; i++) {
        if (selection == i) {
            valid = 1;
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