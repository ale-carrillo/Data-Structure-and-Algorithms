/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

// INCLUIMOS LAS BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "Computadora.h" -> HEADER


typedef struct {
	char marca[20];
	char modelo[20];
	char procesador[20];
	char memoria[20];
	int RAM;
	int GB;
}Computadora;



void llenarDatosComputadora(Computadora *creadas, int cantidad);

void imprimirDatosComputadora(Computadora *creadas, int cantidad); // IMPRIMIR COMPUTADORA


void llenarDatosComputadora(Computadora *creadas, int cantidad){

	printf("\nINGRESE LOS DATOS DE LAS COMPUTADORAS\n");
	fflush(stdin);

	for (int i = 0; i < cantidad; ++i)
	{
		printf("\nCOMPUTADORA %d\n", i+1);

		printf("Marca: ", i+1);
		scanf("%[^\n]", creadas[i].marca);
		fflush(stdin);

		printf("Modelo: ");
		scanf("%[^\n]", creadas[i].modelo);
		fflush(stdin);

		printf("Procesador: ");
		scanf("%[^\n]", creadas[i].procesador);
		fflush(stdin);

		printf("Tipo de almacenamiento: ");
		scanf("%[^\n]", creadas[i].memoria);
		fflush(stdin);

		printf("Capacidad de memoria RAM: ");
		scanf("%d", &creadas[i].RAM);
		fflush(stdin);

		printf("Capacidad de memoria GB: ");
		scanf("%d", &creadas[i].GB);
		fflush(stdin);

	}
}

// IMPRIMIMOS DATOS DE LA COMPUTADORA
void imprimirDatosComputadora(Computadora *creadas, int cantidad){
	for (int i = 0; i < cantidad; ++i)
	{
		printf("\n__________________________\n\n");
		printf("COMPUTADORA %d\n", i+1);
		printf("\nMarca: %s \n", creadas[i].marca);
		printf("Modelo: %s \n", creadas[i].modelo);
		printf("Procesador: %s  \n", creadas[i].procesador);
		printf("Tipo de almacenamiento: %s \n", creadas[i].memoria); 
		printf("RAM: %d GB\n", creadas[i].RAM); 
		printf("GB: %d GB\n", creadas[i].GB);
	}
		printf("__________________________\n");
}