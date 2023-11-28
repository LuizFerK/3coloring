#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queueNode {
  int node;
  struct queueNode *next;
} QueueNode;

struct queue {
  QueueNode *first;
  QueueNode *last;
};

Queue *QUEUE() {
  Queue *q;

  q = malloc(sizeof(*q));

  q->first = NULL;
  q->last = NULL;

  return q;
}

bool QUEUEempty(Queue *q) {
  return (q->first == NULL);
}

void QUEUEinsert(Queue *q, int i) {
  QueueNode *aux;

  aux = malloc(sizeof(*aux));
  aux->node = i;
  aux->next = NULL;

  if (QUEUEempty(q)) {
    q->first = aux;
    q->last = aux;
  } else {
    q->last->next = aux;
    q->last = aux;
  }
}

int QUEUEremove(Queue *q) {
  int i;
  QueueNode *aux;

  if (QUEUEempty(q)) {
    printf("Error on function QUEUEremove: Empty queue!\n");
    exit(EXIT_FAILURE);
  }

  i = q->first->node;
  aux = q->first;

  if (q->first == q->last) {
    q->first = NULL;
    q->last = NULL;
  } else {
    q->first = q->first->next;
  }

  free(aux);
  return i;
}

void QUEUEwipe(Queue *q) {
  QueueNode *aux;

  while (!QUEUEempty(q)) {
    aux = q->first;
    q->first = q->first->next;

    free(aux);
}

  free(q);
}
