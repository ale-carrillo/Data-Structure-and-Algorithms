/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.List;

public class QuickSort {
    
    // Método para separar un arreglo
    static int partition(List<Integer> lista, int low, int high){
        int pivot = lista.get(high);
        int i = (low-1);
        for(int j = low; j<high; j++){
            if(lista.get(j)<=pivot){
                i++;
                swap(lista, i, j);
            }
        }
        int temp = lista.get(i+1);
        lista.set(i+1, lista.get(high));
        lista.set(high, temp);

        return i+1;
    }
    
    // Método constructor para ordenar el arreglo
    static void QuickSort(List<Integer> lista, int low, int high){
        if (low < high){
            int pi = partition(lista, low, high);
            QuickSort(lista, low, pi-1);
            QuickSort(lista, pi+1, high);
        }
    }
    
        // Intercambia dos elementos del arreglo
    static void swap(List<Integer> lista, int i, int j){
        int temp = lista.get(i);
        lista.set(i, lista.get(j));
        lista.set(j, temp);
    }
}
