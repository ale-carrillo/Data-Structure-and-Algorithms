package practica5;
import java.util.Map;

/**
 * Carrillo Cervantes Ivette Alejandra 
 * Estructura de Datos y Algoritmos II - Grupo 3
 * @author alejandra
 */

public class TablaHash {
    
    // Se inicializa la tabla hash con 8 elementos
    // Se utiliza el método put -> agregar valores a la tabla hash
    public static void inicializarTabla(Map<String,Integer> alumnos){
        alumnos.put("Malfoy Black Draco", 123456);
        alumnos.put("Potter Harry James", 456789);
        alumnos.put("Lovegood Luna", 784564);
        alumnos.put("Granger Hermionie Jean", 159263);
        alumnos.put("Weasley Ronald Bilius", 147258);
        alumnos.put("Fido Scamander Newton Artemis", 258369);
        alumnos.put("Weasley Ginevra Molly", 987654);
        alumnos.put("Delacour Fleur Isabelle", 321654);
    }
    
    // Se imprime la tabla hash
    public static void imprimirTabla(Map<String,Integer> alumnos){
        // Se verifica si la tabla esta vacia
        if(alumnos.isEmpty()){
            System.out.println("\nLa tabla esta vacia ):");
            System.out.println("La tabla actual tiene: "+alumnos.size()+" alumnos");
            System.out.println("* * * * * * * * * * * * * * * * * *");
        }else{
            System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
            for(Map.Entry<String,Integer> entry: alumnos.entrySet()){
                System.out.println("Nombre: "+entry.getKey());
                System.out.println("Número de cuenta: "+entry.getValue());
                System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __ __\n");
            }
        }    
    }

    // Se realiza la prueba de los métodos de la tabla
    public static void metodosTabla(Map<String,Integer> alumnos){
        imprimirTabla(alumnos);
        inicializarTabla(alumnos);
        imprimirTabla(alumnos);
        System.out.println("Ahora tiene: "+alumnos.size()+" alumnos\n");
        System.out.println("¿Tiene una clave 'Lovegood Luna'? "+alumnos.containsKey​("Lovegood Luna"));
        System.out.println("¿Tiene una clave 'Fred Weasley'? "+alumnos.containsKey​("Fred Weasley"));
        System.out.println("\n¿Tiene el valor '357241'? "+alumnos.containsValue(357241));
        System.out.println("¿Tiene el valor '123456'? "+alumnos.containsValue(123456));
        System.out.println("\nEl número de cuenta de 'Delacour Fleur Isabelle', es: "+alumnos.get("Delacour Fleur Isabelle"));
        System.out.println("\n¿El número de cuenta de 'Granger Hermionie Jean' es el mismo que el de 'Potter Harry James'? "+alumnos.get("Granger Hermionie Jean").equals(alumnos.get("Potter Harry James")));
        alumnos.remove("Weasley Ronald Bilius");
        System.out.println("\nSe elimino el alumno 'Weasley Ronald Bilius' de la tabla hash");
        imprimirTabla(alumnos);
        System.out.println("Ahora tiene: "+alumnos.size()+" alumnos");        
    }    
}
