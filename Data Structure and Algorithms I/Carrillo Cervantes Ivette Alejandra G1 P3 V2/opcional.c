#include <stdio.h>
#define TAM 2
#define NUM_AS 5

struct alumno{
	char *nombre;
	char *apellido;
	int numCuenta;
	char *asignaturas[20];
};

struct estudiante
{
	char nombre [20];
	char apellido [20];
	int numCuenta;
	int numAlumnos;
	char asignaturas[NUM_AS][20];	
};

void imprimirDatosAlumno(struct alumno); //función
void pedirDatosAlumno(struct estudiante *);
void imprimirArreglo(struct estudiante *);
struct alumno Asignatura(char *, char*, int , char*[20]);


int main(){

	int op, a;

	while(1){

		printf("\t\n\nELIJA UNA OPCION\n");
		printf("1) Ver datos almacenados\n");
		printf("2) Crear\n");
		printf("3) Salir\n");
		scanf("%d", &op);

		switch(op){

			case 1: ;
			char *asignaturas[20];
			asignaturas[0] = "ALGEBRA";
			asignaturas[1] = "EDA";
			asignaturas[2] = "MECANICA";
			struct alumno promedio = Asignatura("Alejandra", "Carrillo", 318320966, asignaturas);
			imprimirDatosAlumno(promedio);
			promedio = Asignatura("Angel", "Duran", 513320143, asignaturas);
			imprimirDatosAlumno(promedio);

			break;

			case 2: ;
				struct estudiante arreglo[TAM]; 
				pedirDatosAlumno (arreglo); 
				imprimirArreglo (arreglo); 
			break;
			
			case 3:
			// Opción para salir
			return 0;
			break;
			
			default:
			printf("Opci%cn no valida\n", 162 );

		}
	}

	return 0;
}

struct alumno Asignatura(char *nombre, char *apellido, int numCuenta, char *asignaturas[20]){
	struct alumno promedio;
	promedio.nombre = nombre;
	promedio.apellido = apellido;
	promedio.numCuenta = numCuenta;
	for (int i = 0; i <3; i++)
	{
		promedio.asignaturas[i] = asignaturas[i];
	}
	return promedio;
}

void imprimirDatosAlumno(struct alumno promedio){
			printf("\n\nNOMBRE: %s \n", promedio.nombre);
			printf("APELLIDO: %s \n", promedio.apellido );
			printf("NUMERO DE CUENTA: %d\n", promedio.numCuenta);
			printf("ASIGNATURAS: \n");
			for (int i = 0; i < 3; ++i)
			{
				printf("- %s\n", promedio.asignaturas[i]);
			}
}

void pedirDatosAlumno(struct estudiante arreglo [TAM]){ 
	for (int x = 0 ; x < TAM ; ++x) { 
		struct estudiante promedio; 
		printf("\nIngresa el nombre del alumno %d: ", x+1);
		setbuf(stdin, NULL); 
		scanf("%s", promedio.nombre); 
		getchar(); 
		printf("Ingresa el apellido del alumno %d: ", x+1);
		setbuf(stdin, NULL); 
		scanf("%s", promedio.apellido); 
		getchar(); 
		printf("Ingresa el numero de cuenta del alumno %d: ", x+1);
		setbuf(stdin, NULL); 
		scanf("%d", &promedio.numCuenta); 
		promedio.numAlumnos = NUM_AS;
		for (int y = 0 ; y < NUM_AS ; ++y){ 
			printf("Ingrese asignatura %d: ", y+1); 
			setbuf(stdin, NULL); 
			scanf("%s", promedio.asignaturas[y]); 
			getchar();
			} arreglo[x] = promedio; 
		} 
	}

void imprimirArreglo(struct estudiante arreglo [TAM]){ 
	for (int x = TAM-1 ; x >= 0 ; --x) { 
		printf("\n\nNOMBRE: %s\n", arreglo[x].nombre); 
		printf("APELLIDO: %s\n", arreglo[x].apellido); 
		printf("NUMERO DE CUENTA: %d\n", 165, arreglo[x].numCuenta); 
		printf("ASIGNATURAS:\n"); 
		for (int y=0 ; y<arreglo[x].numAlumnos ; y++){ 
			printf("%s\n", arreglo[x].asignaturas[y]); 
		} 
	} 
}