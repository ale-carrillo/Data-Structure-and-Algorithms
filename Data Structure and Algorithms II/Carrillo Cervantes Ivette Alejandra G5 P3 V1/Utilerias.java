// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos - Grupo 5

public class Utilerias{

    // Imprime el arreglo
    static void printArray(char arr[]){
        int n = arr.length;
        System.out.print(" {");
        for (int i=0; i<n; ++i)
            if(i<n-1){
                System.out.print(" "+arr[i]+",");
            } else{
                System.out.print(" "+arr[i]);
            }
        System.out.print("}");   
        System.out.println();
    }
   
    static void printArray(int arr[]){
        int n = arr.length;
        System.out.print(" {");
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

    static char valorMaximo(char arr[]){
    	char max = arr[0];
    	for(int i = 0; i<arr.length; i++){
    		if(arr[i]>max){
    			max = arr[i];
    		}
    	}
    	return max;
    }


    static void llenarCeros(int arr[]){
    	int n = arr.length;
    	for (int i = 0; i<n; i++) {
    		arr[i] = 0;
    	}
    }
}