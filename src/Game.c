#include <snake/Game.h>

#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#ifdef LOCALE
#include <locale.h>
#endif

void
g_loop(void) {
    Direction dir = Up;
    int c;

    while (move_snake(snake, dir)) {
        c = wgetch(stdscr);

        switch(c) {
            case KEY_UP:
                if (dir != Down) {
                    dir = Up;
                }
                break;
            case KEY_LEFT:
                if (dir != Right) {
                    dir = Left;
                }
                break;
            case KEY_RIGHT:
                if (dir != Left) {
                    dir = Right;
                }
                break;
            case KEY_DOWN:
                if (dir != Up) {
                    dir = Down;
                }
                break;
            case 'q':
                stdscr = NULL;
                return;
                break;
            default:
                break;
        }

        usleep(100000);
    }

    usleep(1500000);
    stdscr = NULL;
    free_board();

    return;
}

void
g_print(void) {
    while (printn(board, stdscr)) {
        usleep(100);
    }
}

void 
g_setup(void) {
    initscr( );             // initialize screen
    nodelay( stdscr, 1 );   // don't wait for `getch()`
    noecho( );              // don't repeat characters entered by user
    cbreak( );              // disable line buffering
    curs_set( 0 );          // don't print cursor
    keypad( stdscr, 1 );    // enable arrows

#ifdef LOCALE
    setlocale(LOCALE, "");
#endif

    srand(time(NULL));

    init_board();
    snake = init_snake();
}

void
g_game(void) {
    g_setup();
    
    pthread_create(&game_loop_id, NULL, g_loop, NULL);
    pthread_create(&print_loop_id, NULL, g_print, NULL);

    pthread_join(game_loop_id, NULL);
    pthread_join(print_loop_id, NULL);

}
