#include <io_utils.h>
#include <string.h>
#include <stdlib.h>

int main() {
//  memchr()
//  strchr()

//  memcmp()
//  strcmp()

  //memset()
  int *mem = malloc(10 * sizeof(int));
  memset(mem, 0x3f, 10 * sizeof(int));

  PRINT_INT_ARRAY(mem, 10);
  free(mem);

  //memcpy
  //strcpy

  //memmove()
  char src[] = "HelloWorld";
  char *dest = malloc(11);
  memset(dest, 0, 11);
  memcpy(dest, src, 11);
  puts(dest);
  memmove(dest, dest + 1, 9);
  puts(dest);
  free(dest);
  return 0;
}
