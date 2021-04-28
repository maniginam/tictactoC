#ifndef TICTACTOC_HELPER_H
#define TICTACTOC_HELPER_H

struct gameStatus game;
int box;

void initTestGame(struct gameStatus *game, int human);
void tearDownTestGame();
void makeCatsGame();
void confirmCornerBox();
void getTestBoard(int *board);

#endif //TICTACTOC_HELPER_H
