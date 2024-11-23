#include <stdlib.h>
#include <stdio.h>

#include "21-item.h"
#include "21-sort_alg.h"

void print_arr(itemtype [], size_t n);

int main(void)
{
    itemtype array[] = {"PNH", "SIN", "HCM", "BKK"};
    size_t sz = sizeof(array)/sizeof(itemtype);

    printf( "%zu", sz);
    print_arr(array, sz);
    putchar('\n');
    selection_sort(array, 0, sz-1);
    print_arr(array, sz);
    putchar('\n');


    
    return 0;
}

void print_arr(itemtype a[], size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        itemprint(&a[i]);
        putchar(' ');
    }
}