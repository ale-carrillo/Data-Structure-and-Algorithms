// ARCHIVO CON LAS OPERACIONES DE UNA LISTA CIRCULAR CON UN TIPO DE DATO ABSTRACTO COMPUTADORA

// AGREGAMOS EL ARCHIVO HEAD
#include "ListaCircComp.h"

// ESTRUCTURA COMPUTADORA
typedef struct {
	char id[20];	
	char marca[20];
	char modelo[20];
	char procesador[20];
	char memoria[20];
	int RAM;
	int GB;
}Computadora;

// ESTRUCTURA NODO
struct Nodo{
	Computadora computadora; 
    int val; // VALOR COMO ENTERO
    struct Nodo* next; // REFERENCIA A LA ESTRUCTURA NODO AL NODO SIGUIENTE
};

// ESTRUCTURA LISTA DE NODOS
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
	int indice = 0;
    if(lista.head==NULL){ // SI LA LISTA ESTA VACIA
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{ // SI NO ESTA VACIA
    	int tamano = lista.tamano;				//se define el tamaño
		printf("LOS ELEMENTOS DE LA LISTA SON: \n\n");
    	Nodo *current = lista.head; // CREAMOS UN NODO QUE RECORRA LA LISTA
   		while (tamano > 0 ) {					//tamaño como condicional
        	// IMPRIMIMOS LOS DETALLES
        	printf("- - - - - - - - - - - - - - - - - \n");	
        	printf("\tComputadora %d\n", indice+1);
        	printf("ID: %s\n", current->computadora.id);
        	printf("Marca: %s\n", current->computadora.marca);
        	printf("Modelo: %s\n", current->computadora.modelo);
        	printf("Procesador: %s\n", current->computadora.procesador);
        	printf("Tipo de almacenamiento: %s\n", current->computadora.memoria);
        	printf("Capacidad de memoria RAM: %d\n", current->computadora.RAM);
        	printf("Capacidad de memoria GB: %d\n", current->computadora.GB);
        	current = current->next; // SE RECORRE UNO EN UNO
        	tamano--;                           //se reduce tamaño
   	 		indice++;
   	 	}
	}
}


// AGREGAMOS ELEMENTOS AL FINAL
void addFinalLista(Lista *lista, char id[], char marca[], char modelo[], char procesador[], char memoria[], int RAM, int GB){ // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR Y EL VALOR QUE SE QUIERE AGREGAR

	int posicion=lista->tamano; // LA POSICION SERA IGUAL AL TAMAÑO DE LA LISTA
	if(lista->head==NULL){ // SI LA LISTA EN SU HEAD ES NULL (LA LISTA ESTA VACIA), SE AGREGA UN ELEMENTO AL FINAL
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo)); // CREAMOS UN NODO Y LO RESERVAMOS CON MEMORIA DINAMICA
		strcpy(nodo->computadora.id, id);
		strcpy(nodo->computadora.marca, marca);
		strcpy(nodo->computadora.modelo, modelo);
		strcpy(nodo->computadora.procesador, procesador);
		strcpy(nodo->computadora.memoria, memoria);
		nodo->computadora.RAM = RAM;
		nodo->computadora.GB = GB;

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
		strcpy(nuevoNodo->computadora.id, id);
		strcpy(nuevoNodo->computadora.marca, marca);
		strcpy(nuevoNodo->computadora.modelo, modelo);
		strcpy(nuevoNodo->computadora.procesador, procesador);
		strcpy(nuevoNodo->computadora.memoria, memoria);
		nuevoNodo->computadora.RAM = RAM;
		nuevoNodo->computadora.GB = GB;
    	nuevoNodo->next = lista->head; // LA REFERENCIA DEL ULTIMO NODO ES EL PRIMERO
	}	
	lista->tamano++; // AUMENTAMOS EN 1 EL TAMAÑO DE LA LISTA
}


