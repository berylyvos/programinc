#include <stdio.h>
#include <io_utils.h>

int main() {
  int a;
  scanf("%d", &a);

  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT((int)sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  PRINT_HEX(pp);
  // *pp => p;
  PRINT_HEX(*pp);
  PRINT_INT(**pp);

  return 0;
}