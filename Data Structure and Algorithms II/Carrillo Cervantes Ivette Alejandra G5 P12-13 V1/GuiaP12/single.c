// * * * * * * Constructor single* * * * * *
#include <stdio.h>
#include <omp.h>

void todosRalizanUnasActividades();
void Actividades();
void RealizanMasActividades();

void main(){
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
	printf("\n\tConstructor single\n\n");

	#pragma omp parallel
	{
		todosRalizanUnasActividades();
		#pragma omp single
		{
			Actividades();
		} // Hilos esperan
		RealizanMasActividades();
	}
	printf(". __ . __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
}


void todosRalizanUnasActividades(){
	printf("Todos realizan unas Actividades\n");
}

void Actividades(){
	printf("Actividades\n");
}

void RealizanMasActividades(){
	printf("Realizan mas actividades\n");
}