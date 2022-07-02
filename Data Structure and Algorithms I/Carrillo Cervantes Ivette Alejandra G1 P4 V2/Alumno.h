/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "Alumno.h" -> HEADER

typedef struct {
	char calle[20]; // 20 byte
	int num; // 4 byte
	char colonia[20]; // 20 byte
	int cPostal; // 4 byte
}Direccion;

typedef struct {
	int numCuenta; // 4 byte
	char nombre[15]; // 15 byte
	char apellido[15]; // 15 bye
	float promedio; // 4 byte
	Direccion domicilio; // ANIDAMOS LA DIRECCION CON EL ALUMNO
}Alumno;

Alumno crearAlumno(int, char*, char*, float, char*, int, char*, int); // FUNCION CREAR ALUMNO
// PASAMOS LOS PARAMETROS PARA CREAR (TIPO DE DATOS QUE TIENE ALUMNO)
// CHAR DEBE DE SER UN APUNTADOR POR QUE NO TE PUEDE REGRESAR UN ARREGLO

void imprimirAlumno(Alumno); // IMPRIMIR ALUMNO


// FUNCIONES

Alumno crearAlumno(int numeroC, char *name, char *lastname, float prom, char *call, int numCalle, char *col, int postal){
	Alumno alumnoCreado; // CREAMOS ALUMNO
	alumnoCreado.numCuenta = numeroC; // ASIGNAMOS NUM DE CUENTA (EL QUE NOS PASO LA FUNCION)
	strcpy(alumnoCreado.nombre,name); // COMO ES TIPO CARACTER USAMOS STRCPY, CON EL NOMBRE QUE PASO LA FUNCION
	strcpy(alumnoCreado.apellido,lastname); // STRCPY
	alumnoCreado.promedio = prom; // ASIGNAMOS 
	// DATOS DIRECCION
	strcpy(alumnoCreado.domicilio.calle, call);
	alumnoCreado.domicilio.num = numCalle;
	strcpy(alumnoCreado.domicilio.colonia, col);
	alumnoCreado.domicilio.cPostal = postal;
	return alumnoCreado;
}

// IMPRIMIMOS DATOS DEL ALUMNO 
void imprimirAlumno(Alumno alumnoPrint){

	printf("\n\nINFORMACION PERSONAL\n");
	printf("Numero de cuenta: %d \n",alumnoPrint.numCuenta);
	printf("Name: %s \n",alumnoPrint.nombre);
	printf("LastName: %s  \n", alumnoPrint.apellido);
	printf("Promedio: %.2f \n", alumnoPrint.promedio); 
	printf("\nDIRECCION\n");
	printf("Calle: %s\n", alumnoPrint.domicilio.calle);
	printf("Numero: %d\n", alumnoPrint.domicilio.num);
	printf("Colonia: %s\n", alumnoPrint.domicilio.colonia);
	printf("Codigo Postal: %d\n", alumnoPrint.domicilio.cPostal);
}
