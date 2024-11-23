#ifndef STACKTYPES_H
#define STACKTYPES_H
#define MAXSTACKSIZE 1000

typedef float itemtype;

typedef struct {
    size_t count;
    itemtype items[MAXSTACKSIZE];
} stack;
#endif