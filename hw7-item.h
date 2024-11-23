// item.h

#ifndef ITEM_H
#define ITEM_H

#define LEN 3
typedef struct
{
    int x;
    int y;
} itemtype;
int itemcmp(itemtype *i, itemtype *j);
void itemprint(itemtype *i);

#endif