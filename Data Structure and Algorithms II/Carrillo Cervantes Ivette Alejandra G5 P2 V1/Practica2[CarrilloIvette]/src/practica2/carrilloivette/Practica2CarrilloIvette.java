package practica2.carrilloivette;

/**
 * @author Carrillo Cervantes Ivette Alejandra
 * Estructura de Datos y Algoritmos II - Grupo 5
 */
import java.util.Scanner;
import java.util.Random;
public class Practica2CarrilloIvette {

    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        Random aleatorio = new Random();
        System.out.println("____________________________________________________________________");
        System.out.println("                           Quick Sort");
        System.out.print("Ingresa el número de elementos que quieres que tenga tu arreglo: ");
        int elementos = sc.nextInt();
        int[] arreglo = new int[elementos];
        int low = 0;
        int high = elementos - 1;
        // Se generán los números aleatorios y se guardan en el arreglo previamente inicializado
        for(int i=0; i<elementos; i++){
            arreglo[i] = aleatorio.nextInt(500); // En un rango del 0 al 500
        //    System.out.println(arreglo[i]);
        }
        System.out.println("\nSe generó el siguiente arreglo aleatorio: ");
        Utilerias.printArray(arreglo);
        System.out.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
        QuickSort.QuickSort(arreglo, low, high);
        System.out.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
        System.out.println("\nEl arreglo ordenado con QuickSort es: ");
        Utilerias.printArray(arreglo);
        System.out.println("");
    }
}
