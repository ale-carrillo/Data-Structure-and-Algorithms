#include <stdio.h>
#include <stdlib.h>
#include "listacirc.c"

int main(){

	// SE CREAN LAS VARIABLES
	int op, valor, rep=1;

	printf("\n\t\tLISTA LIGADA CIRCULAR\n");
	Lista Nueva = crearLista(); // SE CREA UNA LNUEVA LISTA LIGADA CIRCULAR, LLAMADA NUEVA

	while (rep != 0){ // SE VA A REPETIR EL MENU DE OPCIONES HASTA EQUE EL USUARIO DECIDA SALIR

		// MENU DE OPCIONES
		printf("________________________________________________\n");
		printf("\n1) IMPRIMIR LA LISTA\n2) AGREGAR AL PRINCIPIO\n3) AGREGAR AL FINAL\n4) ELIMINAR AL PRINCIPIO\n");
		printf("5) ELIMINAR AL FINAL\n7) SALIR\n");	
		printf("\n%cQUE OPERACION QUIERES HACER? ", 168);
		scanf("%d", &op);

		// OPCIONES
		switch (op){
			case 1:
				printf("\nIMPRIMIR LISTA\n");
				print_list(Nueva); // RECIBE LA LISTA NUEVA
				break;

			case 2:
				printf("\nAGREGAR AL PRINCIPIO\n");
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				addPrincipioLista(&Nueva, valor); // RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				printf("\nSE AGREGO %d AL PRINCIPIO DE LA LISTA\n", valor);
				break;

			case 3:
				printf("\nAGREGAR AL FINAL\n");
				printf("VALOR QUE SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &valor);
				addFinalLista(&Nueva, valor); // RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE EL USUARIO INGRESO
				printf("\nSE AGREGO %d AL FINAL DE LA LISTA\n", valor);
				break;

			case 4:
				printf("\nELIMINAR AL PRINCIPIO\n");
				borrarPrimero(&Nueva); // RECIBE EL APUNTADOR DE LA LISTA NUEVA
				printf("\nSE BORRO AL PRINCIPIO DE LA LISTA\n");
				break;

			case 5:
				printf("\nELIMINAR AL FINAL\n");
				borrarUltimo(&Nueva); // RECIBE EL APUNTADOR DE LA LISTA NUEVA
				printf("\nSE BORRO AL FINAL DE LA LISTA\n");
				break;

			case 6:
				printf("\nSALIR (:\n");
				rep = 0;
				break;

			default: 
				printf("OPCION NO VALIDA ):\n");
				break;
		}
	}
	return 0;
}