/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

// AGREGAMOS LAS BIBLIOTECAS CORRESPONDIENTES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AGREGAMOS EL ARCHIVO DONDE SE ENCUENTRAN LAS OPERACIONES DE LA LISTA CIRCULAR DOBLE 
#include "CircularDoble.c"

int main(){

	// DECLARAMOS LAS VARIABLES
	int op, valor, rep=1, lugar, retorna, elemento, e;

	printf("\n\t\tLISTA LIGADA CIRUCLAR DOBLE\n");
	Lista Nueva = crearLista(); // SE CREA UNA NUEVA LISTA LIGADA CIRCULAR DOBLE, LLAMADA NUEVA

	while (rep != 0){ // SE VA A REPETIR EL MENU DE OPCIONES HASTA QUE EL USUARIO DECIDA SALIR 

		// MENU DE OPCIONES 
		printf("_____________________________________________________________\n");
		printf("\n\tOPERACIONES DE UNA LISTA LIGADA CIRCULAR DOBLE\n");
		printf("\n1) IMPRIMIR LA LISTA\n2) AGREGAR AL PRINCIPIO\n3) AGREGAR AL FINAL\n4) AGREGAR N-ESIMO\n");
		printf("5) ELIMINAR AL INICIO\n6) ELIMINAR AL FINAL\n7) SALIR\n");
		printf("\n%cQUE OPERACION QUIERES HACER? ", 168);
		scanf("%d", &op);

		// OPCIONES
		switch (op){
			case 1: 
				printf("\nIMPRIMIR LISTA\n\n");
				print_list(Nueva); // RECIBE LA LISTA NUEVA
				break;

			case 2:
				printf("\nAGREGAR AL PRINCIPIO\n");
				// LE PEDIMOS AL USUARIO EL VALOR QUE SE QUIERE AGREGAR AL PRINCIPIO
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION AGREGAR AL PRINCIPIO, RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				addPrincipioLista(&Nueva, valor); 
				printf("\nSE AGREGO %d AL PRINCIPIO DE LA LISTA\n", valor);
				break;

			case 3:
				printf("\nAGREGAR AL FINAL\n");
				// LE PEDIMOS AL USUARIO EL VALOR QUE SE QUIERE AGREGAR AL FINAL
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION AGREGAR AL FINAL, RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				addFinalLista(&Nueva, valor);
				printf("\nSE AGREGO %d AL FINAL DE LA LISTA\n", valor);
				break;

			case 4:
				printf("\nAGREGAR N-ESIMO\n");
				// LE PEDIMOS AL USUARIO EL VALOR QUE SE QUIERE AGREGAR Y LA POSICION EN DONDE SE QUIERE AGREGAR
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				printf("EN QUE POSICION SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &lugar);
				// LLAMAMOS A LA FUNCION AGREGAR N-ESIMO, RECIBE EL APUNTADOR DE LA LISTA, EL VALOR QUE EL USUARIO INGRESO Y EL LUGAR DONDE SE AGREGARA
				addNesimo(&Nueva, valor, lugar);
				break;

			case 5:
				printf("\nELIMINAR AL PRINCIPIO\n");
				// LAMAMOS A LA FUNCION AGREGAR AL INICIO, RECIBE EL APUNTADOR DE LA LISTA NUEVA
				borrarPrimero(&Nueva);
				printf("\nSE BORRO AL PRINCIPIO DE LA LISTA\n");
				break;

			case 6:
				printf("\nELIMINAR AL FINAL\n");
				// LLAMAMOS A LA FUNCION AGREGAR AL FINAL, RECIBE EL APUNTADOR DE LA LISTA NUEVA
				borrarUltimo(&Nueva); 
				printf("\nSE BORRO AL FINAL DE LA LISTA\n");
				break;

			case 7:
				printf("\nSALIR (:\n"); // OPCION SALIR
				rep = 0;
				break;

			default: 
				printf("OPCION NO VALIDA ):\n"); // OPCION NO VALIDA EN CASO DE QUE INGRESE EL USUARIO OTRO NUMERO
				break;
		}
	}
	return 0;
}