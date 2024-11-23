#include <stdio.h>
#include <string.h>

#include "22-item.h"

/*
 * return <0, >0, ==0 accoring to whether
 *   i has smaller, bigger, or same prio as j
 */
int itemcmp(itemtype *i, itemtype *j)
{
    return *i - *j;
}

void itemprint(itemtype *i)
{
    printf("%d", *i);
}

void itemcpy(itemtype *i, itemtype *j)
{
    *i = *j;
}