#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PERGAMINO "pergamino.bin"
#define POCION "pocion.bin"
#define ARMA "arma.bin"
#define ARMADURA "armadura.bin"

typedef struct Objeto
{
    char prefacio[200];
    char nombre[30];
    int modificador; ///danio o curacion
    int tipo;///1. Pergamino, 2. Pocion,3. Arma,4. Armadura
} Objeto;

Objeto crearobjeto(); ///Crea un objeto

#endif // OBJETO_H_INCLUDED