// AGREGAMOS ELEMENTOS AL INICIO
void addPrincipioLista(Lista *lista, char id[], char marca[], char modelo[], char procesador[], char memoria[], int RAM, int GB) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR Y EL VALOR QUE SE QUIERE AGREGAR
	
	Nodo *node,*temp; // CREAMOS DOS NODOS, EL QUE SE VA A AGREGAR Y UNO TEMPORAL
    node = (Nodo*)malloc(sizeof(Nodo)); // RESERVAMOS CON MEMORIA DINAMICA EL NODO "NODE"
	strcpy(node->computadora.id, id);
	strcpy(node->computadora.marca, marca);
	strcpy(node->computadora.modelo, modelo);
	strcpy(node->computadora.procesador, procesador);
	strcpy(node->computadora.memoria, memoria);
	node->computadora.RAM = RAM;
	node->computadora.GB = GB;

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
        printf("LA LISTA ESTA VACIA");
    }
    else{ // SI NO ESTA VACIA
    	Nodo *nuevo_head = NULL; // CREAMOS UN NUEVO NODO HEAD QUE ESTARA IGUALADO AL NULL (RESTABLECEMOS EL VALOR DEL HEAD)
    	Nodo *temp = lista->head; // ASIGNAMOS UN NODO TEMPORAL A EL VALOR ACTUAL DEL HEAD
    	nuevo_head = temp->next; // EL VALOR DE HEAD, SERA IGUAL AL SIGUIENTE DE NEXT
    	free(lista->head); // LIBERAMOS HEAD
    	lista->head = nuevo_head; // LA LISTA EN SU HEAD, SERA EL NUEVO NODO QUE SE CRE
		lista->tamano--; // EL TAMAÑO DE LA LISTA VA A DISMINUIR
	}
}

// ELIMINAMOS EL ULTIMO ELEMENTO DE LA LISTA
void borrarUltimo(Lista *lista) { // RECIBE COMO PARAMETRO LA LISTA COMO APUNTADOR
    Nodo *temp = lista->head; // ASIGNAMOS UN NODO TEMPORAL A EL VALOR ACTUAL DEL HEAD
	int posicion = lista->tamano; // LA POSICION SERÁ IGUAL AL TAMAÑO DE LA LISTA
	if (lista->head == NULL) { // SI LA LISTA ESTA VACIA
        printf("LA LISTA ESTA VACIA");
    }
    else{ // SI NO ESTA VACIA
    	if(temp->next == lista->head){ // SI EL SIGUIENTE DEL NODO TEMP ES IGUAL A LA LISTA EN EL HEAD
    		temp->next = NULL; // EL SIGUIENTE DE TEMP SERÁ NULL
    		free(temp->next); // SE ELIMINARA
    		lista->tamano--; // DISMINUIRA EL TAMAÑO
    	}
    	else{ // SI NO
    		Nodo *current = lista->head; // SE CREARA UN NODO CURRENT EL CUAL SERÁ IGUAL A LA LISTA EN EL HEAD
    		while(posicion != 1){ // MIENTRAS QUE LA POSICION SEA DIFERENTE A 1
    			current = current->next; // CURRENT IRA AUMENTANDO DE UNO EN UNO
    			posicion--; // DISMINUIRA LA POSICION
    		}
    		current->next = NULL; // EL SIGUIENTE DEL CURRENT SERÁ NULL
    		free(current->next); // SE ELIMINARA
    		current->next = lista->head; // EL SIGUIENTE DEL CURRENT SERÁ EL HEAD
    		lista->tamano--; // SE DISMINUIRA EL TAMAÑO DE LA LISTA
    	}
	}
}

