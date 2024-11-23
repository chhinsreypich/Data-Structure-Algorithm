/*
 * postfix.c: evaluate a postfix expression
 *            using a stack
 */

#define BUF_SIZE 1024 /* size of input string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h" /* itemtype is float */

void interpret_postfix(char *inputexp, stack *sp)
{
  char *current = inputexp; /* current location in string */
  char *next;               /* next location to be processed */
  char c;
  float left, right;

  while (strlen(current) > 0)
  {
    float d = strtof(current, &next);
    if (current < next)
    {
      /* got a float */
      stack_push(d, sp);
      current = next;
    }
    else
    {
      c = *current++;
      if (c == '+' || c == '-' || c == '*' || c == '/')
      {
        right = stack_pop(sp);
        left = stack_pop(sp);
        switch (c)
        {
        case '+':
          stack_push(left + right, sp);
          break;
        case '-':
          stack_push(left - right, sp);
          break;
        case '*':
          stack_push(left * right, sp);
          break;
        case '/':
          stack_push(left / right, sp);
          break;
        }
      }
    } /* else */
  }   /* while */
}

int main(void)
{
  char buf[BUF_SIZE];
  stack *sp = stack_initialize();

  printf("Enter a postfix expression: ");
  if (fgets(buf, sizeof(buf), stdin) != NULL)
    buf[strcspn(buf, "\n")] = '\0';

  interpret_postfix(buf, sp);
  printf("answer: %f\n", stack_pop(sp));

  return 0;
}