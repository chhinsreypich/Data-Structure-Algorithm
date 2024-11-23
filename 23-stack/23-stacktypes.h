#ifndef STACKTYPES_H
#define STACKTYPES_H
#define MAXSTACKSIZE 1000

typedef char itemtype;

typedef struct {
    size_t count;
    itemtype items[MAXSTACKSIZE];
} stack;
#endif