/*
 * dyn-mem.c:
 *  illustrates dynamic memory manipulation
 */

#include <stdio.h>
#include <stdlib.h> // for malloc(), free()

int *f(int n)
{
    int *p = malloc(sizeof(int));

    *p = n;
    return p;
}

int main(void)
{
    int *q = f(10);

    printf("%d\n", *q);
    free(q);

    return 0;
}