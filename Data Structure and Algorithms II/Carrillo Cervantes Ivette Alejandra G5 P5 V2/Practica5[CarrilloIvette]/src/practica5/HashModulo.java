package practica5;

import java.util.List;
import java.util.Scanner;

/**
 * Carrillo Cervantes Ivette Alejandra 
 * Estructura de Datos y Algoritmos II - Grupo 3
 * @author alejandra
 */

public class HashModulo {
    
    // Inicializa la lista con 20 valores nulos
    public static void inicializarNull(List<Integer> lista, int n){
        for(int i = 0; i<n; i++){
            lista.add(null);
        }
    }
    
    // Imprime la lista
    public static void imprimirLista(List<Integer> lista){
        System.out.println("La lista es la siguiente: ");
        for(Integer elemento: lista){
            System.out.println(elemento);
        }        
        System.out.println("");
    }    
    
    // Pide al usuario que agregue los 20 valores que se inicializaron en NULL
    public static void agregarValor(List <Integer> lista){
        Scanner sc = new Scanner(System.in);
        System.out.println("    INGRESA NUMEROS DE 9 DIGITOS (:");
        System.out.println("** NOTA: Los números no pueden empezar, ni terminar en cero **");
        System.out.println("** Se considera que se ingresaron 9 digitos, de lo contrario marcará error **\n");
        for(int i = 0; i<lista.size(); i++){
            System.out.print("Ingresa el elemento "+(i+1)+" de la lista: ");
            int numero = sc.nextInt();
            lista.set(i,numero);
        }
    }
    
    // Función hash plegamiento
    public static void hashPlegamiento(List<Integer> lista, List<Integer> listaA){

        System.out.println("\nSe hicieron los siguientes cambios:");
        for(Integer elemento: lista){
            int valor = elemento;

            // Devuelve el número en forma de arreglo
            int[] arr = convertirArreglo(valor);

            // Se crean plegamientos de 4 digitos
            // Devuelve la suma de los plegamientos
            int suma = sumas(arr);
            
            // Devuelve un arreglo que contiene los últimos dos digitos del número
            int [] arr2 = convertirArreglo2(suma);
            
            // Devuelve el módulo de los ultimos dos digitos del arreglo
            int mod = modulo(arr2);
            // System.out.println("El modulo es: "+mod);
            
            
            // PRUEBA LINEAL -> Si el indice del elemento es diferente de null, al modulo (indice) se le sumará 1
            int w=0;
            while(w!=1){
                // System.out.println(mod);
                if(listaA.get(mod) == null){
                    listaA.set(mod, elemento);
                    System.out.println("El elemento se acomodó el número "+elemento+" en la posición: "+mod);
                    w = 1;
                }else{
                    if(mod==lista.size()-1){
                        mod = 0;
                        System.out.println("El elemento se acomodó el número "+elemento+" en la posición: "+mod);
                    }else{
                        mod++;
                        w=0;
                    }
                }                         
            }          
        }
        System.out.println("");
    }
    
    // Convierte el número dado a arreglo
    public static int[] convertirArreglo(int valor){
        int [] arr = new int[9];
        int n = arr.length-1;
        while(valor > 0){
            int mod = valor%10;
            arr[n] = mod;
            valor = valor/10;
            n--;
        }       
        return arr;
    }
    
    // Convierte los ultimos dos digitos del número dado a arreglo
    public static int[] convertirArreglo2(int valor){
        int [] arr2 = new int[2];
        int n2 = arr2.length-1;   
        int x=0;
        while(valor > 0){
            if(x == 2){
                break;
            }else{
                int mod2 = valor%10;
                arr2[n2] = mod2;
                valor = valor/10;
                n2--;    
                x++;
            }                
        }    
        return arr2;
    }
    
    // Divide el número dado en modulos de 4 digitos, después hace la suma
    public static int sumas(int arr[]){
        String a = String.valueOf(arr[0]);
        String b = String.valueOf(arr[1]);
        String c = String.valueOf(arr[2]);
        String d = String.valueOf(arr[3]);
        String e = String.valueOf(arr[4]);
        String f = String.valueOf(arr[5]);
        String g = String.valueOf(arr[6]);
        String h = String.valueOf(arr[7]);
        String i = String.valueOf(arr[8]);

        String pliegue1s = a+b+c+d;
        int pliegue1 = Integer.parseInt(pliegue1s);

        String pliegue2s = e+f+g+h;
        int pliegue2 = Integer.parseInt(pliegue2s);

        String pliegue3s = i;
        int pliegue3 = Integer.parseInt(pliegue3s);

        int suma = pliegue1 + pliegue2 + pliegue3;
        //System.out.println("Suma: "+suma);        
        
        return suma;
    }
    
    // Retorna el modulo de los ultimos dos digitos de la suma del número a acomodar
    public static int modulo(int arr2[]){
        String a = String.valueOf(arr2[0]);
        String b = String.valueOf(arr2[1]);
        
        String ultDigS = a+b;
        int ultDig = Integer.parseInt(ultDigS);
        int modulo = ultDig%20;
        return modulo;
    }
    
    // Busca el número por busqueda lineal
    public static int buscarNumero(List<Integer> listaA, int busqueda){   
        for(int i = 0; i<listaA.size(); i++){
            if(busqueda == listaA.get(i)){
                return i;
            }
        }
        return -1;
    }
    
    // Imprime si se encontró el número o no
    public static void imprimeBusqueda(List<Integer> listaA, int busqueda){
        int indice = buscarNumero(listaA, busqueda);
        if(indice == -1){
            System.out.println("No se encontró el valor ):");
        }else{
            System.out.println("Se encontró el elemento "+busqueda+" en el índice: "+indice);
        }
    }
}