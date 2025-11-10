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

  NodeT* merge_lista(NodeT *p1, NodeT *p2){
   if (p1 == NULL) {
     return p2;
   }
   if (p2 == NULL) {
     return p1;
   }

   NodeT *r_cap = NULL;

   if (p1->key <= p2->key) {
     r_cap = p1;
     p1 = p1->next;
   } else {
     r_cap = p2;
     p2 = p2->next;
   }

   NodeT *curent = r_cap;

   while (p1 != NULL && p2 != NULL) {
     if (p1->key <= p2->key) {
       curent->next = p1;
       p1 = p1->next;
     } else {
       curent->next = p2;
       p2 = p2->next;
     }
     curent = curent->next;
   }

   if (p1 != NULL) {
     curent->next = p1;
   }
   if (p2 != NULL) {
     curent->next = p2;
   }

   return r_cap;
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

     char command[10];
     int key;

     printf("Lab 2.3.2.1 (Comenzi: i1, i2, p1, p2, m, exit)\n");

     while (1) {
       printf("> ");
       scanf("%s", command);

       if (strcmp(command, "i1") == 0) {
         scanf("%d", &key);
         inserare(&lista1, key);
       }
       else if (strcmp(command, "i2") == 0) {
         scanf("%d", &key);
         inserare(&lista2, key);
       }
       else if (strcmp(command, "p1") == 0) {
         printf("Lista 1: ");
         afisare(lista1);
       }
       else if (strcmp(command, "p2") == 0) {
         printf("Lista 2: ");
         afisare(lista2);
       }
       else if (strcmp(command, "m") == 0) {
         printf("Interclasare\n");
         lista_rez = merge_lista(lista1, lista2);
         printf("Rezultat:  ");
         afisare(lista_rez);
         lista1 = NULL;
         lista2 = NULL;
       }
       else if (strcmp(command, "exit") == 0) {
         break;
       }
     }

     return 0;
   }