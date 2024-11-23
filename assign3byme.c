#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 3 // airport code len
struct node *head = NULL;
struct node
{
  char code[LEN + 1];
  struct node *next;
};
void list_insert(char *s, struct node **start);
void list_print(struct node *p);
int main(void)
{

  list_insert("BKK", &head);
  list_insert("PNH", &head);
  list_insert("SGN", &head);
  list_print(head);
  return 0;
}
/* insert node at beginning of list */
void list_insert(char *s, struct node **start)
{
  // missing code goes here
  struct node *n = malloc(sizeof(struct node));
  // cannot execute with strlcpy
  strncpy (n->code, s, LEN+1);

  n->next = head;
  head = n;
  
}
void list_print(struct node *p)
{
  while (p != NULL)
  {
    printf("%s\n", p->code);
    p = p->next;
  }
}