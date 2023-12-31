#include <io_utils.h>
#include <string.h>

void SwapString(char **first, char **second) {
  char *temp = *first;
  *first = *second;
  *second = temp;
}

char **Partition(char **low, char **high) {
  char *pivot = *(low + (high - low) / 2);
  char **p = low;
  char **q = high;

  while (p < q) {
    while (strcmp(*p, pivot) < 0) p++;
    while (strcmp(*q, pivot) > 0) q--;
    if (p < q) SwapString(p, q);
  }

  return q;
}

void QuickSort(char **low, char **high) {
  if (low >= high) return;
  char **partition = Partition(low, high);
  QuickSort(low, partition - 1);
  QuickSort(partition + 1, high);
}

int main() {
  char *string = "Hello World!";
  PRINT_INT((int)strlen(string));
  //PRINT_INT(strnlen_s(string, 100)); // C11, msvc
  //PRINT_INT(strnlen(string, 100)); // gcc

  char *left = "Hello World!";
  char *right = "Hello C Programmers!";

  PRINT_INT(strcmp(left, right));
  PRINT_INT(strncmp(left, right, 5));

  char* names[] = {
      "Zero",
      "Cam",
      "Shingo",
      "Alyssa",
      "Eva",
      "Morty",
      "Rick",
      "Bryce",
      "Abed",
      "KFC"
  };

  QuickSort(names, names + 9);
  PRINT_ARRAY("%s, ", names, 10);
  return 0;
}
