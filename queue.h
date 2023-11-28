#ifndef QUEUE_H

#define QUEUE_H

#include <stdbool.h>

typedef struct queue Queue;

Queue *QUEUE();

bool QUEUEempty(Queue *q);

void QUEUEinsert(Queue *q, int i);

int QUEUEremove(Queue *q);

void QUEUEwipe(Queue *q);

#endif /* QUEUE_H */
