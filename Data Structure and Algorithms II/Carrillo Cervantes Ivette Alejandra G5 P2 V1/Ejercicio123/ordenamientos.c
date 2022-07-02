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

int Heapify(int* A, int i, int size)
{
	int nuevoContador = 0;
	int l = 2 * i + 1;
	nuevoContador += 1;

	int r = 2 * i + 2;
	nuevoContador += 1;
	
	int largest;
	
	if(l <= heapSize && A[l] > A[i]){
    	largest = l;
    	nuevoContador += 1;
    }else{
    	largest = i;
    	nuevoContador += 1;
    }

    nuevoContador += 1;
  	if(r <= heapSize && A[r] > A[largest]){
    	largest = r;
    	nuevoContador += 1;
    }

    nuevoContador += 1;
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	nuevoContador += 1;
    	// Comentamos la impresión de cada iteración 
		// para que se imprima el resultado del total de operaciones más rápido
    	// printArray(A,size);
    	int b = Heapify(A, largest,size);
    	nuevoContador += b;
     }
     return nuevoContador;
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

int partition(int arr[], int low, int high, int *contador){
	int pivot = arr[high];
	*contador += 1;
	// printf("\nPivote: %d\n", pivot);
	int j, i = (low-1);
	for(j = low; j <= high-1; j++){
		*contador += 1;
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			*contador +=1;
		}
	}
	swap(&arr[i+1], &arr[high]);
	*contador +=1;
	return (i+1);
}

int quickSort(int arr[], int low, int high){
	int contador = 0;
	contador +=1;
	if (low < high)
	{
		int pi = partition(arr, low, high, &contador);
		// printSubArray(arr, low, pi-1);
		int a = quickSort(arr, low, pi-1);
		contador += a;
		// printSubArray(arr, pi+1, high);
		int b = quickSort(arr, pi+1, high);
		contador += b;
	}
	int a;
	int n = sizeof(arr[a]) / sizeof(arr[0]);
	return contador;
}

void bubbleSort(int a[], int size){
	int contador = 0;
	int i, j, n;
	n = size;
	int interna = n;
	int iteracion = 1;
	for(i=n-1; i> 0; i--, iteracion++){
		int contBubble = 0;
		// printf("\nIteraci%cn: %d\n", 162, iteracion);
		// printf("Iteracion interna: %d\n", interna);
		// printf("Arreglo: ");
		// printArray(a, size);
		interna--;
		contador += 1;
		for(j=0; j<i; j++){
			contador += 1;
			if(a[j]>a[j+1]){
				swap(&a[j], &a[j+1]);
				contador += 1;
			}
			else{
				contBubble += 1;
				// printf("contBubble: %d  ", contBubble);
			}
			// printArray(a, size);
		}
		if (contBubble == interna){
			contador += 1;
			printf("\n\n  -> La lista ya esta ordenada en la iteraci%cn: %d (:\n", 162, iteracion);
			break;
		}
	}
	printf("\nEl arreglo ordenado es: ");
	printArray(a, size);
	printf("\nNumero de operaciones: %d\n", contador);
}

// void bubbleSort(int a[], int size){
// 	int i, j, n;
// 	n = size;
// 	for(i=n-1; i> 0; i--){
// 		for(j=0; j<i; j++){
// 			if(a[j]>a[j+1])
// 				swap(&a[j], &a[j+1]);
// 		}
// 	}
// }

int mergeSort(int arr[], int p, int r){
	int contador = 0;
	int q;
	contador += 1;
	if (p < r){
		contador += 1;
		q = (p + r) / 2;
		int a = mergeSort(arr, p, q);
		contador += a;
		int b = mergeSort(arr, q + 1, r);
		contador += b;
		int c = merge(arr, p, q, r);
		contador += c;
	}

	return contador;
}

int merge(int arr[], int p, int q, int r){
	int contMerge = 0;
	// int e;
	// int n = sizeof(arr[e]) / sizeof(arr[0]);
	int n = q+r;
	int temp[n];
	int i, j, k;

	contMerge += 1;
	k = 0;
	contMerge += 1;
	i = p;
	contMerge += 1;
	j = q + 1;

	contMerge += 1;
	while(i <= q && j <= r){
		contMerge += 1;
		if (arr[i]<=arr[j]){
			contMerge += 1;
			temp[k++]=arr[i++];
		}else{
			contMerge += 1;
			temp[k++]=arr[j++];
		}
	}
	while(i <= q){
		contMerge += 1;
		temp[k++] = arr[i++];
		contMerge += 1;
	}
	while(j <= r){
		contMerge += 1;
		temp[k++] = arr[j++];
		contMerge += 1;
	}
	for(i=r; i>=p; i--){
		contMerge += 1;
		arr[i]= temp[--k];
	}
	return contMerge;
}