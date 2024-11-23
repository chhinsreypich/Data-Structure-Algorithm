#include <stdio.h>
#include <stdlib.h>
#include "2prio.h"

int main(void)
{
    pq_prio *pq = pq_initialize();

    if (!pq_full(pq))
        pq_insert(3, pq);

    if (!pq_full(pq))
        pq_insert(4, pq);

    if (!pq_full(pq))
        pq_insert(3, pq);

    if (!pq_full(pq))
        pq_insert(1, pq);

    if (!pq_full(pq))
        pq_insert(3, pq);

    while (!pq_empty(pq)) {

        /* can use %d, since a pq_item is an int */
        printf("%d ", pq_remove(pq));
    }
    putchar('\n');

    free(pq);

    return 0;
}