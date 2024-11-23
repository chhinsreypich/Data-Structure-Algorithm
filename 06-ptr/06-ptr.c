/*
 * 06-ptr.c:
 *
 * illustrates function modifying variable
 * through a pointer
 */

#include <stdio.h>

void f(int *p)
{
    ++*p;
}

int main(void)
{
    int j = 10;

    f(&j);
    printf("j: %d\n", j);

    return 0;
}