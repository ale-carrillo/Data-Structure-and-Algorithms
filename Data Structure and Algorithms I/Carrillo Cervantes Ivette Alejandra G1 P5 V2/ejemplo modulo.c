void encolarInicio(Cola *c,int x){ 

// SUPONGAMOS QUE EL VALOR DEL TAM DE LA COLA ES 8, Y SU INDICE PRIMERO ES 9

	if(c->ultimo == 0){ 
		encolarFinal(c,x); 
	}
	else{ 
		if(c->disponibles == 0){ 
			printf("ya esta a su maxima capacidad \n");	
		}
		else{ 
			if(c->primero==1){ 
			// SUPONEMOS QUE C->PRIMERO = 9, POR LO TANTO NO CUMPLE CON ESTA CONDICION
				c->primero+=c->tamano-1; 
				c->lista[c->primero-1]=x; 
				c->disponibles--; 
			}
			else{ // COMO C->PRIMERO = 9, HACEMOS LAS OPERACIONES SIGUIENTES
				c->primero=(c->primero+c->tamano)%((c->tamano)+1);
				// C->PRIMERO = (9 + 8) % (8 + 1)    >>    C->PRIMERO = (17) % (9)    >>    C->PRIMERO = 8

				c->lista[c->primero-1]=x;
				// C->LISTA[8-1] = X    >>    C->LISTA[7] = X    >>    C->PRIMERO = 7

				c->disponibles--;
			}
			// REPETIMOS ELSE HASTA QUE C->PRIMERO=1 Y ENTRE EN LA FUNCION IF
		}
	}
}

