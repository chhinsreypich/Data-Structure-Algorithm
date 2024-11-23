// sort_alg.c

#include <stddef.h> // for size_t
#include "hw7-item.h"
#include "hw7-sort_alg.h"

/* sort array of itemtype from index m to n, inclusive */
void selection_sort(itemtype a[], size_t m, size_t n)
{
    size_t i;

    if (m < n) {
        i = findmax(a, m, n);

        // swap a[i] and a[m]
        itemtype temp = a[m];

        a[m] = a [i];
        a[i] = temp;

        // sort the rest
        selection_sort(a, m+1, n);
    }
}


/*
 * return index of maximum element in the range
 * [m:n], inclusive; assume m <= n
 */
size_t findmax(itemtype a[], size_t m, size_t n)
{
    size_t maxind = m;
    for (size_t i = m+1; i <= n; ++i)
        if (itemcmp(&a[i], &a[maxind]) > 0)
            maxind = i;
    return maxind;
}
