/* 
 * fptr1.c:
 *   calling a function through a pointer
 */

#include <stdio.h>

int f(int n)
{
    return n * n;
}

int main(void)
{
    int (*pf)(int) = f;

    printf("%d\n", pf(3));
    return 0;
}