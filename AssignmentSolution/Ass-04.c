/*
    1. Study the code for list delete item() in 12-linked-list-v2.c on the classroom site.
    How does that function behave if it’s given a pointer to a node that’s not on the list?
    How would you “fix” the code?

    Programming

    Instructions: Upload a .c file of your program by the deadline

    1. Download hw4-unfinished.c from the classroom site, and supply the missing code. Note:
    the output is
    SGN
    PNH
    BKK

    SIN
    DBX
    FRA

    SGN
    PNH
    BKK
    SIN
    DBX
    FRA
*/

/*
 * hw4.c: implementation of the list_concat function
 */

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
void list_print(struct node *p);
void list_concat(struct node **ph, struct node *q);

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
    list_concat(&head1, head2);
    list_print(head1);

    return 0;
}

void list_append(char *s, struct node **ph)
{
    // prepare new node
    // correct strncpy
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

void list_print(struct node *p)
{
    while (p != NULL)
    {
        printf("%s\n", p->code);
        p = p->next;
    }
}

void list_concat(struct node **ph, struct node *q)
{
    if (*ph == NULL)
        // first list is empty; adjust its head
        *ph = q;
    else
    {
        // find last element on first list
        struct node *last = *ph;
        while (last->next != NULL)
            last = last->next;

        // append second list
        last->next = q;
    }
}