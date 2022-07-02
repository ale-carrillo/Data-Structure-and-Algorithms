/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>
 
 int arr1 [3] [4] [5] [2], var, h, i, j, k; // Variables a utilizar
 int *point; // Declaración del apuntador
 void main (){
 	int i;
 	point = &arr1[0][0][0][0];
 	var = 1;

 	for (int h = 0; h < 3; ++h)
 	{
	 	for (int i = 0; i < 4; ++i)
	 	{
	 		for (int j = 0; j < 5; ++j)
	 		{
	 			for (int k = 0; k < 2; ++k)
	 			{
	 				arr1 [h][i][j][k] = var; 
	 				var += 2;
	 			}
	 		} 	
	 	}

 	}

 	int a = *(point + 3);
 	int b = *(point + 12);
 	int c = *(point + 27);

 	// Se imprime el valor de a, b, c
 	printf("\n\n\ta=%d\tb=%d\tc=%d\n", a, b, c);

 		// 121, ya que 120 es el resultado de multiplicar a los indices 
 		for (int var = 1; var < 121; ++var)
	 	{
	 		if (var < 31)
	 		{
	 			*(point + var) = 5 * var;
	 		}
	 		else if (var > 31 || var < 61) 
	 		{
	 			*(point + var) = 6 * (var); 
	 		}
	 		else if (var > 61 || var < 91)
	 		{
	 			*(point + var) = 7 * (var); 
	 		}
	 		else if (var > 91 || var < 121)
	 		{
	 			*(point + var) = 3 * (var); 
	 		}
	 	}
	 	
	 	// NOTA: Modifique algo en este ciclo y el anterior
	 	// No se que fue lo que quite pero ya no se imprime bien ):

	 	//Se imprime el arreglo modificado

		 for (int i = 0; i < 4; ++i) // Se repite 4 veces, ya que son los planos que se utilizaran
		 {
			printf("\n\n\n\n");
			for (int var = i; var < (10+(1+i)*30); ++var)
			{
				printf("%d\t", *(point+var)); // Se imprime el arreglo modificado
			}
			printf("\n\n");
		 }
 }