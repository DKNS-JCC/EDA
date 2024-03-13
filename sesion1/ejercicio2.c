#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "arbol.h"

int altura(Arbol raiz){

    if(raiz == NULL){
        return -1;
    }else{
        int alturaIzq = altura(raiz->izq);
        int alturaDer = altura(raiz->der);
        
        return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
    }   
    
}

int numNodos(Arbol raiz){

    if(raiz == NULL){
        return 0;
    }else{
        int nodoIzq = numNodos(raiz->izq);
        int nodoDer = numNodos(raiz->der);

        return 1 + (nodoIzq + nodoDer);
    }

}

Arbol anula(Arbol raiz){

    if(raiz == NULL){
        return NULL;
    }else{
        anula(raiz->izq);
        anula(raiz->der);

        free(raiz);
        return NULL;
    }

}

/*
int profuncidad(Arbol raiz){

    if(raiz == NULL){
        return 0;
    }
    else{
        int izq = 0, der = 0;
        
        if(raiz->izq != NULL){
            raiz->izq->info = ++izq;
        }
        if(raiz->der != NULL){
            raiz->der->info = ++der;
        }

        izq += profuncidad(raiz->izq);
        der += profuncidad(raiz->der);

        return 0;
    }
  

}
*/

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y){

    if(raiz == NULL){
        return 0;
    }else{
        int contador = 0;
        int infoIzq = sustituye(raiz->izq, x, y);
        int infoDer = sustituye(raiz->der, x, y);

        if(raiz->info == x){
            raiz->info = y;
            contador++;
        }
        
        return contador + infoIzq + infoDer;

    }



}

int numNodosHoja(Arbol raiz){
    
    if(raiz == NULL){
        return 0;
    }else{
        int contador = 0;
        
        if(raiz->izq == NULL && raiz->der == NULL){
            contador++;
        }

        int numIzq = numNodosHoja(raiz->izq);
        int numDer = numNodosHoja(raiz->der);

        contador += numIzq + numDer;

        return contador;

    }

}

int numNodosInternos(Arbol raiz){   // DEBERIA CONTAR EL NODO RAIZ?

    if(raiz == NULL){
        return 0;
    }else{
        int contador = 0;

        if(raiz->izq != NULL || raiz->der != NULL){
            contador++;
        }

        int numIzq = numNodosInternos(raiz->izq);
        int numDer = numNodosInternos(raiz->der);

        contador += numIzq + numDer;

        return contador;

    }

}

int numHijoUnico(Arbol raiz){

    if(raiz == NULL){
        return 0;
    }else{
        int contador = 0;

        if((raiz->izq != NULL && raiz->der == NULL) || (raiz->izq == NULL && raiz->der != NULL)){
            contador++;
        }

        int numIzq = numHijoUnico(raiz->izq);
        int numDer = numHijoUnico(raiz->der);

        contador += numIzq + numDer;

        return contador;
    }

}

Arbol buscarMax(Arbol raiz){

    if(raiz == NULL){
        return NULL;
    }else{  
        Arbol izq = buscarMax(raiz->izq);
        Arbol der = buscarMax(raiz->der);
        Arbol max = raiz;
        
        if (izq != NULL && izq->info > max->info) {
            max = izq;
        }

        if (der != NULL && der->info > max->info) {
            max = der;
        }

        return max;
    }

}

Arbol buscarMin(Arbol raiz){

    if(raiz == NULL){
        return NULL;
    }else{  
        Arbol izq = buscarMax(raiz->izq);
        Arbol der = buscarMax(raiz->der);
        Arbol min = raiz;
        
        if (izq != NULL && izq->info < min->info) {
            min = izq;
        }

        if (der != NULL && der->info < min->info) {
            min = der;
        }

        return min;
    }
}

int similares(Arbol r1, Arbol r2){

    if(r1 == NULL && r2 == NULL){
        return 0;
    }else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
        return 1;
    }else{
        int similIzq = similares(r1->izq, r2->izq);
        int similDer = similares(r1->der, r2->der);

        if(similIzq == 0 && similDer == 0){
            return 0;
        }else{
            return 1;
        }
    }

}

int equivalentes(Arbol r1,Arbol r2){

    if(r1 == NULL && r2 == NULL){
        return 0;
    }else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
        return 1;
    }else if(r1->info != r2->info){
        return 1;
    }else{

        int equiIzq = equivalentes(r1->izq, r2->izq);
        int equiDer = equivalentes(r1->der, r2->der);

        if(equiIzq == 0 && equiDer == 0){
            return 0;
        }else{
            return 1;
        }
    }
}

Arbol especular(Arbol raiz){

    if(raiz==NULL){
        return raiz;

    }else{
        Arbol nuevo = creaNodo(raiz->info);
        nuevo->izq = especular(raiz->der);
        nuevo->der = especular(raiz->izq);

        return nuevo;
    }

}

/* ______________________________
   EJERCICIO 3: EVALUAR UN ARBOL
   ______________________________ */

int evaluar(Arbol raiz){
    
    // PORQUE EL IF DEBE SER CON COMILLAS SIMPLES (') Y NO DOBLES("")??????

    int izquierda, derecha;

    if(raiz == NULL){
        return 0;
    }
    if(raiz->izq == NULL && raiz->der == NULL){
        return raiz->info - 48;
    }

    izquierda = evaluar(raiz->izq);
    derecha = evaluar(raiz->der);

    if(raiz->info == '+'){
        return izquierda + derecha;
    }

    if(raiz->info == '*'){
        return izquierda * derecha;
    }

    if(raiz->info == '/'){
        return izquierda / derecha;
    }

    if(raiz->info == '-'){
        return izquierda - derecha;
    }

}
/* __________________________________
   EJERCICIO 4: RECONSTRUIR UN ARBOL
   __________________________________ */

/*
    P: A B H I K L M J C D E F G
    O: I L K M H J B A D F E G C

    iPreorden = 0;

*/

Arbol reconstruir(char *orden, char *preorden, int i, int longitud){

    if(longitud <= 0){
        return NULL;
    }

    Arbol a = creaNodo(preorden[i]);

    int j, k;

    for(j = 0; j < longitud; j++){
        if((orden[j] == preorden[i])){
            k = j;
            break;
        }
    }

    a->izq = reconstruir(orden, preorden, i+1, k);
    a->der = reconstruir(orden + k + 1, preorden, i + k + 1, longitud - k - 1);

    return a;
}
