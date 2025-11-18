#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int cheie;
    struct node *next;
} NodeT;

NodeT* creare_node(int cheie) {
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if (p == NULL)
      exit(1);
    p->cheie = cheie;
    p->next = NULL;
    return p;
}

void insereaza_lista(NodeT **cap, int cheie) {
    NodeT *NodNou = creare_node(cheie);
    if (*cap == NULL) {
        *cap = NodNou;
    } else {
        NodeT *p = *cap;
        while (p->next != NULL)
            p = p->next;
        p->next = NodNou;
    }
}

void afisare(NodeT *cap) {
    while (cap != NULL) {
        printf("%d -> ", cap->cheie);
        cap = cap->next;
    }
    printf("NULL\n");
}

NodeT* lista_inversata(NodeT *cap) {
    NodeT *prev = NULL;
    NodeT *element = cap;
    NodeT *urm_nod = NULL;

    while (element != NULL) {
        urm_nod = element->next;
        element->next = prev;

        prev = element;
        element = urm_nod;
    }
    return prev;
}

int main() {
    NodeT *lista = NULL;

    insereaza_lista(&lista, 1);
    insereaza_lista(&lista, 2);
    insereaza_lista(&lista, 3);
    insereaza_lista(&lista, 4);

    printf("Lista initiala:\n");
    afisare(lista);

    lista = lista_inversata(lista);

    printf("\nLista inversata:\n");
    afisare(lista);

    return 0;
}