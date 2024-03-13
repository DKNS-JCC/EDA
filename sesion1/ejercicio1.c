#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void){ 
    
    Arbol varArbol;
    Arbol varArbol2;

/* Creación arbol ejemplo de las transparencias de recorridos */
    varArbol = creaNodo('A');
    varArbol->izq = creaNodo('B');
    varArbol->der = creaNodo('C');
    varArbol->izq->izq = creaNodo('D');
    varArbol->izq->der = creaNodo('E');
    varArbol->der->izq = creaNodo('F');
    varArbol->der->der = creaNodo('G');
    // varArbol->der->der->der = creaNodo('x');
    // varArbol->der->der->izq = creaNodo('y');
    varArbol2 = creaNodo('A');
    varArbol2->izq = creaNodo('B');
    varArbol2->der = creaNodo('C');
    varArbol2->izq->izq = creaNodo('D');
    varArbol2->izq->der = creaNodo('E');
    varArbol2->der->izq = creaNodo('F');
    varArbol2->der->der = creaNodo('G');

/* Aplicación de recorridos al arbol ejemplo */

    printf("Recorrido en PRE_ORDEN: ");
    preOrden(varArbol);
    printf("\n");
    printf("Recorrido en ORDEN: ");
    enOrden(varArbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN: ");
    postOrden(varArbol);
    printf("\n");
    printf("Recorrido en AMPLITUD: ");
    amplitud(varArbol);
    printf("\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */
    
    /*
    int profundidar;
    profundidar = profuncidad(varArbol);
    printf("\nProfundidad\n");
    preOrden(varArbol);
    */

    // ALTURA DE UN NODO
    int alt;

    alt = altura(varArbol);
    printf("\nAltura del nodo %c: %d\n", varArbol->info, alt);

    // NUMERO DE NODOS INCLUYENDO EL NODO QUE SE PASA POR PARAMETRO
    int nNodos;

    nNodos = numNodos(varArbol);
    printf("Numero de nodos de %c: %d\n", varArbol->info, nNodos);


    // ANULAR ARBOL
    // varArbol = anula(varArbol);
    // enOrden(varArbol);

    // SUSTITUIR
    int cambios;
    cambios = sustituye(varArbol, 'B', 'B');
    printf("Se han producido %d cambios\n", cambios);
    preOrden(varArbol);
    printf("\n");

    // NODOS HIJOS HOJA
    int hojas;
    hojas = numNodosHoja(varArbol);
    printf("Hay %d nodos HOJA\n", hojas);

    // NODOS HIJOS INTERNO
    int internos;
    internos = numNodosInternos(varArbol);
    printf("Hay %d nodos INTERNOS\n", internos);

    // NODOS QUE TIENEN UN SOLO HIJO
    int unHijo;
    unHijo = numHijoUnico(varArbol);
    printf("Hay %d UNIHIJOS\n", unHijo);

    // BUSCAR MAX
    Arbol max;
    max = buscarMax(varArbol);
    printf("El nodo max: %c\n", max->info);

    // BUSCAR MIN
    Arbol min;
    min = buscarMin(varArbol);
    printf("El nodo min: %c\n", min->info);

    // SIMILARES
    if(similares(varArbol, varArbol2) == 0){
        printf("Los dos arboles son similares\n");
    }else{
        printf("Los dos arboles NO son similares\n");
    }

    /*
    printf("Recorrido en PRE_ORDEN: ");
    preOrden(varArbol2);
    printf("\n");
    printf("Recorrido en ORDEN: ");
    enOrden(varArbol2);
    printf("\n");
    printf("Recorrido en POST_ORDEN: ");
    postOrden(varArbol2);
    printf("\n");
    printf("Recorrido en AMPLITUD: ");
    amplitud(varArbol2);
    printf("\n");
    */

    // EQUIVALENTES
    if(equivalentes(varArbol, varArbol2) == 0){
        printf("Los dos arboles son equivalentes\n");
    }else{
        printf("Los dos arboles NO son equivalentes\n");
    }

    // ESPECULAR
    Arbol especul;
    especul = especular(varArbol);
    printf("EL ARBOL ESPECULAR: ");
    amplitud(especul);
    printf("\n");

    return 0;
    
}