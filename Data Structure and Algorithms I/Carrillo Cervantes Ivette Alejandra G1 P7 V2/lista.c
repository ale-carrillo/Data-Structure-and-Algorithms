// INCLUIMOS EL HEAD DE LISTA
#include "lista.h"

// ESTRUCTURA NODO
struct Nodo{
    int val; // VALOR
    struct Nodo* next; // APUNTADOR AL SIGUIENTE NODO
};

// ESTRUCTURA LISTA DE NODOS
struct Lista{
	struct Nodo* head; // PRIMER ELEMENTO HEAD
};

// CREAMOS UNA LISTA
Lista crearLista(){
	Lista lista; // CREAMOS UNA LISTA
	lista.head = NULL; // EL PRIMER ELEMENTO SE IGUALA A NULL
	return lista; // REGRESA UNA LISTA, NO DEVUELVE NINGUN VALOR
}

// IMPRIMIMOS UNA LISTA
void print_list(Lista lista) { // RECIBIMOS UNA LISTA
    if(lista.head==NULL){ // SI EL ELEMENTO DE LA LISTA EN HEAD ES IGUAL A NULL
    	printf("LA LISTA ESTA VACIA \n"); // LA LISTA ESTA VACIA
    }
    else{ // SI NO ESTA VACIA
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head; // CREAMOS UN NODO PARA RECORRER LA LISTA
   		while (current != 0) { // MIENTRAS CURRENT SEA DIFERENTE A NULL (RECORRE LA LISTA HASTA EL FINAL)
        	printf("%d \n",current->val); // IMPRIME LOS VALORES
			current = current->next; // AUMENTAMOS EL VALOR DE CURRENT DE 1 EN 1
   	 	}
	}
}

// AGREGAMOS UN NODO AL PRINCIPIO DE LA LISTA
void addPrincipioLista(Lista *lista, int val) { // RECIBIMOS LA LISTA CON SU APUNTADOR Y SU VALOR DEL NODO NUEVO
	Nodo *new_node;// CREAMOS UN NUEVO NUEVO
    new_node = (Nodo*)malloc(sizeof(Nodo)); // ASIGNAMOS MEMORIA DINAMICA PARA ALMACENAR EL NODO NUEVO
    new_node->val = val; // EL VALOR DEL NUEVO NODO SERA IGUAL AL VALOR QUE LE PASAMOS A LA FUNCION
    new_node->next = lista->head; // EL NUEVO NODO EN SU ELEMENTO SIGUIENTE SERA IGUAL A HEAD
    lista->head = new_node; // EL HEAD SERÁ IGUAL AL NUEVO NODO
}

// AGREGAMOS UN NODO AL FINAL DE LA LISTA
void addFinalLista(Lista *lista, int val) { // RECIBIMOS A LA LISTA CON SU APUNTADOR Y SU VALOR DEL NODO NUEVO
	if(lista->head==NULL){ // SI LA LISTA EN HEAD ES IGUAL A NULO, OSEA ESTA VACIA
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo)); // CREAMOS UN NUEVO NODO EL CUAL RESERVAMOS CON MALLOC
		nodo->val = val; // EL VALOR DEL NUEVO NODO SERA IGUAL AL VALOR QUE LE PASAMOS A LA FUNCION
    	nodo->next = NULL; // EL NODO EN SU ELEMENTO SIGUIENTE SERA IGUAL A NULL (LO ULTIMO)
    	lista->head = nodo; // LISTA EN HEAD SERA IGUAL A SU NUEVO NODO
	}	
	else // SI LA LISTA EN EL HEAD NO ES IGUAL A NULO
	{
		Nodo *current = lista->head; // CREAMOS UN NUEVO NODO TEMPORAL QUE SERA IGUAL AL HEAD
		while (current->next != 0) { // MIENTRAS CURRENT EN SU ELEMENTO NEXT SEA DIFERENTE A NULL, (RECORRE LA LISTA HASTA EL FINAL)
 			current = current->next; // PARA IR INCREMENTANDO DE 1 EN 1 EL VALOR DE CURRENT
 		}
		Nodo *nuevoNodo; // CREAMOS UN NUEVO NODO
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // RESERVAMOS MEMORIA DINAMICA PARA PODER ALMACENAR EL VALOR DEl NODO
    	nuevoNodo->val = val; // EL VALOR DEL NUEVO NODO SERA IGUAL AL VALOR QUE LE PASAMOS A LA FUNCION
    	nuevoNodo->next = NULL; // EL NODO EN SU ELEMENTO SIGUIENTE SERA IGUAL A NULL (LO ULTIMO)
 		current->next = nuevoNodo; // CURRENT EN EL ELEMENTO SIGUIENTE SERA IGUAL AL NUEVO NODO
	}	
}

