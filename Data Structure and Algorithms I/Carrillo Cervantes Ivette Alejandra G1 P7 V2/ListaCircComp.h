typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*, char*, char*, char*, char*, char*, int, int);
void addFinalLista(Lista*, char*, char*, char*, char*, char*, int, int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
int buscarCompuId(Lista, char*);
void addNesimo(Lista*, char*, char*, char*, char*, char*, int, int, int);
void eliminarNesimo(Lista*, int);
void recorrerlista(Lista);

