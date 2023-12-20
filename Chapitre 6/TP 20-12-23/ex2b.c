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

typedef struct Queue{stack *left; stack *right;} queue;

void queue_enqueue(queue *q, int x){
  stack_push(q->right,x);
}

void check_left(queue *q){
  if(stack_is_empty(q->left)){
    while(!stack_is_empty(q->right)){
      int p = stack_top(q->right);
      stack_push(q->left,p);
      stack_pop(q->right);
    }
  }
}

int queue_dequeue(queue *q){
      check_left(q);
      return stack_pop(q->left);
}


int main(int argc, char *argv[]) {

  return 0;
}