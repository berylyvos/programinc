#include <stdio.h>
#include <io_utils.h>
#include <errno.h>
#include <string.h>

void ReadFile() {
  FILE *file = fopen("CMakeLists.txt", "r");
  if (file) {
    char buffer[BUFSIZ];
    char *next;
    while (next = fgets(buffer, BUFSIZ, file)) {
      PRINT_HEX(next);
      PRINT_HEX(buffer);
      printf("%s", buffer);
    }
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }
}

void Echo() {
  char buffer[4];
  while (1) {
    if (!fgets(buffer, 4, stdin)) {
      break;
    }
    //puts(buffer);
    printf("%s", buffer);
  }
}

int main() {
  //Echo();
  ReadFile();
  return 0;
}
