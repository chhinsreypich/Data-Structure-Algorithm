#include <stdlib.h>
#include <stdio.h>
#include "20-item.h"
#include "20-sort_alg.h"

#define MAXARRAY 10

void print_arr(itemtype [], size_t n);

int main(void)
{
    itemtype array[MAXARRAY];

    for (size_t i = 0; i < MAXARRAY; ++i)
        // fill with pseudo-random data
        array[i] = rand() % 100;
    print_arr(array, MAXARRAY);
    putchar('\n');
    selection_sort(array, 0, MAXARRAY-1);
    print_arr(array, MAXARRAY);
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
