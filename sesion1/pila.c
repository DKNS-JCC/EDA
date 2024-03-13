#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pilaCreaVacia(Pila *p){

    if(p == NULL){
        return -1;
    }else{
        p = NULL;
        return 0;
    }

}

int pilaVacia(Pila *p){

    return(p == NULL) ? 1 : 0;

}

int pilaInserta(Pila *p, tipoElemento elemento){


    if(p == NULL){
        return -1;
    }
    
    tipoCelda *nuevo;
    if((nuevo = (tipoCelda *)malloc(sizeof(tipoCelda))) == NULL){
        return -2;
    }else{
        nuevo->elemento = elemento;

        if(pilaVacia(p)){
            (*p) = nuevo;
            nuevo->sig = NULL;
            return 0;
        }else{
            nuevo->sig = *p;
            *p = nuevo;
            return 0;
        }
    }

}

tipoElemento pilaSuprime(Pila *p){

    tipoCelda *borrar;
    tipoElemento e;
    
    if(p == NULL || pilaVacia(p)){
        return NULL;
    }else{
        borrar = *p;
        e = (*p)->elemento;
        *p = (*p)->sig;
        free(borrar);
        return e;
    }

    return 0;
    
}