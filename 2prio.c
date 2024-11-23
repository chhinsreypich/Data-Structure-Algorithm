/*
 * an implementation of priority queue
 * using an array
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "2prio.h"


/* static function declarations */
static int pq_itemcmp(pq_item i, pq_item j);


pq_prio *pq_initialize(void)
{
    pq_prio *pq = malloc(sizeof(pq_prio));
    pq->count = 0;

    return pq;
}

bool pq_empty(pq_prio *pq)
{
    return pq->count == 0;
}

bool pq_full(pq_prio *pq)
{
    return pq->count == MAXCOUNT;
}


void pq_insert(pq_item item, pq_prio *pq)
{
    pq->a[pq->count] = item;
    pq->count++;
}

pq_item pq_remove(pq_prio *pq)
{
    size_t maxind = 0; /* index containing */
                    /* highest priority item */
    pq_item maxitem = pq->a[maxind];   /* highest priority item */

    for (size_t i = 1; i < pq->count; ++i)
        if (pq_itemcmp(pq->a[i], maxitem) > 0) {
            maxind = i;
            maxitem = pq->a[i];
        }
    pq->count--;

    /* move last item in array into hole at maxind */
    pq->a[maxind] = pq->a[pq->count];

    return maxitem;
}

/*
 * helper functions; internal linkage
 */

/*
 * return <0, >0, ==0 accoring to whether
 *   i has smaller, bigger, or same prio as j
 */
static int pq_itemcmp(pq_item i, pq_item j)
{
    return i - j;    
}
