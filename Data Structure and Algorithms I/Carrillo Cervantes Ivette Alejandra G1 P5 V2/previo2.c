#include "colaDoble.c"

int main(){

	Cola previo2 = crearCola(10);

	encolarInicio(&previo2, 5);
	printf("\nINGRESAMOS EL VALOR 5 A LA COLA\n");

	encolarInicio(&previo2, 6);
	printf("\nINGRESAMOS EL VALOR 6 A LA COLA\n");

	encolarInicio(&previo2, 16);
	printf("\nINGRESAMOS EL VALOR 16 A LA COLA\n");

	encolarInicio(&previo2, 12);
	printf("\nINGRESAMOS EL VALOR 12 A LA COLA\n");

	encolarInicio(&previo2, 23);
	printf("\nINGRESAMOS EL VALOR 23 A LA COLA\n");

	encolarInicio(&previo2, 28);
	printf("\nINGRESAMOS EL VALOR 28 A LA COLA\n");

	desencolarFinal(&previo2);
	printf("\nVALOR DESPUES DE DESENCOLAR: %d\n", desencolarFinal(&previo2));

	desencolarFinal(&previo2);
	printf("\nVALOR DESPUES DE DESENCOLAR: %d\n", desencolarFinal(&previo2));

	desencolarFinal(&previo2);
	printf("\nVALOR DESPUES DE DESENCOLAR: %d\n", desencolarFinal(&previo2));
}
