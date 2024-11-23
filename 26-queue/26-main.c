/*
 * main.c: test program for queue
 */

#include <stdio.h>
#include <stdlib.h>

#include "26-queue.h"  /* itemtype is int */


int main(void)
{
    queue *qp = queue_initialize();

    for (int i = 0; i < 10; ++i)
        queue_insert(i*i, qp);

    for (int i = 0; i < 10; ++i)
        printf("%d ", queue_remove(qp));
    putchar('\n');

    return 0;
}