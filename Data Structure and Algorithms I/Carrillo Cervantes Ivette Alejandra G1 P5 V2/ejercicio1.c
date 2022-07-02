/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include "Pila.c" // INCLUIMOS EL ARCHIVO DONDE TIENE LAS FUNCIONES DE PILA

int main(){
	// CREAMOS LA PRIMERA PILA
	Pila datos = crearPila(); // ALMACENAR LOS DATOS QUE INGRESO EL USUARIO
	Pila mayor = crearPila(); // ALMACENAR EL NUMERO MAYOR
	Pila aux = crearPila(); // PILA AUXILIAR PARA PASAR DATOS A LA OTRA

	// CREAMOS EL CICLO PARA AGREGAR VALORES
	for (int i = 0; i < 10; ++i) // SE VA A REPETIR EL CICLO 10 VECES 
	{
		int valor;
		printf("\nESCRIBE EL VALOR [%d] DE LA PILA:  ", i+1);
		scanf("%d", &valor);
		fflush(stdin);
		// LE PASAMOS LA PILA PARA LLENAR LOS DATOS INGRESADOS POR EL USUSARIO
		push (&datos, valor);
	}

	// DETERMINAMOS EL MAYOR DE LOS DATOS INGRESADOS POR EL USUARIO
	while(isEmpty(datos)==0){ // MIENTRAS QUE LA PILA NO ESTE VACIA
	push(&mayor, pop(&datos)); // AGREGAMOS A LA PILA MAYOR EL POP DE LA PILA EN LA QUE EL USUARIO INGRESO LOS DATOS
		// SACAMOS LOS VALORES DE LA PILA DATOS Y LOS INGRESAMOS A LA PILA MAYOR, PERO SIENDO ESTA DE TIPO LIFO, 
		// EL ULTIMO DATO DE LA PILA DATOS SERA EL PRIMERO QUE INGRESE A LA PILA MAYOR
		while(isEmpty(datos)==0){ // MIENTRAS QUE LA PILA NO ESTE VACIA
			if (top(datos)<top(mayor)) // MIENTRAS QUE LA PILA DE LOS DATOS QUE INGRRESO EL USUARIO ES MENOR QUE EL TOPE DE LA PILA MENOR
			{
				push(&aux, pop(&datos));
			} else{
				push(&aux, pop(&mayor));
				push(&mayor, pop(&datos));
			}
		}
	}

	// IMPRIMIMOS EL VALOR MAYOR DE LOS DATOS INGRESADOS POR EL USUARIO
	printf("\nEL VALOR MAYOR DE LOS NUMEROS INGRESADOS POR EL USUARIO ES: %d\n", pop(&mayor));

}