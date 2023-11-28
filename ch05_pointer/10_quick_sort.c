#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io_utils.h>

void SwapInt(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Shuffle(int *array, int length) {
  srand(time(NULL));

  for (int i = length - 1; i > 0; --i) {
    int k = rand() % (i + 1);
    SwapInt(array + i, array + k);
  }
}

int *Partition(int *low, int *high) {
  int pivot = *(low + (high - low) / 2);
  int *p = low - 1, *q = high + 1;

  while (p < q) {
    while (*++p < pivot);
    while (*--q > pivot);
    if (p < q) SwapInt(p, q);
  }

  return q;
}

void QuickSort(int *low, int *high) {
  if (low >= high) return;
  int *partition = Partition(low, high);
  QuickSort(low, partition);
  QuickSort(partition + 1, high);
}

#define PLAYER_COUNT 100

int main() {
  int *players = malloc(sizeof(int) * PLAYER_COUNT);
  if (!players) {
    return 1;
  }
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players[i] = i;
  }
  Shuffle(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  QuickSort(players, players + PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  free(players);

  return 0;
}
