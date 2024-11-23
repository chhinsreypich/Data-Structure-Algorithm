#include <stdio.h>
#include <stdlib.h>

#include "23-stack.h"

stack *stack_initialize(void)
{
    stack *s = malloc(sizeof(stack));
    s->count = 0;

    return s;
}

bool stack_is_empty(stack *s)
{
    return s->count == 0;
}

bool stack_is_full(stack *s)
{
    return s->count == MAXSTACKSIZE;
}

itemtype stack_pop(stack *s)
{
    return s->items[--s->count];
}

void stack_push(itemtype x, stack *s)
{
    s->items[s->count++] = x;
}