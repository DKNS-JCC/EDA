#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................

tipoCelda *creaNodo(particion P){

	tipoCelda *nuevo;

	if(NULL == (nuevo = (tipoCelda *)malloc(sizeof(tipoCelda)))){
		return NULL;
	}

	nuevo->elemento = P;
	nuevo->sig = NULL;

	return nuevo;

}

tipoCelda *localiza(tipoElemento x, tipoLista P){

	tipoCelda *aux;

	aux = P.primero;

	while(aux != NULL && aux->elemento != x){
		aux = aux->sig;
	}

	return aux;

}

void crea(particion C){

	int i;

	for(i=0; i<MAXIMO; i++){
		C[i].primero = C[i].ultimo = creaNodo(i);
	}

}

tipoElemento buscar(tipoElemento x, particion C){

	int i;
	
	for(i=0; i<MAXIMO; i++){
		if(NULL != localiza(x, C[i])){
			return i;
		}
	}

	return -1;
}




void unir(tipoConjunto x, tipoConjunto y, particion P){
	
	x = buscar(x, P);
    y = buscar(y, P);

    if(x<0 || x >= MAXIMO || y<0 || y >= MAXIMO) return -1;

    P[x].ultimo->sig = P[y].primero;
	P[x].ultimo = P[y].ultimo;
	P[y].primero = P[y].ultimo = NULL;

}


void verParticion(particion P){ 

    int i;
   	tipoCelda *aux;

    for (i=0; i<MAXIMO; i++){
        aux = P[i].primero;
        if (aux!=NULL)  printf("\n\nClase equivalencia representante %d: ", i);
        
		while (aux != NULL){ 
			printf("%d ", aux->elemento);
         	aux = aux->sig;
        }
    }
}

void verClaseEquivalencia(tipoElemento x,particion P){ 
	
	int representante;
  	tipoCelda *aux;
  
    representante = buscar(x,P);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
    aux = P[representante].primero;
    while (aux){ 
		printf(" %d ",aux->elemento);
        aux=aux->sig;
    }
    printf("\n\n");

}
