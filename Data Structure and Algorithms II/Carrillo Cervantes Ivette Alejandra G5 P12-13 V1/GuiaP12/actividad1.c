// Completar la versión serie y paralela del ejemplo explicado de búsqueda del valor mayor de los elementos de un
// arreglo unidimensional de enteros.

// La forma paralela se encuentra en el archivo correspondiente


#include <stdio.h>
#include <omp.h>

int buscaMaximo(int *a, int n);

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tVersion Serie\n\n");
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
	for(i=1;i<n;i++) {
		if(a[i]>max)
		max=a[i];
	}
	return max;
}