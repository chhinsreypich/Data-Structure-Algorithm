#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

#include "26-queuetypes.h"

queue *queue_initialize();
bool queue_is_empty(queue *q);
bool queue_is_full(queue *q);
void queue_insert(itemtype x, queue *q);
itemtype queue_remove(queue *q);
#endif