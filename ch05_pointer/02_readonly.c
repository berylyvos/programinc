#include <stdio.h>
#include <io_utils.h>

int main() {
  int a;
  int b;
  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT((int)sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  // *pp => p;

  *p = 20;
  PRINT_INT(*p);
  PRINT_INT(a);

  int *const cp = &a;
  *cp = 2; // OK
  // cp = &b; ERROR
  const int* cp2 = &a;
  // *cp2 = 2; ERROR
  cp2 = &b; // OK

  const int *const ccp = &a;
  // ccp = &b; ERROR
  // *ccp = 2; ERROR
  return 0;
}
