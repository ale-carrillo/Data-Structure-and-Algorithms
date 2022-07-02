package practica8_9;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos II - Grupo 5

public class Pruebas {
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
       
        
        // * * * * * * ARBOL BINARIO 1 * * * * * *
        
        System.out.println("\n\nARBOL BINARIO 1");
        
        ArbolBin arbol; 
        
        Nodo n7 = new Nodo(7);
        Nodo n9 = new Nodo(9);
        Nodo n1 = new Nodo(1,n7,n9);
        Nodo n15 = new Nodo(15);
        Nodo n8 = new Nodo(8);
        Nodo n4 = new Nodo(4);
        Nodo n2 = new Nodo(2);
        Nodo n16 = new Nodo(16);
        Nodo n3 = new Nodo(3);
        
        List<Nodo> lista = new LinkedList<>();
        arbol = new ArbolBin(n1, lista);
        // valor, hijo, lado==0 izquierdo else derecho
        arbol.add(n7,n15,0);
        arbol.add(n7,n8,1);
        arbol.add(n9,n4,0);
        arbol.add(n9,n2,1);
        arbol.add(n15,n16,1);
        arbol.add(n8,n3,0);
        arbol.breadthFrist();

        // * * * * * * ARBOL BINARIO 2 * * * * * *
        
        System.out.println("\nARBOL BINARIO 2");
        
        ArbolBin arbol2;
        
        Nodo no1 = new Nodo(1);
        Nodo no6 = new Nodo(6);
        Nodo no16 = new Nodo(16);
        Nodo no31 = new Nodo(31);
        Nodo no24 = new Nodo(24);
        Nodo no26 = new Nodo(26);
        Nodo no36 = new Nodo(36);
        Nodo no2 = new Nodo(2);
        Nodo no7 = new Nodo(7);
        Nodo no9 = new Nodo(9);
        Nodo no3 = new Nodo(3);
        
        List<Nodo> lista2 = new LinkedList<>();
        arbol2 = new ArbolBin(no16, lista2);
        
        arbol2.add(no16, no6, 0);
        arbol2.add(no16, no1, 1);
        arbol2.add(no6, no24, 0);
        arbol2.add(no6, no26, 1);
        arbol2.add(no24, no31, 0);
        arbol2.add(no1, no7, 0);
        arbol2.add(no1, no2, 1);
        arbol2.add(no7, no9, 0);
        arbol2.add(no2, no36, 1);
        arbol2.add(no36, no3, 0);
        arbol2.breadthFrist();
//        arbol2.eliminarNodo(lista2, no16);
//        arbol2.breadthFrist();
//        System.out.println("Buscando el nodo 36... "+arbol2.busquedaNormal(36));
        
    }
    
}
