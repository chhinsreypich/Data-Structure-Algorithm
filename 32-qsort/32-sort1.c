#include <stdio.h>
#include <stdlib.h>

#define MAXARR 1000

/* get integers into array; return number of items read */
size_t get_data(int *a)
{
    int m;    /* return status of scanf */
    size_t i;

    printf("Enter integers, followed by EOF to finish: \n");
    for (i = 0; (m = scanf("%d", &a[i])) != EOF && m == 1; ++i)
        ;

    return i;
}

/* print array */
void print_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

int cmp(const void *x, const void *y)
{
    return *(const int *)x - *(const int *)y;
}

int main(void)
{
    int data[MAXARR];
    size_t sz;

    sz = get_data(data);

    printf("\noriginal array:\n\t");
    print_arr(data, sz);
    putchar('\n');

    qsort(data, sz, sizeof(int), cmp);
    printf("\nsorted array:\n\t");
    print_arr(data, sz);
    putchar('\n');

    return 0;
}