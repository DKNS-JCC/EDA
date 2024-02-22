#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c){
    if (c == NULL) return -2;
    else if (NULL == (c->frente = c->fondo = (tipoCelda *)malloc(sizeof(tipoCelda)))) return -1;
    else {
        c->frente->sig = NULL;
        return 0;
    }
}

int colaVacia(Cola *c){
    if (c == NULL || c->frente == NULL) return -1;
    else return 0;
}

int colaInserta(Cola *c,tipoElemento elemento){
    // Añade el elemento x en la posición a continuación del fondo,
    // o último elemento de la cola, pasando a ser el nuevo fondo de la misma
    tipoCelda *nuevaPosicion;
    if (colaVacia(c) == -1) return -1;
    if(NULL == (nuevaPosicion = malloc(sizeof(tipoCelda)))) return -2;
    nuevaPosicion->elemento = elemento;
    nuevaPosicion->sig = NULL;
    c->fondo->sig = nuevaPosicion;
    return 0;
}

tipoElemento colaSuprime(Cola *c){
    // Elimina el elemento del frente o primer elemento de la cola,
    // pasando a ser el nuevo frente el siguiente elemento.
    // Devuelve el valor almacenado en esa posición.
    tipoCelda *aBorrar;
    if (colaVacia(c) != 0) return -1;
    else {
        aBorrar = c->frente;
        if(aBorrar == NULL) return -2;
        c->frente = aBorrar->sig;
        free(aBorrar);
        return 0;
    }
}
