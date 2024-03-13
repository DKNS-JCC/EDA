#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

void iniciaMonticulo(Monticulo *m){

    m->tamanno = 0;

}

int vacioMonticulo(Monticulo m){
    
    return((m.tamanno == 0) ? 1 : 0);

}

int insertar(tipoElemento x, Monticulo *m){

    if(m->tamanno >= MAXIMO){
        return 1;
    }

    m->tamanno++;
    m->elemento[m->tamanno] = x;
        
    filtradoAscendente(m, m->tamanno);

    return 0;

}

int eliminarMinimo(Monticulo *m, tipoElemento *minimo){

    if(vacioMonticulo(*m)){
        return 1;
    }    

    *minimo = m->elemento[1];
    m->elemento[1] = m->elemento[m->tamanno];
    m->tamanno--;

    filtradoDescendente(m,1);

    return 0;
    
}

void decrementarClave(int pos, tipoClave cantidad, Monticulo *m){

    m->elemento[pos].clave -= cantidad;
           
    filtradoAscendente(m, pos);

}


void incrementarClave(int pos, tipoClave cantidad, Monticulo *m){


    m->elemento[pos].clave += cantidad;

    filtradoDescendente(m, pos);

}


int esMonticulo(Monticulo m){
    
    int i;

    for(i=m.tamanno; i>1; i--){

        if(m.elemento[i/2].clave > m.elemento[i].clave){
            return 1;
        }

    }

    return 0;

}

void crearMonticulo(Monticulo *m){
    
    int i;

  	for(i=m->tamanno/2; i>=1; i--)
  		filtradoDescendente(m,i);

}

void filtradoDescendente(Monticulo *m, int i){

    int hijo, finFiltrado;
  	tipoElemento aux = m->elemento[i];

  	finFiltrado = 0;

  	while(2*i <= m->tamanno && !finFiltrado){
  		hijo = 2*i;
  		if(hijo+1 <=m->tamanno && m->elemento[hijo+1].clave < m->elemento[hijo].clave)
  			hijo++;

  		if(aux.clave > m->elemento[hijo].clave){
  			m->elemento[i] = m->elemento[hijo];
  			i = hijo;
  		}else
  			finFiltrado = 1;
  	}

  	m->elemento[i] = aux;

}

void filtradoAscendente(Monticulo *m, int i){

    tipoElemento aux = m->elemento[i];

    while(i>1 && aux.clave < m->elemento[i/2].clave){
        m->elemento[i] = m->elemento[i/2];
        i/=2;
    }

    m->elemento[i] = aux;
}

void heapsort(Monticulo *m){
    
    int tam, i;
  	tipoElemento e;

  	crearMonticulo(m);
    
    tam = m->tamanno;

  	for(i = tam; i >= 1; i--){
        
        if(eliminarMinimo(m, &e) == 0){ 
            m->elemento[i+1] = e;
        }   
  		
  	}

    m->tamanno = tam;

    for(i=1; i<=m->tamanno/2; i++){
        e = m->elemento[i];
        m->elemento[i] = m->elemento[tam];
        m->elemento[tam ] = e;
        tam--;
    }

}