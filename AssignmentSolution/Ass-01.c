
/*
    In 04-find neg.c, comment out the line makes a[17] negative.
    What output do you expect the compiled program to give? What is the actual output?
    Where is the problem?
    Upload a .c file containing the fix.
    Suggestion: If you are on a Unix system, you may use
    ssize_t instead of size t, but in general you can use ptrdiff_t.
*/

#include <stdio.h>
#include <stddef.h> // for ptrdiff_t
#include <stdint.h> // for PTRDIFF_MAX

#define MAXIND 100

/*
 * return the first index containing negative value, or -1.
 *
 * constraint: only checks the first PTRDIFF_MAX entries
 *             of arr.
 *
 * see: https://en.cppreference.com/w/c/types/ptrdiff_t
 */
ptrdiff_t find_neg(int arr[], size_t n)
{
    // n = min(n, PTRDIFF_MAX)
    n = (n > PTRDIFF_MAX) ? PTRDIFF_MAX : n;

    for (size_t j = 0; j < n; ++j)
        if (arr[j] < 0)
            return j;

    return -1;
}

int main(void)
{
    int a[MAXIND];

    /* initialize array to squares of integers */
    for (size_t i = 0; i < MAXIND; ++i)
        a[i] = i * i;

    // a[17] = -a[17];  /* make a[17] negative */

    printf("First negative integer found at index = %td\n",
           find_neg(a, MAXIND));

    return 0;
}