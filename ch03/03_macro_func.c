#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

#define IS_HEX_CHARACTER(ch) \
  ((ch) >= '0' && (ch) <= '9') || \
  ((ch) >= 'A' && (ch) <= 'F') || \
  ((ch) >= 'a' && (ch) <= 'f')

int Max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int max = MAX(1.0, 3);
  int max2 = MAX(1, MAX(3, 4));
  printf("max: %d\n", max);
  printf("max2: %d\n", max2);

  int max3 = Max(1, Max(3, 4));
  printf("max3: %d\n", max3);

  int max4 = MAX(max3++, 1); // (max3++) > (1) ? (max3++) : (1)
  printf("max3: %d\n", max3);
  printf("max4: %d\n", max4);

  printf("is F a hex character? %d\n", IS_HEX_CHARACTER('F'));
  return 0;
}
