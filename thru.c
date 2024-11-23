/*

//// what did we do this semester? 
    - learned c
    - wrote alot of  code
    - learned some algorithm and data structure
***********************************
C . python has dictory : hash 
C doesnt have datastructure 
it has only basic type
//////book








*/
// #include <stdio.h>
// #include <stdlib.h>


// int main()
// {









// }




#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag {
    int data;
    struct nodetag *next;
} node;

node *list_append(int key, node *p);
void list_print(node *p);
node *list_search(int key, node *p);
node *list_insert(int key, node *p);
node *list_sort(node *p);

int main(void)
{
    node *head = NULL;
    node *q;
    int key;

    for (size_t i = 0; i < 20; ++i)
        head = list_append(rand() % 100, head);
    list_print(head);
    printf("\n\n");

    for (size_t i = 0; i < 10; ++i) {
	    key = rand() % 100;
	    printf("searching for key %d...\n", key);
	
	    q = list_search(key, head);
	    if (q != NULL){
	        printf("\tfound at location %p\n", (void *)q);  
            ++q->data;
            //// value of the pointer , address where it was. 
            //// print pointer address in the decimal maximum (not sure---record )
            //// (void*)is to casting something


        }
	    else
	        printf("\tnot found\n");
    }
    list_print(head);
    printf("\n");

    return 0;
}

/* search list for first occurrence of key */
node *list_search(int key, node *p)
{
    while (p != NULL) {
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

node *list_sort(node *p){


}

node *list_insert(int key, node *p){


}

void list_print(node *p)
{
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct nodetag {
//     int data;
//     struct nodetag *next;
// } node;

// node *list_append(int key, node *p);
// void list_print(node *p);
// node *list_search(int key, node *p);

// int main(void)
// {
//     node *head = NULL;
//     node *q;
//     int key;

//     for (size_t i = 0; i < 20; ++i)
//         head = list_append(rand() % 100, head);
//     list_print(head);
//     printf("\n\n");

//     for (size_t i = 0; i < 10; ++i) {
// 	    key = rand() % 100;
// 	    printf("searching for key %d...\n", key);
	
// 	    q = list_search(key, head);
// 	    if (q != NULL)
// 	        printf("\tfound at location %p\n", (void *)q);
// 	    else
// 	        printf("\tnot found\n");
//     }
//     list_print(head);

//     return 0;
// }

// /* search list for first occurrence of key */
// node *list_search(int key, node *p)
// {
//     while (p != NULL) {
//         if (p->data == key)
//             break;
//         p = p->next;
//     }
//     return p;
// }

// /* append a new node containing key to list */
// node *list_append(int key, node *p)
// {
//     // prepare new node
//     node *n = malloc(sizeof(node));
//     n->data = key;
//     n->next = NULL;

//     if (p == NULL)
//         return n;

//     // find last node
//     node *last = p;
//     while (last->next != NULL)
//         last = last->next;

//     // append new node to list
//     last->next = n;
//     return p;
// }

// void list_print(node *p)
// {
//     while (p != NULL) {
//         printf("%d ", p->data);
//         p = p->next;
//     }
// }