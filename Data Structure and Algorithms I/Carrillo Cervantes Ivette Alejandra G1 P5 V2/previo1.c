#include "Pila.c"
#include "Cola.c"

int main(){

	printf("\n___________PILA_____________________________\n");
	
	// CREAMOS UNA PILA
	Pila previo = crearPila();

	// INGRESAMOS ELEMENTOS
	printf("\nNO INGRESAMOS NINGUN VALOR\n");
	printf("Valor dentro del Tope es: %d \n", top(previo));

	push(&previo, 6); // 
	printf("\nINGRESAMOS EL VALOR 6 A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	push(&previo, 16); //
	printf("\nINGRESAMOS EL VALOR 16 A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	push(&previo, 4); //
	printf("\nINGRESAMOS EL VALOR 4 A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	pop(&previo);
	printf("\nELIMINAMOS UN VALOR A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	pop(&previo);
	printf("\nELIMINAMOS UN VALOR A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	push(&previo, 9); //
	printf("\nINGRESAMOS EL VALOR 9 A LA PILA\n");
	printf("VALOR DEL TOPE: %d \n", previo.tope);
	printf("VALOR DENTRO DEL TOPE: %d \n\n", top(previo));

	printf("\n___________COLA_____________________________\n");

	// CREAMOS UNA COLA
	Cola previoC = crearCola();
	printf("\nEL PRIMER ELEMENTO DE LA COLA ES: %d\n", previoC.primero); 
	printf("EL ULTIMO ELEMENTO DE LA COLA ES: %d\n", previoC.ultimo); 

	encolar(&previoC, 16);
	printf("\nINGRESAMOS EL VALOR 16 A LA COLA\n");

	encolar(&previoC, 5);
	printf("\nINGRESAMOS EL VALOR 5 A LA COLA\n");

	encolar(&previoC, 23);
	printf("\nINGRESAMOS EL VALOR 23 A LA COLA\n");

	printf("\nVALOR DENTRO DE LA COLA AL DESENCOLAR: %d \n", desencolar(&previoC));

	encolar(&previoC, 52);
	printf("\nINGRESAMOS EL VALOR 52 A LA COLA\n");

	printf("\nVALOR DENTRO DE LA COLA AL DESENCOLAR: %d \n", desencolar(&previoC));

}