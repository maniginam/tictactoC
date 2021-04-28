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
int getBox(struct gameStatus *game);
void play_game(struct gameStatus *game, int box);

int makeBestMove(struct gameStatus *game);
int scoreBoxes(int *board, int player, int depth);
int scoreBox(int *board, int depth);
int maxBox(int *scores);
int minBox(int *scores);

int isGameOver(int *board);
int isWin(int *board);
int isFull(int *board);

#endif //TICTACTOC_GAME_H
