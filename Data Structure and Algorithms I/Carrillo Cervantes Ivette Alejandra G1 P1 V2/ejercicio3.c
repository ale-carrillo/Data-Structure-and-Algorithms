/* Carrillo Cervantes Ivette Alejandra
Estructura de Datos y Algoritmos I
Grupo 1
*/

#include <stdio.h>
#include <math.h>

/*Ejercicio 3. Convirtiendo a Binario

Escribe un programa en el cual se solicite al usuario llenar un arreglo de 9 elementos 
(únicamente 0’s y 1’s). Una vez que el usuario llene el arreglo con el número binario, 
podrá seleccionar entre alguna codificación

a) Binario puro 
b) Punto fijo (6 bit entero y 3 bit decimal) 
c) Representación de complemento a 2 

El programa realizará la conversión y como salida mostrará el resultado en representación decimal
*/

int main(){

	printf("\n\tCONVIRTIENDO A BINARIO\n\n");

	//Declarar variables
	int arr[9];
	int i, potencia, acum, temp, comp, entero;
	short op = 0;
	float tempf, acumf;

		//Pide los datos para que el usuario los ingrese
		printf("Ingrese un n%cmero binario de 9 bits\n", 163);
		for (i = 0; i < 9; ++i)
		{
			printf("Ingresa bit [%d]: ", i+1);
			scanf("%d", &arr[i]);
		}

		//Se verifica que el número sea un binario
		for(i= 0; i < 9; ++i)
		{
			if (arr[i]!= 0 && arr[i]!= 1){ 
			//Cuando el usuario ingrese un número diferente a 0 ó 1, no te mostrará el menú de opciones
			printf("El n%cmero no es un binario\n", 163);
			return 0;
			}
		}


		while(1){
			//Se muestra el menú
			printf("\n\nSeleccione una codificaci%cn\n", 162);

			printf("1) Binario Puro\n");
			printf("2) Punto Fijo (6 bit entero y 3 bit decimal)\n");
			printf("3) Representaci%cn de complemento a2\n", 162);
			printf("4) Salir\n");

			scanf("%d", &op);

			//Opciones a elegir
			switch(op){
				case 1:
					//Se imprime el número binario de 9 digitos que el usuario Ingreso
					printf("\nN%cmero Binario:  ", 163);	
					for (i = 0; i < 9; ++i)
					{
						printf("%d ", arr[i]);
					}

					potencia = 0;
					acum = 0; //Variable acumulador
					temp = 0; //Variable temporal para almacenar el valor de 2 elevada a una potencia
					//Ciclo for para que vaya contando de derecha a izquierda
					for(i = 8; i >= 0; i--){ 
						//Se eleva 2 a la posición donde se encuentre el número 1
						temp = pow(2,potencia) * arr[i]; 
						acum = acum + temp;
						potencia = potencia + 1;
					}
					printf("\nEl valor en decimal %d",acum );			

				break;

				case 2:
					//Se imprime el número binario de 9 digitos que el usuario Ingreso
					printf("\nN%cmero Binario:  ", 163);	
					for (i = 0; i < 9; ++i)
					{
						printf("%d ", arr[i]);
					}

					//El primer arreglo lo partimos en 6
					potencia = 0;
					acum = 0; //Variable acumulador
					temp = 0;  //Variable temporal para almacenar el valor de 2 elevada a una potencia
					//Ciclo for para que vaya contando de derecha a izquierda
					for(i = 5; i >= 0; i--){
						//Se eleva 2 a la posición donde se encuentre el número 1
						temp = pow(2,potencia) * arr[i]; 
						acum = acum + temp;
						potencia = potencia + 1;
					}

					//Obtenemos el decimal (flotante)
					potencia = 1;
					acumf = 0; //Variable acumulador
					tempf = 0; //Variable temporal para almacenar el valor de 2 elevada a una potencia
					//Ciclo for para que vaya contando de izquierda a derecha
					for(i = 6; i < 9; i++){
						tempf = pow(2,(-1*potencia)) * arr[i]; //Se eleva 2 a la (-1) por la posición donde se encuentre el número 1
						acumf = acumf + tempf;
						potencia++;
					}

					//Imprimimos el resultado, el cual se obtiene sumando el acumulador (entero)
					//más el acumuladorf (float)
					printf("\nEl resultado es: %f" ,acumf+ (float)acum );
					
				break;

				case 3:
					//Se imprime el número binario de 9 digitos que el usuario Ingreso
					printf("\nN%cmero Binario:  ", 163);	
					for (i = 0; i < 9; ++i)
					{
						printf("%d ", arr[i]);
					}

					//Se hace la operación para que los 0's se vuelvan a 1's y viceversa
					for (i = 0; i < 9 ; i++ ){
				        if(arr[i] == 0){ //Si el número del arreglo (i) es 0, se le va a sumar 1
				            arr[i] = arr[i]+1; //Aquí daría 1
				        } //En dado caso de que no sea 0 (que sea 1) se le va a restar 1 
				        else{
				            arr[i] = arr[i]-1; //Aquí daría 0
				        }
			    	}

			    	//Se imprime el complemento 1
				    printf("\nComplemento a1 :  ");
				    for (i = 0; i < 9 ; ++i){
				        printf("%d ", arr[i]);
				    }

				    //Complemento 2
				    printf("\n\nComplemento a2 :  ");
						    
				    comp= 9 - 1; //variable complementoa2 para almacenar valor
				    while ( (comp >= 0) && (arr[comp] == 1)) { //mientras el numero sea 1, se suma y se guarda 
				        arr[comp] = 0;
				        comp--;
				    }
				    arr[comp] = 1; 

				    //Se imprime el nuevo arreglo, el que es complemento 2
				    for (i = 0; i < 9 ; i++ ){
				        printf("%d ",arr[i]);
				    }
				    printf("\n");

				break;

				case 4:
				//Opción para Salir
				return 0;
				break;

				default: 
					//En caso de que no exista la opción elegida
					printf("\nOpci%cn no v%Clida.", 162, 160); 
			}

		}
	

	return 0;

}

