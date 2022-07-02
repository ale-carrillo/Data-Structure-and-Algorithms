// * * * * * * Constructor sections * * * * * *

#include <stdio.h>
#include <omp.h>

int alfa();
int beta();
int delta();
int gama(int v, int w);
float epsilon(int x, int y);

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tConstructor sections\n\n");
	int v,w,y,x;
	#pragma omp parallel sections
	{
		#pragma omp section
		v= alfa();
		
		
		#pragma omp section
		w= beta();
		
		
		#pragma omp section
		y= delta();
		
	}
	x= gama(v,w);
	
	printf("%6.2f\n", epsilon(x,y));
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}

int alfa(){
	printf("Alfa\n");
	return 1;
}

int beta(){
	printf("Beta\n");
	return 2;
}

int delta(){
	printf("Delta\n");
	return 3;
}

int gama(int v, int w){
	printf("Gama\n");
	return v+w;
}

float epsilon(int x, int y){
	printf("Epsilon\n");
	return x+y;
}

// * * * * * * * * * * * * * * * * * *

/*
v = alfa ();
w = beta ();
x = gama (v, w);
y = delta ();
printf ("%6.2f\n", épsilon(x,y));
*/

/*
#pragma omp parallel sections
{
#pragma omp section
v = alfa();
#pragma omp section
w = beta();
#pragma omp section
y = delta();
}
x = gama(v, w);
printf ("%6.2f\n", epsilon(x,y));
*/


/*
#pragma omp parallel
{
#pragma omp sections
{
#pragma omp section
v = alfa();
#pragma omp section
w = beta();
}
#pragma omp sections
{
#pragma omp section
x = gama(v, w);
#pragma omp section
y = delta();
}
}
printf ("%6.2f\n", epsilon(x,y));

*/