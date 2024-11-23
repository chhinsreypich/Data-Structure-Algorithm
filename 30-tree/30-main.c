#include <string.h>
#include <stdio.h>
#include "30-tree.h"

/* word frequency count: K&R Chap 6 */
int main(void)
{
    char word[MAXWORD+1];
    tnode *root = NULL;

    while (scanf("%100s", word) != EOF)
        root = addtree(root, word);
    treeprint(root);

    // printf("the output is: %zu", root->count);
    return 0;
}