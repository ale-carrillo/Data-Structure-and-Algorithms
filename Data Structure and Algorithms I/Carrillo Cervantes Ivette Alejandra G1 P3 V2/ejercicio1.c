/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>

// Estructura Militar
typedef struct
{
	int matricula;
	char nombre [20];
	char nombre2 [20];	
	char gradomil[20];
}Militar;

// Estructura Batallon
typedef struct
{
	int claveidentificador;
	char categoria[20];
	char ubicacion[20];
	Militar militar[25]; // Asociamos la estructura Militar con Batallon
}Batallon;

// Estructura División
typedef struct
{
	char nombre [20];
	char zona [20];
	Batallon batallon[10]; // Asociamos la estructura Batallon con División
}Division;

// Funciones propuestas
Division crearDivision();
Batallon crearBatallon();
Militar crearMilitar();
void asignarMilitalABatallon(Batallon*);
void asignarBatallonADivison(Division*);
void mostrarDivisiones(Division division);
void mostrarBatallones(Division division);
void mostrarMilitares(Batallon batallon);

// Función principal
int main (){
	printf("\nINGRESA DIVISION\n");
	Division division1 = crearDivision();
	mostrarDivisiones(division1);
	printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");

	return 0;
}

Division crearDivision(){
	Division dbmil;

	// Ingresa los datos de la División
	printf("Ingrese nombre de la divisi%cn: ", 162);
	setbuf(stdin, NULL);
	scanf("%s", &dbmil.nombre);
	getchar();

	printf("Ingrese Zona: ");
	setbuf(stdin, NULL);
	scanf("%s", &dbmil.zona);
	getchar();

	// Se le manda a llamar a la función para asignar el batallon a la división
	asignarBatallonADivison(&dbmil);
	return dbmil;
}

Batallon crearBatallon(){
	Batallon bmil;

	// Ingresa los datos del Batallón
	printf("Ingrese clave identificador: ", 162);
	setbuf(stdin, NULL);
	scanf("%d", &bmil.claveidentificador);
	getchar();

	printf("Ingrese Categoria: ");
	setbuf(stdin, NULL);
	scanf("%s", &bmil.categoria);
	getchar();

	printf("Ingrese Ubicaci%cn: ", 162);
	setbuf(stdin, NULL);
	scanf("%s", &bmil.ubicacion);
	getchar();

	// Se le manda a llamar a la función para asignar el Militar al Batallón
	asignarMilitalABatallon(& bmil);
	return bmil;
}

Militar crearMilitar(){
	Militar mil;

	// Ingresa los datos del Militar
	printf("Ingresa matricula del militar: ");
	setbuf(stdin, NULL);
	scanf("%d", &mil.matricula);

	printf("Ingresa nombre del militar: ");
	setbuf(stdin, NULL);
	scanf("%s %s", &mil.nombre, &mil.nombre2);
	getchar();

	printf("Ingresa el grado del militar: ");
	setbuf(stdin, NULL);
	scanf("%s", &mil.gradomil);

	return mil;
}

void asignarBatallonADivison(Division *dbmil){

	// Ciclo for para que se repita 3 veces crear batallón
	for (int i = 0; i < 3; ++i)
	{
	printf("\n\n\tINGRESA BATALLON %d\n", i+1);
		dbmil -> batallon[i] = crearBatallon(i+1); // Se manda a llamar a la función crear Batallón
	}
}

void asignarMilitalABatallon(Batallon *bmil){

	// Ciclo for para que se repita en cada Batallón, 3 veces crear Militar
	for (int i = 0; i < 3; ++i)
	{
		printf("\nINGRESA MILITAR %d\n", i+1);
		bmil -> militar[i]= crearMilitar(i+1); // Se manda a llamar a la función crear Militar
	}
}

void mostrarDivisiones(Division division){

	// Mostramos en pantalla los datos obtenidos de la División
	printf("_______________________________________________\n");
	printf("\n\tDIVISION\n");
	printf("El nombre de la divisi%cn es: %s\n", 162, division.nombre);
	printf("La zona de la divisi%cn es:   %s\n", 162, division.zona);
	mostrarBatallones(division);
}

void mostrarBatallones(Division division){

	// Mostramos en pantalla los datos obtenidos de los Batallones
	for (int i = 0; i < 3; ++i)
	{
		printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
		printf("\n\tBATALLON %d\n", i+1);
		printf("Clave del Batallon:    %d\n", division.batallon[i].claveidentificador);
		printf("Categoria:             %s\n", division.batallon[i].categoria);
		printf("Ubicaci%cn:             %s\n", 162, division.batallon[i].ubicacion);
		mostrarMilitares(division.batallon[i]);
	}
}

void mostrarMilitares(Batallon batallon){

	// Mostramos en pantalla los datos obtenidos de los Militares
	for (int i = 0; i < 3; ++i)
	{
		printf("\n\nDATOS DEL MILITAR %d\n", i+1);
		printf("Matricula:             %d\n", batallon.militar[i].matricula);
		printf("Nombre:                %s %s\n", batallon.militar[i].nombre, batallon.militar[i].nombre2);
		printf("Grado:                 %s", batallon.militar[i].gradomil);
	}
}