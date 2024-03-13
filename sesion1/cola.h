#ifndef __COLAS__H
#define __COLAS__H

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO

#include "arbol.h"

typedef Arbol tipoElemento;

#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA

typedef struct tipoCelda {
    tipoElemento elemento;
    struct tipoCelda *sig;
} tipoCelda;

#endif

typedef struct {
    tipoCelda *frente, *fondo;
} Cola;


// declaracion de funciones
int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoElemento elemento);
tipoElemento colaSuprime(Cola *c);

#endif