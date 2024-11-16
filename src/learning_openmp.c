#include <stdio.h>
#include <omp.h>

int main()
{
  int counter = 0; // Shared variable to be incremented by threads
  int num_threads = 6;
  int increments_per_thread = 1000;

  omp_lock_t lock;      // Declare an OpenMP lock variable
  omp_init_lock(&lock); // Initialize the lock

// Parallel region with specified number of threads
#pragma omp parallel num_threads(num_threads)
  {
    int i;

    // Each thread increments the counter multiple times
    for (i = 0; i < increments_per_thread; i++)
    {
      // Lock the critical section
      omp_set_lock(&lock);

      // Critical section: incrementing the shared counter
      counter++;

      // Unlock the critical section
      omp_unset_lock(&lock);
    }
  }

  // Destroy the lock after it is no longer needed
  omp_destroy_lock(&lock);

  printf("Final counter value: %d\n", counter);

  return 0;
}