// SE AGREGA UNA FUNCION DE AGREGAR N-ESIMO
 void addNesimo(Lista *lista, int val, int lugar){ // RECIBIMOS A LA LISTA CON SU APUNTADOR, EL VALOR DEL NODO NUEVO Y EL LUGAR DONDE SE QUIERE AGREGAR
	
	// VERIFICAMOS EL TAMAÑO DE LA LISTA
	int tamano = 1; // INICIALIZAMOS UNA VARIABLE "tamano" IGUAL A UNO, YA QUE IRA AUMENTANDO
	Nodo *current = lista->head; // CREAMOS UN NODO CURRENT EL CUAL SERA IGUAL AL HEAD
	while (current->next != NULL) // MIENTRAS CURRENT EN SU ELEMENTO NEXT SEA DIFERENTE A NULL, (RECORRE LA LISTA HASTA EL FINAL)
	{
		current = current->next; // PARA IR INCREMENTANDO DE 1 EN 1 EL VALOR DE CURRENT
		tamano++; // VA A IR AUMENTANDO EL TAMAÑO DE UNO EN UNO
	}


 	if (lugar>(tamano+1)) // SI EL LUGAR EN EL QUE QUIERE AGREGARSE EL NODO, ES MAYOR QUE EL TAMAÑO DE LA LISTA + 1
	{
		printf("\nNO EXISTE LA POSICION EN LA LISTA\n"); // NO EXISTE LA POSICION
	}
	else{ // SI EXISTE LA POSICION, ENTONCES
		if (lugar == 1) // SI EL LUGAR EN EL QUE SE QUIERE AGREGAR EL NODO ES 1
		{
			addPrincipioLista(lista, val); // LLAMAMOS A LA FUNCION AGREGAR PRINCIPIO DE LA LISTA, RECIBE LA LISTA Y EL VALOR QUE SE AGREGARA
		}
		else{ // SI EL LUGAR ES DIFERENTE DE 1, ENTONCES
		 	Nodo *temp = lista->head; // CREAMOS UN NODO TEMPORAL EL QUE IGUALAMOS A HEAD
		 	int i;
		 	for (i = 1; i < (lugar - 1); ++i) // CREAMOS UN CICLO FOR EL CUAL INICIARA DESDE 1 Y SE IRA RECORRIENDO TEMP, HASTA LLEGAR AL LUGAR QUE SE QUIERE AGREGAR -1
		 	{
		 		temp = temp->next; // PARA IR INCREMENTANDO DE 1 EN 1 EL VALOR DE TEMP
		 	}
		 	Nodo *Nuevo = (Nodo *)malloc(sizeof(Nodo)); // CREAMOS UN NODO NUEVO EL CUAL RESERVAMOS CON MALLOC
		 	Nuevo->val = val; // EL VALOR DEL NUEVO NODO SERA IGUAL AL VALOR QUE LE PASAMOS A LA FUNCION

		 	Nuevo->next = temp->next; // ASIGNAMOS EL SIGUIENTE DEL NODO AL SIGUIENTE DE TEMP
		 	temp->next = Nuevo; // EL SIGUIENTE DEL NODO TEMP, SERA IGUAL AL NUEVO NODO
		}
		printf("\nSE AGREGO %d EN EL LUGAR %d DE LA LISTA\n", val, lugar);
	}
 }

