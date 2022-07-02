#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[30];
	char autor [30];
	int numPag;
	int tam;
}Documento;

typedef struct{
	int primero;
	int ultimo;
	Documento documento[100]; // ES UNA COLA DE DOCUMENTOS
}Cola;

Cola crearCola(){
	Cola c;
	c.primero = 1;
	c.ultimo = 0;
	return c;
}

int isEmpty(Cola c){
	if (c.primero == c.ultimo + 1)
	{
		return 1;
	} return 0;
}

void encolar(Cola *c, Documento x){
	c->documento[c->ultimo]=x;
	c->ultimo += 1;
}

Documento desencolar(Cola *c){
	if (isEmpty(*c)==1){
		printf("LA COLA ESTA VACIA\n");
	} else{
		Documento aux = c->documento[c->primero-1];
		c->primero++;
		if (c->primero ==c->ultimo +10)
		{
			*c = crearCola();
		}
		return aux;
	}
}