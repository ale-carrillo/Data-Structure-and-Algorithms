/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.LinkedList;
import java.util.List;

public class Listas {
    
    public static void main(String[] args) {
        
        List<Integer> lista1 = new LinkedList<>() ;    
        lista1.add(15);
        // [Aquí agrega 5 instrucciones más de “add” con los elements que quieras]
        lista1.add(80);
        lista1.add(16);
        lista1.add(6);
        lista1.add(24);
        lista1.add(31);
        lista1.add(26);

        System.out.println("****** ");
        System.out.println(" Estado 1 ");
        System.out.println("Se agregaron 7 elementos a la lista: ");
        imprimirLista(lista1);
        System.out.println("****** ");

        lista1.add(2,300);
        lista1.add(4,500);
        lista1.add(5,700);

        System.out.println(" Estado 2 ");
        System.out.println("Se agregaron 3 elementos en posiciones especificadas de la lista: ");
        imprimirLista(lista1);
        System.out.println("****** ");

        lista1.set(1, 14);
        lista1.set(2, 16);
        lista1.set(7, 18);
        System.out.println(" Estado 3 ");
        System.out.println("Se reemplazaron elementos en posiciones especificadas de la lista: ");
        imprimirLista(lista1);
        System.out.println("****** ");

        System.out.println(" Estado 4 ");
        System.out.println("Se eliminó el elemento en la posición 1 de la lista... ");
        System.out.println("Se eliminó el elemento en la posición 6 de la lista... ");
        lista1.remove(1);
        lista1.remove(6);
        imprimirLista(lista1);
        System.out.println("****** ");
        
        System.out.println(" ¿La lista 1 esta vacia? "+lista1.isEmpty());
        System.out.println("****** ");
        
        System.out.println(" Se busca el elemento 6 en la lista... ");
        System.out.println(" El elemento 6, esta en la posición: "+lista1.indexOf(6));
        System.out.println(" Se busca el elemento 16 en la lista... ");
        System.out.println(" El elemento 16, esta en la posición: "+lista1.indexOf(16));
        System.out.println("****** ");
        
        List<Integer> lista2, lista3;
        System.out.println("Se creó la lista 2 y 3 con respecto a la lista 1");

        lista2 = lista1.subList(2, 4);
        lista3 = lista1.subList(2, 4);
        System.out.println(" Lista 2");
        imprimirLista(lista2);
        System.out.println("****** ");
        System.out.println(" Lista 3");
        imprimirLista(lista3);
        System.out.println("****** ");
        System.out.println("¿La lista 1 es igual a la lista 2?");
        System.out.println(lista1.equals(lista2));

    }   

    public static void imprimirLista(List<Integer> listaPrint){
        for(Integer var : listaPrint){
            System.out.println(var);
        }
    }
}        