// AGREGAMOS ELEMENTO EN EL N-ESIMO LUGAR DE LA LISTA
void addNesimo(Lista *lista, char id[], char marca[], char modelo[], char procesador[], char memoria[], int RAM, int GB, int lugar){
	// RECIBE COMO PARAMETROS LA EL APUNTADOR DE LA LISTA Y LOS DATOS QUE EL USUARIO INGRESO CON RESPECTO A LOS MIEMBROS DE LA ESTRUCTURA COMPUTADORA
	if (lugar>(lista->tamano+1)) // SI EL LUGAR ES MAYOR AL TAMAÑO DE LA LISTA + 1
	{
		printf("\nNO SE EXISTE ESA POSICION EN LA LISTA\n");
	}
	else{ // SI NO
		if (lugar == 1) // SI EL LUGAR QUE QUIERE INGRESAR EL USUARIO ES 1
		{
			addPrincipioLista(lista, id, marca, modelo, procesador, memoria, RAM, GB); // SE AGREGARÁ AL PRINCIPIO DE LA LISTA
		}
		else{ // SI ES DIFERENTE A 1
			Nodo *temp = lista->head; // SE CREA UN NODO TEMPORAL
			int i;
			for (i = 0; i < (lugar-2); ++i){ // SE RECORRERA LA LISTA HASTA ANTES DEL LUGAR EN EL QUE SE QUIERE AGREGAR EL NODO
				temp = temp->next; // AUMENTA DE 1 EN 1
			}
			Nodo *Nuevo = (Nodo *)malloc(sizeof(Nodo)); // SE CREA UN NUEVO NODO EL CUAL SE RESERVA CON MALLOC
			// SE GUARDAN LOS DATOS DE LA COMPUTADORA
			strcpy(Nuevo->computadora.id, id);
			strcpy(Nuevo->computadora.marca, marca);
			strcpy(Nuevo->computadora.modelo, modelo);
			strcpy(Nuevo->computadora.procesador, procesador);
			strcpy(Nuevo->computadora.memoria, memoria);
			Nuevo->computadora.RAM = RAM;
			Nuevo->computadora.GB = GB;

			Nuevo->next = temp->next; // EL SIGUIENTE DEL NUEVO NODO SERA IGUAL AL SIGUIENTE DEL TEMP
			temp->next = Nuevo; // EL SIGUIENTE DEL NEXT SERA IGUAL AL NUEVO NODO
			lista->tamano++; // AUMENTA EL TAMAÑO DE LA LISTA
		}
		printf("\nSE AGREGO LA DIRECCION IP %s EN EL LUGAR %d DE LA LISTA\n", id, lugar);
	}
}

// ELIMINAMOS ELEMENTO EN EL N-ESIMO LUGAR DE LA LISTA
void eliminarNesimo(Lista *lista, int lugar){ // RECIBE EL APUNTADOR DE LA LISTA Y EL LUGAR EN DONDE SE QUIERE ELIMINAR EL NODO
	if (lugar>(lista->tamano+1)) // SI EL LUGAR INGRESADO ES MAYOR QUE EL TAMAÑO DE LA LISTA +1
	{
		printf("\nNO EXISTE ESA POSICION EN LA LISTA\n");
	}
	else{ // SI NO
		if (lugar == 1) // SI EL LUGAR ES 1
		{
			borrarPrimero(lista); // LLAMAMOS A LA FUNCION BORRAR PRIMERO
		}
		else{ // SI ES DIFERENTE A Q
			Nodo *temp = lista->head; // SE CREA UN NOTO TEMPORAL EL CUAL SERA IGUAL A LA LISTA EN SU HEAD
		 	Nodo *eliminar; // CREAMOS UN NODO "eliminar" EL CUAL LLEGARA HASTA EL NODO QUE SE QUIERE ELIMINAR

		 	for (int i = 1; i < (lugar-2); ++i) // SE RECORRE LA LISTA HASTA ANTES DEL LUGAR QUE SE QUIERE ELIMINAR
		 	{
		 		temp = temp->next; // SE RECORRE DE 1 EN 1
		 	}

		 	eliminar = temp; // EL NODO ELIMINAR ESTARA EN EL TEMP
		 	eliminar = eliminar->next; // ELIMINAR SERA IGUAL SU SIGUIENTE
		 	temp->next = eliminar->next; // EL SIGUIENTE DEL NEXT SERA IGUAL AL SIGUIENTE DE ELIMINAR
		 	eliminar = NULL; // SE IGUALARA EL NODO ELIMINAR A NULL
		 	free(eliminar); // SE ELIMINARA
		 	lista->tamano--; // DISMINUYE EL TAMAÑO DE LA LISTA
		}
		printf("\nSE ELIMINO EL LUGAR %d DE LA LISTA\n", lugar);
	}
 	
}

