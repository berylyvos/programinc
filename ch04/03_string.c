#include <stdio.h>
#include <wchar.h>
#include "io_utils.h"

int main() {
  char char_arr[11] = "Hello,World";
  char string[] = "Hello,World";

  // NULL \0
  char_arr[11] = 65;
  char_arr[12] = 66;
  PRINTLNF("%s| %lu", char_arr, sizeof(char_arr)); // Hello,WorldAB| 11
  PRINTLNF("%s| %lu", string, sizeof(string)); // Hello,World| 12

  char string_zh[] = "你好，中国";

  PRINTLNF("sizeof(wchar_t): %lu", sizeof(wchar_t)); // 4
  PRINTLNF("sizeof(string_zh): %lu", sizeof(string_zh)); // 16

  wchar_t ws[] = L"你好，中国";
  PRINTLNF("sizeof(ws): %lu", sizeof(ws)); // 6 * 4

  return 0;
}