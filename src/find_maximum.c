#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

// 	4.	Find Maximum in Array:
// Use OpenMP to find the maximum element in an array with parallel reduction.

int FindMaximum(int *array, int size)
{

  int biggest = 0;

#pragma omp parallel for
  for (int i = 0; i < size; i++)
  {
    if (array[i] > biggest)
    {
      biggest = array[i];
    }
  }

  return biggest;
}

int main()
{

  int array[] = {1, 2, 3, 448, 50, 6, 7, 8, 24, 46};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Maksimum for this array is %d", FindMaximum(array, size));

  return 0;
}