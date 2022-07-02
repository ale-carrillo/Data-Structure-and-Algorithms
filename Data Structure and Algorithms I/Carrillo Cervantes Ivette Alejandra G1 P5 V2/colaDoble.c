#include "colaDoble.h"
struct Cola{
    int primero;
    int ultimo;
    int tamano;
	int disponibles;
  	int* lista;
};

Cola crearCola(int tamano){ // RECIBIMOS UN TAMAÑO
	Cola c;
	c.primero=1;
	c.ultimo=0;
	c.tamano=tamano; // TAMAÑO QUE NOS PASARON
	c.disponibles = c.tamano;
	c.lista = (int*)calloc(c.tamano,sizeof(int)); // ASIGNAMOS LISTA A MEMORIA DINAMICA
	return c; // DEVUELVE LA COLA DOBLE
}

int isEmpty(Cola c){ // RECIBIMOS LA COLA
	if((c.primero==c.ultimo+1)&&(c.disponibles==c.tamano)) 
	// VERIFICAMOS SI ESTA VACIA Y SI LOS ESPACIOS DISPONIBLES SON IGUAL QUE EL TAMAÑO
		return 1; // SI SE CUMPLE DEVUELVE 1
	return 0; // DE LO CONTRARIO, DEVUELVE 0
}

void encolarFinal(Cola *c,int x){ // RECIBE EL APUNTADOR DE COLA Y EL VALOR DE X
	if(c->disponibles == 0){ // SI NO HAY ESPACIOS DISPONIBLES
		printf("ya esta a su maxima capacidad \n");	
	}
	else{
		c->ultimo=(c->ultimo%c->tamano)+1; // PARA QUE NO NOS PASEMOS DE SU ULTIMO ELEMENTO
		c->lista[c->ultimo-1]=x; // ASIGNAMOS EL VALOR QUE NOS PASARON PARA ENCOLARLO AL FINAL
		c->disponibles--; // DISMINUIMOS LA CANTIDAD DE DISPONIBLES
	}
}

void encolarInicio(Cola *c,int x){ // RECIBE EL APUNTADOR DE LA COLA Y EL VALOR DE X
	if(c->ultimo == 0){ // VERIFICAMOS SI LA COLA EN SU INDICE ULTIMO ES IGUAL A CERO, ENCOLAMOS AL FINAL
		encolarFinal(c,x); // SE ENCOLA EL ELEMENTO
	}
	else{ 
		if(c->disponibles == 0){ // VERIFICAMOS SI HAY ESPACIOS DISPONIBLES
			printf("ya esta a su maxima capacidad \n");	
		}
		else{ 
			if(c->primero==1){ // SI HAY ESPACIOS DISPONIBLES, ENCOLAMOS AL INICIO
				c->primero+=c->tamano-1; // TAM-1 PARA SABER CUAL ES EL PRIMERO
				c->lista[c->primero-1]=x; // ASIGNAMOS EL VALOR QUE NOS PASA
				c->disponibles--; // DISMINUYE LOS LUGARES DISPONIBLES
			}
			else{ // CUALQUIER VALOR QUE NO SEA 1
				c->primero=(c->primero+c->tamano)%((c->tamano)+1);
				// c -> primero = (c->primero)-1;
				// VALOR DEL PRIMER0 = (PRIMERO + TAM) MODULO (TAM+1)
				// EL MODULO DA EL RESTO DE LA DIVISION, ESTO ES PARA SABER QUE NO NOS ESTAMOS PASANDO DEL ULTIMO
				c->lista[c->primero-1]=x; // ASIGNAMOS EL VALOR QUE NOS PASA	
				c->disponibles--; // DISMINUYE LOS LUGARES DISPONIBLES
			}
		}
	}
}

int desencolarInicio(Cola *c){ // RECIBE EL PARAMETRO DE LA COLA
	if((isEmpty(*c))==1) // VERIFICAMOS SI ESTA VACIO
		printf("la cola está vacía \n");
	else{ 
		c->disponibles++; // AUMENTAMOS EL ESPACIO DE DISPONIBLES
		int aux = c->lista[c->primero-1]; // CREAMOS UNA VARIABLE AUXILIAR
		c->lista[c->primero-1]=0; // RESTABLECER EL VALOR DE CALLOC, IGUALAMOS A 0
		if(c->primero!=c->ultimo) // SI EL INDICE PRIMERO ES DIFERENTE A EL ULTIMO ENTONCES
			c->primero=(c->primero % c->tamano)+1; // SU INDICE PRIMERO ES IGUAL AL RESULTADO DE SU MODULO +1
		// PARA SABER SI AUN SEGUIMOS TENIENDO ESPACIO EN LA COLA
		else   
			c->primero++; // AUMENTAMOS EL TAM DEL PRIMERO
		if((c->primero)==(c->ultimo+1)){ // SI ESTA VACIO
	  		*c=crearCola(c->tamano); // CREAMOS LA COLA
	  	}
	 	return aux; // REGRESAMOS EL AUXILIAR
	}
}

int desencolarFinal(Cola *c){ // RECIBIMOS UN PARAMETRO, EL APUNTADOR DE COLA
	if((isEmpty(*c))==1) // SI LA COLA ESTA VACIA
		printf("la cola está vacía \n");
	else{
		c->disponibles++; // AUMENTAMOS EL LUGAR DE DISPONIBLES
		int aux = c->lista[c->ultimo-1]; // CREAMOS VARIABLE AUXILIAR
		c->lista[c->ultimo-1]=0; // RESTABLECER EL VALOR DE CALLOC, IGUALAMOS A 0
		c->ultimo--; // DISMINUIMOS EL ESPACIO DEL ULTIMO
		if(c->ultimo==0){ // SI ESTA COMO EMPIEZA LA COLA
			if(c->primero==(c->ultimo+1)){ // VERIFICAMOS SI ESTA VACIA
	 			*c=crearCola(c->tamano); // CREAMOS UNA COLA
			}
			else // SI SI TIENE VALORES
				c->ultimo+=c->tamano; // EN EL ULTIMO INDICE, SE AUMENTARA EL TAMAÑO
		}
		if(c->primero==(c->ultimo+1)){ // VERIFICAMOS SI ESTA VACIA LA COLA
	 			*c=crearCola(c->tamano); // CREAMOS UNA COLA
		}
    return aux; // RETORNA EL AUXILIAR
	}
}

void mostrarValores(Cola queue1){ // NO REGRESA VALOR, YA QUE SOLO MUESTRA VALORES
	int i=0; // EMPIEZA DESDE EL PRINCIPIO
	for(i=0;i<queue1.tamano;i++){ // SE REPITE EL CICLO SEGUN EL TAMAÑO DE LA COLA
	    printf("Posicion %d \t valor %d \n",i+1,queue1.lista[i]); 
	    // IMPRIMIMOS LA POSICION Y CALOR DE CADA ELEMENTO QUE SE AGREGA A LA COLA
	}
}

void mostrarIndices(Cola queue1){ // RECIBE A COLA
	printf("\nPrimero = %d \n",queue1.primero); // IMPRIMIMOS SU INDICE PRIMERO
	printf("Ultimo = %d \n",queue1.ultimo); // IMPRIMIMOS SU INDICE ULTIMO
	printf("Disponibles = %d \n",queue1.disponibles); // IMPRIMIMOS CUANTOS VALORES HAY DISPONIBLES
	
}
