typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista(); // NO TIENE PARAMETROS PERO DEVUELVE UNA LISTA
void print_list(Lista); // RECIBE UNA LISTA
void addPrincipioLista(Lista*,int); // RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE SE QUIERE AGREGAR
void addFinalLista(Lista*,int); // RECIBE EL APUNTADOR DE LA LISTA Y EL VALOR QUE SE QUIERE AGREGAR
void addNesimo(Lista*, int, int); // RECIBE EL APUNTADOR DE LA LISTA, VALOR QUE SE VA A AGREGAR Y LA POSICION DONDE SE AGREGARA
void borrarPrimero(Lista*); // RECIBE EL APUNTADOR DE LA LISTA
void borrarUltimo(Lista*); // RECIBE EL APUNTADOR DE LA LISTA
void eliminarNesimo(Lista*, int); // RECIBE EL APUNTADOR DE LA LISTA Y EL LUGAR DONDE SE QUIERA ELIMINAR EL NODO
int primerElemento(Lista); // RECIBE LA LISTA Y DEVUELVE EL PRIMER ELEMENTO DE ESTA
int buscar(Lista, int); // RECIBE LA LISTA Y EL VALOR QUE SE QUIERE BUSCAR, DEVUELVE CUANTOS ELEMENTOS ENCONTRO CON ESE VALOR
void eliminarMenores(Lista*, int); // RECIBE LA LISTA Y 