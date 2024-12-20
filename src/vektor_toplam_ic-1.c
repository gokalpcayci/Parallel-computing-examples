#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char** argv) {
	srand(time(0));
	int i, n;
	
	n = atoi(argv[1]);
	
	omp_set_num_threads(n / 2);
	
	int* array = (int*) malloc (n * sizeof(int));
	
	for (i = 0; i < n; i++)
	{
		array[i] = (rand() % 10) + 1;
		printf("%d ", array[i]);
	}
	
	#pragma omp parallel default(shared) 
	{
		int k, tid = omp_get_thread_num();
		int sol, sag;
		
		for (k = 1; k <= n / 2; k *= 2)
		{
			if (tid < (n / 2) / k)
			{
				sol = tid * k * 2;
				sag = sol + k;
				
				array[sol] += array[sag];
			}
			
			#pragma omp barrier
		}
	}
	
	printf("\n\ntoplam = %d", array[0]);
	
	return 0;
}
