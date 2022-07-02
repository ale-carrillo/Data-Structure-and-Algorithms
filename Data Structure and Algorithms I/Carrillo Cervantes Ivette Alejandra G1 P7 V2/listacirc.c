#include "listacirc.h"

struct Nodo{
    int val; // VALOR COMO ENTERO
    struct Nodo* next; // REFERENCIA A LA ESTRUCTURA NODO AL NODO SIGUIENTE
};

struct Lista{
	struct Nodo* head; // HEAD PARA EL PRIMER ELEMENTO DE LA LISTA
	int tamano; // TAMAÑO COMO ENTERO
};

// CREAMOS UNA LISTA
Lista crearLista(){
	Lista lista; // CREAMOS UNA LISTA
	lista.head = NULL; // EL HEAD SERÁ EL ULTIMO ELEMENTO AL MOMENTO DE CREARLA
	lista.tamano = 0; // TENDRA UN TAMAÑO DE CERO ELEMENTOS
	return lista; // REGRESAMOS ESA LISTA
}


// IMPRIMIMOS UNA LISTA
void print_list(Lista lista) { // RECIBIMOS UNA LISTA COMO PARAMETRO
    if(lista.head==NULL){ // SI LA LISTA ESTA VACIA
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{ // SI NO ESTA VACIA
    	int tamano = lista.tamano;				//se define el tamaño
		printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head; // CREAMOS UN NODO QUE RECORRA LA LISTA
   		while (tamano > 0 ) {					//tamaño como condicional
        	printf("%d \n", current->val);
        	current = current->next; // SE RECORRE UNO EN UNO
        	tamano--;                           //se reduce tamaño
   	 	}
	}
}


// AGREGAMOS ELEMENTOS AL FINAL
void addFinalLista(Lista *lista, int val) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR Y EL VALOR QUE SE QUIERE AGREGAR

	int posicion=lista->tamano; // LA POSICION SERA IGUAL AL TAMAÑO DE LA LISTA
	if(lista->head==NULL){ // SI LA LISTA EN SU HEAD ES NULL (LA LISTA ESTA VACIA), SE AGREGA UN ELEMENTO AL FINAL
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo)); // CREAMOS UN NODO Y LO RESERVAMOS CON MEMORIA DINAMICA
		nodo->val = val; // EL VALOR DEL NODO, SERA IGUAL AL NODO QUE NOS PASARON
    	nodo->next = nodo; // EL SIGUIENTE DEL NODO, SERA IGUAL AL NODO (AUTOREFERENCIA)
    	lista->head = nodo; // LA LISTA EN SU INDICE HEAD SERA EL NODO QUE SE CREO 
	}	
	else // SI LA LISTA NO ESTA VACIA
	{
		Nodo *current = lista->head; // CREAMOS UN NODO CURRENT EL CUAL SERA IGUAL AL HEAD DE LA LISTA
		while (posicion!=1) { // MIENTRAS LA POSICION SEA DIFERENTE A 1
       		current = current->next; // VAMOS RECORRIENDO UNO A UNO HASTA EL FINAL DE LA LISTA
       		posicion--; // DISMINUIMOS EL VALOR DE LA POSICION
 		}
		Nodo *nuevoNodo; // CREAMOS UN NUEVO NODO
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // RESERVAMOS LA MEMORIA DINAMICA PARA EL NUEVO NODO
    	current->next = nuevoNodo; // EL SIGUIENTE DE CURRENT (EL FINAL), APUNTARA AL NUEVO NODO
		nuevoNodo->val = val; // EL VALOR DEL NUEVO NODO, SERA IGUAL AL VALOR QUE PASO LA FUNCION
    	nuevoNodo->next = lista->head; // LA REFERENCIA DEL ULTIMO NODO ES EL PRIMERO
 		
	}	
	lista->tamano++; // AUMENTAMOS EN 1 EL TAMAÑO DE LA LISTA
}


