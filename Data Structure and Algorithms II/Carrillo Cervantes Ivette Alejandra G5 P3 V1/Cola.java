// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos - Grupo 5

public class Cola{
	int[] cola;
	int tam;
	int primero;
	int ultimo;

	public Cola(){
		tam = 4;
		primero =1;
		ultimo = 0;
		cola = new int[tam];
		int info;
		Cola sig;
	}

	public void encolar(int elemento){
		cola[ultimo]= elemento;
		ultimo += 1;
	}

}