// BORRAMOS EL PRIMER NODO DE LA LISTA
void borrarPrimero(Lista *lista) { // RECIBIMOS A LA LISTA CON SU APUNTADOR
    if (lista->head == NULL) { // SI HEAD ES IGUAL A NULL, ESTA VACIA LA LISTA
        printf("La lista esta vacia");
    }
    else{ // SI NO ESTA VACIA LA LISTA
    	Nodo *nuevo_head = NULL; // CREAMOS UN NODO NUEVO HEAD QUE SE IGUALARA A NULL
    	Nodo *temp = lista->head; // CREAMOS UN NODO TEMPORAL TEMP QUE SERA IGUAL AL HEAD DE LA LISTA
    	nuevo_head=temp->next; // HEAD SERA IGUAL AL TEMP EN SU ELEMENTO NEXT
    	free(lista->head); // HACEMOS UN FREE PARA ELIMINAR EL NUEVO ELEMENTO DEL HEAD DE LA LISTA
    	lista->head = nuevo_head; // EL ELEMENTO HEAD SERA IGUAL AL NUEVO HEAD
   		printf("\nSE BORRO AL PRINCIPIO DE LA LISTA\n");
	}
}

// BORRAMOS EL ULTIMO NODO DE LA LISTA
void borrarUltimo(Lista *lista) { // RECIBIMOS LA LISTA CON SU APUNTADOR
    Nodo *temp = lista->head; // CREAMOS UN NODO TEMPORAL EL QUE IGUALAMOS A HEAD
	if (lista->head == NULL) { // SI EL ELEMENTO SIGUIENTE DE TEMP ES NULL, LA LISTA ESTA VACIA
        printf("La lista esta vacia");
    }
    else{ // SI NO ESTA VACIA
    	if(temp->next==NULL){ // SE VA A RECORRER LA LISTA
    		lista->head = NULL; // HEAD ES IGUAL A NULO, OSEA SOLO ESTA ESE ELEMENTO
			free(lista->head); // SE ELIMINA CON UN FREE
    	}else{
    		Nodo *current = lista->head; // CREAMOS UN NODO QUE SERA IGUAL A HEAD
    		while (current->next->next != NULL) { // RECORREMOS CURRENT POR LA LISTA HASTA EL FINAL
        		current = current->next; // VA INCREMENTANDO DE 1 EN 1 EL VALOR DEL CURRENT
    		}
    		current->next = NULL; // CUANDO ESTE EN EL ULTIMO ELEMENTO
			free(current->next); // SE ELIMINA CON UN FREE		
    	}
    	printf("\nSE BORRO AL FINAL DE LA LISTA\n");
	}
}

 // ELIMINAR N-ESIMO DE LA LISTA
 void eliminarNesimo(Lista *lista, int lugar){ // RECIBIMOS A LA LISTA CON SU APUNTADOR, EL VALOR DEL NODO NUEVO Y EL LUGAR DONDE SE QUIERE ELIMINAR
 	
	// VERIFICAMOS EL TAMAÑO DE LA LISTA
	int tamano = 1; // INICIALIZAMOS UNA VARIABLE "tamano" IGUAL A UNO, YA QUE IRA AUMENTANDO
	Nodo *current = lista->head; // CREAMOS UN NODO CURRENT EL CUAL SERA IGUAL AL HEAD
	while (current->next != NULL) // MIENTRAS CURRENT EN SU ELEMENTO NEXT SEA DIFERENTE A NULL, (RECORRE LA LISTA HASTA EL FINAL)
	{
		current = current->next; // PARA IR INCREMENTANDO DE 1 EN 1 EL VALOR DE CURRENT
		tamano++; // VA A IR AUMENTANDO EL TAMAÑO DE UNO EN UNO
	}

 	if (lugar >= tamano+1) // SI EL LUGAR EN EL QUE QUIERE AGREGARSE EL NODO, ES MAYOR O IGUAL QUE EL TAMAÑO DE LA LISTA + 1
	{
		printf("\nNO EXISTE LA POSICION EN LA LISTA\n");
	}
	else{ // SI EXISTE LA POSICION
		if(lugar == 1){ // SI EL LUGAR ES IGUAL A 1
			borrarPrimero(lista); // LLAMAMOS A LA FUNCION BORRAR PRIMERO, RECIBE LA LISTA
		}
		else{
			Nodo *temp = lista->head;
			int i;
		 	for (i = 1; i < (lugar - 1); ++i) // CREAMOS UN CICLO FOR EL CUAL INICIARA DESDE 1 Y SE IRA RECORRIENDO TEMP, HASTA LLEGAR AL LUGAR QUE SE QUIERE AGREGAR -1
		 	{
		 		temp = temp->next; // PARA IR INCREMENTANDO DE 1 EN 1 EL VALOR DE TEMP
		 	}
		 	Nodo *eliminar = temp; // CREAMOS UN NODO ELIMINAR EL CUAL IGUALAREMOS A TEMP
		 	eliminar = eliminar->next; // EL NODO ELIMINAR SERÁ IGUAL AL SIGUIENTE DE ESE MISMO NODO
		 	temp->next = eliminar->next; // EL SIGUIENTE DE TEMP, SE ASIGNARA AL SIGUIENTE DE ELIMINAR

		 	// ELIMINAMOS EL NODO "eliminar"
		 	eliminar = NULL; 
		 	free(eliminar);		
		}
		printf("\nSE ELIMINO EL LUGAR %d DE LA LISTA\n", lugar);
	}
}

