/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include <stdio.h>
#include <stdlib.h>

#include "colaDoble.c"

int main(){

	int tam;
	printf("\nINGRESA TAMA%cO DE LA COLA: ", 165);
	scanf("%d", &tam);

	Cola queue = crearCola(tam);

	printf("\n\nSe encola el n%cmero 8\n", 163);
	encolarInicio(&queue,8);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 14\n", 163);
	encolarFinal(&queue,14);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 22\n", 163);
	encolarFinal(&queue,22);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 28\n", 163);
	encolarFinal(&queue,28);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 30\n", 163);
	encolarFinal(&queue,30);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 33\n", 163);
	encolarFinal(&queue,33);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 40\n", 163);
	encolarFinal(&queue,40);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe desencola\n", 163);
	desencolarFinal(&queue);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe desencola\n", 163);
	desencolarFinal(&queue);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe desencola\n", 163);
	desencolarFinal(&queue);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe encola el n%cmero 50\n", 163);
	encolarFinal(&queue,50);
	mostrarValores(queue);
	mostrarIndices(queue);

	printf("\n\nSe desencola\n", 163);
	desencolarFinal(&queue);
	mostrarValores(queue);
	mostrarIndices(queue);
	
}