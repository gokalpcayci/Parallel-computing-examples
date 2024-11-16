#include <stdio.h>
#include <omp.h>

int main()
{
  int counter = 0;
  int num_threads = 4;
  int increments_per_thread = 1000;

// Parallel region with specified number of threads
#pragma omp parallel num_threads(num_threads)
  {
    int i;

    // Each thread increments the counter multiple times
    for (i = 0; i < increments_per_thread; i++)
    {
// Atomic update: ensures the increment operation is thread-safe
#pragma omp atomic
      counter++;
    }
  }

  printf("Final counter value: %d\n", counter);

  return 0;
}
