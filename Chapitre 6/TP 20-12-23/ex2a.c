#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cell{int value; struct Cell *next;} list;

list *ajout(int x, list *n){
  list *c = malloc(sizeof(struct Cell));
  c->value = x;
  c->next = n;
  return c;
}



typedef struct Stack {list *head} stack;

stack *stack_create(void){
  stack *s = malloc(sizeof(struct Cell));
  s->head = NULL;
}

bool stack_is_empty(stack *s){
  return s-> head = NULL;
}

void stack_push(stack *s, int x){
  s-> head = ajout(x, s-> head);
}

int stack_top(stack *s){
  return s->head->value;
}

int stack_pop(stack *s){
  int c = s-> head -> value;
  list *p = s -> head;
  s->head = p->next;
  free(p);
  return c;
}


int main(int argc, char *argv[]) {

  return 0;
}