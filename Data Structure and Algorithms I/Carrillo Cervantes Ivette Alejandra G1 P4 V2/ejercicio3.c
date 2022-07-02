/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include "Computadora.h" // HEADER QUE SE CREO
// NO ES NECESARIO PONER #INCLUDE <STDIO.H> POR QUE YA LO TIENE EL HEADER

int main(){

	// LE PEDIMOS AL USUARIO LA CANTIDAD DE COMPUTADORAS QUE QUIERE CREAR
	int cantidad;
	printf("\n%cCUANTAS COMPUTADORAS QUIERES CREAR? ", 168);
	fflush(stdin);
	scanf("%d", &cantidad);

	// FUNCION CALLOC, CREAMOS UN APUNTADOR PARA COMPUTADORAS CREADAS
	Computadora *creadas = (Computadora *)calloc(cantidad, sizeof(Computadora)); // TIPO COMPUTADORAS
	
	// COMO ARGUMENTO PASAMOS LAS COMPUTADORAS CREADAS (APUNTADOR) Y LA CANTIDAD QUE EL USUARIO INGRESO
	llenarDatosComputadora(creadas, cantidad); 

	printf("DATOS DE LAS COMPUTADORAS\n");
	imprimirDatosComputadora(creadas, cantidad);
	free(creadas);
}
