#ifndef TICTACTOC_GAME_H
#define TICTACTOC_GAME_H

struct gameStatus {
    char *board[9];
    char *currentPlayer;
    char *humanToken;
    char *winner;
};

void run_game(struct gameStatus *game);
void play_game(struct gameStatus *game);

#endif //TICTACTOC_GAME_H
