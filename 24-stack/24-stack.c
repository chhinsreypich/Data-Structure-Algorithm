#include <stdio.h>
#include <stdlib.h>

#include "24-stack.h"

stack *stack_initialize(void)
{
  stack *s = malloc(sizeof(stack));
  s->start = NULL;

  return s;
}

bool stack_is_empty(stack *s)
{
  return s->start == NULL;
}

bool stack_is_full(stack *s)
{
  return false;
}

itemtype stack_pop(stack *s)
{
  stacknode *first = s->start;
  itemtype ret = first->item;

  s->start = first->next;
  free(first);

  return ret;
}

void stack_push(itemtype x, stack *s)
{
  stacknode *temp;

  if ((temp = malloc(sizeof(stacknode))) == NULL)
  {
    fprintf(stderr, "System storage is exhausted\n");
    exit(1);
  }
  temp->item = x;
  temp->next = s->start;
  s->start = temp;
}