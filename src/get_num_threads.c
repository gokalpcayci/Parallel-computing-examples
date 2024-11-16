#include <stdio.h>
#include <omp.h>

int main()
{
  // Number of iterations
  int num_iterations = 10;

  // If you want the iterations to be assigned in a more predictable (sequential or block-based) order, you can specify schedule(static):
  // #pragma omp parallel for schedule(static)

  // Parallel region with a number of threads
#pragma omp parallel for
  for (int i = 0; i < num_iterations; i++)
  {
    // Get the thread number of the current thread
    int thread_id = omp_get_thread_num();

    // Get the number of threads in the parallel region
    int total_threads = omp_get_num_threads();

    // Print the thread number along with the iteration
    printf("Thread %d (Total Threads: %d) is processing iteration %d\n", thread_id, total_threads, i);
  }

  return 0;
}
