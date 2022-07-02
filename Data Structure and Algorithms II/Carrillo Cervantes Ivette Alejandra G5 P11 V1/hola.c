// * * * * * * Código Original * * * * * *

/*#include <stdio.h>

int main(){
	int i;
	printf("Hola Mundo\n");
	for (i = 0; i < 10; i++)
	{
		printf("Iteración: %d\n", i);
	}
	printf("Adiós \n");
	return 0;
}
*/

// * * * * * * Actividad 1 * * * * * *

// #include <stdio.h>

// int main(){
// 	#pragma omp parallel
// 	{
// 		int i;
// 		printf("Hola Mundo\n");
// 		for (i = 0; i < 10; i++)
// 			printf("Iteración: %d\n", i);
		
// 	}

// 	printf("Adiós \n");
// 	return 0;
// }

// * * * * * * Actividad 2 * * * * * *

// #include <stdio.h>
// #include <omp.h>

// int main(){
// 	omp_set_num_threads(n);
// 	#pragma omp parallel num_threads(n)
// 	{
// 		int i;
// 		printf("Hola Mundo\n");
// 		for (i = 0; i < 10; i++)
// 			printf("Iteración: %d\n", i);
		
// 	}

// 	printf("Adiós \n");
// 	return 0;
// }

// * * * * * * Actividad 3 * * * * * *

// #include <stdio.h>

// int main(){
// 	int i;
// 	#pragma omp parallel
// 	{
// 		printf("Hola Mundo\n");
// 		for (i = 0; i < 10; i++)
// 			printf("Iteración: %d\n", i);
		
// 	}

// 	printf("Adiós \n");
// 	return 0;
// }

// * * * * * * Actividad 4 * * * * * *

// #include <stdio.h>

// int main(){
// 	int i;
// 	#pragma omp parallel private(i)
// 	{
// 		printf("Hola Mundo\n");
// 		for (i = 0; i < 10; i++)
// 			printf("Iteración: %d\n", i);
		
// 	}

// 	printf("Adiós \n");
// 	return 0;
// }

// * * * * * * Actividad 5 * * * * * *

// #include<stdio.h>
// #include<omp.h>

// int main(){
// 	int tid,nth;
// 	#pragma omp parallel
// 	{
// 		tid = omp_get_thread_num();
// 		nth = omp_get_num_threads();
// 		printf("Hola Mundo desde el hilo %d de un total de %d\n",tid,nth);
// 	}
// 	printf("Adios");
// 	return 0;
// }

// * * * * * * Actividad 6.1 * * * * * *

// #include<stdio.h>
// #include<stdlib.h>
// #include <math.h>
// #define n 10

// void llenaArreglo(int *a);
// void suma(int *a,int *b,int *c);

// int main(){
// 	int max,*a,*b,*c;
// 	a=(int *)malloc(sizeof(int)*n);
// 	b=(int *)malloc(sizeof(int)*n);
// 	c=(int *)malloc(sizeof(int)*n);
// 	llenaArreglo(a);
// 	llenaArreglo(b);
// 	suma(a,b,c);
// }


// void llenaArreglo(int *a){
// 	int i;
// 	for(i=0;i<n;i++){
// 		a[i]=rand()%n;
// 		printf("%d\t", a[i]);
// 	}
// 	printf("\n");
// }

// void suma(int *A, int *B, int *C){
// 	int i;
// 	for(i=0;i<n;i++){
// 		C[i]=A[i]+B[i];
// 		printf("%d\t", C[i]);
// 	}
// }

// * * * * * * Actividad 6.2 * * * * * *

// #include<stdio.h>
// #include<stdlib.h>
// #include <math.h>
// #include<omp.h>
// #define n 10

// void llenaArreglo(int *a);
// void suma(int *a,int *b,int *c);

// int main(){
// 	int max,*a,*b,*c;
// 	a=(int *)malloc(sizeof(int)*n);
// 	b=(int *)malloc(sizeof(int)*n);
// 	c=(int *)malloc(sizeof(int)*n);
// 	llenaArreglo(a);
// 	llenaArreglo(b);
// 	suma(a,b,c);
// }


// void llenaArreglo(int *a){
// 	int i;
// 	for(i=0;i<n;i++){
// 		a[i]=rand()%n;
// 		printf("%d\t", a[i]);
// 	}
// 	printf("\n");
// }

// void suma(int *A, int *B, int *C){
// 	int i,tid,inicio,fin;
// 	omp_set_num_threads(2);
// 	#pragma omp parallel private(inicio,fin,tid,i)
// 	{
// 		tid = omp_get_thread_num();
// 		inicio = tid* 5;
// 		fin = (tid+1)*5-1;
// 		for(i=inicio;i<fin;i++){
// 			C[i]=A[i]+B[i];
// 			printf("hilo %d calculo C[%d]= %d\n",tid,i, C[i]);
// 		}
// 	}
// }

// * * * * * * Actividad 7 * * * * * *

// #include <stdio.h>

// int main() {
// #pragma omp parallel
// {
// 	int i;
// 	printf("Hola Mundo\n");
// 	#pragma omp for
// 	for(i=0;i<10;i++)
// 	printf("Iteración:%d\n",i);
// 	}
// 	printf("Adiós \n");
// 	return 0;
// }

// * * * * * * Actividad 8 * * * * * *

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<omp.h>
#define n 10

void llenaArreglo(int *a);
void suma(int *a,int *b,int *c);

int main(){
	int max,*a,*b,*c;
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	c=(int *)malloc(sizeof(int)*n);
	llenaArreglo(a);
	llenaArreglo(b);
	suma(a,b,c);
}


void llenaArreglo(int *a){
	int i;
	for(i=0;i<n;i++){
		a[i]=rand()%n;
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void suma(int *A, int *B, int *C){
	int i,tid;
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		#pragma omp for
		for(i=0;i<n;i++){
			C[i]=A[i]+B[i];
	printf("hilo %d calculo C[%d]= %d\n",tid,i, C[i]);
		}
	}
}