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

     NodeT* p1;
     NodeT* p2;

     while(lista1 != NULL || lista2 != NULL){
       if(p1->key < p2->key)
         inserare(&lista_rez, p1->key)
       else(p2->key >p1->key)
         inserare(&lista_rez, p2->key)

     return 0;
   }