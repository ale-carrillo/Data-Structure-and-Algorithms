package practica4_.carrillo.ivette;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class PrincipalComputadora {

    public static void main(String[] args) {
        String marca;   
        int memoriaRam;
        String color;
        double precio;
        boolean descuento;
        
        Scanner sc = new Scanner(System.in);
        List<Computadora> listaComputadora = new LinkedList<>();
        List<Computadora> listaComputadoraBuscar = new LinkedList<>();
        
        System.out.println("\n  * Se inicializaron las siguientes 5 computadoras antes de iniciar el programa *");
        
        Computadora computadora1 = new Computadora("Apple", 8 , "blanco", 32000, false);
        listaComputadora.add(computadora1);
        listaComputadoraBuscar.add(computadora1);
        
        Computadora computadora2 = new Computadora("Dell", 4 , "negro", 19000, true);
        listaComputadora.add(computadora2);
        listaComputadoraBuscar.add(computadora2);
        
        Computadora computadora3 = new Computadora("Huawei", 8, "gris", 22000, false);
        listaComputadora.add(computadora3);
        listaComputadoraBuscar.add(computadora3);
        
        Computadora computadora4 = new Computadora("HP", 16 , "gris", 28000, true);
        listaComputadora.add(computadora4);
        listaComputadoraBuscar.add(computadora4);
        
        Computadora computadora5 = new Computadora("Lenovo", 8 , "gris", 24000, true);
        listaComputadora.add(computadora5);
        listaComputadoraBuscar.add(computadora5);
        
        Computadora.imprimirComputadoras(listaComputadora);
        
        
        int op = 0;
        do{
            System.out.println("________________________________________________\n\n\t\tMENU DE OPCIONES\n");
            System.out.println("  1. Crear una computadora\n  2. Imprimir lista de computadoras\n  3. Buscar computadoras por marca");
            System.out.println("  4. Buscar computadoras por memoria RAM\n  5. Buscar existencia de una computadora por marca\n  6. Salir");
            System.out.print("Elige una opción: ");   
            op = sc.nextInt();
            switch(op){
                case 1:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tCREAR UNA COMPUTADORA");
                    System.out.println("\n 1 -> Crear con todos sus atributos\n 2 -> Crear solo con marca y memoria RAM (los demás atributos inicializarlos en cero)");
                    System.out.print("Elige una opción: ");
                    int op2 = sc.nextInt();
                    switch(op2){
                        case 1:
                            System.out.print("\nInserta los datos de la computadora:");
                            sc.nextLine(); // Limpiamos el buffer
                            
                            System.out.print("\nMarca: ");
                            marca = sc.nextLine();

                            System.out.print("Memoria RAM: ");
                            memoriaRam = sc.nextInt();
                            
                            sc.nextLine(); // Limpiamos el buffer
                            System.out.print("Color: ");
                            color = sc.nextLine();

                            System.out.print("Precio: ");
                            precio = sc.nextDouble();

                            System.out.print("Descuento (true/false): ");
                            descuento = sc.nextBoolean();
                            
                            Computadora nuevaComputadora = new Computadora(marca, memoriaRam, color, precio, descuento);
                            listaComputadora.add(nuevaComputadora);
                            break;
                        case 2:
                            System.out.print("\nInserta los datos de la computadora:");
                            sc.nextLine(); // Limpiamos el buffer
                            System.out.print("\nMarca: ");
                            marca = sc.nextLine();

                            System.out.print("Memoria RAM: ");
                            memoriaRam = sc.nextInt();
                            
                            Computadora nuevaComputadora2 = new Computadora(marca, memoriaRam);     
                            listaComputadora.add(nuevaComputadora2);
                            break;
                        default:
                            break;
                    }                   
                    break;
                case 2:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tIMPRIMIR COMPUTADORAS");
                    Computadora.imprimirComputadoras(listaComputadora);
                    break;
                case 3:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tBUSCAR COMPUTADORAS POR MARCA");      
                    System.out.print("\nIngresa la marca a buscar: ");
                    sc.nextLine(); // Limpiamos el buffer
                    marca = sc.nextLine();
                    List<Computadora> listaMarca = new LinkedList<>();
                    Computadora.LinealComputadora(listaComputadora, listaMarca, marca);
                    if(listaMarca.isEmpty()){
                        System.out.println("\t* * * * * * * * * * * * * * * * *  *");
                        System.out.println("\t* No se encontró la computadora ): *");
                        System.out.println("\t* * * * * * * * * * * * * * * * *  *");
                    }else{
                        System.out.println("\nLas computadoras que tienen como marca '"+marca+"' son las siguientes:");
                        Computadora.imprimirComputadoras(listaMarca);
                    }
                    break;
                case 4:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tBUSCAR COMPUTADORAS POR MEMORIA RAM"); 
                    System.out.print("\nIngresa la memoria RAM a buscar: ");
                    sc.nextLine(); // Limpiamos el buffer
                    memoriaRam = sc.nextInt();
                    List<Computadora> listaRam = new LinkedList<>();
                    Computadora.LinealComputadora(listaComputadora, listaRam, memoriaRam);
                    if(listaRam.isEmpty()){
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                        System.out.println("\t* No se encontró la memoria Ram ):  *");
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                    }else{
                        System.out.println("\nLas computadoras que tienen una memoria RAM de "+memoriaRam+" GB son las siguientes:");
                        Computadora.imprimirComputadoras(listaRam);
                    }
                    break;
                case 5:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tBUSCAR EXISTENCIA DE UNA COMPUTADORA");
                    System.out.println("\n  * Solo se tomarán en cuenta las computadoras inicializadas antes del inicio del programa *");
                    System.out.print("\nIngresa la marca a buscar: ");
                    sc.nextLine(); // Limpiamos el buffer
                    marca = sc.nextLine();
                    boolean seEncuentra = Computadora.BinariaComputadora(listaComputadoraBuscar, marca);
                    if(seEncuentra){
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                        System.out.println("\t* Si se encuentra la computadora (: *");
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                    }else{
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                        System.out.println("\t* No se encuentra la computadora ): *");
                        System.out.println("\t* * * * * * * * * * * * * * * * * * *");
                    }
                    break;
                case 6:
                    System.out.println("______  ______  ______  ______  ______  ______\n");
                    System.out.println("\tSALIR\n");
                    break;
                default:
                    System.out.println("No existe esa opción ):");
                    break;
            }
        }while(op!=6);

    }
    
}

