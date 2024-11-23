#include <stdio.h>
#include <stdlib.h>

#include "26-queue.h"

queue *queue_initialize(void)
{
  queue *q = malloc(sizeof(queue));
  q->count = 0;
  q->front = 0;
  q->rear = 0;

  return q;
}

bool queue_is_empty(queue *q)
{
  return q->count == 0;
}

bool queue_is_full(queue *q)
{
  return q->count == MAXQUEUESIZE;
}

void queue_insert(itemtype x, queue *q)
{
  q->items[q->rear] = x;
  q->rear = (q->rear + 1) % MAXQUEUESIZE;
  ++q->count;
}

itemtype queue_remove(queue *q)
{
  itemtype ret = q->items[q->front];
  q->front = (q->front + 1) % MAXQUEUESIZE;
  --q->count;

  return ret;
}