#include <stdio.h>
#include <omp.h>

int main()
{
  int array[1000];
  int total_sum = 0;
  int i, num_threads = 4;
  int local_sums[4] = {0}; // Array to store local sums for each thread

  // Initialize the array with values 1 to 1000 for demonstration
  for (i = 0; i < 1000; i++)
  {
    array[i] = i + 1;
  }

// Parallel region with specified number of threads
#pragma omp parallel num_threads(num_threads)
  {
    int thread_id = omp_get_thread_num(); // Get the thread ID
    int local_sum = 0;

    // Divide work among threads
    int start = (1000 / num_threads) * thread_id;
    int end = start + (1000 / num_threads);

    // Each thread calculates a local sum
    for (i = start; i < end; i++)
    {
      local_sum += array[i];
    }

    // Store the local sum in the shared array
    local_sums[thread_id] = local_sum;

// Synchronize all threads to make sure local sums are complete
#pragma omp barrier

// Only one thread (e.g., thread 0) should combine the local sums
#pragma omp single
    {
      for (i = 0; i < num_threads; i++)
      {
        total_sum += local_sums[i];
      }
    }
  }

  printf("Total sum: %d\n", total_sum);

  return 0;
}
