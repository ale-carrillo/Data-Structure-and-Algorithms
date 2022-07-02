#include <stdio.h>
#include <stdlib.h>
int main (){ 
	int *arreglo, num, cont; 
	printf("\n%cCu%cntos elementos tiene el conjunto?\n", 168, 160); 
	scanf("%d",&num); 
	arreglo = (int *)calloc (num, sizeof(int)); 
	if (arreglo!=NULL) { 
		printf("Vector reservado:\n\t["); 
		for (cont=0 ; cont<num ; cont++){ 
			printf("\t%d",*(arreglo+cont)); 
		} 
		printf("\t]\n"); 
		printf("Se libera el espacio reservado.\n"); 
		free(arreglo); 
	} 
	return 0; 
}