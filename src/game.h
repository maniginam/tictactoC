#ifndef TICTACTOC_GAME_H
#define TICTACTOC_GAME_H

struct gameStatus {
    int board[9];
    int currentPlayer;
    int humanToken;
    int winner;
};

void run_game(struct gameStatus *game);
void play_game(struct gameStatus *game);

int isWinner(int *board[9]);
int gameOver(int *board[9]);

#endif //TICTACTOC_GAME_H
