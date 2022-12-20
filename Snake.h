#pragma once

#include <stdlib.h>

typedef enum { Down, Left, Right, Up } Direction;

typedef struct { int x; int y; } Point;
typedef struct Node Node;

struct Node {
    Point point;
    Point saved;

    Node* NEXT;
    Node* PREV;

    Direction current_dir;

    int size;
};

Node* s_init(void);
void s_free(Node* head);

void add_node(Node* head, Point value);
void s_move(Node* head, Direction u_dir);
