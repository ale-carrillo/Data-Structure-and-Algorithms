/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.List;
import java.util.*;
import java.util.Scanner;

public class BusquedaBinaria {
    
    public static void Binaria(List<Integer> lista){
        Scanner sc = new Scanner(System.in); 
        System.out.print("\n¿Qué valor deseas buscar en la lista? ");
        int valor = sc.nextInt();

        // int indice = encontrarIndice(lista, inicio, fin, valor);
        int indice = encontrarIndice(lista, valor);
        if(indice == -1){
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
            System.out.println("\t*   El valor no se encuentra en la lista ):     *");
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
        }
        else{
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
            System.out.println("\t* SI se encuentra el valor "+valor+" en la lista (:    *");
            System.out.println("\t* Posición: "+indice+"                                  *");
            int veces = numVeces(lista, valor, indice);
            System.out.println("\t* Número de veces: "+veces+"                            *"); 
            System.out.println("\t* * * * * * * * * * * * * * * * * * * * * * * * *");
        }
    }
    
    public static int encontrarIndice(List<Integer> lista, int valor){
        
        int izq = 0;
        int der = lista.size()-1;
        while(izq <= der){
            int medio = (der+izq)/2;
            if(valor == lista.get(medio)){
                return medio;
            }
            if(valor < lista.get(medio)){
                der = medio-1;
            }
            if(valor > lista.get(medio)){
                izq = medio +1;
            }
        }
        return -1;
    }
    
//    public static int encontrarIndice(List<Integer> lista, int inicio, int fin, int valor){
//        
//        if(fin > inicio){
//            int medio = (int) Math.floor(inicio+fin/2);
//            int numMedio = lista.get(medio);
//            if(numMedio == valor){
//                return medio;
//            }
//            if(numMedio > valor){
//                return encontrarIndice(lista, inicio, medio-1, valor);
//            }else{
//                return encontrarIndice(lista, medio+1, fin, valor);
//            }
//            
//        }else{
//            return -1;
//        }
//    }
    
    public static int numVeces(List<Integer> lista, int valor, int indice){
        int numVeces = 1;
        
        int derecha = indice;
        if(derecha == lista.size()-1){
            numVeces = numVeces;
        }else{
            while(lista.get(derecha) == lista.get(derecha+1)){
                numVeces++;
                derecha++;
                if(derecha+1 == lista.size()){
                    break;
                }
            }            
        }

        
        int izquierda = indice;
        if(izquierda == 0){
            numVeces = numVeces;
        }else{
            while(lista.get(izquierda) == lista.get(izquierda-1)){
                numVeces++;
                izquierda--;
                if(izquierda == 0){
                    break;
                }
            }            
        }

        return numVeces;
    }
}