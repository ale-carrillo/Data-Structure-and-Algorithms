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
public class Utilerias {
    
    // Imprime el arreglo
    static void printArray(int arr[]){
        int n = arr.length;
        System.out.print("{");
        for (int i=0; i<n; ++i)
            if(i<n-1){
                System.out.print(" "+arr[i]+",");
            } else{
                System.out.print(" "+arr[i]);
            }
        System.out.print("}");   
        System.out.println();
    }
    
    // Intercambia dos elementos del arreglo
    static void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Imprime los sub arreglos generados
    static void printSubArray(int arr[], int low, int high){
        int i;
        System.out.print("Sub array : ");
            for (i=low; i <= high; i++)
                System.out.print(" "+arr[i]);
        System.out.print("\n");
    }
}
