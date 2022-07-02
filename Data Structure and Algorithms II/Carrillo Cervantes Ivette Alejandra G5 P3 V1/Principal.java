// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos - Grupo 5

import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class Principal{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int opcion;

		// Se crea una lista donde se van a introducir los objetos
		ArrayList<Cola> colecciones = new ArrayList<Cola>();

		do{
			System.out.println("____________________________________________________________");
			System.out.println("\n\t\tALGORITMOS DE ORDENAMIENTO PARTE 3\n");
			System.out.println(" 1 -> Counting Sort\n 2 -> Radix Sort\n 3 -> Salir");
			System.out.print("\nElige una opción: ");
			opcion = sc.nextInt();

			switch(opcion){
				case 1:
					System.out.println("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
					System.out.println("\n\tCounting Sort\n");

					int elementos = 20;
					char counting [] = new char[elementos];

					System.out.println("Ingresa los elementos en el array en un rango de [A-J]\n");
					for(int i=0;i<elementos; i++){
						System.out.print("Elemento ["+(i+1)+"] del array: ");
						char variable = sc.next().charAt(0);
						if (variable >= 'A' && variable <= 'J'){
							counting[i] = variable;
						}
						else{
							System.out.println(" *La letra que ingresaste no es valida en el rango [A-J]");
							System.out.println("  Se asigno la letra 'A' por defecto\n");
							counting[i] = 'A';
						}
					}
					System.out.println("\n -> El arreglo a ordenar es el siguiente: ");
					Utilerias.printArray(counting);
					Ordenamiento.countingSort(counting);

					break;
				case 2:
					System.out.println("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
					System.out.println("\n\tRadix Sort");

					int elementosR = 15;
					for(int j=0; j<elementosR; j++){
						Cola cola = new Cola();
						System.out.println("\nIngresa los datos de la colección "+(j+1)+" del arraylist");
						for (int i=0; i<4; i++) {
							System.out.print("Ingresa elemento "+(i+1)+" de la cola: ");
							int elemento = sc.nextInt();
							if(elemento >= 1 && elemento <= 4){
								cola.encolar(elemento);
							}
							else{
								System.out.println("  *El número que ingresaste no es valido en el rango [1 - 4]");
								System.out.println("   Se asigno el número 1 por defecto\n");
								cola.encolar(1);
							}
						}
						colecciones.add(cola);						
					}

					// for(Cola cola: colecciones){
					// 	Utilerias.printArray(cola);
					// }


					break;
				case 3:
					System.out.println("\n\tByeeee");
					break;
				default:
					System.out.println("\n\tEsa opción no existe ):");
					break;
			}
		}
		while(opcion != 3);
	}
}