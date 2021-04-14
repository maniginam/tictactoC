#ifndef TICTACTOC_GAME_H
#define TICTACTOC_GAME_H

struct gameStatus {
    int currentPlayer;
    int humanToken;
    int *board;
    int winner;
};

void run_game(struct gameStatus *game);
void play_game(struct gameStatus *game);

int isGameOver(int *board);
int isWinner(int *board);
int boardIsFull(int *board);

#endif //TICTACTOC_GAME_H
