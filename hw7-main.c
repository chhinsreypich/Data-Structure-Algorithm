// main.c
#include <stdlib.h>
#include <stdio.h>

#include "hw7-item.h"
#include "hw7-sort_alg.h"

#define MAXARRAY 10

void print_arr(itemtype * i);
void print_array(itemtype array[]);

int main(void)
{
    itemtype array[MAXARRAY];
    size_t sz = sizeof(array)/sizeof(itemtype);

    for (size_t i = 0; i < MAXARRAY; i++){
      array[i].x = rand() % 100;
      array[i].y = rand() % 100;
    }

    print_array(array);

    putchar('\n');
    selection_sort(array, 0, sz-1);
    print_array(array);
    //putchar("\n");
    
    return 0;
}

void print_array(itemtype array[]){
  for (int i = 0 ; i < MAXARRAY; i++ ){
      print_arr(&array[i]);

    }
}

void print_arr( itemtype *i)
{
   printf("(%d, %d) ", i->x, i->y);

}