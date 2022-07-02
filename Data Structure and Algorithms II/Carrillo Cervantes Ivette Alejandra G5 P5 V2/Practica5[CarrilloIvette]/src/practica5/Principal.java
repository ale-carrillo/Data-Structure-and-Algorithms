package practica5;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * Carrillo Cervantes Ivette Alejandra 
 * Estructura de Datos y Algoritmos II - Grupo 3
 * @author alejandra
 */

public class Principal {

    public static void main(String[] args) {
        
        // Creación del objeto para ocupar la bibliotecas bibliotecas correspondientes
        Scanner sc = new Scanner(System.in);
        
        // Creación de la tabla Hash Map para el ejercicio 1
        Map<String,Integer> alumnos = new HashMap<>();
        
        // Creación de la listas para el ejercicio 2
        List<Integer> lista = new LinkedList<>();  
        List<Integer> listaA = new LinkedList<>();
        
        // Creación de la lista de listas para el ejercicio 3
        List<List<Integer>> encadenamiento = new LinkedList<>();
        
        // Menú de opciones, se repetirá hasta que el usuario decida salir
        int op;
        do{
            System.out.println("\n______________________________________________________\n");
            System.out.println("\t\tALGORITMOS DE BÚSQUEDA\n");
            System.out.println("  1. Manejo de Tablas Hash en Java\n  2. Función por módulo\n  3. Encadenamiento\n  4. Salir");
            System.out.print(" -> Elige una opción: ");
            op = sc.nextInt();
            
            switch(op){
                
                case 1:
                    // Manejo de Tablas Hash en Java
                    System.out.println("______  ______  ______  _______  _______\n");
                    System.out.println("\tTABLAS HASH");
                    TablaHash.metodosTabla(alumnos);
                    break;
                    
                case 2:
                    // Función por módulo
                    System.out.println("______  ______  ______  _______  _______\n");
                    System.out.println("\tFUNCION POR MODULO");
                    HashModulo.inicializarNull(lista, 20); // Lista donde se almacenarán los números que ingrese el usuario
                    HashModulo.inicializarNull(listaA, 20); // Lista donde se hará la función hash
                    System.out.println("\nSe inicializó una lista con 20 elementos null (:");
                    
                    // Submenú de opciones -> Función por módulo
                    int op2;
                    do{
                        System.out.println("\n__  __  __  __  __  __  __  __  __\n");
                        System.out.println("      SUBMENU\n    1. Agregar elementos\n    2. Imprimir lista\n    3. Buscar elementos\n    4. Salir del submenú");
                        System.out.print("  -> Elige una opción: ");
                        op2 = sc.nextInt();
                        switch(op2){
                            case 1:
                                System.out.println("\n* * * * * * * * * * * * * * * * *\n");
                                System.out.println("\tAGREGAR ELEMENTOS\n");
                                HashModulo.agregarValor(lista);
                                HashModulo.hashPlegamiento(lista, listaA);
                                HashModulo.imprimirLista(listaA);
                                break;
                            case 2:
                                System.out.println("\n* * * * * * * * * * * * * * *\n");
                                System.out.println("\tIMPRIMIR LISTA\n");
                                HashModulo.imprimirLista(listaA);
                                break;
                            case 3:
                                System.out.println("\n* * * * * * * * * * * * * * *\n");
                                System.out.println("\tBUSCAR ELEMENTOS\n");
                                System.out.print("Ingresa el número que quieres bucar: ");
                                int buscar = sc.nextInt();
                                HashModulo.imprimeBusqueda(listaA, buscar); 
                                break;
                            case 4:
                                System.out.println("\n* * * * * * * * * * * * * * *\n");
                                System.out.println("\tSALIR DEL SUBMENU\n");
                                break;
                            default:
                                System.out.println("No hay, no existe la opción");
                                break;
                        }
                    }while(op2!=4);
                    
                    break;
                    
                case 3:
                    // Encadenamiento
                    System.out.println("______  ______  ______  _______  _______\n");
                    System.out.println("\tENCADENAMIENTO");
                    Encadenamiento.inicializarNull(encadenamiento); // Lista donde se almacenan los números
                    System.out.println("\nSe inicializó una lista con 15 elementos null (:");                  
                    
                    // Submenú de opciones -> Encadenamiento
                    int op3;
                    do{
                        System.out.println("\n__  __  __  __  __  __  __  __  __\n");
                        System.out.println("      SUBMENU\n    1. Agregar elemento\n    2. Salir del submenú");
                        System.out.print("  -> Elige una opción: ");
                        op3 = sc.nextInt();                        
                        switch(op3){
                            
                            case 1:
                                // Agregar elemento
                                System.out.println("\n* * * * * * * * * * * * * * *\n");
                                System.out.println("\tAGREGAR ELEMENTO\n"); 
                                Encadenamiento.imprimirLista(encadenamiento);
                                Encadenamiento.agregarElemento(encadenamiento);
                                break;
                                
                            case 2:
                                // Salir del submenú
                                System.out.println("\n* * * * * * * * * * * * * * *\n");
                                System.out.println("\tSALIR DEL SUBMENU\n");                                
                                break;
                                
                            default:
                                System.out.println("No hay, no existe la opción");
                                break;
                        }
                    }while(op3!=2);
                    break;
                    
                case 4:
                    // Salir
                    System.out.println("______  ______  ______  _______  _______\n");
                    System.out.println("\tSALIR\n");
                    break;
                    
                default:
                    System.out.println("\tNo existe esa opción ):");
            }
        }while(op != 4);
    }
    
}
