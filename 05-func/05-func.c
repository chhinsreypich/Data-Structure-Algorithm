/*
 * 05-func.c:
 *
 * illustrates the fact that in C,
 * functions are called by value
 */

#include <stdio.h>

void f(int j)
{
    ++j;
    printf("%s: j = %d\n", __func__, j);
}

int main(void)
{
    int j = 10;

    printf("%s: before call to f: j = %d\n", __func__, j);
    f(j);
    printf("%s: after call to f: j = %d\n", __func__, j);

    return 0;
}