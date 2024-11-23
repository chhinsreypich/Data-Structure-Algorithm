/*
 * main.c: parses input expression into a general list;
 *   reverses the list recursively; then, prints the
 *   result.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "28-genlist.h"

#define BUF_SIZE 1024

int main(void)
{
    char buf[BUF_SIZE];
    glnode *list;

    printf("Give input expression without newlines: ");
    if (fgets(buf, sizeof(buf), stdin) != NULL)
        buf[strcspn(buf, "\n")] = '\0';

    list = genlist_parse_str(buf);
    genlist_print(list);
    putchar('\n');

    list = genlist_flatten(list);
    genlist_print(list);
    putchar('\n');






    // list = genlist_reverse(list);
    // genlist_print(list);
    // putchar('\n');

    return 0;
}






























// /*
//  * parse.c: parses input expression
//  *   into a general list; then, prints
//  *   the expression from the list
//  *
//  *   See Standish, p. 306
//  */

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "28-genlist.h"

// #define BUF_SIZE 1024

// int main(void)
// {

//   // ///// lesson
//   char buf[BUF_SIZE];
//   glnode *list;

//   printf("Give input expression without newlines: ");
//   if (fgets(buf, sizeof(buf), stdin) != NULL)
//     buf[strcspn(buf, "t")] = '\0';

//   list = genlist_parse_str(buf);
//   genlist_print(list);
//   putchar('\n');

//   return 0;

// }


  // glnode * list;
  // glnode n1, n2, n3, n4, n5, n6;


  // n6.atom = true;
  // n6.subnode.item = 4;
  // n6.next = NULL;

  // n5.atom = true;
  // n5.subnode.item = 3;
  // n5.next = &n6;

  // n4.atom = false;
  // n4.subnode.sublist = &n5;
  // n4.next = NULL;

  // n3.atom = true;
  // n3.subnode.item = 2;
  // n3.next = &n4;

  // n2.atom = false;
  // n2.subnode.sublist = &n3;
  // n2.next = NULL;

  // n1.atom = true;
  // n1.subnode.item = 1;
  // n1.next = &n2;

  // list = &n1;

  // genlist_print(list);





  ///// the above is shorter than

  // glnode * list;
  // glnode n1, n2, n3, n4, n5, n6;

  // n6.atom = true;
  // n6.subnode.item = 4;
  // n6.next = NULL;

  // n5.atom = true;
  // n5.subnode.item = 3;
  // n5.next = &n6;

  // list  = &n5;

  // n4.atom = false;
  // n4.subnode.sublist = list;
  // n4.next = NULL;

  // n3.atom = true;
  // n3.subnode.item = 2;
  // n3.next = &n4;

  // list  = &n3;

  // n2.atom = false;
  // n2.subnode.sublist = list;
  // n2.next = NULL;

  // n1.atom = true;
  // n1.subnode.item = 1;
  // n1.next = &n2;

  // list = &n1;

  // genlist_print(list);



