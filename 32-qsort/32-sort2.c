#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARR 1000
#define MAXWORD 1000

/* get words into array; return number of items read */
size_t get_data(char **a)
{
    int m;    /* return status of scanf */
    size_t i;
    char word[MAXWORD+1];

    printf("Enter words, followed by EOF to finish: \n");
    for (i = 0; (m = scanf("%1000s", word)) != EOF && m == 1; ++i) {
        a[i] = malloc(strlen(word) + 1);
        strcpy(a[i], word); /* dangerous? */
    }

    return i;
}

/* print array */
void print_arr(char *a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%s ", a[i]);
}

int cmp(const void *x, const void *y)
{
    return strcmp(*(const char **)x, *(const char **)y);
}

int main(void)
{
    char *data[MAXARR];
    size_t sz;

    sz = get_data(data);

    printf("\noriginal array:\n\t");
    print_arr(data, sz);
    putchar('\n');

    qsort(data, sz, sizeof(char *), cmp);
    printf("\nsorted array:\n\t");
    print_arr(data, sz);
    putchar('\n');

    return 0;
}