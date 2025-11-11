#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetype{
  int key;
  struct nodetype *next;
 }NodeT;

 NodeT* creare_node(int key){
   NodeT *p = (NodeT*)malloc(sizeof(NodeT));
   if (p==NULL){
     printf("eroare la alocarea memoriei \n");
     exit(1);
   }
   p->key = key;
   p->next = NULL;
   return p;
 }

void inserare(NodeT **prm_rf, int cheie){
   NodeT *newNode = creare_node(cheie);
   NodeT *current;

   if (*prm_rf == NULL || (*prm_rf)->key >= cheie) {
     newNode->next = *prm_rf;
     *prm_rf = newNode;
   }
   else{
     current = *prm_rf;

     while(current->next != NULL && current->next->key < cheie)
       current = current->next;
     newNode->next = current->next;
     current->next = newNode;
   }
 }

void afisare(NodeT *prim) {
   if (prim == NULL) {
     printf("Lista vida\n");
     return;
   }
   NodeT *p = prim;
   while (p != NULL) {
     printf("%d -> ", p->key);
     p = p->next;
   }
   printf("NULL\n");
 }

int main() {
     NodeT *lista1 = NULL;
     NodeT *lista2 = NULL;
     NodeT *lista_rez = NULL;

    inserare(&lista1, 20);
    inserare(&lista1, 30);
    inserare(&lista1, 15);
    inserare(&lista1, 7);

   inserare(&lista2, 80);
   inserare(&lista2, 10);
   inserare(&lista2, 90);
   inserare(&lista2, 17);

   while (lista1 != NULL && lista2 !=NULL) {
     if (lista1->key < lista2->key) {
       inserare(&lista_rez, lista1->key);
       lista1 = lista1->next;
     }
     else if (lista1->key > lista2->key) {
       inserare(&lista_rez, lista2->key);
       lista2 = lista2->next;
     }
     else {
       lista1 = lista1->next;
       lista2 = lista2->next;
     }
   }

   while (lista1 != NULL) {
     inserare(&lista_rez, lista1->key);
     lista1 = lista1->next;
   }

   while (lista2 != NULL) {
     inserare(&lista_rez, lista2->key);
     lista2 = lista2->next;
   }

   afisare(lista_rez);

     return 0;
   }