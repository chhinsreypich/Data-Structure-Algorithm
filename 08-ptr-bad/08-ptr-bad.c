/*
 * ptr-bad.c:
 */

#include <stdio.h>

int *f(void)
{
    int n = 5;

    return &n;
}

int main(void)
{
    int *p = f();

    ++*p;
    printf("%d\n", *p);

    return 0;
}