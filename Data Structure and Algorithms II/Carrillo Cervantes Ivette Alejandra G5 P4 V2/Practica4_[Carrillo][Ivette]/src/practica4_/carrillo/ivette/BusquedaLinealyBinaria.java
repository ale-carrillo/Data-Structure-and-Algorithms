/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class BusquedaLinealyBinaria {

    public static void main(String[] args) {
        
        // Se generan 2 listas tipo LinkedList
        List<Integer> lista = new LinkedList<>() ;
        List<Integer> lista2 = new LinkedList<>() ;
    

        System.out.println("__  __  __  __  __  BUSQUEDA LINEAL  __  __  __  __  __");
        listaAleatoria(lista);
        imprimirLista(lista);
        BusquedaLineal.Lineal(lista);
        
        System.out.println("\n__  __  __  __  __  BUSQUEDA BINARIA  __  __  __  __  __");
        listaConsecutiva(lista2);
        imprimirLista(lista2);
        BusquedaBinaria.Binaria(lista2);

    }
    
    public static List listaAleatoria(List<Integer> lista){
        // Se generan los objetos necesarios para ocupar las bibliotecas importadas
        Scanner sc = new Scanner(System.in);
        Random rd = new Random();
        System.out.print("¿De cuántos elementos quieres generar tu lista aleatoria? ");
        int elementos = sc.nextInt();
        for (int i = 0; i < elementos; i++) {
            int aleatorio = rd.nextInt(100)+1;
            lista.add(aleatorio);
        }
        return lista;
    }

    public static List listaConsecutiva(List<Integer> lista){
        Scanner sc = new Scanner(System.in);
        Random rd = new Random();
        System.out.print("¿De cuántos elementos quieres generar tu lista aleatoria? ");
        int elementos = sc.nextInt();
        for (int i = 0; i < elementos; i++) {
            int aleatorio = rd.nextInt(10)+1;
            lista.add(aleatorio);
        }
        QuickSort.QuickSort(lista, 0, lista.size()-1);
        return lista;
    }   

    public static void imprimirLista(List<Integer> listaPrint){
        for(Integer var : listaPrint){
            System.out.print(var+" - ");
        }
    }
    
}
