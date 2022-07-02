package practica8_9;

// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos II - Grupo 5

public class Nodo {
    
    int valor;
    Nodo izq = null;
    Nodo der = null;
    
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Métodos constructores
    
    public Nodo(){
        izq=der=null;
    }
    public Nodo(int data){
        this(data,null,null); // Se crea un nodo con hijo izquierdo y derecho como null
    }
    public Nodo(int data, Nodo lt, Nodo rt){
        valor=data;
        izq = lt;
        der = rt;
    }   
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    //                      Métodos de acceso
    
    public void setIzq(Nodo izq) {
        this.izq = izq;
    }
    
    public void setDer(Nodo der) {
        this.der = der;
    }

    public Nodo getIzq() {
        return izq;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }

    public Nodo getDer() {
        return der;
    }

}
