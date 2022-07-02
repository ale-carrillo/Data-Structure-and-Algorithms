/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica2.carrilloivette;

/**
 *
 * @author aleja
 */
public class QuickSort {
    // Método para separar un arreglo
    static int partition(int arr[], int low, int high){
        int pivot = arr[high];
        System.out.println("\nPivote: "+pivot);
        int i = (low-1);
        for(int j = low; j<high; j++){
            if(arr[j]<=pivot){
                i++;
                Utilerias.swap(arr, i, j);
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return i+1;
    }
    
    // Método constructor para ordenar el arreglo
    static void QuickSort(int arr[], int low, int high){
        if (low < high){
            int pi = partition(arr, low, high);
            Utilerias.printSubArray( arr, low, pi-1);
            QuickSort(arr, low, pi-1);
            Utilerias.printSubArray( arr, pi+1, high);
            QuickSort(arr, pi+1, high);
        }
    }
}
