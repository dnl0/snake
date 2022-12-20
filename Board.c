#include "Board.h"

#define SNAKE 1
#define FRUIT 2

#define hits_itself(o, t)   (t[o->point.y][o->point.x] == SNAKE)
#define hits_fruit(o, t)    (t[o->point.y][o->point.x] == FRUIT)
#define hits_border(o)      (o->point.y == BOARD_HEIGHT-1 || o->point.y == 0 || \
                             o->point.x == BOARD_WIDTH -1 || o->point.x == 0)

#define random_number       ((rand() % BOARD_HEIGHT-2) + 1)

static void
put_on_board(Node* head, int value) {
    while (head) {
        board[head->point.y][head->point.x] = value;
        head = head->PREV;
    }
}

static Node*
get_last_node(Node* head) {
    while (head->PREV) {
        head = head->PREV;
    }

    return head;
}

static void
teleport_snake(Node* snake, Direction u_dir) {
    switch (u_dir) {
        case Up:
            snake->point.y = 1;
            break;
        case Left:
            snake->point.x = BOARD_WIDTH-2;
            break;
        case Right:
            snake->point.x = 1;
            break;
        case Down:
            snake->point.y = BOARD_HEIGHT-2;
            break;
    }
}

void
init_board(void) {
    board = (int**) malloc(BOARD_HEIGHT * sizeof(int*));

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        board[i] = (int*) malloc(BOARD_WIDTH * sizeof(int));

        for (int o = 0; o < BOARD_WIDTH; ++o) {
            board[i][o] = 0;
        }
    }

    generate_fruit();
}

void
free_board(void) {
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        free(board[i]);
    }
    free(board);
}

Node*
init_snake(void) {
    Node* snake = s_init();

    put_on_board(snake, 1);

    return snake;
}

int
move_snake(Node* snake, Direction u_dir) {
    Node *last = get_last_node(snake);

    Point last_point;
    last_point.x = last->point.x;
    last_point.y = last->point.y;

    s_move(snake, u_dir);

    if (hits_itself(snake, board)) {
        return 0;
    }

    if (hits_border(snake)) {
        teleport_snake(snake, u_dir);
    }

    // if snake eats fruit, it gains another Node, that stands in
    // the place of the last Node, if it doesn't eat fruit, that
    // point of last Node is cleared (because the last Node moved)
    if (hits_fruit(snake, board)) {
        generate_fruit();
        add_node(snake, last_point);
    } else {
        board[last_point.y][last_point.x] = 0;
    }

    put_on_board(snake, 1);

    return 1;
}

void
generate_fruit(void) {
    int x = random_number;
    int y = random_number;

    while (board[x][y] != 0) {
        int x = random_number;
        int y = random_number;
    }

    board[x][y] = 2;
}
