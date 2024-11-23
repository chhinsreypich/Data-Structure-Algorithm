#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("bool: %zu\n", sizeof(bool));
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));

    putchar('\n');
    printf("int [3]: %zu\n", sizeof(int [3]));

    return 0;
}