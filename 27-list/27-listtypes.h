#ifndef LISTTYPES_H
#define LISTTYPES_H

#define LISTSIZE 2    /* initial size of list */

typedef int itemtype;

typedef struct {
    size_t maxitems;
    size_t count;
    itemtype *items;    /* pointer to array */
} list;
#endif