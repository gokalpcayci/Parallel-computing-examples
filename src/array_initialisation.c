#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

// c arrays do not contain size information.

void InitializeArray(int *array, int num)
{
#pragma omp parallel for
  for (int i = 0; i < num; i++)
  {
    array[i] = i * 2;
  }
}

int main()
{
  int n = 1000;
  int *array = (int *)malloc(n * sizeof(int));

  if (array == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  InitializeArray(array, n);

  for (int i = 0; i < 10; i++)
  {
    printf("array[%d] = %d\n", i, array[i]);
  }

  free(array);

  return 0;
}
