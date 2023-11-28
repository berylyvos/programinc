#include <stdio.h>
#include <io_utils.h>
#include <errno.h>
#include <string.h>

int main() {
  FILE *file = fopen("CMakeLists.txt", "r");
  PRINT_INT((int)sizeof(FILE));
  if (file) {
    //...
    puts("Open successfully.");
    int err = ferror(file);
    PRINT_INT(err);
    int eof = feof(file);
    PRINT_INT(eof);
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }

  for (int i = 0; i < 10; ++i) {
    PRINT_INT(i);
    puts(strerror(i));
  }
  int x = 2147483647;
  PRINT_INT(31 - __builtin_clz(x));
  for (int i = 30; ~i; --i)
    if (x >> i & 1) {
      PRINT_INT(i);
      break;
    }

  stdout;
  stderr;
  stdin;
  return 0;
}
