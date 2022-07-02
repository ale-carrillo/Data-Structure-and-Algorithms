package practica6_7;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Alejandra Carrillo
 */

public class Principal {

    public static void main(String[] args) {
        int opcion;
        do{
            Scanner sc = new Scanner(System.in);
            System.out.println("________________________________________________");
            System.out.println("\n\t\t    GRAFOS\n");
            System.out.println("  1. Dirigido\n  2. No Dirigido\n  3. Ponderado Dirigido\n  4. Ponderado no dirigido\n  5. Salir\n");
            System.out.print(" -> Elige opción: ");
            opcion = sc.nextInt();
            switch(opcion){
                    case 1:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\t\tGRAFO DIRIGIDO");
                        Graph graphD = Graph.crearGrafo(opcion);
                        subMenu(graphD, opcion);
                        break;
                        
                    case 2:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\t\tGRAFO NO DIRIGIDO");
                        Graph graphND = Graph.crearGrafo(opcion);
                        subMenu(graphND, opcion);
                        break;
                        
                    case 3:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\t\tGRAFO PONDERADO DIRIGIDO");
                        Graph graphPD = Graph.crearGrafo(opcion);
                        subMenu(graphPD, opcion);
                        break;
                        
                    case 4:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\t\tGRAFO PONDERADO NO DIRIGIDO");
                        Graph graphPND = Graph.crearGrafo(opcion);
                        subMenu(graphPND, opcion);
                        break;
                        
                    case 5:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\t\tElegiste salir, Byeeee (:");
                        break;
                        
                    default:
                        System.out.println(". __ . __ . __ . __ . __ . __ . __ . __ . __ .\n");
                        System.out.println("\tNo hay, no existe esa opción ):");
                        break;
                }
        }while(opcion!=5);

    }
    
    public static void subMenu(Graph graph, int opcion){
        Scanner sc = new Scanner(System.in);
        int opcion2;
        do{
            System.out.println("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
            System.out.println("\t\tSUBMENU\n");
            System.out.println("  1) Imprimir Grafo\n  2) Recorrer Grafo (BFS)\n  3) Recorrer Grafo (DFS)\n  4) Algoritmo de Primm\n  5) Salir\n");
            System.out.print(" -> Elige opción: ");
            opcion2 = sc.nextInt();
            switch(opcion2){
                case 1:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tImprimir Grafo");
                    graph.printGraph(graph, opcion); 
//                    Graph graph2 = new Graph(5);
//                    graph2.addEdge(0,1,2);
//                    graph2.addEdge(0,4,2);
//                    graph2.addEdge(1,2,2);
//                    graph2.addEdge(1,3,2);
//                    graph2.addEdge(1,4,2);
//                    graph2.addEdge(2,3,2);
//                    graph2.addEdge(3,4,2);
//                    graph2.printGraph(graph2, 2); 
                    break;
                    
                case 2:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tRecorrer Grafo (BFS)\n");
                    System.out.print("¿Desde que vertice quieres iniciar el recorrido? ");
                    int verticeB = sc.nextInt();
                    graph.BFS(graph,verticeB, opcion);
                    break;
                    
                case 3:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tRecorrer Grafo (DFS)\n");
                    System.out.print("¿Desde que vertice quieres iniciar el recorrido? ");
                    int verticeD = sc.nextInt();
                    graph.DFS(graph, verticeD, opcion);
                    break;
                    
                case 4:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tAlgoritmo de Primm\n");
                    if(opcion == 1 || opcion == 2){ // Si no es un grafo ponderado
                        System.out.println("No es un grafo ponderado, no se puede realizar el algoritmo de Primm ):");
                    }else{
                        System.out.print("¿Desde que vertice quieres iniciar el recorrido? ");
                        int verticeP = sc.nextInt();
                    }
                    break;
                    
                case 5:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("Elegiste salir, Byeeee (:\n");
                    break;
                default:
                    System.out.println(".  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tNo hay, no existe esa opción ):");
                    break;
            }
        }while(opcion2 != 5);
    }
}