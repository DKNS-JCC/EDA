# Sesión 2 Implementación de las funciones del ejercicio2

# Ejercicio 1: Recorridos en árboles binarios

ejercicio1: arbol.o cola.o ejercicio2.o
	gcc -g arbol.o cola.o ejercicio2.o -o ejercicio1

#Ejercicio 2: Aplicar las funciones recursivas del ejercicio2 a los arboles de los ejercicios 1 y 3
ejercicio2: ejercicio1.c arbol.o cola.o ejercicio2.o
		gcc -g ejercicio1.c arbol.o cola.o ejercicio2.o -o ej2
# Sesión 1 	Aplicación de los TAD's pila y cola en la generación y recorrido de árboles binarios

ejercicio3: ejercicio3.c arbol.o genArbol.o pila.o cola.o ejercicio2.o
	gcc -g ejercicio3.c arbol.o genArbol.o pila.o cola.o ejercicio2.o -o ejercicio3

ejercicio2.o: arbol.h ejercicio2.c
	gcc -c -g ejercicio2.c
arbol.o: arbol.h arbol.c 
	gcc -c -g arbol.c 
genArbol.o: genArbol.c  
	gcc -c genArbol.c 
cola.o: cola.h cola.c 
	gcc -g -c cola.c
pila.o: pila.c pila.h arbol.h
	gcc -c pila.c
limpiar:
	rm *.o




