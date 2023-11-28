#include <stdio.h>
#include <io_utils.h>
#include <stddef.h>
//#pragma pack(2)

int main() {
  typedef struct {
    char a; // 1
    char b; // 1
    // __attribute((aligned(2))) int c; // 4 gcc only
    _Alignas(8) int c; // 4 c11
    short d; // 2
    double e; // 8
  } Align;

  typedef struct {
    char a; // 1
    char b; // 1
    short d; // 2
    int c; // 4
    double e; // 8
  } OptimizedAlign;

  Align align = {'a', 'b', 3, 4, 5.0};
  OptimizedAlign optimized_align = {'a', 'b', 3, 4, 5.0};
  PRINT_INT((int)sizeof(align));
  PRINT_INT((int)sizeof(optimized_align));

  PRINT_INT((int)_Alignof(align.c));
  PRINT_INT((int)offsetof(Align, e));

  return 0;
}
