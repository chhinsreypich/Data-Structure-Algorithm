
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "29-tree.h"

int main(void)
{

  char word[MAXWORD];
  tnode *root;

  printf("Give a prefix expression without a newline: ");
  if (fgets(word, sizeof(word), stdin) != NULL)
    word[strcspn(word, "\n")] = '\0';

  root = tree_parse(word);

  printf("Pre-order: ");
  traverse(root, PREORDER);
  putchar('\n');

  printf("In-order: ");
  traverse(root, INORDER);
  putchar('\n');
  printf("Post-order: ");
  traverse(root, POSTORDER);
  putchar('\n');
  return 0;
}
