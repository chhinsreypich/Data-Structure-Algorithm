#ifndef PRIO_H

#define PRIO_H

#include <stdbool.h>

typedef int pq_item;

typedef struct pq_node {
            pq_item item;
            struct pq_node *next;
        } pq_node;

typedef struct {
            size_t count;
            pq_node *list;
        } pq_prio;     // priority queue type

pq_prio *pq_initialize(void);
bool pq_empty(pq_prio *);     /* true if priority queue is empty */
bool pq_full(pq_prio *);      /* true if full */
void pq_insert(pq_item, pq_prio *);
pq_item pq_remove(pq_prio *);

#endif