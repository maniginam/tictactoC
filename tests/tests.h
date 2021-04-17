#ifndef TICTACTOC_TESTS_H
#define TICTACTOC_TESTS_H

void initTestGame(struct gameStatus *game, int human) {
    game->currentPlayer = 1;
    game->winner = 0;
    game->humanToken = human;
    game->board = malloc(9 * sizeof(int));
    for (int i = 0; i < 9; i++) { game->board[i] = 0; }
}

void tearDownTestGame() {
    free(game.board);
}
#endif //TICTACTOC_TESTS_H
