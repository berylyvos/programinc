#include <io_utils.h>

typedef enum FileFormat {
  PNG, JPEG = 10, BMP = 20, WEBP, UNKNOWN
} FileFormat;

FileFormat GuessFormat(char *file_path) {
  FILE *file = fopen(file_path, "r");
  FileFormat file_format = UNKNOWN;
  if (file) {
    char buffer[8] = {0};
    size_t bytes_count = fread(buffer, 1, 8, file);
    if (bytes_count == 8) {
      // bmp: 42 4D
      // png: 89 50 4E 47 0D 0A 1A 0A
      // jpeg: FF D8 FF E0
      // webp: 52 49 46 46
      if (*((short *) buffer) == 0x4D42) {
        file_format = BMP;
      } else if (*((long long *) buffer) == 0x0A1A0A0D474E5089) {
        file_format = PNG;
      } else if (*((int *) buffer) == 0xE0FFD8FF) {
        file_format = JPEG;
      } else if (*((int *) buffer) == 0x46464952) {
        file_format = WEBP;
      }
    }
    fclose(file);
  }
  return file_format;
}

int main() {
  PRINT_INT(GuessFormat("images/c.png"));
  PRINT_INT(GuessFormat("images/c.jpeg"));
  PRINT_INT(GuessFormat("images/c.bmp"));
  PRINT_INT(GuessFormat("images/c.webp"));

  return 0;
}
