#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quicksort.h"

static size_t partition(char *a[], size_t left, size_t right); // change to char*
static void swap(char *a[], size_t i, size_t j);               // change to char*

/* sort subarray a[left:right] in ascending order */
void quicksort(char *a[], size_t left, size_t right) // change to char*
{
  /* base step */
  if (left >= right)
    return;
  size_t p = partition(a, left, right);

  /* careful: p is unsigned */
  if (p > 0)
  {
    quicksort(a, left, p - 1);
  }

  quicksort(a, p + 1, right);
}

static void swap(char *a[], size_t i, size_t j) // change to char*
{
  char *temp = a[i]; // change to char*
  a[i] = a[j];
  a[j] = temp;
}

size_t partition(char *a[], size_t left, size_t right)
{
  char *pivot = a[right]; // change to char*
  size_t i = left;        /* temporary index of pivot */

  for (size_t j = left; j < right; ++j)
  {
    if (itemcmp(a[j], pivot) <= 0)
    {
      swap(a, i, j);
      ++i;
    }
  }
  swap(a, i, right);

  return i;
}