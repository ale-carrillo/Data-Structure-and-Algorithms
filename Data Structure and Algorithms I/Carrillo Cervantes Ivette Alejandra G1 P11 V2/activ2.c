/*
CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS - GRUPO 1
*/

#include <stdio.h>

void activities(int s[], int f[], int n){ // FUNCIÓN ACTIVIDADES
	int i, j;
	printf ("\nSelected Activities are:\n");
	i = 0;
	printf("A%d ", i+1);
	for (j = 1; j < n; j++) // CICLO FOR PARA IMPRIMIR EL HORARIO
	{
		if (s[j] >= f[i]) // SI EL SEGUNDO INDICE DE s ES MAYOR O IGUAL AL PRIMER INDICE DE f
		{
			printf ("A%d ", j+1); // IMPRIME EL HORARIO
			i = j; // i SE IGUALA A j
		}
	}
	printf("\n");
}

void main(){
	int s[] = {1, 2, 3, 2, 4, 5, 6, 8, 7}; // horarios inicio de actividades
	int f[] = {4, 5, 6, 8, 6, 7, 7, 12, 9}; // horario fin de actividades
	int n = sizeof(s)/sizeof(s[0]);
	// printf("\nsizeof(s): %d", sizeof(s));
	// printf("\nsizeof(s[0]): %d", sizeof(s[0]));
	// printf("%d", n);
	activities(s, f, n);
	// getchar();
}