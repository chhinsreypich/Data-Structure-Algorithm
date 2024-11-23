/*
 * rev.c: functions that reverse an array
 */

#include <stdio.h>

/* reverse array using indices */
void reverse(int a[], size_t n)
{
    for (size_t i = 0, j = n - 1; i < j; ++i, --j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

/* same thing, but using pointers */
void reverse2(int *left, size_t n)
{
    for (int *right = left + n - 1; left < right; ++left, --right) {
        int temp = *left;
        *left = *right;
        *right = temp;
    }
}

void print_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    putchar('\n');
}

int main(void)
{
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {10, 20, 30, 40, 50};

    size_t lenb = sizeof(b)/sizeof(int),
           lenc = sizeof(c)/sizeof(int);

    print_arr(b, lenb);
    reverse(b, lenb);
    print_arr(b, lenb);

    print_arr(c, lenc);
    reverse2(c, lenc);
    print_arr(c, lenc);

    return 0;
}