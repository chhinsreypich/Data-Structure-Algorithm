/*
1. Complete the program by writing the missing code for list insert.


//  same output as 11-linked-list.c, but
//  uses list_insert(). note that list_insert()
//  is called in reverse order


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define LEN 3 // airport code len
    struct node {
        char code[LEN+1];
        struct node *next;
    };

    void list_insert(char *s, struct node **start);
    void list_print(struct node *p);

    int main(void)
    {
        struct node *head = NULL;
        list_insert("BKK", &head);
        list_insert("PNH", &head);
        list_insert("SGN", &head);
        list_print(head);
        return 0;
    }

    // insert node at beginning of list
    void list_insert(char *s, struct node **start)
    {
        // missing code goes here
    }

    void list_print(struct node *p)
    {
        while (p != NULL) {
            printf("%s\n", p->code);
            p = p->next;
        }
    }


*/

/*
 * same output as 11-linked-list.c, but
 * uses list_insert(). note that list_insert()
 * is called in reverse order
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

void list_insert(char *s, struct node **start);
void list_print(struct node *p);

int main(void)
{
    struct node *head = NULL;

    list_insert("BKK", &head);
    list_insert("PNH", &head);
    list_insert("SGN", &head);

    list_print(head);

    return 0;
}

/* insert node at beginning of list */
void list_insert(char *s, struct node **start)
{
    // prepare new node
    struct node *n = malloc(sizeof(struct node));
    strlcpy(n->code, s, LEN + 1); /*
                                   * strcpy should not be used.
                                   * systems that don't have strlcpy,
                                   * should use strncpy.
                                   */
    n->next = *start;             /*
                                   * head is *start.
                                   * head points at previous first,
                                   * which is now the second node
                                   */

    // adjust head
    *start = n;
}

void list_print(struct node *p)
{
    while (p != NULL)
    {
        printf("%s\n", p->code);
        p = p->next;
    }
}