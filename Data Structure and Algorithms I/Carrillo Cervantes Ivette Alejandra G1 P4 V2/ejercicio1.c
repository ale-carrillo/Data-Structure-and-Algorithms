/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include <stdio.h>
#include <stdlib.h>
 int main(){
	
	int cont,arreglo[]={35,40,45,50,55}; 
	int variable;
	// int *ptr = malloc(10*sizeof(int)); // FUNCION MALLOC

	// INCISO B, CAMBIAMOS MALLOC POR CALLOC, POR LO QUE NECESITAMOS AHORA 2 PARAMETROS, UNO PARA EL NUMERO DE LOCALIDADES A RESERVAR Y EL SEGUNDO ES EL TAMAÑO DE ESAS LOCALIDADES 
	 int *ptr = calloc(10, sizeof(int));
	char *ptr2 = malloc(100*sizeof(char));
	
	// IMPRIME DIRECCIONES DEL ARREGLO INICIALIZADO
	printf("\nDIRECCIONES DEL ARREGLO INICIALIZADO\n");
	for(cont=0;cont<10;cont++){
		printf("direccion arreglo[%d]=%d   valor arreglo[%d]=%d\n",cont,&arreglo[cont],cont,arreglo[cont]);
	}
	printf("\n");
	

	// IMPRIME DIRECCIONES Y CONTENIDO DE UN APUNTADOR DE MEMORIA DINAMICA RESERVADO CON MALLOC/CALLOC
	// printf("DIRECCIONES Y CONTENIDO DEL APUNTADOR DE MEMORIA DINAMICA RESERVADO CON MALLOC\n");
	printf("DIRECCIONES Y CONTENIDO DEL APUNTADOR DE MEMORIA DINAMICA RESERVADO CON CALLOC\n");
	for(cont=0;cont<10;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");


	//
    /* No remover estos comentarios, (por lo menos no antes de acabar la actividad1) /*/
 	//strcpy(ptr2,"hola amigo como estas");  //esto si se puede hacer 
	// //ptr2 = "Hola amigo como estas";    //nunca haga esto compa 
  	//for(cont=0;cont<100;cont++){
 	//   printf("%c",ptr2[cont]);     //no vaya a descomentar esta linea, ni cambiar el contador del for a 1000 (
 	//}
	//

	// INCISO C

	// DIRECCION DE MEMORIA Y VALOR DE CADA ELEMENTO DE UN ARREGLO CON MULTIPLOS DE 4
	printf("DIRECCION DE MEMORIA Y EL VALOR DE CADA ELEMENTO (MULTIPLOS DE 4)\n");
	for(cont=0;cont<10;cont++){
    		*(ptr + cont) = 4*(cont+1); 
    	// *(PTR + CONT) LUGARES DE MEMORIA PARA ASIGNAR  EJ. *(PTR + 0) <- SE GUARDA EN LA POSICION 0 DE LA MEMORIA
		// 4*(CONT + 1 ) QUEREMOS QUE EMPIECE DESDE EL 4, NO DEL CERO POR LO QUE A CONT SUMAMOS 1 Y LO MULTIPLICAMOS POR 4
	}
	printf("\n");

	// IMPRIME LA DIRECCION DE MEMORIA Y EL VALOR DE CADA ELEMENTO (MULTIPLOS DE 4)
	for(cont=0;cont<10;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");


	// INCISO D

	// FUNCION REALLOC, PARA REASIGNAR EL TAMAÑO DE PTR A 20
	printf("REALLOC\n");

	// UTILIZANDO EL MISMO APUNTADOR PTR

	printf("UTILIZAMOS EL MISMO APUNTADOR PTR\n");

	ptr = (int*)realloc(ptr, sizeof(int)*20);
	
	for (int cont = 0; cont < 20; ++cont)
	{
		printf("Direccion = %d    *valor = %d\n", ptr+cont, *(ptr+cont) );
	}
	printf("\n");

	// UTILIZANDO UN NUEVO APUNTADOR PTR3

	printf("UTILIZAMOS UN APUNTADOR DIFERENTE PTR3\n");
	int *ptr3 = (int*)realloc(ptr, 20*sizeof(int)); // ES LA MISMA LOCALIDAD DE MEMORIA	
	for ( cont = 0; cont < 20; ++cont)
	{
		printf("Direccion = %d    *valor = %d\n", ptr3+cont, *(ptr3+cont));
	}

	free(ptr);	
	free(ptr2);

	system("PAUSE");
}
