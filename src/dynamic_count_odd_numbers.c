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
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int *array = (int *)malloc(size * sizeof(int));

  if (array == NULL)
  {
    printf("Memory allocation failed.");
  }

  printf("Enter %d elements of the array:\n", size);
  for (int i = 0; i < size; i++)
  {
    printf("Element %d: ", i);
    scanf("%d", &array[i]);
  }

  printf("There are %d odd numbered elements in this array.", CountOddNumber(array, size));

  free(array);

  return 0;
}
