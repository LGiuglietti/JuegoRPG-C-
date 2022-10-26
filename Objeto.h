#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct objeto
{
    char prefacio[200];
    char nombre[30];
    int modificador; ///danio o curacion
    int tipo;///0. Pergamino, 1. Pocion,2. Arma,3. Armadura,-1. Inventario Vacio
} objeto;

objeto crearobjeto(); ///Crea un objeto
void cargaarchiobj(objeto elobjeto);/// Carga a un archivo un objeto

#endif // OBJETO_H_INCLUDED
