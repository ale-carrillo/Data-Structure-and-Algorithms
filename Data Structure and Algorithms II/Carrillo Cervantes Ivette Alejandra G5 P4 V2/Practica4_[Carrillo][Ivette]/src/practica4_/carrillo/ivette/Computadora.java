/*
    Carrillo Cervantes Ivette Alejandra
    Programación Orientado a Objetos - Grupo 3
*/

package practica4_.carrillo.ivette;

import java.util.List;
import java.util.Scanner;

public class Computadora {
    
    // * * Atributos de clase * *
    String marca;   
    int memoriaRam;
    String color;
    double precio;
    boolean descuento;
    
    // * * Métodos Constructores sobrecargados * *
    public Computadora(){}
    public Computadora(String marca, int memoriaRam){
        this.marca = marca;
        this.memoriaRam = memoriaRam;
    }
    public Computadora(String marca, int memoriaRam, String color, double precio, boolean descuento){
        this.marca = marca;
        this.memoriaRam = memoriaRam;
        this.color = color;
        this.precio = precio;
        this.descuento = descuento;
    }
    // * * Métodos de acceso * *
    public String getMarca(){
        return marca;
    }   
    public void setMarca(String marca){
        this.marca = marca;
    }
    
    public int getMemoriaRam_(){
        return memoriaRam;
    }   
    public void setMemoriaRam(int memoriaRam){
        this.memoriaRam = memoriaRam;
    }
    
    public String getColor(){
        return color;
    }   
    public void setColor(String color){
        this.color = color;
    }
    
    public double getPrecio(){
        return precio;
    }
    public void setPrecio(double precio){
        this.precio = precio;
    }
    
    public boolean getDescuento(){
        return descuento;
    }
    public void setDescuento(boolean descuento){
        this.descuento = descuento;
    }
    
    // * * Métodos de la clase * *
    public void descuento(){
        if(getDescuento()){
            System.out.println("La computadora tiene un descuento del 20% ");
            double precioOriginal = getPrecio();
            double precioDescuento = (80*precioOriginal)/100;
            System.out.println("Su precio final es: "+precioDescuento);
        }else{
            System.out.println("La computadora no tiene ningún descuento ):");
        }
    }
    
    public static void imprimirComputadoras(List<Computadora> listaComputadora){
        System.out.println("__  __  __  __  __  __  __  __  __  __  __\n");
        for(Computadora compu: listaComputadora){
            System.out.println("Marca: "+compu.getMarca());
            System.out.println("Memoria RAM: "+compu.getMemoriaRam_()+" GB");
            System.out.println("Color: "+compu.getColor());
            System.out.println("Precio: "+compu.getPrecio());
            compu.descuento();             
            System.out.println("__  __  __  __  __  __  __  __  __  __  __\n");
        }
    }
    
    // * * Métodos Busqueda Lineal
    public static List LinealComputadora(List<Computadora> listaComputadora,List<Computadora> listaMarca, String marca){
        for(Computadora compu: listaComputadora){
            String marcaGet = compu.getMarca();
            int comparacion = marca.compareTo(marcaGet);
            if(comparacion == 0){
                listaMarca.add(compu);
            }
        }
        return listaMarca;
    }
    public static List LinealComputadora(List<Computadora> listaComputadora,List<Computadora> listaRam, int memoriaRam){
        for(Computadora compu: listaComputadora){
            int memoriaGet = compu.getMemoriaRam_();
            if(memoriaGet == memoriaRam){
                listaRam.add(compu);
            }
        }
        return listaRam;
    }
    
    // * * Método Busqueda Binaria * *
    public static boolean BinariaComputadora(List<Computadora> lista, String marca){
        
        int izq = 0;
        int der = lista.size()-1;
        while(izq <= der){
            int medio = (der+izq)/2;
            String marcaGet = lista.get(medio).getMarca();
            int comparacion = marca.compareTo(marcaGet);
            if(comparacion == 0){
                return true;
            }
            if(comparacion < 0){
                der = medio-1;
            }
            if(comparacion > 0){
                izq = medio +1;
            }
        }
        return false;
    }
  
}
