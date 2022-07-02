/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include <stdio.h>
#include <stdlib.h>

#include "colaDoble.c"

int main(){

	Cola queue = crearCola(8);

	printf("\n\n\t_ESTADO 1_\n");
	//printf("\nSe encola al final el n%cmero 101\n", 163);
	encolarFinal(&queue,101);

	//printf("Se encola al final el n%cmero 102\n", 163);
	encolarFinal(&queue,102);

	//printf("Se encola al final el n%cmero 103\n", 163);
	encolarFinal(&queue,103);

	//printf("Se encola al final el n%cmero 104\n", 163);
	encolarFinal(&queue,104);

	//printf("Se encola al final el n%cmero 105\n", 163);
	encolarFinal(&queue,105);

	//printf("Se desencolo el inicio el inicio\n\n", 163);
	desencolarInicio(&queue);

	mostrarValores(queue);
	//mostrarIndices(queue);

	printf("\n\n\t_ESTADO 2:_\n");
	//printf("\nSe encola desencolo al final\n");
	desencolarFinal(&queue);

	//printf("Se encola desencolo el inicio\n");
	desencolarInicio(&queue);
	
	//printf("Se encola al inicio el n%cmero 99\n", 163);
	encolarInicio(&queue,99);

	//printf("Se encola al inicio el n%cmero 98\n", 163);
	encolarInicio(&queue,98);

	//printf("Se encola al incio el n%cmero 97\n", 163);
	encolarInicio(&queue,97);

	//printf("Se encola al final el n%cmero 120\n", 163);
	encolarFinal(&queue,120);

	//printf("Se encola al final el n%cmero 121\n\n", 163);
	encolarFinal(&queue,121);

	mostrarValores(queue);
	//mostrarIndices(queue);

	printf("\n\n\t_ESTADO 3:_\n");

	//printf("\nSe encola desencolo el inicio\n");
	desencolarInicio(&queue);

	//printf("Se encola desencolo el inicio\n");
	desencolarInicio(&queue);

	//printf("Se encola desencolo el inicio\n");
	desencolarInicio(&queue);

	//printf("Se encola al final el n%cmero 122\n\n", 163);
	encolarFinal(&queue,122);

	mostrarValores(queue);
	//mostrarIndices(queue);
}