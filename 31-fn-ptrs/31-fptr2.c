/*
 * fptr2.c:
 *   passing a function to a function
 */

#include <stdio.h>

/* evaluates a function at the given point */
int eval(int (*pf)(int), int point)
{
    return pf(point);
}

int f(int n)
{
    return n * n;
}

int main(void)
{
    printf("%d\n", eval(f, 5));
}