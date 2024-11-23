#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#include "27-listtypes.h"

list *list_initialize();
size_t list_length(list *s);
bool list_is_empty(list *s);
itemtype list_select(size_t i, list *s);
void list_replace(itemtype x, size_t i, list *s);
itemtype list_delete(size_t i, list *s);
itemtype list_insert(itemtype x, size_t i, list *s);
itemtype list_append(itemtype x, list *s);

#endif