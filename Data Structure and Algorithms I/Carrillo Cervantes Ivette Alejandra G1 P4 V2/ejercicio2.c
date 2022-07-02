/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include "Alumno.h" // HEADER QUE SE CREO
// NO ES NECESARIO PONER #INCLUDE <STDIO.H> POR QUE YA LO TIENE EL HEADER

int main(){

void llenarAlumno(Alumno *din); // CREAMOS UN APUNTADOR DE TIPO ALUMNO	

	int j;
	printf("\nTama%co de objeto Alumno = %d \n", 164, sizeof(Alumno)); // CUAL ES EL TAMAÑO DE LA ESTRUCTURA
	Alumno *din1,*din2,*din3;
	din1 = malloc(5*sizeof(Alumno)); // TIPO ALUMNO
	din2 = calloc(5,sizeof(Alumno));
	
	// IMPRIME LAS DIRECCIONES DE MEMORIA QUE SE RESERVA CON MALLOC
	printf("\nPrimer apuntador: \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d] = %d \n",j,din1+j); // APUNTADOR
	}
	printf("\n");
	
	// IMPRIME LAS DIRECCIONES DE MEMORIA QUE SE RESERVA CON MALLOC
	// OJO. EL VALOR ES EL QUE IMPRIME CEROS
	printf("Segundo apuntador \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d] = %d \n",j,din2+j); // EN DADO CASO SERIA *(din2+j)
	}
	printf("\n");
	
	// REASIGNAMOS VALOR DE CALLOC (DIN2), REASIGNAMOS EL TAM A 10 LOCALIDADES DE MEMORIA
	printf("Con realloc: \n");
	din3 = realloc(din2,10);
	for(j=0;j<10;j++){
		printf("&din3[%d] = %d \n",j,din3+j);
	}

	// LLENAMOS DATOS DEL ALUMNO DEL PRIMER Y SEGUNDO APUNTADOR
	llenarAlumno(din1);
	llenarAlumno(din2);

	// IMPRIMIMOS DATOS DEL ALUMNO
	printf("\n_______________________________________\n");
	printf("\nDATOS DEL ALUMNO CON DIN1\n");
	printf("Numero de cuenta: %d \n",din1->numCuenta);
	printf("Nombre: %s \n",din1->nombre);
	printf("Apellido: %s \n", din1->apellido);
	printf("Promedio: %.2f\n", din1->promedio); 
	printf("_______________________________________\n");

	// IMPRIMIMOS DATOS DEL ALUMNO
	printf("________________________________________\n");
	printf("\nDATOS DEL ALUMNO CON DIN2\n");
	printf("Numero de cuenta: %d \n",din2->numCuenta);
	printf("Nombre: %s \n",din2->nombre);
	printf("Apellido: %s  \n", din2->apellido);
	printf("Promedio: %.2f\n", din2->promedio); 
	printf("_______________________________________\n\n\n");

/*
	free(din1);

	free(din2);
*/


	
	printf("MEMORIA LIBERADA\n");
	
	din1 = (Alumno *)realloc(din1, 0); 

	printf("****************************************************\n");
	printf("\nDATOS DEL ALUMNO CON DIN1\n\n");
	printf("Numero de cuenta: %d \n",din1->numCuenta);
	printf("Nombre: %s \n",din1->nombre);
	printf("Apellido: %s \n", din1->apellido);
	printf("Promedio: %.2f\n", din1->promedio); 
	printf("Calle: %s\n", din1->domicilio.calle);
	printf("Numero: %d\n", din1->domicilio.num);
	printf("Colonia: %s\n", din1->domicilio.colonia);
	printf("Codigo Postal: %d\n\n\n", din1->domicilio.cPostal);

	din2 = (Alumno *)realloc(din1, 0); 

	printf("\nDATOS DEL ALUMNO CON DIN2\n\n");
	printf("Numero de cuenta: %d \n",din2->numCuenta);
	printf("Nombre: %s \n",din2->nombre);
	printf("Apellido: %s  \n", din2->apellido);
	printf("Promedio: %.2f\n", din2->promedio);
	printf("Calle: %s\n", din2->domicilio.calle);
	printf("Numero: %d\n", din2->domicilio.num);
	printf("Colonia: %s\n", din2->domicilio.colonia);
	printf("Codigo Postal: %d\n\n", din2->domicilio.cPostal);



	free(din3);

	system("PAUSE");

}


void llenarAlumno(Alumno *din){

	printf("\n\n\tDATOS DEL ALUMNO\n");

	printf("\nNum de Cuenta:  ");
	scanf("%d", &din->numCuenta); // SE UTILIZA (->) POR QUE ESTAMOS TRABAJANDO CON UN APUNTADOR
	fflush(stdin);

	printf("\nNombre:  ");
	scanf("%[^\n]", din->nombre);
	fflush(stdin);

	printf("\nApellido:  ");
	scanf("%[^\n]", din->apellido);
	fflush(stdin);

	printf("\nPromedio:  ");
	scanf("%f", &din->promedio);
	fflush(stdin);

	printf("\n\tDIRECCION\n");

	printf("\nCalle:  ");
	scanf("%[^\n]", din->domicilio.calle);
	fflush(stdin);

	printf("\nNumero:  ");
	scanf("%d", &din->domicilio.num);
	fflush(stdin);

	printf("\nColonia:  ");
	scanf("%[^\n]", din->domicilio.colonia);
	fflush(stdin);

	printf("\nCodigo Postal:  ");
	scanf("%d", &din->domicilio.cPostal);
	fflush(stdin);

	// PARAMETROS QUE LE PASAMOS A CREAR ALUMNO
	crearAlumno(din->numCuenta, din->nombre, din->apellido, din->promedio, din->domicilio.calle, din->domicilio.num, din->domicilio.colonia, din->domicilio.cPostal);

	// PASAMOS EL APUNTADOR DE TIPO ALUMNO (DIN)
	imprimirAlumno(*din);
}

