// AGREGAMOS EL ARCHIVO HEAD
#include "CircularDoble.h"

// ESTRUCTURA NODO
struct Nodo{
	int val;
	struct Nodo* next; // REFERENCIA AL NODO SIGUIENTE
	struct Nodo* prev; // REFERENCIA AL NODO ANTERIOR
};

// ESTRUCTURA LISTA DE NODOS
struct Lista{
	int tamano; // TAMAÑO DE LA LISTA
	struct Nodo* head; // HEAD COMO EL PRIMER ELEMENTO DE LA LISTA
};

// CREAMOS UNA LISTA
Lista crearLista(){
	Lista lista; // CREAMOS LISTA
	lista.head = NULL; // LA LISTA EN SU HEAD ES IGUAL A NULO
	lista.tamano = 0; // LA LISTA ES DE TAMAÑO CERO
	return lista; // REGRESAMOS LISTA
}

// IMPRIMIMOS UNA LISTA
void print_list(Lista lista) {
	int tamano = lista.tamano;
	if (lista.head == NULL)
	{
		printf("LA LISTA ESTA VACIA\n");
	}
	else{
		printf("LOS ELEMENTOS DE LA LISTA SON: \n");
		Nodo *current = lista.head; // CREAMOS UN NODO PARA RECORRER LA LISTA
		while(tamano>0){ // MIENTRAS QUE EL TAMAÑO SEA MAYOR QUE CERO
			printf("%d\n", current->val); // IMPRIMIMOS EL VALOR DEL CURRENT
			current = current->next; // AUMENTAMOS EL VALOR DE CURRENT HACIA EL SIGUIENTE
			tamano--; // DISMINUIMOS EL TAMAÑO
		}
	}
}

// PRIMER NODO, AGREGA UN ELEMENTO EN LA PRIMERA POSICION
void First(Lista *lista, int val){
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo)); // RESERVAMOS ESPACIO CON MALLOC
	nodo->val = val; // ASIGNAMOS EL VALOR AL NODO NUEVO
	// NO TENEMOS REFERENCIA A NULL, POR LO TANTO QUEDA:
	nodo->next = nodo; 
	nodo->prev = nodo;
	lista->head = nodo;
}

// AGREGAMOS ELEMENTOS AL FINAL
void addFinalLista(Lista *lista, int val) { // RECIBIMOS EL APUNTADOR DE LA LISTA Y EL VALOR QUE SE QUIERE AGREGAR
	if (lista->head == NULL) // SI LA LISTA EN SU HEAD ES NULL
	{
		First(lista, val); // LLAMAMOS A LA FUNCION PRIMER NODO
	}
	else{
		Nodo *nuevo, *temp; // CREAMOS DOS
		nuevo = (Nodo *)malloc(sizeof(Nodo)); // RESERVAMOS MEMORIA
		nuevo->val = val; // ASIGNAMOS EL VALOR QUE NOS DIO EL USUARIO AL NUEVO NODO
		nuevo->next = lista->head; // EL SIGUIENTE DEL NUEVO NODO SERA IGUAL A HEAD
		nuevo->prev = lista->head->prev; // EL PREVIO DEL NUEVO NODO SERA IGUAL A AL PREVIO DEL HEAD
		lista->head->prev = nuevo; // EL PREVIO DEL HEAD SERA IGUAL AL NUEVO
		temp = lista->head; // EL TEMP SERA IGUAL A LA LISTA EN SU HEAD

		while(temp->next != lista->head){ // RECORRE LA LISTA TEMP
			temp = temp->next; // AUMENTA DE UNO EN UNO 
		} 
		temp->next = nuevo; // EL SIGUIENTE DE TEMP SERA EL NUEVO NODO
	}
	lista->tamano++; // AUMENTAMOS EL TAMAÑO
}

