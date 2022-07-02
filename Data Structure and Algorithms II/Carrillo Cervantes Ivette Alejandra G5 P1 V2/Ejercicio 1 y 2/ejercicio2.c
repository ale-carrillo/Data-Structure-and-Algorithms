// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos - Grupo 5

#include "ordenamientos.c" // Se incluye a la biblioteca "ordenamientos"

void main(){

	// Declaramos variables para carácteres
	char aa = 160, ae = 130, ai = 161, ao = 162, au = 163, interr = 168;

	// Declaramos las variables a utilizar
	int op, n = 20, rep = 1, arreglo[20];

	// Mensaje Principal
	printf("\n______________________________________________________________________");
	printf("\n\n\t\t\tAlgoritmos de ordenamiento (:\n\n");
	
	// Se utilizó la función srand para generar números aleatorios
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		// Se fueron guardando números (del rango cero a 100) en el arreglo previamente incializado  
		arreglo[i]=rand()%100;
	}

	// Se imprime el arreglo aleatorio
	printf("\nSe gener%c un arreglo aleatorio con %d elementos: \n", ao, n);
	printArray(arreglo, n);

	while (rep != 0) {
		printf("\n____________________________________");
		printf("\n\n    Men%c de opciones (:\n", au);
		printf("\n 1) Selection Sort\n 2) Insertion Sort\n 3) Heap Sort\n 4) Salir");
		printf("\n\nSelecciona una opci%cn: ", ao);
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("Seleccionaste Selection Sort:\n");
				selectionSort(arreglo, n);
				break;

			case 2:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("Seleccionaste Insertion Sort:\n");
				insertionSort(arreglo, n);
				break;
			
			case 3:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n\n");
				printf("Seleccionaste Heap Sort:\n");
				HeapSort(arreglo, n);
				break;
			
			case 4:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("\tDecidiste salir, byeee (:\n\n");
				rep = 0;
				break;
			
			default:
				printf("\n\tOpci%cn no valida ):\n", ao);
				break;
		}
	}
}