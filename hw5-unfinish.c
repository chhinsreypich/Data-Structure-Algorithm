/*
 * hw5-unfinished.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3   // airport code len

struct node {
    char code[LEN + 1];
    struct node *next;
};


struct node *list_append(char *s, struct node *p);
struct node *list_insert(char *s, struct node *p);
void list_print(struct node *p);
struct node *list_search(char *s, struct node *p);
struct node *list_delete_node(struct node *n, struct node *p);
struct node *list_concat(struct node *list1, struct node *list2);
struct node *list_reverse(struct node *p);
struct node *list_reverse2(struct node *p);

int main(void)
{
    struct node *head = NULL;   // first list
    struct node *head2 = NULL;  // second list

    // build first list
    head = list_append("SGN", head);
    head = list_append("PNH", head);
    head = list_append("BKK", head);
    head = list_insert("NRT", head);
    list_print(head);
    putchar('\n');

    head = list_delete_node(list_search("PNH", head), head);
    list_print(head);
    putchar('\n');

    // build second list
    head2 = list_append("SIN", head2);
    head2 = list_append("DBX", head2);
    head2 = list_append("FRA", head2);
    list_print(head2);
    putchar('\n');

    // concatenate
    head = list_concat(head, head2);
    list_print(head);
    putchar('\n');

    head = list_reverse2(head);
    list_print(head);

    return 0;
}

struct node *list_append(char *s, struct node *p)
{
    // prepare new node
    struct node *n = malloc(sizeof(struct node));
    strncpy(n->code, s, LEN + 1);
    n->next = NULL;

    if (p == NULL)
        return n;

    // find last node
    struct node *last = p;
    while (last->next != NULL)
        last = last->next;
        
    // append new node to list
    last->next = n;
    return p;
}

struct node *list_insert(char *s, struct node *p)
{
    struct node *n = malloc(sizeof(struct node));
    strncpy(n->code, s, LEN+1);
    n->next = p;

    return n;
}

void list_print(struct node *p)
{
    while (p != NULL) {
        printf("%s\n", p->code);
        p = p->next;
    }
}

struct node *list_search(char *s, struct node *p)
{
    while (p != NULL && strncmp(p->code, s, LEN) != 0)
            p = p->next;
    return p;
}

struct node *list_delete_node(struct node *n, struct node *p)
{
    if (n == NULL)  // don't do anything if n is NULL
        return p;

    if (p == n) { /* n is pointing to first element */
        struct node *ret = n->next;
        free(n);
        return ret;
    }

    /* step 1: find node previous to n */
    struct node *prev = p;
    while (prev->next != n)
        prev = prev->next;

    /* step 2: delete node */
    prev->next = n->next;
    free(n);
    return p;
}

struct node *list_concat(struct node *list1, struct node *list2)
{
    if (list1 == NULL)
        return list2;

    // find last element on first list
    struct node *last = list1;
    while (last->next != NULL)
        last = last->next;

    // append second list
    last->next = list2;
    return list1;
}

struct node *list_reverse(struct node *p)
{
    // going up 
    if (p == NULL || p->next == NULL) // base step
        return p; 

    struct node *tail = p-> next;
    p->next = NULL;
    return list_concat(list_reverse(tail), p);
}

struct node *list_reverse2(struct node *p)
{
    // going down
    if (p == NULL || p->next == NULL) // base step
        return p; 

    /* break up list into two */
    struct node *prev, *last;
    for (prev = NULL, last = p; last->next != NULL; prev = last, last = last->next);
    
    
     /* Questions:
     *    What are prev and last pointing at now?
     *    What are the two lists?
     *    What else needs to be done?
     */

    /* 
     * the prev pointing at DBX which is the node before the last node in linked list  and the last pointing at FRA which is the last node in linked list.

     * the first list contain nodes from beginning to the node that the prev pointer points to
       and the second list contain only the node that the last pointer points to.

     * something needs to be done
    */

    prev->next = NULL;  
    last->next = list_reverse2(p);

    return last;
   
    // struct node * tail = last;
    // prev->next = NULL;

    // if (tail != NULL){

    //     p = list_reverse2(p);
    //     tail-> next = p;
    // }
    // return tail;
}


   
