#include "ordenamientos.c"
#include <stdlib.h>
#include <time.h>

void main(){

	// Declaramos variables para carácteres
	char aa = 160, ae = 130, ai = 161, ao = 162, au = 163, interr = 168, cuadro = 254;

	// Declaramos las variables a utilizar
	int op, n, rep = 1;

	while (rep != 0) {
		
		// Mensaje Principal _____________________________________________________________________________
		printf("\n\n______________________________________________________________________");
		printf("\n\n\tAlgoritmos de ordenamiento (:\n\n");
		// Se le pregunta al usuario cuantos número quiere que tenga el arreglo que se va a crear
		printf(" %c %cCu%cntos elementos quieres que tenga tu arreglo? ", cuadro, interr, aa);
		scanf("%d", &n);
		int arreglo[n];
		
		// Se utilizó la función srand para generar números aleatorios
		srand(time(NULL));
		int i;
		for (i = 0; i < n; ++i)
		{
			// Se fueron guardando números (del rango cero a 1000) en el arreglo previamente incializado  
			arreglo[i]=rand()%1000;
		}

		// Se imprime el arreglo aleatorio
		printf("\nSe gener%c un arreglo aleatorio con %d elementos: ", ao, n);
		printArray(arreglo, n);

		// Si no se tuviera el número de elementos del arreglo se haría la siguiente operación:
		// n = sizeof(arreglo[i]) / sizeof(arreglo[0])

		// Menú de opciones ______________________________________________________________________________
		printf("\n____________________________________");
		printf("\n\n    Men%c de opciones (:\n", au);
		printf("\n 1) Selection Sort\n 2) Insertion Sort\n 3) Heap Sort\n 4) Salir");
		printf("\n\nSelecciona una opci%cn: ", ao);
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("Seleccionaste Selection Sort:\n");
				clock_t inicio = clock();
				selectionSort(arreglo, n);
				clock_t fin = clock ();
				double tiempo = (double)(fin-inicio)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecuci%cn: %.4f segundos", ao, tiempo);
				break;

			case 2:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("Seleccionaste Insertion Sort:\n");
				clock_t inicio2 = clock();
				insertionSort(arreglo, n);
				clock_t fin2 = clock ();
				double tiempo2 = (double)(fin2-inicio2)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecuci%cn: %.4f segundos", ao, tiempo2);
				break;
			
			case 3:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n\n");
				printf("Seleccionaste Heap Sort:\n");
				clock_t inicio3 = clock();
				HeapSort(arreglo, n);
				clock_t fin3 = clock ();
				double tiempo3 = (double)(fin3-inicio3)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecuci%cn: %.4f segundos", ao, tiempo3);
				break;
			
			case 4:
				printf("_ _ _ _ _ _ _ _ _ _ _ _\n\n");
				printf("Decidiste salir, byeee (:\n\n");
				rep = 0;
				break;
			
			default:
				printf("\n\tOpci%cn no valida ):\n", ao);
				break;
		}
	}
}
