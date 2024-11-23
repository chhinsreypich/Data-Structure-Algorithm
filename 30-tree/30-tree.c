#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "30-tree.h"

tnode *addtree(tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  { /* new word */
    p = malloc(sizeof(tnode));
    p->word = malloc(strnlen(w, MAXWORD) + 1);
    strncpy(p->word, w, MAXWORD);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strncmp(w, p->word, MAXWORD)) == 0)
  {
    p->count++;
  }
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);

  return p;
}

void treeprint(tnode *p)
{
  if (p == NULL)
    return;
  treeprint(p->left);
  printf("%4zu: %s\n", p->count, p->word);
  treeprint(p->right);
}