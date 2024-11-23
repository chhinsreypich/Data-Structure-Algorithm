/*
 * maxmin.c:
 */

#include <stdio.h>

/* stores max and min values of a[] through ptrs */
void max_min(int a[], size_t n, int *max, int *min)
{
    *max = *min = a[0];

    for (size_t i = 1; i < n; ++i)
    {
        if (a[i] > *max)
            *max = a[i];
        if (a[i] < *min)
            *min = a[i];
    }
}

int main(void)
{
    int big, small;
    int a[] = {10, -1, 20, 0, 5}; // test array

    max_min(a, sizeof(a) / sizeof(int), &big, &small);
    printf("big: %d\n", big);
    printf("small: %d\n", small);

    return 0;
}