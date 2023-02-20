#include <snake/Graphics.h>

#include <stdlib.h>

int
printn(int* board[], WINDOW* w) {
    if (w) {
        clear();
        wprintw(w, "+========================================+\n");
        for (int i = BOARD_HEIGHT-2; i >= 1; --i) {
            wprintw(w, "|");
            for (int o = 1; o <= BOARD_WIDTH-2; ++o) {
                switch (board[i][o]) {
                    case 0:
                        wprintw(w, "  ");
                        break;
#ifdef LOCALE
                    default:
                        wprintw(w, "■ ");
                        break;
#else
                    case 2:
                        wprintw(w, "X ");
                        break;
                    default:
                        wprintw(w, "O ");
                        break;
#endif
                }
            }
            wprintw(w, "|\n");
        }
        wprintw(w, "+========================================+\n");
        refresh();

        return 1;
    }

    endwin();
    return 0;
}
