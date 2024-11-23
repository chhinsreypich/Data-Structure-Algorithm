#include <stdio.h>
#include <stdlib.h>

size_t partition(int a[], size_t left, size_t right);
void print_arr(int a[], size_t n);

/* sort subarray a[left:right] in ascending order */
void quicksort(int a[], size_t left, size_t right)
{
    /* base step */
    if (left >= right)
        return;

    size_t p = partition(a, left, right);

    /* careful: p is unsigned */
    if (p > 0)
    {
        quicksort(a, left, p - 1);
    }

    quicksort(a, p + 1, right);
}

void swap(int a[], size_t i, size_t j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

size_t partition(int a[], size_t left, size_t right)
{
    int pivot = a[right];
    size_t i = left; /* temporary index of pivot */

    for (size_t j = left; j < right; ++j)
    {
        if (a[j] <= pivot)
        {
            swap(a, i, j);
            ++i;
        }
    }
    swap(a, i, right);

    return i;
}

void print_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

int main(void)
{
    int arr[] = {10, -1, 5, 8, -17, 0};
    size_t sz = sizeof(arr) / sizeof(int);

    print_arr(arr, sz);
    putchar('\n');

    quicksort(arr, 0, sz - 1);

    print_arr(arr, sz);
    putchar('\n');

    return 0;
}