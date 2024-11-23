#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3 // airport code len

struct node
{
    char code[LEN + 1];
    struct node *next;
};

void list_append(char *s, struct node **ph);
void list_insert(char *s, struct node **ph);
void list_print(struct node *p);
struct node *list_search(char *s, struct node *p);
void list_delete_node(struct node *n, struct node **ph);

int main(void)
{
    struct node *head = NULL;
    /// note: we use strncpy here
    // but haven't change into the correct form
    // this is the strlcpy
    
    list_append("SGN", &head);
    list_append("PNH", &head);
    list_append("BKK", &head);
    list_insert("NRT", &head);
    list_print(head);
    putchar('\n');

    list_delete_node(list_search("PNH", head), &head);
    list_print(head);

    return 0;
}

void list_append(char *s, struct node **ph)
{
    // prepare new node
    struct node *n = malloc(sizeof(struct node));
    strncpy(n->code, s, LEN + 1);
    n->next = NULL;

    if (*ph == NULL)
        // adjust head
        *ph = n;
    else
    {
        // find last node
        struct node *last = *ph;
        while (last->next != NULL)
            last = last->next;

        // append new node to list
        last->next = n;
    }
}

void list_insert(char *s, struct node **ph)
{
    struct node *n = malloc(sizeof(struct node));
    strncpy(n->code, s, LEN + 1);
    n->next = *ph;

    // adjust head
    *ph = n;
}

void list_print(struct node *p)
{
    while (p != NULL)
    {
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

void list_delete_node(struct node *n, struct node **ph)
{
    if (n == NULL) // don't do anything if n is NULL
        return;

    if (*ph == n)
    { /*
       * n is pointing to first element;
       * adjust head
       */
        *ph = n->next;
        free(n);
    }
    else
    {
        /* step 1: find node previous to n */
        struct node *prev = *ph;
        while (prev->next != n)
            prev = prev->next;

        /* step 2: delete node */
        prev->next = n->next;
        free(n);
    }
}