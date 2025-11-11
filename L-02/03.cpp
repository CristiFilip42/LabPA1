#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodetype{
  char nume[50];
  int nota;
  struct nodetype *next;
 }NodeT;

void afisare(NodeT *prim) {
  if (prim == NULL) {
    printf("Lista vida\n");
    return;
  }
  NodeT *p = prim;
  while (p != NULL) {
    printf("%s -> ", p->nume);
    printf("%d -> ", p->nota);
    p = p->next;
  }
  printf("NULL\n");
}

void elim_5(NodeT **cap_lista){
  NodeT *curent = *cap_lista;
  NodeT *prev = NULL;

  while(curent != NULL){
    if(curent->nota == 5){
      NodeT *strs = curent;
      if(prev == NULL){
        *cap_lista = curent->next;
        curent = *cap_lista;
        }else{
          prev->next = curent->next;
          curent = curent->next;
          }
          free(strs);
          }else{
            prev = curent;
            curent = curent->next;
          }
        }
      }

NodeT* creare_node(int nota, char* nume){
  NodeT *p = (NodeT*)malloc(sizeof(NodeT));
  if (p==NULL){
    printf("eroare la alocarea memoriei \n");
    exit(1);
  }
  strcpy(p->nume, nume);
  p->nota = nota;
  p->next = NULL;
  return p;
}


void inserare(NodeT **prm_rf, int cheie, char* nume){
  NodeT *newNode = creare_node(cheie, nume);
  NodeT *current;

  if (*prm_rf == NULL || (*prm_rf)->nota >= cheie) {
    newNode->next = *prm_rf;
    *prm_rf = newNode;
  }
  else{
    current = *prm_rf;

    while(current->next != NULL && current->next->nota < cheie)
      current = current->next;
    newNode->next = current->next;
    current->next = newNode;
  }
}

int main() {
  NodeT *cap_lst = NULL;

  inserare(&cap_lst, 8, "Andrei");
  inserare(&cap_lst, 5, "Mihai");
  inserare(&cap_lst, 10, "Elena");
  inserare(&cap_lst, 4, "David");
  inserare(&cap_lst, 5, "Ana");
  inserare(&cap_lst, 5, "Bogdan");
  inserare(&cap_lst, 9, "Maria");

  printf("Lista inainte de stergere:\n");
  afisare(cap_lst);

  elim_5(&cap_lst);

  printf("\nLista dupa stergere:\n");
  afisare(cap_lst);

  return 0;
}


