#ifndef PRIO_H

#define PRIO_H

#include <stdbool.h>

#define MAXCOUNT 1000

typedef int pq_item;

typedef struct {
            size_t count;
            pq_item a[MAXCOUNT];
        } pq_prio;     // priority queue type

pq_prio *pq_initialize(void);
bool pq_empty(pq_prio *);     /* true if priority queue is empty */
bool pq_full(pq_prio *);      /* true if full */
void pq_insert(pq_item, pq_prio *);
pq_item pq_remove(pq_prio *);

#endif