package practica8_9;
import java.util.Scanner;

// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos II - Grupo 5

public class Principal {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int opcion;
        int opcion2;
        do{
            System.out.println("\n___________________________________________\n");
            System.out.println("\t\tMENÚ DE OPCIONES\n");
            System.out.println("  1. Árboles Binarios");
            System.out.println("  2. Árboles Binarios de búsqueda");
            System.out.println("  3. Árboles B");
            System.out.println("  4. Salir");
            System.out.print(" -> Selecciona una opción: ");
            opcion = sc.nextInt();
            switch(opcion){
                case 1:
                    Opciones.ArbolBinario();
                    break;
                    
                case 2:
                    Opciones.ArbolBinarioBusqueda();
                    break;
                    
                case 3:
                    Opciones.ArbolB();
                    break;
                
                case 4:
                    System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
                    System.out.println("\tSALIR (:");
                    break;
                
                default:
                    System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
                    System.out.println("\tNo hay, no existe esa opción ):");
                    break;
            }
        }while(opcion!=4);
    }
    
}