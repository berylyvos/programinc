#include <stdio.h>

/**
 * Tower of Hanoi
 * @param n   The count of plates.
 * @param src The source of the plates to move from.
 * @param dst The destination of the plates to move to.
 * @param tmp The temporary place to use.
 */
void Move(int n, char src, char dst, char tmp) {
  if (n == 0) return;
  else if (n == 1) printf("%c --> %c\n", src, dst);
  else {
    Move(n - 1, src, tmp, dst);
    Move(1, src, dst, tmp);
    Move(n - 1, tmp, dst, src);
  }
}

int main(void) {
  Move(4, 'A', 'C', 'B');

  return 0;
}