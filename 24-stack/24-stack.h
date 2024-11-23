#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

#include "24-stacktypes.h"

stack *stack_initialize();
bool stack_is_empty(stack *s);
bool stack_is_full(stack *s);
void stack_push(itemtype x, stack *s);
itemtype stack_pop(stack *s);
#endif