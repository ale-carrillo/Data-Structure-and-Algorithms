/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ordenamientop1;


public class OrdenamientoP1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Se inicializan 2 arreglos para ordenar
        int[] arr1 = {9,14,3,2,43,11,58,22}; 
        int[] arr2 = {10,15,4,3,44,12,59,23}; 

        System.out.println("Arreglos Originales");  
        // Se mandan a llamar los métodos de imprimir
        Utilerias.imprimirArreglo(arr1);
        Utilerias.imprimirArreglo(arr2);
        
        // Se mandan a llamar a los métodos para ordenar el arreglo
        Insercion.insertionSort(arr1);
        
        Seleccion seleccion = new Seleccion();   
        seleccion.selectionSort(arr2);  
       
        // Se mandan a llamar los métodos de imprimir el arreglo ya ordenado
        System.out.println("Arreglos ordenados");  
        Utilerias.imprimirArreglo(arr1);
        Utilerias.imprimirArreglo(arr2);
    }
    
}
