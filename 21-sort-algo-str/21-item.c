#include <stdio.h>
#include <string.h>

#include "21-item.h"

/*
 * return <0, >0, ==0 accoring to whether
 *   i has smaller, bigger, or same prio as j
 */
int itemcmp(itemtype *i, itemtype *j)
{
    return strncmp(*i, *j, LEN);
}

void itemprint(itemtype *i)
{
    printf("%s", *i);
}

void itemcpy(itemtype *i, itemtype *j)
{
    strncpy(*i, *j, LEN);
    *i [LEN] = '\0';
}