#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

// n elemanl� bir dizi �retip i�erisine [a, b) aral���nda say�lar doldurur
int *paralelDiziUret(long long int n, int a, int b)
{

  if (a >= b)
    return NULL;

  int *dizi = (int *)malloc(n * sizeof(int));

#pragma omp parallel
  {
    srand(time(0) * (omp_get_thread_num() + 1));

    long long int i;

#pragma omp for
    for (i = 0; i < n; i++)
      dizi[i] = rand() % (b - a) + a;
  }

  return dizi;
}

int *diziUret(long long int n, int a, int b)
{

  if (a >= b)
    return NULL;

  int *dizi = (int *)malloc(n * sizeof(int));

  srand(time(0));

  long long int i;

  for (i = 0; i < n; i++)
    dizi[i] = rand() % (b - a) + a;

  return dizi;
}

void diziYazdir(int *dizi, long long int n)
{
  long long int i;
  for (i = 0; i < 3; i++)
    printf("%d ", dizi[i]);
  printf("\n");
  return;
}

int main()
{

  omp_set_dynamic(0);

  long long int n;
  printf("Dizinin eleman sayisini gir: ");
  scanf("%lld", &n);

  double start, end;

  int *dizi;
  start = omp_get_wtime();
  dizi = paralelDiziUret(n, 5, 25);
  end = omp_get_wtime();
  printf("paralel s�re = %.2f sn \n", end - start);

  start = omp_get_wtime();
  dizi = diziUret(n, 5, 25);
  end = omp_get_wtime();
  printf("seri s�re = %.2f sn \n", end - start);

  return 0;
}
