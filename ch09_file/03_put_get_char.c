#include <stdio.h>
#include <io_utils.h>
#include <errno.h>
#include <string.h>

void ReadFile() {
  FILE *file = fopen("03_put_get_char.c", "r");
  if (file) {
    while (1) {
      int c = getc(file);
      if (c == EOF) break;
      putchar(c);
    }
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }
}

int main() {
//  while (1) {
//    int next_input = getchar();
//    if (next_input == EOF) {
//      break;
//    } else if(next_input == '\n') {
//      continue;
//    }
//    putchar(next_input);
//  }

  ReadFile();

  return 0;
}