// AGREGAMOS ELEMENTOS AL INCIIO
void addPrincipioLista(Lista *lista, int val) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR Y EL VALOR QUE SE QUIERE AGREGAR
	
	Nodo *node,*temp; // CREAMOS DOS NODOS, EL QUE SE VA A AGREGAR Y UNO TEMPORAL
    node = (Nodo*)malloc(sizeof(Nodo)); // RESERVAMOS CON MEMORIA DINAMICA EL NODO "NODE"
    node->val = val; // ASIGNAMOS EL VALOR DEL NODO, IGUAL AL VALOR QUE PASO LA FUNCION
    if(lista->head==NULL){ // SI LA LISTA ESTA VACIA
    	node->next=node; // EL SIGUIENTE DEL NODO, SERA A EL NODO MISMO (AUTOREFERENCIA)
	}
    else{
    	node->next = lista->head; // EL NUEVO NODO SERA IGUAL AL HEAD DE LA LISTA
		temp = lista->head; // EL NODO TEMPORAL SERA IGUAL A EL HEAD DE LA LISTA
    	while(temp->next != lista->head){ // RECORREMOS LA LISTA
    		temp=temp->next; // AUMENTAMOS DE 1 EN 1
		}
		temp->next=node; // EL SIGUIENTE NODO DEL FINAL, ES EL PRIMERO
	}
	lista->head = node; // LA LISTA EN EL HEAD ES IGUAL AL NODO QUE VAMOS A AGREGAR
    lista->tamano++; // AUMENTAMOS EL TAMAÑO DE LA LISTA
}

// ELIMINAMOS EL PRIMER ELEMENTO DE LA LISTA
void borrarPrimero(Lista *lista) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR
    if (lista->head == NULL) { // SI LA LISTA ESTA VACIA
        printf("La lista esta vacia");
    }
    else{ // SI NO ESTA VACIA
    	Nodo *nuevo_head = NULL; // CREAMOS UN NUEVO NODO HEAD QUE ESTARA IGUALADO AL NULL (RESTABLECEMOS EL VALOR DEL HEAD)
    	Nodo *temp = lista->head; // ASIGNAMOS UN NODO TEMPORAL A EL VALOR ACTUAL DEL HEAD
    	nuevo_head=temp->next; // EL VALOR DE HEAD, SERA IGUAL AL SIGUIENTE DE NEXT
    	free(lista->head); // LIBERAMOS HEAD
    	lista->head = nuevo_head; // LA LISTA EN SU HEAD, SERA EL NUEVO NODO QUE SE CRE
		lista->tamaño--; // EL TAMAÑO DE LA LISTA VA A DISMINUIR
	}
}

// ELIMINAMOS EL ULTIMO ELEMENTO DE LA LISTA
void borrarUltimo(Lista *lista) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR
    Nodo *temp = lista->head; // ASIGNAMOS UN NODO TEMPORAL A EL VALOR ACTUAL DEL HEAD
	if (lista->head == NULL) { // SI LA LISTA ESTA VACIA
        printf("La lista esta vacia");
    }
    else{ // SI NO ESTA VACIA
    	if(temp->next==NULL){ // SI EL SIGUIENTE DEL TEMPORAL ES IGUAL A NULL (EL ULTIMO)
    		lista->head = NULL; // SE ELIMINA EL HEAD
			free(lista->head);	// LIBERAMOS EL HEAD
			lista->tamaño--; // EL TAMAÑO DE LA LISTA VA A DISMINUIR
    	}else{ // SI NO
    		Nodo *current = lista->head; // CREAMOS UN CURRENT PARA IR RECORRIENDO LA LISTA Y LO IGUALAMOS AL HEAD
    		Nodo *current2 =current->next; //
    		while (current2->next != NULL) {
        		current = current->next;
    		}
    		free(current->next);
    		current->next = NULL;
    	}
	}
}

