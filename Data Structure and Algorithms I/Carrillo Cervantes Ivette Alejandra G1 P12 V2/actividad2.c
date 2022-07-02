// Carrillo Cervantes Ivette Alejandra
// Juárez Juárez María José
// Estructura de Datos y Algoritmos I

#include <stdio.h>

int cat(int num){
	if (num%2==0)
	{
		num--;
	}
	if (num>0)
	{
		printf("%d\n", num);
		cat(num-2);
	}
}

void main(){
	int num;
	printf("\nIngrese un numero: ");
	scanf("%d", &num);
	cat(num);
}