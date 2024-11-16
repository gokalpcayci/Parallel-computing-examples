#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

// c arrays do not contain size information.

int calculateSumOfArray(int *array, int size)
{

  int sum = 0;
#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < size; i++)
  {
    sum += array[i];
  }

  return sum;
}

int InitializeArray(int num)
{
}

int main()
{

  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(array) / sizeof(array[0]);
  printf("sum of array: %d\n", calculateSumOfArray(array, size));

  // #pragma omp parallel
  //   {
  //     printf("hello from thread %d.\n", omp_get_thread_num());

  // #pragma omp single
  //     printf("total number of threads %d\n------\n", omp_get_num_threads());
  //   }

  return 0;
}