// BUSCAMOS UNA COMPUTADORA POR SU ID
int buscarCompuId(Lista lista, char busqueda[]){ // DE TIPO INT POR QUE SE DEVOLVERA UN ENTERO
	if(lista.head==NULL){
		printf("LA LISTA ESTA VACIA\n");
	}
	else{
		int cont = 0, encontrado = 0, control = 0;
		for (int i = 0; i < lista.tamano; ++i)
		{
			if (strcmp(lista.head->computadora.id, busqueda)==0) // COMPARAMOS EL ID DE LA COMPUTADORA CON EL ID QUE NOS DA EL USUARIO
			{ // SI SON IGUALES Y REGRESESA UN CERO
				encontrado = 1; // MARCAMOS COMO ENCONTRADO
				printf("LA COMPUTADORA ESTA EN LA POSICION %d\n", cont+1);
				break;
			}
			while(strcmp(lista.head->computadora.id, busqueda)!=0 && control < lista.tamano){ // COMPARAMOS DE NUEVO EL ID Y EVALUAMOS PARA QUE NO SE PASE DE SU TAMAÑO 
				cont ++; // AUMENTA EN EL CONTADOR
				control ++; // AUMENTA EL CONTROL
				lista.head = lista.head->next; // AUMENTAMOS LA LISTA EN SU HEAD DE UNO EN UNO
			}	
		}
		return encontrado; // REGRESA 1 SI SE ENCONTRO, 0 SI NO SE ENCONTRO
	}

}

// RECORREMOS LA LISTA
void recorrerlista(Lista lista){
	int op, rep=0;
	while(rep == 0){
		printf("\nID DE LA COMPUTADORA ACTUAL\n");
		printf("ID: %s\n", lista.head->computadora.id);

		// MENU DE OPCIONES
		printf("\nELIJE UNA OPCION (:\n");
		printf("1) DETALLES DE LA COMPUTADORA\n2) AVANZAR\n3) SALIR\n");
		fflush(stdin);
		scanf("%d", &op);

		switch(op){
			case 1:
			// SE IMPRIMEN LOS DATOS DE LA COMPUTADORA
				printf("\n* * * * * * * * * * * * * * * * * * *");
				printf("\nDETALLES DE LA COMPUTADORA ACTUAL\n");
				printf("ID: %s\n", lista.head->computadora.id);
				printf("Marca: %s\n", lista.head->computadora.marca);
				printf("Modelo: %s\n", lista.head->computadora.modelo);
				printf("Procesador: %s\n", lista.head->computadora.procesador);
				printf("Tipo de almacenamiento: %s\n", lista.head->computadora.memoria);
				printf("Capacidad de memoria RAM: %d\n", lista.head->computadora.RAM);
		        printf("Capacidad de memoria GB: %d\n", lista.head->computadora.GB);	
		    break;

		    case 2:
		    	printf("ELEJISTE AVANZAR A LA SIGUIENTE COMPUTADORA (:\n");
		    	lista.head = lista.head->next; // RECORRE LA LISTA DE UNO EN UNO
		    break;

		    case 3:
		    	printf("SALIR (:\n");
		    	rep = 1; // SI REP ES 1, SE SALE DEL MENU
		    break;

		    default:
		    	printf("OPCION NO VALIDA ):\n");
		    break;
		}
	}
}
