/*
 * an implementation of priority queue
 * using a linked-list
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "prio.h"


/* static function declarations */
static int pq_itemcmp(pq_item i, pq_item j);
static pq_node *do_insert(pq_item item, pq_node *p);

void pq_itemprint(pq_item item)
{
    printf("%d", item);
}


pq_prio *pq_initialize(void)
{
    pq_prio *pq = malloc(sizeof(pq_prio));
    pq->count = 0;
    pq->list = NULL;

    return pq;
}

bool pq_empty(pq_prio *pq)
{
    return pq->count == 0;
}

bool pq_full(pq_prio *pq)
{
    return false;
}


void pq_insert(pq_item item, pq_prio *pq)
{
    pq->count++;
    pq->list = do_insert(item, pq->list);
}

pq_item pq_remove(pq_prio *pq)
{
    pq_item ret = pq->list->item;
    pq_node *d = pq->list;

    pq->list = pq->list->next;
    pq->count--;
    // free(d->item);
    free(d);
    return ret;
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
    return -(i - j) ;    
}

static pq_node *do_insert(pq_item item, pq_node *p)
{
    // prepare new node
    pq_node *n = malloc(sizeof(pq_node));
    n->item = item;

    if (p == NULL || pq_itemcmp(item, p->item) > 0) {
        // node goes in front
        n->next = p;
        return n;
    } else {
        p->next = do_insert(item, p->next);
        return p;
    }

    // // otherwise, find node previous to n
    // pq_node *prev = p;
    // while (prev->next != NULL && 
    //         pq_itemcmp(item, prev->next->item) <= 0)
    //     prev = prev->next;

    // n->next = prev->next;
    // prev->next = n;

    // return p;
}
