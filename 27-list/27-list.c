#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "27-list.h"

list *list_initialize(void)
{
  list *s = malloc(sizeof(list));
  s->count = 0;

  s->items = malloc(sizeof(itemtype) * LISTSIZE);
  s->maxitems = LISTSIZE;

  return s;
}

size_t list_length(list *s)
{
  return s->count;
}

bool list_is_empty(list *s)
{
  return s->count == 0;
}

itemtype list_select(size_t i, list *s)
{
  return s->items[i];
}

void list_replace(itemtype x, size_t i, list *s)
{
  s->items[i] = x;
}

/*
 * deletes item at position i,
 * assuming there i is a valid index
 */
itemtype list_delete(size_t i, list *s)
{
  itemtype ret = s->items[i];

  /*
   * for (size_t j = i+1; j < s->count; ++j)
   *    s->items[j] = s->items[j-1];
   */

  memmove(s->items + i, s->items + (i + 1),
          sizeof(itemtype) * (s->count - 1 - i));

  --s->count;

  return ret;
}

/*
 * inserts x in front of item at index i
 * assumes: 0 <= i <= s->count
 */
itemtype list_insert(itemtype x, size_t i, list *s)
{
  if (s->count == s->maxitems)
  {
    s->items = realloc(s->items, 2 * s->maxitems * sizeof(itemtype));
    s->maxitems = 2 * s->maxitems;
  }

  memmove(s->items + (i + 1), s->items + i,
          sizeof(itemtype) * (s->count - i));
  s->items[i] = x;
  ++s->count;

  return x;
}

itemtype list_append(itemtype x, list *s)
{
  return list_insert(x, s->count, s);
}