/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.List;
import java.util.*;

public class BusquedaLineal {
    Scanner sc = new Scanner(System.in);
    Random rd = new Random();
    
    public static void Lineal(List<Integer> lista){
        Scanner sc = new Scanner(System.in);      
        System.out.print("\n¿Qué valor deseas buscar en la lista? ");
        int valor = sc.nextInt();
        if(encontrar(lista, valor)){
            int ind = indice(lista, valor);
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
            System.out.println("\t* SI se encuentra el valor "+valor+" en la lista (:    *");
            System.out.println("\t* Posición: "+ind+"                                   *");
            int numVec = numVeces(lista, valor);
            System.out.println("\t* Número de veces: "+numVec+"                            *"); 
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
        }else{
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
            System.out.println("\t*   El valor no se encuentra en la lista ):     *");
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
        }
    }
    
    public static boolean encontrar(List<Integer> lista1, int num){
        for(int numero: lista1){
            if(numero == num){
                return true;
            }
        }
        return false;
    }
    
    public static int indice(List<Integer> lista, int num){
        for (int i = 0; i < lista.size(); i++) {
            if(lista.get(i)==num){
                return i;
            }
        }
        return -1;
    }
    
    public static int numVeces(List<Integer> lista, int num){
        int contador = 0;
        for (int i = 0; i < lista.size(); i++) {
            if(lista.get(i)==num){
                contador++;
            }
        }
        return contador;
    }
}
