#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct {
    int vec[CAPACITY];
    int top;
} Stiva;

void init(Stiva* stv) {
    stv->top = 0;
}

void push(Stiva* stv, int cheie) {
    if (stv->top == CAPACITY) {
        return;
    }
    stv->vec[stv->top] = cheie;
    stv->top++;
}

void pop(Stiva* stv) {
    if (stv->top == 0) {
        exit(1);
    }
    stv->top--;
}

void afisare(Stiva* stv) {
    for (int i = stv->top - 1; i >= 0; i--) {
        printf("%d ", stv->vec[i]);
    }
    printf("\n");
}

int main() {
    Stiva stv;
    init(&stv);

    push(&stv, 10);
    push(&stv, 20);
    push(&stv, 30);

    afisare(&stv);

    pop(&stv);

    afisare(&stv);

    return 0;
}