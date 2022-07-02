/* Carrillo Cervantes Ivette Alejandra 
Estructuras de Datos y Algoritmos I
Grupo 1 
*/

#include <stdio.h>

/*Codifica, compila y ejecuta el siguiente código, en caso de que se ejecute correctamente 
indica la salida y qué hace el programa. En caso de que no compile o se obtengan resultados diferentes a los esperados, 
indica el por qué y realiza la corrección respectiva en el código.

*/
void main () {
	int i, j, k;
	int arr[2][3][5]={2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60};

	for (i=0; i<2; i++){
		for (j=0; j<3; j++){
			for (k=0; k<5; k++){
				printf("Arreglo[%d][%d][%d]: %d\n", i, j, k, arr[i][j][k]);
			}
		}
	}
}