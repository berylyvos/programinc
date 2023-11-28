#include <io_utils.h>
#include <string.h>

int main() {
  const char *src = "HelloWorld";
  char dst[20] = "C said: ";
  strcat(dst, src);
  strcpy(dst + strlen(dst), "xx");
  puts(dst);
  return 0;
}
