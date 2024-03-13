#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

int colaCreaVacia(Cola *c){

    c->frente = NULL;
    c->fondo = NULL;

    return 0;

}

int colaVacia(Cola *c){

    return(c->frente == NULL && c->fondo == NULL) ? 1 : 0;

}

int colaInserta(Cola *c, tipoElemento elemento){
    
    if(elemento == NULL){
        return -1;
    }
    else{
        // printf("se crea nuevo nodo - ");
        tipoCelda *nuevo;
        nuevo = (tipoCelda*)malloc(sizeof(tipoCelda));

        nuevo->elemento = elemento;
        nuevo->sig = NULL;

        if(colaVacia(c) == 1){

            c->frente = nuevo;
            c->fondo = nuevo;

        }else{

            c->fondo->sig = nuevo;
            c->fondo = nuevo;

        }
    }
    return 0;
    
}

tipoElemento colaSuprime(Cola *c){   // Devuelve y suprime el primer elemento

    if(c == NULL){
        return NULL;
    }
    if(!colaVacia){
        return NULL;
    }
    else{
 
        tipoElemento aux;
        tipoCelda *eliminar = c->frente;

        c->frente = c->frente->sig;
        
        aux = eliminar->elemento;

        if(c->frente == NULL){
            c->fondo = NULL;
        }

        // Destruir nodo
        free(eliminar);

        return aux;
    }

}
