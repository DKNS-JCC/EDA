#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int main(void){ 
    
    printf("Inicio del programa\n");

    Arbol arbol; 
    char ex_postfija[10];

/* Generaci�n del �rbol algebraico */
    strcpy(ex_postfija,"AB+CDE+**\0");
    
    arbol = genArbol(ex_postfija);

/* Recorrido en amplitud o por niveles */
    printf("\nRecorrido en AMPLITUD: ");
    amplitud(arbol);

/* Aplicaci�n de algunas operaciones y recorridos al �rbol ejemplo */

    printf("\nRecorrido en PRE_ORDEN: ");
    preOrden(arbol);
    printf("\n");

    printf("Recorrido en ORDEN: ");
    enOrden(arbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN: ");
    postOrden(arbol);
    printf("\n");
    printf("\nDebe coinicidir con la expresion postfija inicial\n");

    printf("El arbol tiene %d nodos \n", numNodos(arbol));
    printf("y altura: %d\n",altura(arbol));

    printf("\nEl arbol tiene %d nodos\n", numNodos(arbol));
    arbol = anula(arbol);
    printf("Despues de anula el arbol queda vacio, por tanto la altura sera 0.\n");
    if (altura(arbol)!=-1)		// Cuidado con definici�n de altura
        printf("El arbol no se ha anulado correctamente\n");
    else
        printf("O.K. Parece que la operacion anula funciona!!!\n\n");


/* Evaluaci�n de un �rbol algebraico: operandos entre '0' y '9'*/

    strcpy(ex_postfija,"23+713+**\0");
    arbol = genArbol(ex_postfija);
    printf("El conjunto de operaciones del arbol es igual a: %d\n", evaluar(arbol));
    printf("Recorrido en PRE_ORDEN (prefija): ");
    preOrden(arbol);
    printf("\n");
    printf("Recorrido en ORDEN(infija): ");
    enOrden(arbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN(postfija): ");
    postOrden(arbol);
    printf("\n\n");

/* Aplicar a este arbol las funciones del ejercicio 2 */

    char pre[] = "ABHIKLMJCDEFG";
    char o[] =   "ILKMHJBADFEGC";

    Arbol nuevo = reconstruir("ILKMHJBADFEGC", "ABHIKLMJCDEFG", 0, 13);

    preOrden(nuevo);
    printf("\n");
    enOrden(nuevo);
    printf("\n");
    amplitud(nuevo);
    printf("\n");

    return 0;
    
}
