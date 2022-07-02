#include "ordenamientos.h"
#include "utilidades.c"
#include <stdio.h>
#include <time.h>

void selectionSort(int arreglo[], int n){
	int contador = 0;
	int indiceMenor, i, j;
	for (i=0; i<n-1; i++){
		indiceMenor=i;
		// Cuenta la operación de asignación -> indiceMenor = i
		contador += 1; 
		for(j = i+1; j<n; j++){
			if(arreglo[j]<arreglo[indiceMenor], contador += 1) // Cuenta la operación de comparación if
				indiceMenor=j;
				// Cuenta la operación de asignación -> indiceMenor = j
				contador += 1; 
		}
		if (i!=indiceMenor, contador += 1){ // Cuenta la operación de comparación if
			swap(&arreglo[i],&arreglo[indiceMenor]);
			// Cuenta la operación de intercambio swap
			contador += 1; 
		}
		// Comentamos la impresión de cada iteración 
		// para que se imprima el resultado del total de operaciones más rápido
		// printf("\nIteracion numero %d \n",i+1);
		// printArray(arreglo,n);
	}
	printf("\nEl arreglo ordenado es: ");
	printArray(arreglo, n);
	printf("\nNumero de operaciones: %d\n", contador);
}


void insertionSort(int a[], int n){
	int contador = 0;
	int i,j,k;
	int aux;

	for(i=1; i<n; i++){
		j=i;
		contador += 1; // Cuenta la operación j = i
		aux=a[i]; 
		contador += 1; // Cuenta la operación aux = a[i]
		while (j>0 && aux < a[j-1]){
			contador += 1; // Cuenta el While
			a[j] = a[j-1];
			contador += 1; // Cuenta la operación de asignación a[j] = a[j-1]
			j--;
			contador += 1; // Cuenta la operación de asignación j--
		}
		a[j]=aux;
		contador += 1; // Cuenta la operación de asignación a[j]=aux

		// Comentamos la impresión de cada iteración 
		// para que se imprima el resultado del total de operaciones más rápido
		// printf("\nIteracion numero %d \n",i);
		// printArray(a,n);
	}
	printf("\nEl arreglo ordenado es: ");
	printArray(a, n);
	printf("\nNumero de operaciones: %d\n", contador);
}

int heapSize;


void HeapSort(int A[], int size){
	int contador = 0;
	int a = BuildHeap(A,size);
	contador += a;
  	int i;
  	for(i = size - 1; i > 0; i--){
    	swap(&A[0],&A[heapSize]);
    	contador += 1;      
      	heapSize--;
    	// Comentamos la impresión de cada iteración 
		// para que se imprima el resultado del total de operaciones más rápido
		// printf("\nIteracion HS: \n");
	// printArray(A,size);
	int a = Heapify(A, 0,size);
	contador += a;
   }
	printf("\nEl arreglo ordenado es: ");
	printArray(A, size);
	printf("\nNumero de operaciones: %d\n", contador);
}

int Heapify(int* A, int i, int size) // 0, 6
{
	int nuevoContador = 0;
	int l = 2 * i + 1; // hijo izquierdo
	int r = 2 * i + 2;	// hijo derecho
	int largest; // raiz
	
	if(l <= heapSize && A[l] > A[i]){
    	largest = l;
    }else{
    	largest = i;
    }
  	if(r <= heapSize && A[r] > A[largest]){
    	largest = r;
    }

    nuevoContador += 1;
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	// Comentamos la impresión de cada iteración 
		// para que se imprima el resultado del total de operaciones más rápido
    	// printArray(A,size);
    	int b = Heapify(A, largest,size);
     }
}

int BuildHeap(int* A, int size){
	int nuevoContador = 0;
	heapSize = size - 1;
	nuevoContador += 1;
  	int i;
  	for(i = (size - 1) / 2; i >= 0; i--){
		int c = Heapify(A, i,size);
		nuevoContador += c;
  	}
	printf("\nTermin%c de construir el HEAP \n",162);
	return nuevoContador;
}
