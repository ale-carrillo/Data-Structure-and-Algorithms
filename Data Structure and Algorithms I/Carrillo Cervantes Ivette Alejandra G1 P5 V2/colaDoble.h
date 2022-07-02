#include <stdio.h>
#include <stdlib.h>

typedef struct Cola Cola;

Cola crearCola(int); // RECIBIMOS UN TAMAÑO
int isEmpty(Cola); // RECIBIMOS LA COLA, DE LA CUAL SE QUIERA VERIFICAR SI ESTA VACIA
void encolarInicio(Cola*,int); // RECIBIMOS LA COLA Y EL VALOR QUE SE QUIERE AGREGAR
void encolarFinal(Cola*,int); // RECIBIMOS LA COLA Y EL VALOR QUE SE QUIERE AGREGAR
int desencolarInicio(Cola*); // RECIBIMOS LA COLA QUE SE QUIERE DESENCOLAR CON SU APUNTADOR
int desencolarFinal(Cola*); // RECIBIMOS LA COLA QUE SE QUIERE DESENCOLAR CON SU APUNTADOR
void mostrarValores(Cola); // RECIBIMOS LA COLA QUE SE QUIERE MOSTRAR
void mostrarIndices(Cola); // RECIBIMOS LA COLA QUE SE QUIERE MOSTRAR

