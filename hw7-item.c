// item.c

#include <stdio.h>
#include <string.h>

#include "hw7-item.h"

/*
 * return <0, >0, ==0 accoring to whether
 *   i has smaller, bigger, or same prio as j
 */
int itemcmp(itemtype *i, itemtype *j)
{
    return i->x - j->x;
}

void itemprint(itemtype *i)
{
    printf("%d", *i);
}

