#ifndef QUEUETYPES_H
#define QUEUETYPES_H
#define MAXQUEUESIZE 1000

typedef int itemtype;

typedef struct
{
  size_t count;
  size_t front;
  size_t rear;
  itemtype items[MAXQUEUESIZE];
} queue;
#endif