// AGREGAMOS ELEMENTOS AL INCIIO
void addPrincipioLista(Lista *lista, int val){ // RECIBE EL APUNTADOR DE LA LISTA Y SU VALOR
	if (lista->head == NULL) // SI HEAD ES NULL
	{
		First(lista, val); // LLAMAMOS A LA FUNCION PRIMER NODO
	}
	else{
		Nodo *nuevo, *temp; // CREAMOS DOS NODOS, UNO NUEVO Y OTRO TEMPORAL
		nuevo = (Nodo *)malloc(sizeof(Nodo)); // RESERVAMOS EL NUEVO NODO CON MALLOC
		nuevo->val = val; // ASIGNAMOS EL VALOR
		nuevo->next = lista->head; // EL SIGUIENTE DEL NUEVO SERA IGUAL AL HEAD
		nuevo->prev = lista-> head->prev; // EL PREVIO DEL NUEVO SERA IGUAL AL PREVIO DEL HEAD
		lista->head->prev = nuevo; // EL PREVIO DEL HEAD SERA IGUAL AL NUEVO

		temp = lista->head; // POSICIONAMOS TEMP EN EL HEAD

		while(temp->next != lista->head){ // RECORREMOS LA LISTA
			temp = temp->next; // AUMENTA DE UNO EN UNO
		} 
		temp->next = nuevo; // EL SIGUIENTE DE TEMP SERA EL NUEVO NODO
		lista->head = nuevo; // EL HEAD DE LA LISTA SERA EL NUEVO NODO
	}
	lista->tamano++; // AUMENTAMOS DE TAMAÑO
}

// AGREGAR EN LA POSICION N-ESIMA DE LA LISTA
void addNesimo(Lista *lista, int val, int lugar){ // RECIBE EL APUNTADOR DE LA LISTA, SU VALOR Y EL LUGAR QUE SE QUIERE AGREGAR

	// ESTE NO ME QUEDO ): 


	if (lugar>(lista->tamano+1)) // VERIFICAMOS SI EXISTE EL TAMAÑO 
	{
		printf("\nNO EXISTE LA POSICION EN LA LISTA\n");
	}
	else{
		if (lugar == 1)
		{
			addPrincipioLista(lista, val);
		}
		else{
			Nodo *temp = lista->head;
			Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
			for (int i = 0; i < (lugar-1); ++i)
			{
				temp = temp->next;
			}
			nuevo->val = val;
			temp->prev->next = nuevo;
			nuevo->prev = temp->prev;
			temp->prev = nuevo;
			nuevo->next = temp;
			lista->tamano++;
		}
		printf("\nSE AGREGO %d EN EL LUGAR %d DE LA LISTA\n", val, lugar);
	}
}

// ELIMINAMOS EL PRIMER ELEMENTO DE LA LISTA
void borrarPrimero(Lista *lista){
	if(lista->head == NULL){ // SI EL HEAD DE LA LISTA ES NULL
		printf("LA LISTA ESTA VACIA\n");
	}
	else{ // SI NO
		Nodo *temp = lista->head; // SE CREA UN NODO TEMPORAL EL CUAL SERA IGUAL AL HEAD
	    while(temp->next!=lista->head){ // SE RECORRE LA LISTA
	    	temp = temp->next; // AUMENTA DE UNO EN UNO 
		}
		temp->next  = lista->head->next; // EL SIGUIENTE DEL T¿NODO TEMPORAL SERA EL SIGUIENTE DEL HEAD
		lista->head->next->prev = temp; 
		temp = lista->head->next;

		// ELIMINAMOS LA LISTA EN SU HEAD
		free(lista->head);
		lista->head = temp;
	}
	lista->tamano--;
}

// ELIMINAMOS EL ULTIMO ELEMENTO DE LA LISTA
void borrarUltimo(Lista *lista){

		Nodo *temp = lista->head; // CREAMOS UN NODO TEMPORAL EL CUAL SE VA A POSICIONAR EN EL HEAD
		
		while(temp->next!=lista->head){ // RECORREMOS LA LISTA
    		temp = temp->next; // AUMENTA DE UNO EN UNO 
		}
		temp= temp->prev; // EL NODO TEMPORAL SERA IGUAL A SU PREVIO
		
		lista->head->prev = temp; // EL PREVIO DEL HEAD SE IGUALARA AL TEMPORAL
		temp->next = lista->head; // EL SIGUIENTE SERA IGUAL AL HEAD DE LA LISTA
		
		// ELIMINAMOS EL NODO
		lista->head->prev = NULL;
		lista->head->prev = temp;
		
		lista->tamano--;
}