package practica8_9;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
/**
 *
 * @author aleja
 */
public class Opciones {
    public static void ArbolBinario(){
        Scanner sc = new Scanner(System.in);
        List <Nodo> lista = new LinkedList<>();
        int opcion2;
        System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
        System.out.println("\tARBOLES BINARIOS\n");
        ArbolBin arbol = ArbolBin.crearABinario(lista);
        do{
            System.out.println(".  ____  .  ____  .  ____  .  ____  .  ____  .\n");
            System.out.println("\tSUBMENU");
            System.out.println("  1. Agregar dato");
            System.out.println("  2. Eliminar dato");
            System.out.println("  3. Buscar elemento");
            System.out.println("  4. Imprimir árbol (BFS)");
            System.out.println("  5. Notación Prefija (preorden)");
            System.out.println("  6. Notación Infija (inorden)");
            System.out.println("  7. Notación Posfija (posorden)");
            System.out.println("  8. Salir");
            System.out.print(" -> Selecciona una opción: ");
            opcion2 = sc.nextInt();
            switch(opcion2){
                case 1:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tAGREGAR DATO\n");
                    List<Nodo> listaNodosAgregar = arbol.getListaNodos();
                    arbol.agregarNodo(arbol, listaNodosAgregar);
                    break;
                case 2:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tELIMINAR DATO\n");
                    System.out.print("Ingresa el nodo a eliminar: ");
                    int eliminarB = sc.nextInt();
                    if(arbol.busquedaNormal(eliminarB)){
                        Nodo eliminar = null;
                        List<Nodo> listaNodos = arbol.getListaNodos();
                        
                        for(Nodo n: listaNodos){
                            if(n.valor == eliminarB){
                                eliminar = n;
                                arbol.eliminarNodo(listaNodos, eliminar);                                  
                            }
                        }
                        listaNodos.remove(eliminar);
                    }else{
                        System.out.println("No existe ese nodo ):");
                    }

                    break;
                case 3:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tBUSCAR DATO\n");
                    System.out.print("¿Qué valor de nodo deseas buscar? ");
                    int busqueda = sc.nextInt();
                    if(arbol.busquedaNormal(busqueda)){
                        System.out.println("Si existe un nodo con valor "+busqueda+" (:");
                    } else{
                        System.out.println("No existe ningún nodo con valor "+busqueda+" ):");
                    }
                    break;

                case 4:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tIMPRIMIR ARBOL (BFS)\n");
                    arbol.breadthFrist();
                    break;

                case 5:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNOTACION PREFIJA (PREORDEN)\n");
                    System.out.print("PreOrden: {");
                    arbol.preOrden(arbol.root);
                    System.out.print("}\n");
                    break;
                case 6:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNOTACION INFIJA (INORDEN)\n");
                    System.out.print("InOrden: {");
                    arbol.inOrden(arbol.root);
                    System.out.print("}\n");
                    break;
                case 7:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNOTACION POSFIJA (POSORDEN)\n");
                    System.out.print("PosOrden: {");
                    arbol.posOrden(arbol.root);
                    System.out.print("}\n");
                    break;
                case 8:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tSALIR\n");
                    break;
                default:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNo hay, no existe esa opción ):");
                    break;
            }
        }while(opcion2!=8);
    }
    
    public static void ArbolBinarioBusqueda(){
        Scanner sc = new Scanner(System.in);
        List <Nodo> lista = new LinkedList<>();
        int opcion2;
        System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
        System.out.println("\tARBOLES BINARIOS DE BUSQUEDA\n");        
        ArbolBin arbol = ArbolBin.crearABBusqueda(lista);
        do{
            System.out.println(".  ____  .  ____  .  ____  .  ____  .  ____  .\n");
            System.out.println("\tSUBMENU");
            System.out.println("  1. Agregar dato");
            System.out.println("  2. Eliminar dato");
            System.out.println("  3. Buscar");
            System.out.println("  4. Imprimir árbol (BFS)");
            System.out.println("  5. Salir");
            System.out.print(" -> Selecciona una opción: ");
            opcion2 = sc.nextInt();
            switch(opcion2){
                case 1:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tAGREGAR DATO\n");
                    List<Nodo> listaNodosA = arbol.getListaNodos();
                    arbol.agregarBinario(arbol, listaNodosA);
                    break;
                case 2:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tELIMINAR DATO\n");
                    System.out.print("Ingresa el nodo a eliminar: ");
                    int eliminarB = sc.nextInt();
                    if(arbol.busquedaNormal(eliminarB)){
                        Nodo eliminar = null;
                        List<Nodo> listaNodos = arbol.getListaNodos();
                        for(Nodo n: listaNodos){
                            if(n.valor == eliminarB){
                                eliminar = n;
                                arbol.eliminarNodo(listaNodos, eliminar);                                  
                            }
                        }
                        listaNodos.remove(eliminar);
                    }else{
                        System.out.println("No existe ese nodo ):");
                    }
                    break;
                case 3:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tBUSCAR\n");
                    System.out.print("¿Qué nodo quieres buscar? ");
                    int buscar = sc.nextInt();
                    System.out.println("¿Se encuentra? "+arbol.busqueda(arbol, buscar));
                    break;
                case 4:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tIMPRIMIR ARBOL (BFS)\n");
                    arbol.breadthFrist();
                    break;
                case 5:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tSALIR\n");
                    break;
                default:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNo hay, no existe esa opción ):");
                    break;
            }
        }while(opcion2!=5);        
    }
    
    public static void ArbolB(){
        Scanner sc = new Scanner(System.in);
        int opcion2;        
        System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
        System.out.println("\tARBOLES B\n");
        BTree arbol = BTree.crearArbol();
        do{
            
        System.out.println(".  ____  .  ____  .  ____  .  ____  .  ____  .\n");
            System.out.println("\tSUBMENU");
            System.out.println("  1. Agregar un valor");
            System.out.println("  2. Buscar valor");
            System.out.println("  3. Imprimir árbol");  
            System.out.println("  4. Salir");
            System.out.print(" -> Selecciona una opción: ");
            opcion2 = sc.nextInt();
            switch(opcion2){
                case 1:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tAGREGAR UN VALOR\n");
                    System.out.print("Ingresa el valor que quieres agregar: ");
                    int agregar = sc.nextInt();
                    arbol.add(agregar);
                    break;
                case 2:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tBUSCAR VALOR\n");
                    System.out.print("Ingresa el valor que quieres buscar: ");
                    int buscar = sc.nextInt();
                    if(arbol.find(buscar)){
                        System.out.println("El valor "+buscar+" si se encontró en el árbol (:");
                    }else{
                        System.out.println("El valor "+buscar+" no se encontró en el árbol ):");
                    }
                    break;
                case 3:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tIMPRIMIR ARBOL\n");
                    arbol.mostrarArbol();
                    break;
                case 4:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tSALIR\n");
                    break;
                default:
                    System.out.println("\n. __ . __ . __ . __ . __ . __ . __ . __ .\n");
                    System.out.println("\tNo hay, no existe esa opción ):");
                    break;
            }
        }while(opcion2!=4);
    }
}
