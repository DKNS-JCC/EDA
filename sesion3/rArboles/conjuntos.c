#include "conjuntos.h"
#include <stdio.h>


/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................

void crea(particion P){
    
    #ifdef TAMANNO
        #undef ALTURA
        #undef ARBITRARIO
    #endif
    #ifdef ALTURA
        #undef TAMANNO
        #undef ARBITRARIO
    #endif
    #ifdef ARBITRARIO
        #undef ALTURA
        #undef TAMANNO
    #endif

    int i;

    #ifdef TAMANNO
	for(i=0; i<MAXIMO; i++)
		P[i] = -1;
    #endif

    #ifdef ALTURA
        for(i=0; i<MAXIMO; i++)
            P[i] = -1;
    #endif

    #ifdef ARBITRARIO
        for(i=0; i<MAXIMO; i++)
            P[i] = i;
    #endif

}

tipoConjunto buscar(tipoElemento x, particion P){

    #ifdef ARBITRARIO
        if(P[x] == x){
            return x;
        }else{
            P[x] = buscar(P[x], P);
            return P[x];
        }
    #endif

    #ifdef TAMANNO
        if(P[x] < 0){
            return x;
        }else{
            P[x] = buscar(P[x], P);
            return P[x];
        }
    #endif

    #ifdef ALTURA
        if(P[x] < 0){
            return x;
        }else{
            P[x] = buscar(P[x], P);
            return P[x];
        }
    #endif

}

int unir(tipoElemento x, tipoElemento y, particion P){

    x = buscar(x, P);
    y = buscar(y, P);

    #ifdef ARBITARIO
        P[y] = x; 
    #endif

    #ifdef ALTURA
        if(C[x] == C[y]){
		    C[x]--;
		    C[y] = x;
	    }else{
		    if(C[x] < C[y])
			    C[y] = x;
		    else
			    C[x] = y;
	    }
    #endif

    #ifdef TAMANNO
        if(C[x] <= C[y]){
            C[x] += C[y];
            C[y] = x;
        }else{
            C[y] += C[x];
            C[x] = y;
        }
    #endif
    
}


//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion P)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
