#include <snake/Snake.h>

#include <stdlib.h>

static void
update_nodes(Node* head) {
    while (head) {
        head->saved.x = head->point.x;
        head->saved.y = head->point.y;

        head->point.x = head->NEXT->saved.x;
        head->point.y = head->NEXT->saved.y;

        head = head->PREV;
    }
}

void
add_node(Node* head, Point value) {
    // `add_node` is not responsible for checking whether the addition
    // is possible, it shall be done in the board implementation.
    head->size++;

    // get to the last element
    while (head->PREV) {
        head = head->PREV;
    }

    head->PREV = (Node*) malloc(sizeof(Node));
    head->PREV->NEXT = head;
    head->PREV->PREV = NULL;

    head->PREV->point.x = value.x;
    head->PREV->point.y = value.y;
}

Node* 
s_init(void) {
    Node* head = (Node*) malloc(sizeof(Node));

    head->point.x = 10;
    head->point.y = 10;

    head->NEXT = NULL;
    head->PREV = NULL;

    int i = 3;
    while (i--) {
        Point temp = { head->point.x, head->point.y+i-3 };
        add_node(head, temp);
    }

    head->size = 4;

    return head;
}

void
s_free(Node* head) {
    Node* temp;

    while (head) {
        temp = head;
        head = head->PREV;
        free(temp);
    }
}

void
s_move(Node* head, Direction u_dir) {
    // `s_move` is not responsible for checking whether the move
    // is possible, it shall be done in the board implementation.
 
    head->saved.x = head->point.x;
    head->saved.y = head->point.y;

    update_nodes(head->PREV);

    switch (u_dir) {
        case Down:
            head->point.y--;
            break;
        case Left:
            head->point.x--;
            break;
        case Right:
            head->point.x++;
            break;
        case Up:
            head->point.y++;
            break;
    }
}
