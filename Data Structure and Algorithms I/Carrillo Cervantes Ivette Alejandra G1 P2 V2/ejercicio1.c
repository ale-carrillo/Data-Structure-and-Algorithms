/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>
int main(){
	int w=10, x=20, y=30, z=40, r1, r2, r3; //variables
	int *p1, *p2, *p3, *p4; //apuntadores
	//p3 es un apuntador, por lo tanto se debe de utilizar el operador indirección *
	p1 = &w;
	p2 = &x; //al asociar el valor con otra variable, el apuntador no debe de llevar el operador indirección
	p3 = &y; //al asociar el valor con otra variable, el apuntador no debe de llevar el operador indirección
			// a la variable asociada se le debe de poner el operador dirección &
	p4 = p1; //p1 no lleva el operador indirección
	r1 = *p1 + *p2; //p1 debe de llevar el operador indirección *
	r2 = *p3 * *p4; //p3 y p4 debe de llevar el operador indirección *
	r3 = *p2 + *p3; //r3 no debe de llevar el operador indirección, ya que no es un apuntador
	printf("\nLos Resultados son %d, %d y %d\n", r1, r2, r3);
}