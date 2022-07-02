// Completar la versión serie y paralela del ejemplo 1 explicado en la guía y medir el tiempo de ejecución de ambas
// versiones utilizando matrices de orden 500𝑥500.

// El ejercicio paralelo ya se resolvio

#include <stdio.h>
#include <omp.h>
#define NRA 500
#define NCB 500
#define NCA 500

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tMultiplicación de Matrices Serie\n");
	double empezar,terminar;
	int i, j, k;
	float a[NRA][NCB], b[NCA][NRA], c[NRA][NCB];
	empezar=omp_get_wtime( );
	for (i=0; i<NRA; i++)
		for(j=0; j<NCB; j++)
			for (k=0; k<NCA; k++)
				c[i][j] += (a[i][k]) * (b[k][j]);
	terminar=omp_get_wtime();
	printf("TIEMPO=%lf\n",empezar-terminar);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}