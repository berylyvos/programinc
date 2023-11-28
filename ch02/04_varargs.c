#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...) {
  // 1. 定义 va_list 用于获取我们变长参数
  va_list args;

  // 2. 开始遍历
  va_start(args, arg_count);
  for (int i = 0; i < arg_count; ++i) {
    // 3. 取出对应参数，(va_list, type)
    const char* arg = va_arg(args, const char*);
    printf("%d: %s\n", i, arg);
  }

  // 4. 结束遍历
  va_end(args);
}

int main(void) {
  printf("Hello World\n");

  HandleVarargs(10, "sad", "what's the pointer?", "");
  return 0;
}