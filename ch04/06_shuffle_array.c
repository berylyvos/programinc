#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io_utils.h"

#define PLAYER_COUNT 20

void SwapElements(int array[], int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArray(int array[], int length) {
  srand(time(NULL));
  //[0, RAND_MAX]
  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % (i + 1);
    SwapElements(array, i, random_number);
  }
}

int main() {
  int players[PLAYER_COUNT];
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players[i] = i;
  }
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  ShuffleArray(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  return 0;
}
