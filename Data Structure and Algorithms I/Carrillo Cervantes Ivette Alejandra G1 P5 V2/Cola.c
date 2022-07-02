#include "Cola.h"

struct Cola{
    int primero;
    int ultimo;
    int lista[100];
};

Cola crearCola(){ 
	Cola c; // CREAMOS UNA COLA "C"
	c.primero=1; // SE ENCARGA DE DESENCOLAR
	c.ultimo=0; // ELEMENTO INGRESADO
	return c; // RETORNA UNA COLA
}

int isEmptyC(Cola c){ // TE DA LA COLA "C"
	if(c.primero==c.ultimo+1) // VERIFICAMOS SI LA COLA ESTA VACIA
		return 1; // DEVUELVE 1, SI LA COLA ESTA VACIA
	return 0; // SI ENCUENTRA ALGUN ELEMENTO, REGRESA UN 0
}

void encolar(Cola *c,int x){ // NO VA A REGRESAR NADA, 
	// SOLO METE VALORES, RECIBE LOS PARAMETROS C, Y X
	c->lista[c->ultimo]=x; // LA LISTA EN EL INDICE ULTIMO SERÁ EL VALOR X
	c->ultimo+=1; // AUMENTAMOS 1
}
	
int desencolar(Cola *c){ // RECIBE UNA COLA
	if((isEmptyC(*c))==1) // VERIFICAMOS SI ESTA VACIA
		printf("la cola está vacía \n");
	else{
		int aux = c->lista[c->primero-1]; // CREAMOS UN AUX = C EN LA LISTA EN SU INDICE PRIMERO MENOS UNO
		c->primero++; // EL PRIMERO AUMENTA 1 PARA DEJAR EL INDICE ANTERIOR VACIO PARA QUE SE PUEDA ELIMINAR
		if(c->primero==c->ultimo+1){ // DEBEMOS DE HACER OTRA VERIFICACION
			*c=crearCola(); // CUANDO ESTA VACIA, DEBEMOS DE CREAR OTRA COLA PARA QUE SE INICIALICE DESDE CERO
		}
		return aux; // RETORNA LA VARIABLE AUXILIAR
	}
}

int first(Cola c){ // RECIBE UNA COLA
	return c.lista[c.primero-1]; // ACCEDEMOS A SU PRIMERO Y RETORNAMOS EL VALOR DEL ULTIMO ELEMENTO INGRESADO
}
