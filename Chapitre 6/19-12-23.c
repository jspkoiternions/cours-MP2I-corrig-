#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


/*
  queue *queue_create(void);
  int queue_size(queue *q);
  bool queue_is_empty(queue *q);
  void queue_enqueue(queue *q, int *x);
  int queue_peek(queue *q);
  int queue_dequeue(queue *q);
  void queue_delete(queue *q);*/

typedef struct Queue {int size; int capacity; int front; int* data} queue;

typedef struct Queue queue;


  
queue *queue_create(int cap) {
    queue *q = malloc(sizeof(struct Queue));
    q->data = malloc(sizeof(int));
    q->size = 0;
    q->capacity = cap;
    q->front = 0;  
    return q;
}

int queue_size(queue *q){ //renvoie la taille de la queue
  return q->size;
};

bool queue_is_empty(queue *q){ // pour le tableau vide
  return q-> size == 0;
}

void queue_enqueue(queue *q, int x){
  assert(q->size != q-> capacity);
  q-> data[(front+size)%(q->capacity)] = x;
  (q-> size)++;
};


int queue_dequeue(queue *q int x){
  assert(q->size != 0);
  (q-> front)++;
  (q-> size)--;
};



/*--------------------------------*/
/*
la suite est analogue mais je n'ai pas eu le tps de l'écire*/

int main(){
  return 0;
}