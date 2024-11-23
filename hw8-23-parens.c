#define BUF_SIZE 1024 /* size of input string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hw8-23-stack.h" /* itemtype is char */

bool match(char c, char d)
{
    return c == d;
}

bool is_valid(char *s)
{
    stack *sp = stack_initialize();
    size_t n = strlen(s);
    char c, d;

    for (size_t i = 0; i < n; ++i)
    {
        d = s[i];

        if (d == 'a' || d == 'b' || d == 'c')
        {
            if (!stack_is_full(sp))
                stack_push(d, sp);
        }
        else if (d == 'm')
        {
            if (stack_is_empty(sp))
            {
                printf("Please input a b c before m.\n");
                return false;
            }
            for (int j = i + 1; j < n; j++)
            {
                d = s[j];
                c = stack_pop(sp);
                if (d == 'm')
                {
                    printf("%s (more than one m)\n", s);
                    return false;;
                }
                if (!match(c, d))
                {
                    printf("%s (illegal char)\n", s);
                    return false;
                }
            }
            break;
        }
        else
        {
            printf("illegal input. Try again! (input only a b and c)\n");
            return false;
        }
    } // end for loop

    if (stack_is_empty(sp))
    {
        printf("%s is valid\n", s);
        return true;
    }
    else
    {
        printf("%s is not valid\n", s);
        return false;
    }
}

int main(void)
{
    char buf[BUF_SIZE];

    printf("Give input a b c and m without newlines: ");
    if (fgets(buf, sizeof(buf), stdin) != NULL)
        buf[strcspn(buf, "\n")] = '\0';

    is_valid(buf);

    return 0;
}