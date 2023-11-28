#include <io_utils.h>
#include <stdlib.h>
#include <errno.h>

int main() {
//  PRINT_INT(atoi("1234")); // 1234
//  PRINT_INT(atoi("-1234")); // -1234
//  PRINT_INT(atoi("   1234abcd")); // 1234
//  PRINT_INT(atoi("0x10")); // 0
//
//  PRINT_DOUBLE(atof("12.34")); // 12.34
//  PRINT_DOUBLE(atof("-12e34")); // -1.2e+35
//  PRINT_DOUBLE(atof("   1.234abcd")); // 1.234
//  PRINT_DOUBLE(atof("0x10")); // 16
//  PRINT_DOUBLE(atof("0x10p3.9")); // 128

  const char *const kInput = "1 200000000000000000000000000000 7fffffff 80000000 5abcd bye#@!$*&^%";
  PRINTLNF("Parse: %s", kInput);

  const char *start = kInput;
  char *end;

  while (1) {
    errno = 0;

    const long i = strtol(start, &end, 16);

    if (start == end) {
      break;
    }

    printf("'%.*s'\t ==> %ld", (int)(end - start), start, i);

    if (errno == ERANGE) {
      perror("");
    }

    putchar('\n');
    start = end;
  }

  PRINTLNF("Left: %s", end);
  return 0;
}
