/*
 * hw4-unfinished.c: supply the missing code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3   // airport code len

struct node {
    char code[LEN + 1];
    struct node *next;
};


void list_append(char *s, struct node **ph);
void list_print(struct node *p);
void list_concat();     /* WHAT ARE THE PARAMETERS? */

int main(void)
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    // first list
    list_append("SGN", &head1);
    list_append("PNH", &head1);
    list_append("BKK", &head1);
    list_print(head1);
    putchar('\n');

    // second list
    list_append("SIN", &head2);
    list_append("DBX", &head2);
    list_append("FRA", &head2);
    list_print(head2);
    putchar('\n');

    // concatenate
    list_concat();  // WHAT ARE THE ARGUMENTS?
    list_print(head1);

    return 0;
}

void list_append(char *s, struct node **ph)
{
    // prepare new node
    struct node *n = malloc(sizeof(struct node));
    strlcpy(n->code, s, LEN + 1);
    n->next = NULL;

    if (*ph == NULL)
        // adjust head
        *ph = n;
    else {
        // find last node
        struct node *last = *ph;
        while (last->next != NULL)
            last = last->next;
        
        // append new node to list
        last->next = n;
    }
}

void list_print(struct node *p)
{
    while (p != NULL) {
        printf("%s\n", p->code);
        p = p->next;
    }
}

void list_concat(/* some params */)
{
    // some code
}