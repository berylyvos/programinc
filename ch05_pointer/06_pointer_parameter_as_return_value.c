#include <stdio.h>
#include <io_utils.h>

int SumIntArray(const int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  return sum;
}

void SumIntArray2(const int array[], int length, int *sum) {
  *sum = 0;
  for (int i = 0; i < length; ++i) {
    *sum += array[i];
  }
}

__int128 TestBigValue() {
  return (__int128)1 << 126;
}

void PrintInt128(__int128 x)
{
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) PrintInt128(x / 10);
  putchar(x % 10 + '0');
}

typedef struct {
  char *name;
  int gender;
  int age;
  char *school;
} Student;

Student TestStruct() {
  Student student = {"shingo", 1, 30, "jxufe"};
  return student;
}

int main() {
  int array[] = {0, 1, 2, 3, 4};
  int sum = SumIntArray(array, 5);
  int sum2;
  SumIntArray2(array, 5, &sum2);

  PRINT_INT(sum);
  PRINT_INT(sum2);

  __int128 big_int = TestBigValue();
  PrintInt128(big_int * 2 - 1); // 170141183460469231731687303715884105727

  Student student = TestStruct();
  return 0;
}
