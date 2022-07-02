/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>

void duplicando();

int main(){

	//Variables a utilizar
	int arr[5][4];
	int *ap; // Declaración del apuntador
	int i, j;

	ap = &arr[0][0]; // Asociación del apuntador con el arreglo
	
	printf("\n");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("Ingrese valor [%d] [%d]: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
		}
	}

	//Se imprime el arreglo original
	printf("\nArreglo Original: \n\n");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{

				printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	duplicando (arr); // Se llama a la función

	// Se imprime el arreglo modificado
	printf("\nArreglo modificado: \nLos valores de los renglones pares se multiplican por 2 y\nlos valores de los renglones impares por 3\n\n");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{

				printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

}
	

// Función duplicando
// Función que sí reciben parámetros y que no devuelven valores
// Se usa este tipo de función, ya que es un arreglo
void duplicando(int arr[5][4]){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{		
			if(i == 0 || i == 2 || i == 4) // Si es el renglón 0, 2, 4 se multiplican por 2
			{
				arr[i][j] *= 2;

			}
			else // Si no son los renglones 0, 2, 4, se multiplicarán por 3
			{
				arr[i][j] *= 3;
			}
		}
	}
}