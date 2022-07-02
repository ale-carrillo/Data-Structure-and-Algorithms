// * * * * * * Constructor barrier * * * * * *

/*
#include <stdio.h>
#include <omp.h>

void realizaUnTrabajo(int A, int B);

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tConstructor barrier\n\n");
	int A, B, C;
	#pragma omp parallel shared (A, B, C)
	{
		realizaUnTrabajo(A,B);
		printf("Procesado A y B\n");
		#pragma omp barrier // esperan
		realizaUnTrabajo (B,C);
		printf("Procesando B y C\n");
	}
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}

void realizaUnTrabajo(int A, int B){
	printf("Realiza un trabajo\n\n");
}
*/

// * * * * * * * * * * * * * * * * * *


#include <stdio.h>
int main(){
	int a[5], i;
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tConstructor barrier\n\n");
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