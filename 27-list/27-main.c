#include <stdlib.h>
#include <stdio.h>

#include "27-list.h"

int main(void)
{
    list *lp = list_initialize();

    for (size_t i = 0; i < 100; ++i)
        list_insert(i, 0, lp);

    while (!list_is_empty(lp)) {
        printf("%d ", list_delete(0, lp));
    }
    putchar('\n');

    /* we are not meant to access this variable */
    printf("maxitems: %zu\n", lp->maxitems);
    
    return 0;
}