// EL VALOR DEL PRIMER ELEMENTO
int primerElemento(Lista lista){ // RECIBIMOS UNA LISTA
	return lista.head->val; // RETORNAMOS EL VALOR DE HEAD (EL VALOR DEL PRIMER NODO)
}


 // SE BUSCA UN ELEMENTO 
 int buscar(Lista lista, int var){
 	Nodo *temp = lista.head; // CREAMOS UN NODO TEMPORAL EL QUE IGUALAMOS A HEAD
 	int encontrado = 0; // CONTADOR QUE INICIA DESDE CERO
 	while(temp != NULL){ // SE RECORRE LA LISTA
 		if (temp->val == var) // SI EL VALOR QUE SE BUSCA ES IGUAL A LA LA VARIABLE DEL NODO
 		{
 			encontrado += 1; // SE VA SUMANDO 1 AL CONTEO
 		}
 		else { // SI NO SE ENCUENTRA SE SUMA CERO
 			encontrado += 0;
 		}
 		temp = temp->next;
 	}
 	return encontrado;
 }

// ELIMINAMOS ELEMENTOS MENORES A UN VALOR DADO
void eliminarMenores(Lista *lista,int var){ // RECIBE EL APUNTADOR DE LA LISTA Y EL ELEMENTO MAYOR
	Nodo *temp = lista->head; // SE CREA UN NUEVO NODO TEMPORAL
	int posicion = 1; // CREAMOS UNA VARIABLE QUE TENGA LA POSICION DEL NODO QUE SE QUIERE ELIMINAR
	int eliminados = 0; // CREAMOS UNA VARIABLE QUE LLEVE EL CONTRO DE LOS NODOS ELIMINADOS, LA INICIALIZAMOS EN CERO

	while(temp != NULL){ // SE VA A RECORRER LA LISTA
		if (temp->val < var) // SI EL VALOR DEL NODO ES MENOR QUE EL VALOR QUE EL USUARIO INGRESO
		{
			temp = temp->next; // PARA QUE SE RECORRA LA LISTA DE UNO EN UNO

			eliminarNesimo(lista, posicion); // LLAMAMOS A LA FUNCION ELIMINAR NESIMO PARA QUE ELIMINE CADA VALOR QUE SEA MENOR
			eliminados++; // SI SE CUMPLE ESTA CONDICION VA A IR AUMENTANDO DE UNO EN UNO EL NUMERO DE NODOS ELIMINADOS
		}
		else{ // SI NO ES MENOR EL NUMERO
			temp = temp->next; // SE RECORRE LA LISTA DE UNO EN UNO 
			posicion++; // AUMENTA LA POSICION
		}
	}

	if (eliminados==0) // SI NO HAY NINGUN ELEMENTO ELIMINADO
	{
		printf("NO SE ELIMINO NINGUN ELEMENTO\n");
	}
	else{ // SI HAY ALGUNO, SE INDICA CUANTOS ELEMENTOS SE ELIMINARON
		printf("SE ELIMINARON %d ELEMENTOS\n", eliminados);
	}
}


