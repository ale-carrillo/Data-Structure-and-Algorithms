// * * * * * * Constructor critical * * * * * *

#include <stdio.h>
#include <omp.h>

int buscaMaximo(int *a, int n);

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tConstructor critical\n\n");
	int arr[] = {16, 2, 3, 4, 12, 6, 7, 8, 6};
	int tam = sizeof(arr)/sizeof(arr[0]);
	printf("Arreglo: ");
	for (int i = 0; i < tam; ++i) {
        printf("%i, ", arr[i]);
    }
	int max = buscaMaximo(arr, tam);
	printf("\nEl valor maximo del arreglo es: %i\n", max);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}

int buscaMaximo(int *a, int n){
	int max,i;
	max=a[0];
	#pragma omp parallel for
	for(i=1;i<n;i++){
		if(a[i]>max) {
			#pragma omp critical
			{
				if(a[i]>max)
					max=a[i];
			}
		}
	}
}

// * * * * * * * * * * * * * * * * * *

// Normal
/*
int buscaMaximo(int *a, int n){
	int max,i;
	max=a[0];
	for(i=1;i<n;i++) {
		if(a[i]>max)
			max=a[i];	
	}
	return max;
}
*/

// Constructor for
/*
int buscaMaximo(int *a, int n){
	int max,i;
	max=a[0];
	#pragma omp parallel
	{
		#pragma omp for
		for(i=1;i<n;i++){
			if(a[i]>max)
				max=a[i];
		}
	}
	return max;
}
*/

// Anidar los constructores parallel y for
/*
int buscaMaximo(int *a, int n){
	int max,i;
	max=a[0];
	#pragma omp parallel for
	for(i=1;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
*/

// agreagando critical

/*
int buscaMaximo(int *a, int n){
	int max,i;
	max=a[0];
	#pragma omp parallel for
	for(i=1;i<n;i++){
		if(a[i]>max){
			#pragma omp critical
			{
				max=a[i];
			}
		}
	}
}
*/