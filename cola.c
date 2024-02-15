#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

int colaCreaVacia(Cola *c)
{
    c->frente = NULL;
    c->fondo = NULL;
    return 0;
}

// 1=Vacia 0=No vacia
int colaVacia(Cola *c)
{
    if (c->frente == NULL && c->fondo == NULL)
        return 1;
    else
        return 0;
}

int colaInserta(Cola *c, tipoElemento elemento)
{
    tipoCelda *nuevo;
    nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (nuevo == NULL)
        return -1;
    nuevo->elemento = elemento;
    nuevo->sig = NULL;
    if (colaVacia(c))
    {
        c->frente = nuevo;
        c->fondo = nuevo;
    }
    else
    {
        c->fondo->sig = nuevo;
        c->fondo = nuevo;
    }
    return 0;
}


int colaSuprime(Cola *c)
{
    tipoCelda *aBorrar;
    if (colaVacia(c))
        return -1;
    aBorrar = c->frente;
    c->frente = c->frente->sig;
    if (c->frente == NULL)
        c->fondo = NULL;
    free(aBorrar);
    return 0;
}
