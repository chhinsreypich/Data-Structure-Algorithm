#include <stdio.h>

#define SOMEVAL 5 // macro definition

int j = SOMEVAL; // global variable

void f(void);
void g(int, int);

int main(void)
{
  ++j;
  f();
  printf("%s: j = %d\n", __func__, j); // __func__ is a predefined macro

  /*
   * for more predefined macros, see:
   *   https://en.cppreference.com/w/c/preprocessor/replace#Predefined_macros
   */

  return 0;
}

void f(void)
{
  int n = 10;
  ++j;
  g(n, j);
  printf("%s: n = %d, j = %d\n", __func__, n, j);
}

void g(int n, int j)
{
  ++n;
  ++j;
  printf("%s: n = %d, j = %d\n", __func__, n, j);
}