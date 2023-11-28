#include <io_utils.h>
#include <string.h>

int main() {
  char *string = "Hello World!";
  char *result = strchr(string, 'l');
  char *result_reverse = strrchr(string, 'l');
  puts(result);
  puts(result_reverse);

  char *substr_pos = strstr(string,"or");
  puts(substr_pos);
  PRINT_INT((int)(substr_pos - string));


  char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
  char *break_set = ",;";

  int count = 0;
  char *p = string2;

  do {
    p = strpbrk(p, break_set);
    if (p) {
      puts(p);
      p++;
      count++;
    }
  } while (p);

  PRINTLNF("Found %d characters.", count);
  return 0;
}
