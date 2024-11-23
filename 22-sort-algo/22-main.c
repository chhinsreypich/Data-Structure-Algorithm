#include <stdlib.h>
#include <stdio.h>

#include "item.h"
#include "sort_alg.h"

void get_items(itemtype a[], size_t n);
itemtype *get_winner(itemtype a[], size_t n, size_t m);
void print_arr(itemtype a[], size_t n);

int main(void)
{
    itemtype a[6];
    itemtype *pitem; // winning amount or zero
    int amt;

    /* Step 1: get input from user into array */
    get_items(a, 6);

    /* Step 2: sort array */
    selection_sort(a, 0, 5);

    /* Step 3: print winning amount */
    pitem = get_winner(a, 6, 3);
    amt = pitem != NULL ? *pitem : 0;
    printf("You won $%d!\n", amt);

    return 0;
}

/* get input from user */

void get_items(itemtype a[], size_t n)
{
    printf("Give six dollar amounts separated by spaces: ");

    for (size_t i = 0; i < n; ++i)
        // use %d, since itemtype is int
        scanf("%d", a + i);
}

/* print first amount repeated at least m times */
itemtype *get_winner(itemtype a[], size_t n, size_t m)
{
    itemtype *cur = a; // possible value to return;
                       // start at beginning of array
    int seen = 1;      // num times we have seen item

    for (size_t i = 1; i < n && seen < m; ++i)
        if (itemcmp(a + i, cur) == 0)
            ++seen;
        else
        {
            cur = a + i;
            seen = 1;
        }

    if (seen < m)
        // didn't find m repetitions
        return NULL;
    return cur;
}