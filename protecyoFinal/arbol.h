#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct nodoArbol
{
    int id; ///del 1 al 7, inicia en 4
    int estado; ///1 completado, 0 no completado
    int encuentro; ///1 si es combate, 0 si es cofre
    struct nodoArbol*derecha; //apunta a derecha
    struct nodoArbol*izquierda;//apunta a izquierda
} nodoArbol;

nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(int dato);
nodoArbol*insertar(nodoArbol*arbol,int dato);
void preorder(nodoArbol*arbol);
void inorder(nodoArbol*arbol);
void postorder(nodoArbol*arbol);
nodoArbol*buscar(nodoArbol*arbol, int dato);
nodoArbol*NMI(nodoArbol*nodo);
nodoArbol*NMD(nodoArbol*nodo);
nodoArbol*borrarNodo(nodoArbol*nodo, int dato);
int esHoja (nodoArbol*nodo);

#endif // ARBOL_H_INCLUDED
