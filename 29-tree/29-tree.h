
#ifndef TREE_H
#define TREE_H
#define MAXWORD 100
typedef struct tnode
{
  char symbol;  
  struct tnode *left;
  struct tnode *right;
} tnode;

typedef enum
{
  PREORDER,
  POSTORDER,
  INORDER
} t_order;

void traverse(tnode *t, t_order to);
tnode *tree_parse(char *s);
tnode *buildTree(char tt);
tnode *addtree(tnode *p, char *w);
#endif