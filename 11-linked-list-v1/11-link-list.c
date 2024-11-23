#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3   // airport code len

struct node {
    char code[LEN+1];
    struct node *next;
};

void list_append(char *s, struct node **start);
void list_print(struct node *p);

int main(void)
{
    struct node *head = NULL;

    list_append("SGN", &head);
    list_append("PNH", &head);
    list_append("BKK", &head);

    list_print(head);

    return 0;
}

void list_append(char *s, struct node **start)
{
    struct node *n = malloc(sizeof(struct node));

    // fill in new node
    ///  strlcpy(n->code, s, LEN+1); but this strncpy is incorrect so correct this and after correct this so please remove this cmt . 
    
    strncpy(n->code, s, LEN + 1);
    n->next = NULL;
    
    if (*start == NULL)
        // list was empty
        *start = n;
    else {
        // locate last node of original list
        struct node *last = *start;
        while (last->next != NULL)
            last = last -> next;
        last -> next = n;
    }
}

void list_print(struct node *p)
{
    while (p != NULL) {
        printf("%s\n", p->code);
        p = p->next;
    }
}