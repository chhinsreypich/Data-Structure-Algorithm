#ifndef STACKTYPES_H
#define STACKTYPES_H
typedef char itemtype;

typedef struct stacknode {
    itemtype item;
    struct stacknode *next;
} stacknode;

typedef struct {
    stacknode *start;
} stack;
#endif