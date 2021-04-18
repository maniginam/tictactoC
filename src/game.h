#ifndef TICTACTOC_GAME_H
#define TICTACTOC_GAME_H

struct gameStatus {
    int currentPlayer;
    int humanToken;
    int *board;
    int winner;
};

void setSrand();
void run_game(struct gameStatus *game);
void getBox(struct gameStatus *game, int *box);
void play_game(struct gameStatus *game, int *box);

int scoreBoxes(int *board, int player, int depth, int *box);
int scoreBox(int *board, int player, int depth);

int isGameOver(int *board);
int isWin(int *board);
int isFull(int *board);

#endif //TICTACTOC_GAME_H
