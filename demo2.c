#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag
{
    int data;
    struct nodetag *next;
} node;

node *list_append(int key, node *p);
node *list_oinsert(int key, node *p);
void list_print(node *p);
node *list_search(int key, node *p);

int main(void)
{
    node *head = NULL;
    node *q;
    int key;

    for (size_t i = 0; i < 20; ++i)
    {
        head = list_oinsert((key = rand() % 100), head);
        printf("%d ", key);
    }
    printf("\n");
    list_print(head);
    printf("\n");

    return 0;
}

/* search list for first occurrence of key */
node *list_search(int key, node *p)
{
    while (p != NULL)
    {
        if (p->data == key)
            break;
        p = p->next;
    }
    return p;
}

/* append a new node containing key to list */
node *list_append(int key, node *p)
{
    // prepare new node
    node *n = malloc(sizeof(node));
    n->data = key;
    n->next = NULL;

    if (p == NULL)
        return n;

    // find last node
    node *last = p;
    while (last->next != NULL)
        last = last->next;

    // append new node to list
    last->next = n;
    return p;
}

void list_print(node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

node *list_oinsert(int key, node *p)
{

    node *n = malloc(sizeof(node));
    n->data = key;
    n->next = NULL;
    node *before = NULL;
    node *after = p;
    while (after != NULL && after->data < key)
    {
        before = after;
        after = after->next;
    }
    if(before != NULL)
        before->next = n;
    n->next = after;

    return before == NULL ? n : p;

}