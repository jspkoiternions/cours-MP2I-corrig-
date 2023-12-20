#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{int value; struct Cell *next;} list;

list *ajout(int x, list *n){
  list *c = malloc(sizeof(struct Cell));
  c->value = x;
  c->next = n;
  return c;
}

list *list_interval(int lo, int hi){
  list *c = NULL;
  while(hi>=lo){
    c = ajout(hi, c);
    hi--;
  }
  return c;
}

int main(int argc, char *argv[]) {
   list *l = list_interval(12,28);
  list *c = l;
  while(c!=NULL){
    printf("%d,",c->value);
    c = c->next; 
  }
  return 0;
}