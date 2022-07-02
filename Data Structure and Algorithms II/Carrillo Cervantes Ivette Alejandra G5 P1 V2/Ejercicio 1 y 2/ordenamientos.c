#include "ordenamientos.h"
#include "utilidades.c"
#include <stdio.h>
#include <stdlib.h> // Se incluyó esta biblioteca para ocupar la función srand
#include <time.h> // Se incluyó esta biblioteca para inicializar la función srand en tiempo NULL

char cuadro = 254;

void selectionSort(int arreglo[], int n){
	int indiceMenor, i, j;
	for (i=0; i<n-1; i++){
		indiceMenor=i;
		for(j = i+1; j<n; j++){
			if(arreglo[j]<arreglo[indiceMenor])
				indiceMenor=j;
		}
		if (i!=indiceMenor){
			swap(&arreglo[i],&arreglo[indiceMenor]);
		}

		printf("\nIteracion numero %d \n",i+1);
		printArray(arreglo,n);
	}
	printf("\n\n %c El arreglo ordenado con Selection Sort es: \n", cuadro);
	printArray(arreglo, n);
}


void insertionSort(int a[], int n){
	int i,j,k;
	int aux;

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		while (j>0 && aux < a[j-1]){
			a[j] = a[j-1];
			j--;
		}
		a[j]=aux;


		printf("\nIteracion numero %d \n",i);
		printArray(a,n);
	}
	printf("\n\n %c El arreglo ordenado con Insertion Sort es: \n", cuadro);
	printArray(a, n);
}

int heapSize;


void HeapSort(int A[], int size){
	BuildHeap(A,size);
  	int i;
  	for(i = size - 1; i > 0; i--){
    	swap(&A[0],&A[heapSize]);      
      	heapSize--;
      	printf("\nIteracion HS: \n");
  	printArray(A,size);
	Heapify(A, 0,size);
   }
	printf("\n\n %c El arreglo ordenado con Heap Sort es: \n", cuadro);
	printArray(A, size);
}

void Heapify(int* A, int i, int size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	if(l <= heapSize && A[l] > A[i])
    	largest = l;
  	else
    	largest = i;
  	if(r <= heapSize && A[r] > A[largest])
    	largest = r;
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	printArray(A,size);
    	Heapify(A, largest,size);
     }
      
}

void BuildHeap(int* A, int size){
	heapSize = size - 1;
  	int i;
  	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size);
  	}
	printf("\nTermin%c de construir el HEAP \n",162);
}
