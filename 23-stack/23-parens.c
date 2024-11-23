/*
 * parens.c: checks for balanced
 *     brackets -- (,[,{  -- using a stack
 */

#define BUF_SIZE 1024 /* size of input string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "23-stack.h" /* itemtype is char */

/* returns true iff c and d are matching pairs of parens*/
bool match(char c, char d)
{
  bool ret;

  switch (c)
  {
  case '(':
    ret = (d == ')');
    break;
  case '[':
    ret = (d == ']');
    break;
  case '{':
    ret = (d == '}');
    break;
  default:
    ret = false;
    break;
  }

  return ret;
}

/* prints whether the input expression is balanced */
void parensmatch(char *inputexp)
{
  stack *sp = stack_initialize();
  size_t n = strlen(inputexp);
  char c, d;

  for (size_t i = 0; i < strlen(inputexp); ++i)
  {
    d = inputexp[i];
    if (d == '(' || d == '[' || d == '{')
    {
      if (!stack_is_full(sp))
        stack_push(d, sp);
    }
    else if (d == ')' || d == ']' || d == '}')
    {
      if (stack_is_empty(sp))
      {
        printf("More right than left parentheses\n");
        return;
      }
      else
      {
        c = stack_pop(sp);
        if (!match(c, d))
        {
          printf("Mismatched parentheses: %c and %c\n", c, d);
          return;
        }
      }
    }
  } // end for loop

  if (stack_is_empty(sp))
    printf("Parentheses are balanced\n");
  else
    printf("More left than right parentheses\n");
}

int main(void)
{
  char buf[BUF_SIZE];

  printf("Give input expression without newlines: ");
  if (fgets(buf, sizeof(buf), stdin) != NULL)
    buf[strcspn(buf, "\n")] = '\0';

  parensmatch(buf);

  return 0;
}