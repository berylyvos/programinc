#include <stdio.h>
#include <io_utils.h>

int *pointer_at_large;

void DangerousPointer() {
  int a = 2;
  pointer_at_large = &a;
  // ...

  // pointer_at_large = NULL;
}

int main() {
//  int *p = (int *)0x6fb36ea0; // DANGEROUS !!!
//  PRINT_INT(p);
//  PRINT_HEX(&p);
//  PRINT_INT(*p);

  int *p = NULL;
  //*p = 3; // error!!

  DangerousPointer();
  if (pointer_at_large) {
    PRINT_INT(*pointer_at_large);
  }

  return 0;
}
