package practica8_9;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos II - Grupo 5

public class ArbolBin {
    Nodo root;
    List<Nodo> listaNodos;
     
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Métodos constructores
    
    public ArbolBin(List<Nodo> listaNodos){
        root = null;
    }
    
    public ArbolBin(int val, List<Nodo> listaNodos){
        root=new Nodo(val);
        this.listaNodos = listaNodos;
    }
    
    public ArbolBin(Nodo root, List<Nodo> listaNodos){
        this.root=root;
        this.listaNodos = listaNodos;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Métodos de acceso
    
    public List<Nodo> getListaNodos() {
        return listaNodos;
    }
    
    public Nodo getRoot(){
        return root;
    }

    public void setListaNodos(List<Nodo> listaNodos) {
        this.listaNodos = listaNodos;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Métodos agregar y visitar
    
    public void add(Nodo padre, Nodo hijo, int lado){
	if(lado==0)
            padre.setIzq(hijo);
	else
            padre.setDer(hijo);
    }

    protected void visit(Nodo n){
        System.out.print(n.valor+" ");
    }	
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Imprimir árbol mediante BFS
    
    public void breadthFrist(){
        Nodo r = root;
	Queue<Nodo> queue = new LinkedList();
	if(r!=null){
            queue.add(r);
            while(!queue.isEmpty()){
                r = (Nodo)queue.poll();
		visit(r);
		if(r.izq!=null)
                    queue.add(r.izq);
		if(r.der!=null)
		queue.add(r.der);
            }
	}
        System.out.println("");
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Crear Arbol Binario
    
    public static ArbolBin crearABinario(List<Nodo> listaNodos){
        Scanner sc = new Scanner(System.in);
        
        System.out.print("¿Cuantos nodos quieres que tenga tu árbol binario? ");
        int nodos = sc.nextInt();
        
        System.out.print("Ingresa el valor del nodo 1 (raíz): ");
        int raiz = sc.nextInt();
        Nodo nRaiz = new Nodo(raiz);
        
        ArbolBin arbolbin = new ArbolBin(nRaiz, listaNodos);
        listaNodos.add(nRaiz);

        for (int i = 0; i < nodos-1; i++) {
            System.out.print("Inserta el valor del nodo "+(i+2)+": ");
            int nodo = sc.nextInt();
            Nodo nNodo = new Nodo(nodo);
            listaNodos.add(nNodo);
        }
        
        for(Nodo n: arbolbin.getListaNodos()){
            System.out.println("\n. __ . __ . __ . __ . __ . __ . __\n");
            System.out.println("Nodo: "+n.valor);
            relacionar(arbolbin, listaNodos, n);
        }
        arbolbin.setListaNodos(listaNodos);
        return arbolbin;
    }

    public static void relacionar(ArbolBin arbol, List<Nodo> lista, Nodo padre){
        Scanner sc = new Scanner(System.in);
        int derecho, izquierdo;
        System.out.println("\n* NOTA: Solo puedes ingresar nodos creados anteriormente *\n");
        System.out.println("  1. Si\n  2. No");
        System.out.print(" -> ¿El nodo tiene hijos? ");
        int hijos = sc.nextInt();
        if(hijos == 1){
            System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .\n");
            System.out.println("  1. Derecho");
            System.out.println("  2. Izquierdo");
            System.out.println("  3. Ambos");
            System.out.print(" -> ¿Qué hijo tiene tu nodo? ");
            int hijo = sc.nextInt();
            System.out.println("");
            switch (hijo) {
                case 1:
                    System.out.print("Ingresa el valor del nodo Derecho: ");
                    derecho = sc.nextInt();
                    for (Nodo n: lista){
                        if(derecho == n.valor){
                            arbol.add(padre, n, 1);
                        }
                    }
                    break;
                case 2:
                    System.out.print("Ingresa el valor del nodo Izquierdo: ");
                    izquierdo = sc.nextInt();
                    for (Nodo n: lista){
                        if(izquierdo == n.valor){
                            arbol.add(padre, n, 0);
                        }
                    }                    
                    break;
                case 3:
                    System.out.print("Ingresa el valor del nodo Derecho: ");
                    derecho = sc.nextInt();
                    System.out.print("Ingresa el valor del nodo Izquierdo: ");
                    izquierdo = sc.nextInt();                    
                    for (Nodo n: lista){
                        if(derecho == n.valor){
                            arbol.add(padre, n, 1);
                        }
                        if(izquierdo == n.valor){
                            arbol.add(padre, n, 0);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Crear árbol binario de busqueda
    
    public static ArbolBin crearABBusqueda(List listaNodos){
       Scanner sc = new Scanner(System.in);
        
        System.out.print("¿Cuantos nodos quieres que tenga tu árbol binario? ");
        int nodos = sc.nextInt();
        
        System.out.print("Ingresa el valor del nodo 1 (raíz): ");
        int raiz = sc.nextInt();
        Nodo nRaiz = new Nodo(raiz);
        
        ArbolBin arbolbin = new ArbolBin(nRaiz, listaNodos);
        listaNodos.add(nRaiz);
        
        for (int i = 0; i < nodos-1; i++) {
            System.out.print("Inserta el valor del nodo "+(i+2)+": ");
            int nodo = sc.nextInt();
            Nodo nNodo = new Nodo(nodo);
            listaNodos.add(nNodo);
        }
        arbolbin.binario(arbolbin, listaNodos);

        arbolbin.setListaNodos(listaNodos);
        return arbolbin;
    }

    public ArbolBin binario(ArbolBin arbol, List<Nodo> listaNodos){
        for(int i = 1; i<listaNodos.size(); i++){
            Nodo padre = arbol.root;
            Nodo actual = listaNodos.get(i);
            
            boolean bandera = false;
            while(bandera == false) {
            	if (actual.valor < padre.valor) {
                    if (padre.getIzq() != null) {
                        padre = padre.getIzq();
                    } else {
                        padre.izq = actual;
                        bandera = true;
                        break;
                    }
            	} else if (actual.valor > padre.valor) {
                    if (padre.getDer() != null) {
                        padre = padre.getDer();
                    } else {
                        padre.der = actual;
                        bandera = true;
                        break;
                    }
            	} else {
                    // Nodos iguales
                    bandera = true;
                }
            }
        }
        return arbol;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Agregar nodo al árbol binario
       
    public ArbolBin agregarBinario(ArbolBin arbol, List<Nodo> listaNodos){
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingresa el nodo por agregar: ");
        int nodo = sc.nextInt();
        Nodo nodoN = new Nodo(nodo);
        
        listaNodos.add(nodoN);
        
        Nodo padre = arbol.root;
        Nodo actual = listaNodos.get(listaNodos.size()-1);

        boolean bandera = false;
        while(bandera == false) {
            if (actual.valor < padre.valor) {
                if (padre.getIzq() != null) {
                    padre = padre.getIzq();
                } else {
                    padre.izq = actual;
                    bandera = true;
                    break;
                }
            } else if (actual.valor > padre.valor) {
                if (padre.getDer() != null) {
                    padre = padre.getDer();
                } else {
                    padre.der = actual;
                    bandera = true;
                    break;
                }
            } else {
                // Nodos iguales
                bandera = true;
            }
        }
        return arbol;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Busqueda en un árbol binario de busqueda 
    
    public boolean busqueda(ArbolBin arbol, int buscar){
        Nodo padre = arbol.root;
        if(buscar == padre.valor){
            System.out.println("Se encontró el nodo con valor "+buscar+" en la raíz (:");
        }else{
            while(padre.valor != buscar){
                if(buscar < padre.valor){
                    padre = padre.getIzq();
                } else if(buscar > padre.valor){
                    padre = padre.getDer();
                }
                if(padre == null){
                    return false;
                }
            }
        }
        return true;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Notaciones
    
    public void preOrden(Nodo nodo){
        if (nodo != null) {
            System.out.print(" "+nodo.valor+" "); // Nodo visitado
            preOrden(nodo.getIzq());
            preOrden(nodo.getDer());
        }
    }
    
    public void inOrden(Nodo nodo) {
        if (nodo != null) {
            inOrden(nodo.getIzq());
            System.out.print(" "+nodo.valor+" "); // Nodo visitado
            inOrden(nodo.getDer());
        }
    }

    public void posOrden(Nodo nodo) {
        if (nodo != null) {
            posOrden(nodo.getIzq());
            posOrden(nodo.getDer());
            System.out.print(" "+nodo.valor+" "); // Nodo visitado
        }
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Eliminar nodo árbol binario normal y de busqueda
    
    public void eliminarNodo(List<Nodo> listaNodos, Nodo eliminar){ // Nodo acrual, o a eliminar
        Nodo actual = eliminar;
        boolean bandera = false;
        
        while(bandera == false){
            if(actual.getDer() != null){
                Nodo padre = actual;
                actual = actual.getDer();
                if(actual.getDer() == null && actual.getIzq() == null){
                    eliminar.valor = actual.valor;
                    actual = null;
                    padre.setDer(null);
                    bandera = true;
                }
            } else if(actual.getIzq() != null){
                Nodo padre = actual;
                actual = actual.getIzq();
                if(actual.getDer() == null && actual.getIzq() == null){
                    eliminar.valor = actual.valor;
                    actual = null;
                    padre.setIzq(null);
                    bandera = true;
                }
            }                
        }
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Busqueda en un árbol binario normal
    
    public boolean busquedaNormal(int valor){
        Nodo r = root;
	Queue<Nodo> queue = new LinkedList();
	if(r!=null){
            queue.add(r);
            while(!queue.isEmpty()){
                r = (Nodo)queue.poll();
                if(r.valor == valor){
                    return true;
                }
		if(r.izq!=null)
                    queue.add(r.izq);
		if(r.der!=null)
		queue.add(r.der);
            }
	}    
        return false;
    }
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Agregar nodo árbol binario normal
    
    public void agregarNodo(ArbolBin arbol, List<Nodo> lista){
        Scanner sc = new Scanner(System.in);
        int agregarSi;
        int derecho, izquierdo;
        System.out.println("Nodos en los que puedes agregar hijos: ");
        for(Nodo n: lista){
            if(n.getDer() == null || n.getIzq() == null){
                System.out.print(" "+n.valor+" ");
            }
        }
        
        System.out.print("\n\nElige el nodo en el cual quieras agregar el nodo hijo: ");
        int hijo = sc.nextInt();
        Nodo agregar = null;
        Nodo agregar2 = null;
        boolean ambos;
        boolean encontrado = false;
        
        for(Nodo n: lista){
            if(n.valor == hijo){
                if((n.getDer() == null) || (n.getIzq() == null) || (n.getDer() == null && n.getIzq() == null)){
                    encontrado = true;
                    System.out.println("");
                    if(n.getDer() == null){
                        System.out.println("Solo tiene disponible el nodo Derecho");
                        System.out.print("    1. Si\n    2.No\n -> ¿Agregar?");
                        agregarSi = sc.nextInt();
                        if(agregarSi == 1){
                            System.out.print("Ingresa el valor del nodo Derecho: ");
                            derecho = sc.nextInt();
                            Nodo derechoN = new Nodo(derecho);
                            n.setDer(derechoN);
                            arbol.add(n, derechoN, 1);
                            lista.add(derechoN);                 
                            break;
                        }
                    } else if(n.getIzq() == null){
                        System.out.println("Solo tiene disponible el nodo Izquierdo");
                        System.out.print("    1. Si\n    2.No\n -> ¿Agregar?");
                        agregarSi = sc.nextInt();
                        if(agregarSi == 1){                        
                            System.out.print("Ingresa el valor del nodo Izquierdo: ");
                            izquierdo = sc.nextInt();
                            Nodo izquierdoN = new Nodo(izquierdo);
                            n.setIzq(izquierdoN);
                            arbol.add(n, izquierdoN, 1);
                            lista.add(izquierdoN);
                            break;
                        }
                    } else if(n.getDer() == null && n.getIzq() == null){
                        System.out.println("Tiene disponibles ambos nodos");
                        System.out.print("    1. Derecho\n    2. Izquierdo\n    3. Ambos\n    4. Ninguno\n -> ¿Cuál quieres agregar?");
                                                agregarSi = sc.nextInt();
                        if(agregarSi == 1){
                            System.out.print("Ingresa el valor del nodo Derecho: ");
                            derecho = sc.nextInt();
                            Nodo derechoN = new Nodo(derecho);
                            arbol.add(n, derechoN, 1);
                            lista.add(derechoN);               
                            break;
                        } else if(agregarSi == 2){
                            System.out.print("Ingresa el valor del nodo Izquierdo: ");
                            izquierdo = sc.nextInt();
                            Nodo izquierdoN = new Nodo(izquierdo);
                            arbol.add(n, izquierdoN, 1);
                            lista.add(izquierdoN);
                            agregar = izquierdoN;              
                            break;
                        } else if(agregarSi == 3){
                            System.out.print("Ingresa el valor del nodo Derecho: ");
                            derecho = sc.nextInt();
                            Nodo derechoN = new Nodo(derecho);
                            arbol.add(n, derechoN, 1);   
                            lista.add(derechoN);
                            System.out.print("Ingresa el valor del nodo Izquierdo: ");
                            izquierdo = sc.nextInt();
                            Nodo izquierdoN = new Nodo(izquierdo);
                            lista.add(izquierdoN);
                            arbol.add(n, izquierdoN, 1);     
                            agregar2 = izquierdoN;       
                            break;
                        }
                    }
                }else{
                    System.out.println("Es un nodo intermedio, no se pueden agregar hijos ):");
                }
            }
        }        
        if(!encontrado){
            System.out.println("No se encontró el valor ingresado ):");
        }

    }
    
}
