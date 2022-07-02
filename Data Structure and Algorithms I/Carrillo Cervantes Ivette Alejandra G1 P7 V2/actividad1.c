/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

// AGREGAMOS LAS BIBLIOTECAS CORRESPONDIENTES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AGREGAMOS EL ARCHIVO DONDE SE ENCUENTRAN LAS OPERACIONES DE LA LISTA
#include "lista.c"

int main(){

	// DECLARAMOS LAS VARIABLES
	int op, valor, rep=1, lugar, retorna, elemento, e;

	printf("\n\t\tLISTA LIGADA SIMPLE\n");
	Lista Nueva = crearLista(); // SE CREA UNA NUEVA LISTA LIGADA SIMPLE, LLAMADA NUEVA

	while (rep != 0){ // SE VA A REPETIR EL MENU DE OPCIONES HASTA QUE EL USUARIO DECIDA SALIR 

		// MENU DE OPCIONES 
		printf("_____________________________________________________________\n");
		printf("\n\tOPERACIONES DE UNA LISTA LIGADA SIEMPLE\n");
		printf("\n1) IMPRIMIR LA LISTA\n2) AGREGAR AL PRINCIPIO\n3) AGREGAR AL FINAL\n4) AGREGAR N-ESIMO \n");
		printf("5) ELIMINAR AL PRINCIPIO\n6) ELIMINAR AL FINAL\n7) ELIMINAR N-ESIMO\n8) PRIMER ELEMENTO\n9) BUSCAR VALOR\n10) ELIMINAR ELEMENTOS MENORES\n11) SALIR\n");
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
				// LE PEDIMOS AL USUARIO QUE INGRESE EL VALOR QUE SE QUIERE AGREGAR AL INICIO DE LA LISTA
				printf("VALOR QUE SE QUIERE AGREGAR: "); 
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION AGREGAR AL PRINCIPIO, RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				addPrincipioLista(&Nueva, valor); 
				printf("\nSE AGREGO %d AL PRINCIPIO DE LA LISTA\n", valor);
				break;

			case 3:
				printf("\nAGREGAR AL FINAL\n");
				// LE PEDIMOS AL USUARIO QUE INGRESE EL VALOR QUE SE QUIERE AGREGAR AL FINAL DE LA LISTA
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION AGREGAR AL FINAL, RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				addFinalLista(&Nueva, valor);
				printf("\nSE AGREGO %d AL FINAL DE LA LISTA\n", valor);
				break;

			case 4:
				printf("\nAGREGAR N-ESIMO\n");
				// LE PEDIMOS AL USUARIO QUE INGRESE EL VALOR QUE SE QUIERE AGREGAR Y EN QUE LUGAR DE LA LISTA LO AGREGARA
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				printf("EN QUE POSICION SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &lugar);
				// LLAMAMOS A LA FUNCION AGREGAR N-ESIMO, RECIBE EL APUNTADOR DE LA LISTA, EL VALOR QUE EL USUARIO INGRESO Y EL LUGAR DONDE LO QUIERE AGREGAR
				addNesimo(&Nueva, valor, lugar);
			break;

			case 5:
				printf("\nELIMINAR AL PRINCIPIO\n");
				// LLAMAMOS A LA FUNCION BORRAR PRIMERO, RECIBE EL APUNTADOR DE LA LISTA NUEVA
				borrarPrimero(&Nueva);
				break;

			case 6:
				printf("\nELIMINAR AL FINAL\n");
				// LLAMAMOS A LA FUNCION BORRAR ULTIMO, RECIBE EL APUNTADOR DE LA LISTA NUEVA
				borrarUltimo(&Nueva);
				break;

			case 7:
				printf("\nELIMINAR N-ESIMO\n");
				// LE PEDIMOS AL USUARIO QUE INGRESE EL LUGAR QUE SE QUIERE ELIMINAR DE LA LISTA
				printf("EN QUE POSICION SE QUIERE ELIMINAR: ");
				fflush(stdin);
				scanf("%d", &lugar);
				// LLAMAMOS A LA FUNCION ELIMINAR N-ESIMO, RECIBE EL APUNTADOR DE LA LISTA Y EL LUGAR QUE SE QUIERE ELIMINAR
				eliminarNesimo(&Nueva, lugar);
				break;

			case 8:
				printf("\nPRIMER ELEMENTO\n");
				// LLAMAMOS A LA FUNCION PRIMER ELEMENTO, RECIBE LA LISTA NUEVA
				primerElemento(Nueva);
				printf("\nEL PRIMER ELEMENTO DE LA LISTA ES: %d\n", Nueva.head->val);
				break;

			case 9:
				printf("\nBUSCAR VALOR\n");
				// LE PEDIMOS AL USUARIO QUE INGRESE EL VALOR QUE SE QUIERE BUSCAR EN LA LISTA
				printf("VALOR QUE SE QUIERE BUSCAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION BUSCAR, RECIBE LA LISTA Y EL VALOR QUE SE QUIERE BUSCAR
				// EL VALOR QUE RETORNA LA FUNCION LA GUARDAMOS EN LA VARIABLE "retorna"
				retorna = buscar(Nueva, valor);
				if (retorna == 0) // SI EL VALOR RETORNADO ES 0, SIGNIFICA QUE NO SE ENCONTRO EL VALOR BUSCADO
				{
					printf("NO SE ENCONTRO EL NUMERO\n");
				}
				else{ // EN CASO DE QUE SI SE HAYA ENCONTRADO, IMPRIMIMOS CUANTAS VECES ESTA DICHO VALOR EN LA LISTA
					printf("EL VALOR %d, SE ENCUENTRA %d CANTIDAD DE VECES EN LA LISTA\n", valor, retorna);
				}
				break;

			case 10:
				printf("ELIMINAR ELEMENTOS MENORES\n");
				// LE PEDIMOS AL USUARIO QUE INGRESE EL ELEMENTO MAYOR
				printf("ELEMENTO MAYOR: ");
				fflush(stdin);
				scanf("%d", &valor);
				// LLAMAMOS A LA FUNCION ELIMINAR MENORES, RECIBE EL APUNTADOR DE LA LISTA Y EL ELEMENTO MAYOR
				eliminarMenores(&Nueva, valor);
			break;

			case 11:
				printf("\nSALIR (:\n"); // OPCION SALIR
				rep = 0;
				break;

			default: 
				printf("OPCION NO VALIDA ):\n"); // EN CASO DE QUE EL USUARIO INGRESE OTRA OPCION, SERA NO VALIDA
				break;
		}
	}
	return 0;
}
