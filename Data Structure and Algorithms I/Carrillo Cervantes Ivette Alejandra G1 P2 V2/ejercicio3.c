/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>
#include <math.h>

void potencia();

void main(){
	long var1, var2; // Variables a ocupar
	long *ap1, *ap2; // Declaración de puntadores
	ap1 = &var1; // Asociación del apuntador con la variable 1
	ap2 = &var2; // Asociación del apuntador con la variable 2
	printf("\nIngrese valor 1: ");
	scanf("%d", &var1);
	printf("Ingrese valor 2: ");
	scanf("%d", &var2);

	potencia(&var1, &var2); //Se llama a la función potencia

	//Se imprime el resultado
	printf("\na) Resultado de elevar el primero a la potencia que indique el segundo: %d\n", var2);
	printf("b) Divisi%cn del valor obtenido en el inciso a y el primer valor ingresado: %d\n", 162, var1);
}

// Función potencia
// Función que sí reciben parámetros y que no devuelve valores
void potencia(int *var1, int *var2){
	*var2 = pow(*var1, *var2); // Eleva el primer valor a la potencia que indica el segundo valor
	*var1 = *var2 / *var1; // Realiza la división del reslutado obtenido anteriormente, entre el primero valor
}