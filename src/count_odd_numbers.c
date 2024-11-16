#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

// 	6.	Count Odd Numbers in Array:
// Count how many numbers in an array are odd using parallel computation and a reduction clause.

int CountOddNumber(int *array, int size)
{

  int sum = 0;

#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < size; i++)
  {

    if (array[i] % 2 != 0)
    {
      sum += 1;
    }
  }

  return sum;
}

int main()
{

  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(array) / sizeof(array[0]);

  printf("there are %d odd numbers in this array.", CountOddNumber(array, size));

  return 0;
}