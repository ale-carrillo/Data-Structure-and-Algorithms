package practica5;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Random;

/**
 * Carrillo Cervantes Ivette Alejandra 
 * Estructura de Datos y Algoritmos II - Grupo 3
 * @author alejandra
 */

public class Encadenamiento {
    public static void inicializarNull(List<List<Integer>> lista){
        for(int i = 0; i<15; i++){
            lista.add(null);
        }        
    }
    
    public static void imprimirLista(List<List<Integer>> lista){
        System.out.println("La lista es la siguiente: ");
        for(List<Integer> elemento: lista){
            System.out.println(elemento);
        }        
        System.out.println("");
    }  
    
    public static void agregarElemento(List<List<Integer>> lista){
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingresa el número que quieres agregar: ");
        int numero = sc.nextInt();
        int indice = indiceAleatorio();        
        if(lista.get(indice)== null){
            List<Integer> sublista = new LinkedList<>();
            sublista.add(numero);    
            lista.set(indice, sublista);           
        }else{
            List<Integer> sublista = lista.get(indice);
            sublista.add(numero);
            lista.set(indice, sublista);               
        }
        System.out.println("Se agregó el número "+numero+" en el índice: "+indice+"\n");

        imprimirLista(lista);
    }
    
    public static int indiceAleatorio(){
        Random rd = new Random();
        int indice = rd.nextInt(14)+0;
        return indice;
    }
}