// * * * * * * Multiplicación de Matrices * * * * * *

#include <stdio.h>
#include <omp.h>
#define NRA 500
#define NCB 500
#define NCA 500

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tMultiplicación de Matrices Paralelo\n");
	double empezar,terminar;
	int i, j, k;
	float a[NRA][NCB], b[NCB][NCA], c[NCA][NRA];
	empezar=omp_get_wtime( );
	#pragma omp parallel for private (j,k)
	for (i=0; i<NRA; i++)
		for(j=0; j<NCB; j++)
			for (k=0; k<NCA; k++)
				c[i][j] += (a[i][k]) * (b[k][j]);
	terminar=omp_get_wtime();
	printf("TIEMPO=%lf\n",empezar-terminar);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}

// * * * * * * * * * * * * * * * * * *


// Algoritmo secuencial
/*
for (i=0; i<NRA; i++)
{
for(j=0; j<NCB; j++)
for (k=0; k<NCA; k++)
c[i][j] += a[i][k] * b[k][j];
}
*/

/*
#pragma omp parallel for
for (i=0; i<NRA; i++)
{
for(j=0; j<NCB; j++)
for (k=0; k<NCA; k++)
c[i][j] += a[i][k] * b[k][j];
}
*/