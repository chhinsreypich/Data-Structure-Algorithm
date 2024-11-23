#ifndef ITEM_H
#define ITEM_H

#define LEN 3
typedef char itemtype[LEN+1];
int itemcmp(itemtype *i, itemtype *j);
void itemcpy(itemtype *i, itemtype *j);
void itemprint(itemtype *i);

#endif