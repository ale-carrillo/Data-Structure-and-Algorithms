#include <stdio.h>

int main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tActividad 5\n\n");
	int a[5], i;
	#pragma omp parallel
	{
		#pragma omp for
		for (i = 0; i < 5; i++)
			a[i] = i * i;
		#pragma omp master
			for (i = 0; i < 5; i++)
				printf("a[%d] = %d\n", i, a[i]);
		#pragma omp barrier
		#pragma omp for
			for (i = 0; i < 5; i++)
				a[i] += i;
	}
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}