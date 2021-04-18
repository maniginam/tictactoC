#ifndef TICTACTOC_MESSAGES_H
#define TICTACTOC_MESSAGES_H

int parseSelection(char *input);
int offerPosition(char *input);
void drawBoard(int *board);
void promptForBox(int *board, int *box);
void printWinner(int winner, int human);
int validBox(char input[4]);
int boxOpen(int *board, int box);

#endif //TICTACTOC_MESSAGES_H
