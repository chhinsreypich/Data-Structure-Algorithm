
#include <ctype.h> //for isspace
#include <stdio.h>
#include <stdlib.h>
#include "29-tree.h"

static void visit(tnode *t);

static tnode *tree_do_parse(char **pp);

void traverse(tnode *t, t_order to)
{
  if (t == NULL)
    return;

  if (to == PREORDER)
  {
    visit(t);
    traverse(t->left, to);
    traverse(t->right, to);
  }
  else if (to == INORDER)
  {
    traverse(t->left, to);
    visit(t);
    traverse(t->right, to);
  }
  else if (to == POSTORDER)
  {
    traverse(t->left, to);
    traverse(t->right, to);
    visit(t);
  }
}

static void visit(tnode *t)
{
  printf("%c ", t->symbol);
}

tnode *buildTree(char s)
{

  tnode *node = malloc(sizeof(tnode));
  if (node != NULL)

  {
    node->symbol = s;
    node->left = NULL;
    node->right = NULL;
  }

  return node;
}

tnode *tree_parse(char *s)
{
  return tree_do_parse(&s);
}

static tnode *tree_do_parse(char **pp)
{

  while (isspace(**pp))
    ++(*pp);
  // if (**pp != '+' || **pp != '*' || **pp != '/' || **pp != '-' || **pp != '^')
  // {
  //   fprintf(stderr, "Not a tree list\n");
  //   exit(1);
  // }

  char *n = *pp;
  char q = *n;
  ++(*pp);

  tnode *root = NULL;
  // root = buildTree(q);

  if (q == '+' || q == '*' || q == '/' || q == '-' || q == '^')
  {
    tnode *new = malloc(sizeof(tnode));

    new->symbol = q;
    new->left = NULL;
    new->right = NULL;
    root->left = tree_do_parse(pp);
    root->right = tree_do_parse(pp);
  }

  return root;
}
