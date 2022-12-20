#pragma once

#include "Board.h"
#include "Graphics.h"

#include <pthread.h>

Node* snake;

void g_loop(void);
void g_print(void);
void g_setup(void);

void g_game(void);

pthread_t game_loop_id;
pthread_t print_loop_id;
