typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void print_list(Lista);
void First(Lista*, int);
void addFinalLista(Lista*, int);
void addPrincipioLista(Lista*, int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void addNesimo(Lista*, int, int);