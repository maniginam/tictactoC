#ifndef TICTACTOC_MESSAGES_H
#define TICTACTOC_MESSAGES_H

int parseSelection(char *input);
int offerPosition(char *input);
void drawBoard(int *board);
int promptForBox(int *board);
void printWinner(int winner, int human);
int validBox(int selection);
int boxOpen(int *board, int box);

#endif //TICTACTOC_MESSAGES_H
