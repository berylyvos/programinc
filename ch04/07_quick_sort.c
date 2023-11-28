#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io_utils.h"

#define PLAYER_COUNT 50

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

int Partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int p = low;
  for (int i = low; i < high; ++i) {
    if (arr[i] < pivot) {
      SwapElements(arr, i, p++);
    }
  }
  SwapElements(arr, high, p);
  return p;
}

void QuickSort(int arr[], int low, int high) {
  if (low >= high) return;
  int p = Partition(arr, low, high);
  QuickSort(arr, low, p - 1);
  QuickSort(arr, p + 1, high);
}

void QuickSort2(int arr[], int low, int high) {
  if (low >= high) return;
  int i = low - 1, j = high + 1, x = arr[(low + high) >> 1];
  while (i < j) {
    while (arr[++i] < x);
    while (arr[--j] > x);
    if (i < j) SwapElements(arr, i, j);
  }
  QuickSort2(arr, low, j);
  QuickSort2(arr, j + 1, high);
}

int main() {
  int players[PLAYER_COUNT];
  for (int i = 0; i < 50; ++i) {
    players[i] = i;
  }
  ShuffleArray(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  QuickSort(players, 0, PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  ShuffleArray(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  QuickSort2(players, 0, PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  return 0;
}