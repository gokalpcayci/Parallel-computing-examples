#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

// implement a parallel reduction algorithm to compute the sum of an array using OpenMP in C.
// i also want the array to be dynamically and randomly generated

int main()
{

  int sum = 0;
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int *array = (int *)malloc(size * sizeof(int));

  if (array == NULL)
  {
    printf("Memory allocation failed.");
    return 1;
  }

  srand(time(NULL));
  printf("Generated random numbers: ");

  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 100;
    printf("%d\n", array[i]);
  }
  printf("\n");

// parallel reduction to compute the sum
#pragma omp parallel for reduction(+ : sum)
  for (int k = 0; k < size; k++)
  {
    sum += array[k];
  }

  printf("The sum of the array is %d\n", sum);

  free(array);

  return 0;
}