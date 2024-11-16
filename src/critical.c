#include <stdio.h>
#include <omp.h>

int main()
{
  // Number of iterations
  int num_iterations = 10;

  // Declare the sum and x value
  int my_sum = 0;

// Parallel region
#pragma omp parallel for private(my_sum) reduction(+ : my_sum)
  for (int i = 0; i < num_iterations; i++)
  {
    // Each thread has its own private my_sum initialized to 0
    int my_x = i + 1; // Just an example calculation, you can change it to any other logic

    // Each thread calculates its sum locally
    my_sum += my_x;

// Critical section to ensure thread-safe output
#pragma omp critical
    {
      printf("Thread %d is processing iteration %d, my_x = %d, my_sum = %d\n",
             omp_get_thread_num(), i, my_x, my_sum);
    }
  }

  // Print the final result after all threads have completed their work
  printf("Final sum: %d\n", my_sum);

  return 0;
}
