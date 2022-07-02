// Para el siguiente programa obtener dos versiones paralelas, una utilizando el constructor section y otra con el
// constructor for. ¿Cuál de las dos versiones tarda más tiempo?.

#include<stdio.h>
#include<omp.h>
#define N 100000

// Versión serie
/*
int main (int argc, char *argv[]) {

	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tVersion Serie\n\n");
	double empezar,terminar;
	int i,j;
	float a[N], b[N], c[N],d[N], e[N],f[N];
	for (i=0; i < N; i++)
		a[i] = b[i] = i * 1.0;
	empezar=omp_get_wtime( );
	for(i=0; i<N; i++)
		c[i]=a[i]+b[i];
	for(j=0; j<N; j++)
		d[j]=e[j]+f[j];
	terminar=omp_get_wtime();
	printf("TIEMPO=%lf\n",empezar-terminar);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}
*/


// Versión paralela for
/*
int main (int argc, char *argv[]) {

	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tVersion Paralelo Section\n\n");
	double empezar,terminar;
	int i,j;
	float a[N], b[N], c[N],d[N], e[N],f[N];

	for (i=0; i < N; i++)
		a[i] = b[i] = i * 1.0;
	empezar=omp_get_wtime();

	#pragma omp parallel sections
	{
		#pragma omp section
		for(i=0; i<N; i++)
			c[i]=a[i]+b[i];
			
		#pragma omp section
		for(j=0; j<N; j++)
			d[j]=e[j]+f[j];
	}
	terminar=omp_get_wtime();
	printf("TIEMPO=%lf\n",empezar-terminar);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}
*/

// Versión paralela for

int main (int argc, char *argv[]) {

	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tVersion Paralelo For\n\n");
	double empezar,terminar;
	int i,j;
	float a[N], b[N], c[N],d[N], e[N],f[N];
	#pragma omp parallel
	{
		#pragma omp for
		for (i=0; i < N; i++)
			a[i] = b[i] = i * 1.0;
		empezar=omp_get_wtime( );

		#pragma omp for
		for(i=0; i<N; i++)
			c[i]=a[i]+b[i];
		
		#pragma omp for
		for(j=0; j<N; j++)
			d[j]=e[j]+f[j];
		terminar=omp_get_wtime();
	}
	printf("TIEMPO=%lf\n",empezar-terminar);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}