#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int row;
  int col;
  int val;
  struct node*next;
}NodeT;

NodeT* creeare_nod(int r, int c, int v){
  NodeT *p = (NodeT*)malloc(sizeof(NodeT));
  if(p==NULL)
    exit(1);
  p->row = r;
  p->col = c;
  p->val = v;
  p->next = NULL;
  return p;
}

void insereaza_element(NodeT **primul, int r, int c, int v){
  if(v==0)
    return;

  NodeT *nod_nou = creeare_nod(r,c,v);

  if (*primul == NULL || ((*primul)->row > r) || ((*primul)->row == r && (*primul)->col > c)) {
    nod_nou->next = *primul;
    *primul = nod_nou;
    return;
  }

  NodeT *curent = *primul;
  NodeT *inainte = NULL;

  while (curent != NULL && (curent->row < r || (curent->row == r && curent->col < c))) {
    inainte = curent;
    curent = curent->next;
  }

  if (curent != NULL && curent->row == r && curent->col == c) {
    curent->val += v;
    free(nod_nou);

  }
  else {
    inainte->next = nod_nou;
    nod_nou->next = curent;
  }
}
