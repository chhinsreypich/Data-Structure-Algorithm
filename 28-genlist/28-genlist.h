#ifndef GENLIST_H
#define GENLIST_H

#include "28-genlisttypes.h"

void genlist_print(glnode *p);
glnode *genlist_parse_str(char *s);
glnode *genlist_insert(glnode *n, glnode *list);
glnode *genlist_append(glnode *n, glnode *list);
glnode *genlist_concat(glnode *list1, glnode *list2);
glnode *genlist_reverse(glnode *p);
glnode *genlist_flatten(glnode *p);


#endif