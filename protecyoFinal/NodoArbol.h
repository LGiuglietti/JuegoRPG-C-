#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/// Los nodos se mantendran fijos en todo momento

typedef struct arbolnodo
{
    int posicion;///Valor dado para ubicarse en las salas
    ///Definir si va a ser objeto o mob
    struct arbolnodo* izq;
    struct arbolnodo* der;
}arbolnodo;

arbolnodo* inicarbol();
arbolnodo* crearnodoarbol();
arbolnodo* insertar(arbolnodo* nodo);
arbolnodo* buscar(arbolnodo* arbol);

#endif // NODOARBOL_H_INCLUDED
