#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;
typedef int tipoConjunto;

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
} tipoCelda;


typedef struct {
	tipoCelda * primero , *ultimo;
} tipoLista;


typedef tipoLista particion[MAXIMO];


// Funciones a implementar
void crea(particion C);
tipoElemento buscar(tipoElemento x, particion C);
void unir(tipoElemento x, tipoElemento y, particion P);

// Funciones proporcionadas
void verParticion(particion P);
void verClaseEquivalencia(tipoElemento x, particion P);

#endif

