#include <stdio.h>

#define MAXIND 100

/* 
 * return the first index containing negative value, or -1
 */
size_t find_neg(int arr[], size_t n)
{
    for(size_t j = 0; j < n; ++j)
        if (arr[j] < 0)
            return j;

    return -1;
}

int main(void)
{
    int a[MAXIND];

    /* initialize array to squares of integers */
    for(size_t i = 0; i < MAXIND; ++i)
        a[i] = i*i;

    a[17] = -a[17];  /* make a[17] negative */

    printf("First negative integer found at index = %zu\n",
        find_neg(a, MAXIND));

    return 0;
}