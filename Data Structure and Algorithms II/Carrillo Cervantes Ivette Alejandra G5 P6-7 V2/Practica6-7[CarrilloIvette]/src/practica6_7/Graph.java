package practica6_7;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author aleja
 */

public class Graph {
    
    // Atributos de clase
    int V;
    LinkedList<Integer> adjArray[];
    HashMap<Integer, HashMap> map;
    
    // Método Constructor
    Graph(int v){
        V = v;
        adjArray = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjArray[i] = new LinkedList();
        }
    }
    Graph(int v, HashMap<Integer, HashMap> map){
        V = v;
        adjArray = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjArray[i] = new LinkedList();
        }
        this.map = map;
    }
    
    // Métodos de acceso
    HashMap<Integer, HashMap> getTabla(){
        return map;
    }
    
    // Agregar
    void addEdge(int v, int w, int opcion){
        if(opcion == 1){ // Si es dirigido
            adjArray[v].add(w);          
        }else if(opcion == 2){ // Si es no dirigido
            adjArray[v].add(w);
            adjArray[w].add(v);   
        }
    }
    void addEdgePonderado(Graph graph, int v, int w, int opcion){
        Scanner sc = new Scanner(System.in);
        HashMap<Integer, HashMap> map = graph.getTabla();
        HashMap<Integer, Integer> subMap = new HashMap<>();
        System.out.print("Ingresa el valor de la arista: ");
        int arista = sc.nextInt();
        if(opcion == 3){ // Si es dirigido
            adjArray[v].add(w);          
        }else if(opcion == 4){ // Si es no dirigido
            adjArray[v].add(w);
            adjArray[w].add(v);   
        }
        subMap.put(v, w);
        map.put(arista, subMap);
        
    }   
    
    // Crear grafo
    public static Graph crearGrafo(int opcion){
        Scanner sc = new Scanner(System.in);
        
        System.out.print("\nIngresa el número de aristas que quieres que tenga tu grafo: ");
        int vertices = sc.nextInt();
        
        int V = 1000;
        
        Graph graph;
        if(opcion == 1 || opcion == 2){
            graph = new Graph(V);
        }else{
            HashMap<Integer, HashMap> map = new HashMap<>();
            graph = new Graph(V, map);
        }
        System.out.println("NOTA: Solo puedes ingresar nodos en un rango de [0 - "+(V-1)+"]\n");

        for (int i = 0; i < vertices; i++) {
            System.out.println("Arista "+(i+1));
            System.out.print("Nodo Inicial: ");
            int x = sc.nextInt();
            System.out.print("Nodo Final: ");
            int y = sc.nextInt();
            if(opcion == 1 || opcion == 2){ // Si es Dirigido o no dirigido
                graph.addEdge(x, y, opcion);
            }else{ // Si es Ponderado
                graph.addEdgePonderado(graph, x, y, opcion);
            }
            
            System.out.println("");
        }
        return graph;
    }
        
    // Imprimir Grafo
    void printGraph(Graph graph, int opcion){    
        for (int v = 0; v < graph.V; v++) {
            if(graph.adjArray[v].isEmpty()){
                continue;
            }else{
                if(opcion == 1 || opcion == 2){
                    System.out.println("Lista de adyacencia del vertice "+v);
                    for(Integer node: graph.adjArray[v]){
                        System.out.print(" -> "+node);
                    }                    
                }else{
                    System.out.println("Lista de adyacencia del vertice "+v);
                    for(Integer node: graph.adjArray[v]){
                        System.out.print(" -> "+node);
                    }                    
                }
                System.out.println("\n");                
            }
        }
        if(opcion == 3 || opcion == 4){
            graph.verAristas(graph, opcion);
        }
    }
    
    // Ver el valor de cada arista -> Solo en nodos ponderados
    void verAristas(Graph graph, int opcion){     
        HashMap<Integer, HashMap> map = graph.getTabla();
        // Se verifica si la lista esta vacia
        if(map.isEmpty()){
            System.out.println("No hay nodos, ni aristas creadas ):");
        }else{
            System.out.println(".      .      .      .      .      .\n");
            System.out.println("\tNodos y el valor de sus aristas\n");
            for(Map.Entry<Integer, HashMap> entry: map.entrySet()){
                int arista = entry.getKey();
                HashMap<Integer, Integer> subMap = entry.getValue();
                
                for(Map.Entry<Integer, Integer> entry2: subMap.entrySet()){
                    if(opcion == 3){
                        System.out.println("  ("+entry2.getKey()+") --- "+arista+" --> ("+entry2.getValue()+")");
                    }else{
                        System.out.println("  ("+entry2.getKey()+") --- "+arista+" --- ("+entry2.getValue()+")");
                    }  
                }
            }
        }
    }
    
    // Recorrer grafo por BFS
    void BFS(Graph graph, int s, int opcion){
        if(graph.adjArray[s].isEmpty()){
            if(opcion == 1 || opcion == 3){
                System.out.println("\n\tNo existe ese nodo o no va dirigido a otro ):");                
            }else{
                System.out.println("\n\tNo hay, no existe ese nodo ):");                
            }
        }else{
            boolean visited[] = new boolean[V];

            LinkedList<Integer> queue = new LinkedList<Integer>();

            visited[s] = true;
            queue.add(s);
            System.out.print("\n\tVisitados: {");
            while(!queue.isEmpty()){
                s = queue.poll();
                System.out.print(" "+s+" ");

                Iterator<Integer> i = adjArray[s].listIterator();
                while(i.hasNext()){
                    int n = i.next();
                    if(!visited[n]){
                        visited[n] = true;
                        queue.add(n);
                    }
                }            
            }
            System.out.print("}");            
        }

    }
    
    // Recorrer grafo por DFS
    void DFSUtil(int v, boolean visited[]){
        visited[v] = true;
        System.out.print(" "+v+" ");
        
        Iterator<Integer> i = adjArray[v].listIterator();
        while(i.hasNext()){
            int n = i.next();
            if(!visited[n])
                DFSUtil(n, visited);
        }
    }
    void DFS(Graph graph, int v, int opcion){
        if(graph.adjArray[v].isEmpty()){
            if(opcion == 1 || opcion == 3){
                System.out.println("\n\tNo existe ese nodo o no va dirigido a otro ):");                
            }else{
                System.out.println("\n\tNo hay, no existe ese nodo ):");                
            }

        }else{
            System.out.print("\n\tVisitados: {");
            boolean visited[] = new boolean[V];
            DFSUtil(v, visited);
            System.out.println("}");
        }
    }
        
}
