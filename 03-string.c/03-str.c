#include <stdio.h>
#include <string.h>

size_t mystrlen(const char s[]);

int main(void)
{
    char msg[] = "hello";

    printf("%s\n", msg);
    msg[0] = 'H';
    printf("%s\n", msg);

    printf("%zu\n", strlen(msg));
    printf("%zu\n", mystrlen(msg));

    return 0;
}

size_t mystrlen(const char s[])
{
    size_t j;
    for (j = 0; s[j] != '\0'; ++j)
        ;
    return j;
}
