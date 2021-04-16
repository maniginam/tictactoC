#ifndef TICTACTOC_MESSAGES_H
#define TICTACTOC_MESSAGES_H

int parseSelection(char *input);
int offerPosition(char *input);
void drawBoard(int *board);
void promptForBox(int *box);
void printWinner(int winner, int human);

#endif //TICTACTOC_MESSAGES_H
