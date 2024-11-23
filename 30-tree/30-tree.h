#ifndef TREE_H
#define TREE_H
#define MAXWORD 10

typedef struct tnode
{
  char *word;
  size_t count;
  struct tnode *left;
  struct tnode *right;
} tnode;

tnode *addtree(tnode *p, char *w);
void treeprint(tnode *p);
#endif