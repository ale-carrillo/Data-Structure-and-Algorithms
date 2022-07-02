/* CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS I
GRUPO 1
*/

#include "Documento.h"

int main(){
	int cantidad;
	printf("\n\nCUANTOS DOCUMENTOS QUIERES REGISTRAR? ");
	fflush(stdin);
	scanf("%d", &cantidad);

	Documento *ap = (Documento *)malloc(cantidad*sizeof(Documento));
	Cola DocCola = crearCola();

	// LLENAMOS LOS DATOS DE LOS DOCUMENTOS
	for (int i = 0; i < cantidad; ++i)
	{
		printf("\n\n\tDOCUMENTO [%i]\n", i+1);

		printf("\nNombre del Documento [%i]: ", i+1);
		fflush(stdin);
		scanf("%[^\n]", ap[i].nombre);

		printf("\nAutor [%i]: ", i+1);
		fflush(stdin);
		scanf("%[^\n]", ap[i].autor);

		printf("\nN%cmero de paginas [%i]: ", 163, i+1);
		fflush(stdin);
		scanf("%d", &ap[i].numPag);

		printf("\nTama%co del documento [%i]: ", 164, i+1);
		fflush(stdin);
		scanf("%d", &ap[i].tam);

		// TODOS LOS DATOS SE MANDAN A ENCOLAR
		encolar(&DocCola, ap[i]);
	}

	printf("\n_ _ _ _ _ _ IMPRIMIENDO _ _ _ _ _ _\n");
	float total = 0.0;
	for (int i = 0; i < cantidad; ++i)
	{
		// COLA REGRESADA, EL PRIMERO QUE METES ES EL PRIMERO QUE SALE
		Documento CRegresada = desencolar(&DocCola); // DESENCOLAMOS PARA PODER IMPRIMIR LOS DATOS
		printf("\nDoc %d:\tNombre: %s\n", i+1, CRegresada.nombre);
		float tiempoS = (CRegresada.numPag)*4; // SE MULTIPLICA POR 4, QUE SON LOS SEGUNDOS EN LOS QUE SE TARDA UNA PAGINA EN IMPRIMIR
		(tiempoS) /= 60; // HACE LA CONVERSION DE MIN A SEG
		printf("      \tTiempo de impresi%cn: %.2f minutos // %d p%cginas x 4 seg = %.2f segundos\n", 162, tiempoS, ap[i].numPag, 160, (tiempoS)*60);
		total += tiempoS; // SUMAMOS EL TIEMPO TOTAL DE IMPRESION DE LOS DOCUMENTOS INGRESADOS
	}
	printf("\n\nTiempo total de la impresion: %.2f minutos\n", total);
}