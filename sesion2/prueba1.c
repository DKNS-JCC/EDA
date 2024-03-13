#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "monticulo.h"

int main(void){ 

	srand(time(NULL));

	Monticulo m;
	tipoElemento elemento;
	tipoElemento minimo;
	int i, n=10;

	iniciaMonticulo(&m);
	elemento.clave = 12;
	elemento.informacion = 0;
	i = insertar(elemento, &m);

	while (m.tamanno <= n){ 
		elemento.clave = rand()%30;
		i = insertar(elemento, &m);
	}

	for (i=1; i <= m.tamanno; i++){
		printf("%d ", m.elemento[i].clave);
	}
	printf("\n");

	if(eliminarMinimo(&m, &minimo) == 0){
		printf("El minimo es %d\n", minimo.clave);
	}

	for (i=1; i <= m.tamanno; i++){
		printf("%d ", m.elemento[i].clave);
	}
	printf("\n");
	
	decrementarClave(6, 10, &m);
	printf("\nDECREMENTAMOS:\n");
	for (i=1; i <= m.tamanno; i++){
		printf("%d ", m.elemento[i].clave);
	}
	printf("\n");
	
	incrementarClave(1, 10, &m);
	printf("\nINCREMENTAMOS:\n");
	for (i=1; i <= m.tamanno; i++){
		printf("%d ", m.elemento[i].clave);
	}
	printf("\n");

	if(esMonticulo(m) == 0){
		printf("\nEs monticulo\n");
	}else{
		printf("\nNo es monticulo\n");
	}

	return 0;
	
}




