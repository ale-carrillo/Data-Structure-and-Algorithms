/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

// AGREGAMOS LAS BIBLIOTECAS CORRESPONDIENTES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AGREGAMOS EL ARCHIVO DONDE SE ENCUENTRAN LAS OPERACIONES DE LA LISTA CIRCULAR 
#include "ListaCircComp.c"

int main(){

	// DECLARAMOS LAS VARIABLES
	int op, valor, rep, lugar, retorna;
	char id[20], marca[20], modelo[20], procesador[20], memoria[20];
	int RAM, GB;

	printf("\n\t\tLISTA LIGADA CIRCULAR COMPUTADORA\n");
	Lista Nueva = crearLista(); // SE CREA UNA NUEVA LISTA LIGADA CIRCULAR, LLAMADA NUEVA

	while (rep != 0){ // SE VA A REPETIR EL MENU DE OPCIONES HASTA QUE EL USUARIO DECIDA SALIR 

		// MENU DE OPCIONES 
		printf("_____________________________________________________________\n");
		printf("\n\tOPERACIONES DE UNA LISTA LIGADA CIRCULAR\n");
		printf("\n1) IMPRIMIR LA LISTA\n2) AGREGAR AL PRINCIPIO\n3) AGREGAR AL FINAL\n4) ELIMINAR AL PRINCIPIO\n");
		printf("5) ELIMINAR AL FINAL\n6) AGREGAR N-ESIMO\n7) ELIMINAR N-ESIMO\n8) BUSCAR VALOR POR ID\n9) RECORRER LISTA\n10) SALIR (:\n");
		printf("\n%cQUE OPERACION QUIERES HACER? ", 168);
		fflush(stdin);
		scanf("%d", &op);

		// OPCIONES
		switch (op){
			case 1: 
				printf("\nIMPRIMIR LISTA\n\n");
				print_list(Nueva); // RECIBE LA LISTA NUEVA
				break;

			case 2:
				printf("\nAGREGAR AL PRINCIPIO\n");
				printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
				printf("INGRESE LOS DATOS DE LA COMPUTADORA");

				// PEDIMOS QUE EL USUARIO INGRESE LOS DATOS DE LA COMPUTADORA

				printf("\nID: ");
				fflush(stdin);
				scanf("%[^\n]", id);

				printf("MARCA: ");
				fflush(stdin);
				scanf("%[^\n]", marca);				

				printf("MODELO: ");
				fflush(stdin);
				scanf("%[^\n]", modelo);

				printf("PROCESADOR: ");
				fflush(stdin);
				scanf("%[^\n]", procesador);

				printf("TIPO DE ALMACENAMIENTO: ");
				fflush(stdin);
				scanf("%[^\n]", memoria);

				printf("MEMORIA RAM: ");				
				fflush(stdin);
				scanf("%d", &RAM);

				printf("MEMORIA GB: ");
				fflush(stdin);
				scanf("%d", &GB);

				// LLAMAMOS A LA FUNCION AGREGAR AL PRINCIPIO, RECIBE EL APUNTADOR DE LA LISTA Y LOS VALORES QUE EL USUARIO INGRESO 
				addPrincipioLista(&Nueva, id, marca, modelo, procesador, memoria, RAM, GB); 
				printf("\nSE AGREGO LA DIRECCION IP %s AL PRINCIPIO DE LA LISTA\n", id);

				break;

			case 3:
				printf("\nAGREGAR AL FINAL\n");
				printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
				printf("INGRESE LOS DATOS DE LA COMPUTADORA");

				// PEDIMOS QUE EL USUARIO INGRESE LOS DATOS DE LA COMPUTADORA

				printf("\nID: ");
				fflush(stdin);
				scanf("%[^\n]", id);

				printf("MARCA: ");
				fflush(stdin);
				scanf("%[^\n]", marca);

				printf("MODELO: ");
				fflush(stdin);
				scanf("%[^\n]", modelo);

				printf("PROCESADOR: ");
				fflush(stdin);
				scanf("%[^\n]", procesador);

				printf("TIPO DE ALMACENAMIENTO: ");
				fflush(stdin);
				scanf("%[^\n]", memoria);

				printf("MEMORIA RAM: ");
				fflush(stdin);
				scanf("%d", &RAM);
				
				printf("MEMORIA GB: ");
				fflush(stdin);
				scanf("%d", &GB);

				// LLAMAMOS A LA FUNCION AGREGAR AL FINAL, RECIBE EL APUNTADOR DE LA LISTA Y LOS VALORES QUE EL USUARIO INGRESO 
				addFinalLista(&Nueva, id, marca, modelo, procesador, memoria, RAM, GB);
				printf("\nSE AGREGO LA DIRECCION IP %s AL FINAL DE LA LISTA\n", id);
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
				printf("\nAGREGAR N-ESIMO\n");
				printf("INGRESE LOS DATOS DE LA COMPUTADORA");

				// PEDIMOS QUE EL USUARIO INGRESE LOS DATOS DE LA COMPUTADORA

				printf("\nID: ");
				fflush(stdin);
				scanf("%[^\n]", id);

				printf("MARCA: ");
				fflush(stdin);
				scanf("%[^\n]", marca);

				printf("MODELO: ");
				fflush(stdin);
				scanf("%[^\n]", modelo);

				printf("PROCESADOR: ");
				fflush(stdin);
				scanf("%[^\n]", procesador);

				printf("TIPO DE ALMACENAMIENTO: ");
				fflush(stdin);
				scanf("%[^\n]", memoria);

				printf("MEMORIA RAM: ");
				fflush(stdin);
				scanf("%d", &RAM);
				
				printf("MEMORIA GB: ");
				fflush(stdin);
				scanf("%d", &GB);

				printf("EN QUE POSICION SE QUIERE AGREGAR: ");
				fflush(stdin);
				scanf("%d", &lugar);
				
				// LLAMAMOS A LA FUNCION AGREGAR AL N-ESIMO, RECIBE EL APUNTADOR DE LA LISTA, LOS VALORES QUE EL USUARIO INGRESO Y EL LUGAR DONDE SE QUIERE AGREGAR
				addNesimo(&Nueva, id, marca, modelo, procesador, memoria, RAM, GB, lugar);
			break;
			
			case 7:
				printf("\nELIMINAR N-ESIMO\n");
				printf("EN QUE POSICION SE QUIERE ELIMINAR: ");
				fflush(stdin);
				scanf("%d", &lugar);

				// LLAMAMOS A LA FUNCION ELIMINAR N-ESIMO, RECIBE EL APUNTADOR DE LA LISTA Y EL LUGAR DONDE SE QUIERE ELIMINAR
				eliminarNesimo(&Nueva, lugar);
			break;

			case 8:
				printf("\nBUSCAR VALOR POR ID\n");
				printf("ID DE LA COMPUTADORA QUE SE QUIERE BUSCAR: ");
				fflush(stdin);
				scanf("%[^\n]", id);
				
				retorna = buscarCompuId(Nueva, id);
				if (retorna == 0)
				{
					printf("NO SE ENCONTRO EL NUMERO ):\n");
				}
			break;
		
			case 9:
				printf("RECORRER LISTA\n");
				recorrerlista(Nueva);
			break;

			case 10:
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
