// * * * * * * Clausula critical * * * * * *

#include <stdio.h>
#include <omp.h>

double prodpunto(double *a,double *b, int n);

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tClausula reductionn\n");
	double arr[] = {1, 2, 3, 4, 5, 6};
	double arr2[] = {7, 8, 9, 10, 11, 12};
	int tam = sizeof(arr)/sizeof(arr[0]);

	printf("Vector 1: ");
	for (int i = 0; i < tam; ++i) {
        printf("%.2f, ", arr[i]);
    }

	printf("\nVector 2: ");
	for (int i = 0; i < tam; ++i) {
        printf("%.2f, ", arr2[i]);
    }

	double res = prodpunto(arr, arr2, tam);
	printf("\n\nResultado del producto punto de dos vectores: %.2f\n", res);
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}

double prodpunto(double *a,double *b, int n){
	double res=0;
	int i;
	#pragma omp parallel for reduction(+:res)
	for(i=0;i<n;i++){
		res+=a[i]*b[i];
	}
	return res;
}
// * * * * * * * * * * * * * * * * * *

// Normal
/*
double prodpunto(double *a, double *b, int n){
	double res=0;
	int i;
	for(i=0;i<n;i++){
		res+=a[i]*b[i];
	}
	return res;
}
*/

// Parallel for
/*
double prodpunto(double *a, double *b, int n){
	double res=0;
	int i;
	#pragma omp parallel for
	for(i=0;i<n;i++){
		res+=a[i]*b[i];
	}
	return res;
}
*/

// 
/*
double prodpunto(double *a ,double *b, int n){
	double res=0,resp[n_hilos];
	int i, tid, nth;
	#pragma omp parallel private (tid) nthreads(n_hilos)
	{
		tid = omp_get_thread_num();
		resp[tid]=0;
		#pragma omp for
		for(i=0;i<n;i++){
			resp[tid]+=a[i]*b[i];
		}
		if(tid==0){
			nth = omp_get_num_threads();
			for(i=0;i<nth;i++){
			res+= resp[i];
			}
		}
	return res;
	}
}
*/