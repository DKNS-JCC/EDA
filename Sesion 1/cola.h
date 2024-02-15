#ifndef __COLA_H
#define __COLA_H

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA

typedef struct tipoCelda
{
	int elemento;
	struct tipoCelda *sig;
} tipoCelda;

#endif

typedef struct
{
	tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);

int colaVacia(Cola *c);

int colaInserta(Cola *c, int elemento);

int colaSuprime(Cola *c);

#endif
