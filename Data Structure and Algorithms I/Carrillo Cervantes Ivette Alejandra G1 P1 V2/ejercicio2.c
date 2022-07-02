/* Carrillo Cervantes Ivette Alejandra 
Estructuras de Datos y Algoritmos I
Grupo 1 
*/

#include <stdio.h>

/* Escribe un programa para trabajar sobre un arreglo de 8 elementos en el 
cual se mostrará al usuario un menú con las siguientes operaciones:
1) Ingresar o modificar elementos del arreglo
2) Mostrar la Suma de los elementos
3) Realizar la multiplicación de los elementos
4) Realizar la suma solo de los elementos divisibles entre 3
5) Multiplicar por 3 cada elemento del arreglo

El usuario seleccionará la opción de su preferencia y el programa mostrará 
los datos del arreglo original y el resultado de la opción seleccionada 
El programa debe realizarse en un menú que debe ejecutarse continuamente hasta que el usuario decida salir
*/

// NOTA: Este programa lo inicie en clase con funciones pero se me complico un poco, así que decidí cambiar de formato
int main () {

	printf("\n\tARREGLOS\n\n");

	//Declaramos variables
	short op = 0;
	int arr[8]; 
	int arr2[8];
	int i, j, valor;
	int sum = 0, sum2 = 0;
	int mul = 1;

		while (1){ 

	//Mostramos opciones
	printf("\n%cQu%c desea realizar?\n", 168, 130); 

	printf("1) Ingresar o modificar elementos del arreglo\n");
	printf("2) Mostrar la Suma de los elementos\n"); 
	printf("3) Realizar la multiplicaci%cn de los elementos\n", 162); 
	printf("4) Realizar la suma solo de los elementos divisibles entre 3\n");
	printf("5) Multiplicar por 3 cada elemento del arreglo\n");
	printf("6) Salir\n\n");

	scanf("%d", &op);

	switch(op){ 

		case 1: 
			// Se utiliza un ciclo for para pedirle al usuario que ingrese los elementos del arreglo.
			for (int i = 0; i < 8; ++i)
			{
				printf("Ingresa Elemento [%d]: ", i+1);
				scanf("%d", &arr[i]);
			}			
			break; 

		case 2: 
			//Se imprimen los datos que el usuario ingreso en el arreglo
			//Arreglo Original
			printf("\nArreglo original: {");	
			for (i = 0; i < 8; ++i)
			{
				printf("%d,", arr[i]);
			}
			printf("}\n");

			//Operación de suma de todos los elementos
			for (int i = 0; i < 8; ++i)
			{
				sum = sum + arr[i];

			}

			//Se imprime el resultado de la suma
			printf("La suma de los elementos es: %d\n", sum);
			break;

		case 3:
			//Se imprime el Arreglo Original
			printf("\nArreglo original: {");	
			for (i = 0; i < 8; ++i)
			{
				printf("%d,", arr[i]);
			}
			printf("}\n");

			//Operación de multiplicación de todos los elementos
			for (int i = 0; i < 8; ++i)
			{
				mul = mul * arr[i];

			}

			//Se imprime el resultado de la multiplicación
			printf("La multiplicaci%cn de los elementos es: %d\n", 162, mul);
			break;

		case 4:
			//Se imprime el Arreglo Original
			printf("\nArreglo original: {");	
			for (i = 0; i < 8; ++i)
			{
				printf("%d,", arr[i]);
			}
			printf("}\n");

		
			//Se hace la operación suma para los elementos que se puedan dividir entre 3
			for (int i = 0; i < 8; ++i)
			{
					if (arr[i] % 3 == 0 ) //Si el numero del arreglo se puede dividir entre 3
				{
					sum2 = sum2 + arr[i]; //Se hará la suma correspondiente
				}
			}

			//Se imprime el resultado de la suma de los elementos que se pueden dividir entre 3
			printf("\nLa suma de los elementos que se pueden dividir entre 3 es: %d \n", sum2); 
			break;

		case 5:

			//Se imprimen los datos que el usuario ingreso en el arreglo.
			printf("\nArreglo original: {");	
			for (i = 0; i < 8; ++i)
			{
				printf("%d,", arr[i]);
			}
			printf("}\n");

			//Se hace la operación
			for (int i = 0; i < 8; ++i)
			{
					arr2[i] = arr[i] * 3;
			}
			
			/*Se imprime un nuevo arreglo donde aparezca el resultado de cada 
			elemento del arreglo original multiplicado por 3
			*/
			printf("El arreglo al multiplicarlo por 3 queda: {");
			for (int i = 0; i < 8; ++i)
			{
				printf("%d,", arr2[i]); 
			}
			printf("}\n");
			break;

		case 6:
			//Opción Salir
			return 0; 

		default: 
			printf("Opci%cn no v%Clida.\n", 162, 160); //En caso de que no exista la opción elegida
		} 
	} 
	return 0;
}