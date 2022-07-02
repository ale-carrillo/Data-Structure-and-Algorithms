#include <stdio.h>
#include "Pila.h"

struct Pila{
    int tope;
    int lista[100];
};

Pila crearPila(){
	Pila p; // CREAMOS UNA PILA "P"
	p.tope=0; // ACCEDEMOS AL TOPE DE LA LISTA CREADA
	return p; // RETORNAMOS LA PILA
}



int isEmpty(Pila p){ // TE DA LA PILA "P"
	if(p.tope==0) // VERIFICAMOS QUE ESTE VACIA
	// SI LA PILA EN SU INDICE TOPE ES IGUAL A CERO
		return 1; // REGRESA 1
	return 0; // REGRESA 0
}

void push(Pila *p,int x){ // METEMOS ELEMENTOS, PILA* P, 
	// Y EL ENTERO QUE VAMOS A METER X SE TRABAJA CON APUNTADOR PILA
	p->lista[p->tope]=x; // ACCEDEMOS A LA LISTA EN EL INDICE TOPE, 
	// LE ASIGNAMOS EL VALOR QUE NOS PASARON
	p->tope++; // UNA VEZ USADO, AUMENTAMOS A UNO EL VALOR DEL TOPE
	// PARA QUE NO SE REESCRIBAN SOBRE ELLOS
}

int pop(Pila *p){ // SACAMOS UN ELEMENTO DE LA PILA, COMO SE VA A MOFICIAR SE USA PASO POR REFERENCIA
	if(isEmpty(*p)==1){ // MANDA A LLAMAR A LA FUNCION "isEmpty", PARA SABER SI ESTA VACIA O NO
		// LE PASAMOS LA PILA QUE RESIVE A "isEmpty"
		printf("La pila ya est%c vac%ca. \n",160,161);
		return -1; // SI LA FUNCION NOS RETORNA -1, LA PILA ESTA VACIA
	}
	else{
		int aux = p->lista[p->tope-1]; // AUX = LISTA EN EL INDICE TOPE MENOS UNO, YA QUE SE QUITA
		p->tope--; // DISMINUIMOS EL TOPE POR QUE SACAMOS UN ELEMENTO
		return aux; // REGRESAMOS EL VALOR DEL ULTIMO VALOR INGRESADO CUANDO YA SACAMOS UN ELEMENTO
	}
}

int top(Pila pila){ // RECIBIMOS LA PILA "pila"
	if(isEmpty(pila)==1){ // COMO NO CAMBIAMOS NADA, NO PONEMOS APUNTADOR,
	// YA QUE SOLO QUEREMOS VER EL ULTIMO ELEMENTO INGRESADO
		printf("La pila ya est%c vac%ca. \n",160,161);
		return -1;
	}
	else{
		return pila.lista[pila.tope-1]; // RETORNAMOS EL ULTIMO VALOR INGRESADO
	}
}

// CUANDO SE HACE PASO POR REFERENCIA ES POR QUE VAMOS A HACER ALGUNA MODIFICACION
// CUANDO SE HACE PASO POR VALOR ES POR QUE NO VAMOS A CAMBIAR NADA
