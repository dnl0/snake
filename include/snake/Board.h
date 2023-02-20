#pragma once

#include "Snake.h"

#define BOARD_WIDTH 22  // the active Board range is [1] to [20], [0] and [21] are borders,
#define BOARD_HEIGHT 22 // which, if gotten to, teleport node to [1] or [20] respectively

int** board;

void init_board(void);
void free_board(void);

Node* init_snake(void);

int move_snake(Node* snake, Direction u_dir);
