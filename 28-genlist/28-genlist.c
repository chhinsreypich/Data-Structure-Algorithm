#include <ctype.h> /* for isspace */
#include <stdio.h>
#include <stdlib.h>

#include "28-genlist.h"

/* helper functions: not part of the interface */
static glnode *genlist_do_parse(char **pp);
static glnode *genlist_shallow_reverse(glnode *p);

/* inserts n at front of list */
glnode *genlist_insert(glnode *n, glnode *list)
{
  n->next = list;
  return n;
}

/* append n to list */
glnode *genlist_append(glnode *n, glnode *list)
{
  if (list == NULL)
    return genlist_insert(n, list);

  n->next = NULL;

  /* find last node */
  glnode *last = list;
  while (last->next != NULL)
    last = last->next;

  /* append new node to list */
  last->next = n;

  return list;
}

void genlist_print(glnode *p)
{
  glnode *q; /* points to successive nodes of list */

  printf("(");
  q = p;
  while (q != NULL)
  {
    if (q->atom)
      printf("%d", q->subnode.item);
    else
      genlist_print(q->subnode.sublist);
    if (q->next != NULL)
      printf(",");
    q = q->next;
  }
  printf(")");
}

/*
 * parses string into a general linked list;
 * returns start of list;
 * minimal error checking
 */
glnode *genlist_parse_str(char *s)
{
  return genlist_do_parse(&s);
}

/* helper */
static glnode *genlist_do_parse(char **pp)
{

  /* clear whitespace */
  while (isspace(**pp))
    ++(*pp);

  if (**pp != '(')
  {
    fprintf(stderr, "Not a list\n");
    exit(1);
  }

  glnode *list = NULL; /* new general list for this level */

  ++(*pp);

  while (**pp != '\0')
  {
    if (isspace(**pp))
    {
      ++(*pp);
      continue;
    }

    glnode *new = malloc(sizeof(glnode));

    if (**pp == '(')
    {
      new->atom = false;
      new->subnode.sublist = genlist_do_parse(pp);
      list = genlist_append(new, list);
    }
    else
    {
      /* must be an integer */
      char *pc;
      new->atom = true;
      new->subnode.item = strtol(*pp, &pc, 10);
      list = genlist_append(new, list);
      *pp = pc;
    }
  }

  return list;
}

glnode *genlist_concat(glnode *list1, glnode *list2)
{
  if (list1 == NULL)
    return list2;

  // find last element on first list
  glnode *last = list1;
  while (last->next != NULL)
    last = last->next;

  // append second list
  last->next = list2;
  return list1;
}

/* reverses one level of list */
static glnode *genlist_shallow_reverse(glnode *p)
{
  if (p == NULL || p->next == NULL) // base step
    return p;

  glnode *tail = p->next;
  p->next = NULL;
  return genlist_concat(genlist_shallow_reverse(tail), p);
}

glnode *genlist_reverse(glnode *p)
{
  p = genlist_shallow_reverse(p); // base step

  glnode *q = p;
  while (q != NULL)
  {
    if (!q->atom)
      q->subnode.sublist = genlist_reverse(q->subnode.sublist);
    q = q->next;
  }

  return p;
}

glnode *genlist_flatten(glnode *p)
{
  glnode *head = NULL;
  glnode *n;
  while (p != NULL)
  {
    if (p->atom)
    {
      n = malloc(sizeof(glnode));
      *n = *p;
      head = genlist_append(n, head);
    }
    else
    {
      glnode *q = genlist_flatten(p->subnode.sublist);
      head = genlist_concat(head, q);
    }

    p = p->next;
  }
  return head;
}

// #include <ctype.h> /* for isspace */
// #include <stdio.h>
// #include <stdlib.h>

// #include "28-genlist.h"

// /* helper function: not part of the interface */
// static glnode *genlist_do_parse(char **pp);

// /* inserts n at front of list */
// glnode *genlist_insert(glnode *n, glnode *list)
// {
//   n->next = list;
//   return n;
// }

// /* append n to list */
// glnode *genlist_append(glnode *n, glnode *list)
// {
//   if (list == NULL)
//     return genlist_insert(n, list);

//   n->next = NULL;

//   /* find last node */
//   glnode *last = list;
//   while (last->next != NULL)
//     last = last->next;

//   /* append new node to list */
//   last->next = n;

//   return list;
// }

// void genlist_print(glnode *p)
// {
//   glnode *q; /* points to successive nodes of list */

//   printf("(");
//   q = p;
//   while (q != NULL)
//   {
//     if (q->atom)
//       printf("%d", q->subnode.item);
//     else
//       genlist_print(q->subnode.sublist);
//     if (q->next != NULL)
//       printf(",");
//     q = q->next;
//   }
//   printf(")");
// }

// /*
//  * parses string into a general linked list;
//  * returns start of list;
//  * minimal error checking
//  */
// glnode *genlist_parse_str(char *s)
// {
//   return genlist_do_parse(&s);
// }

// /* helper */
// static glnode *genlist_do_parse(char **pp)
// {

//   /* clear whitespace */
//   while (isspace(**pp))
//     ++(*pp);

//   if (**pp != '(')
//   {
//     fprintf(stderr, "Not a list\n");
//     exit(1);
//   }

//   glnode *list = NULL; /* new general list for this level */

//   ++(*pp);

//   while (**pp != '\0')
//   {
//     if (isspace(**pp))
//     {
//       ++(*pp);
//       continue;
//     }

//     glnode *new = malloc(sizeof(glnode));

//     if (**pp == '(')
//     {
//       new->atom = false;
//       new->subnode.sublist = genlist_do_parse(pp);
//       list = genlist_append(new, list);
//     }
//     else if (**pp == ',')
//     {
//       ++(*pp);
//     }
//     else if (**pp == ')')
//     {
//       ++(*pp);
//       return list;
//     }
//     else
//     {
//       /* must be an integer */
//       char *pc;
//       new->atom = true;
//       new->subnode.item = strtol(*pp, &pc, 10);
//       list = genlist_append(new, list);
//       *pp = pc;
//     }
//   }

//   return list;
// }