#include <stdio.h>
#include <stdlib.h>

int *read_array(int size) {
  int verifySize = sizeof(size);
  int *allocation = malloc(verifySize *size);
  return allocation;
  // TASK: Allocate an integer array of sufficient size
  // TASK: Read the integers
}

double compute_average(int *array, int size) {
  double average = *array/ size;
  return average;
  // TASK: Compute the average
}

int main() {
  int size;
  printf("Enter number of values: ");
  scanf("%d", &size);
  int *array = read_array(size);
  double avg = compute_average(array, size);
  printf("Average: %lf", avg);

  // TASK: Free array
}
