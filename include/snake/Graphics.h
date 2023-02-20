#pragma once

#include <ncurses.h>

#include "Board.h"

#ifndef __APPLE__ // Apple users don't deserve happiness
#define LOCALE LC_ALL
#endif

int printn(int** board, WINDOW* w);
