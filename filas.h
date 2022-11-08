#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include "libreriaDoble.h"
typedef struct
{
    struct nodoD*cabecera;
    struct nodoD*cola;
}fila;
void inicfila(fila*fila);
void agregar(fila*fila, int dato);
int extraer (fila*fila);
nodoD*borrarPrimero(nodoD*lista);
int verPrimero(nodoD*lista);
#endif // FILAS_H_INCLUDED
