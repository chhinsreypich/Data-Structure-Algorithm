#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quicksort.h"

#define MAXARRAY 1000

size_t get_data(char *a[]) // change pointer to int into pointer to array of char
{
  size_t i = 0;
  char word[MAXARRAY]; // new variable

  printf("Enter integers, followed by EOF to finish: \n");
  for (i = 0; i < MAXARRAY && fgets(word, sizeof(word), stdin) != NULL; ++i)
  {
    a[i] = malloc(sizeof(word));
    word[strcspn(word, "\n")] = '\0';

    strncpy(a[i], word, strlen(word)); /// copy
    a[i][strlen(word)] = '\0';         // add null char
  }
  return i;
}

int main(void)
{
  char *data[MAXARRAY]; // change to char*
  size_t sz;

  sz = get_data(data);

  printf("\noriginal array:\n\t");
  print_arr(data, sz);
  putchar('\n');

  quicksort(data, 0, sz - 1);
  printf("\nsorted array:\n\t");
  print_arr(data, sz);
  putchar('\n');

  return 0;
}