#ifndef GENLISTTYPES_H
#define GENLISTTYPES_H

#include <stdbool.h>

typedef int itemtype;

typedef struct glnode
{
  bool atom;
  union
  {
    itemtype item;
    struct glnode *sublist;
  } subnode;
  
  struct glnode *next;
} glnode;

#endif