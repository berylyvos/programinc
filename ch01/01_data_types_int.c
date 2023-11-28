#include <stdio.h>
#include <limits.h>

int main() {
  short short_int = 0;
  int i = 100;
  long long_int = 0;

  long long longlong_int = 0;

  unsigned int unsigned_int = 123;

  unsigned long unsigned_long = 111;

  printf("short int %d\n", short_int);
  printf("int in hex: %x\n", i);

  // d = decimal
  // x = hex
  // o = oct
  // hd%: short decimal
  // %d: decimal
  // %ld: long decimal
  // %lld: long long decimal
  // %hu: unsigned short decimal
  // \n: new line
  // size_t
  printf("short int: %lu\n", sizeof(short int));
  printf("int: %lu\n", sizeof(int));
  printf("long int: %lu\n", sizeof(long int));
  printf("long long: %lu\n", sizeof(long long int));

  printf("max int %d, min %d\n", INT_MAX, INT_MIN);
  printf("max long %ld, min %ld\n", LONG_MAX, LONG_MIN);
  printf("unsigned max int %u, unsigned min %d\n", UINT_MAX, 0);
  return 0;
}