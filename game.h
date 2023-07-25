#pragma once

#include "player.h"

void board_clear(char board[3][3]);

void game(Player p1, Player p2, char board[3][3], char option, char currentGameState[]);

char check_win(char board[3][3]);