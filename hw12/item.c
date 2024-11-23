#include <stdio.h>
#include <string.h> /// for strcmp
#include "item.h"

/*
 * return <0, >0, ==0 according to whether
 *   i has smaller, bigger, or same prio as j
 */
int itemcmp(char *i, char *j) // change to char*
{
  return strcmp(i, j); /// use strcmp
}

void print_arr(char *a[], size_t n) // change to char*
{
  for (size_t i = 0; i < n; ++i)
    printf("%s ", a[i]); // change to %s
}