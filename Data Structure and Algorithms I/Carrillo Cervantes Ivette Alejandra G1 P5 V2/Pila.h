// INCLUIMOS LAS LIBRERIAS

#include <stdlib.h>

typedef struct Pila Pila;

Pila crearPila(); // RETORNA UNA PILA
int isEmpty(Pila); // REGRESA UN ENTERO Y VA A SER LA FUNCION QUE VA A VERIFICAR SI ESTA VACIA O NO
void push(Pila*,int); // NO REGRESA NADA POR QUE SOLO METE COSAS
// A DONDE METE LA PILA Y DE QUE TIPO VA A SER (EN ESTE CASO ENTEROS)
int pop(Pila*); // AGARRA EL ULTIMO QUE FUE METIDO Y LO SACA, MODIFICA LOS VALORES CUANDO PASAMOS POR REFERENCIA
int top(Pila); // INDICA EL ULTIMO ELEMENTO DE LA PILA SIN NECESIDAD DE SACARLO O MODIFICARLO, 
// POR ESO LE PASAMOS LA PILA POR VALOR Y NO POR REFERENCIA

