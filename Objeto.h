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
void persistenciaobj(Objeto elobjeto); /// Carga a un archivo un objeto
void persistirpergamino(Objeto elobjeto);
void persistirpocion(Objeto elobjeto);
void persistirarma(Objeto elobjeto);
void persistirarmadura(Objeto elobjeto);
Objeto depersistenciaobjetos(int tipo,int* ultimo); ///Trae de un archivo un objeto, el puntero para no leer 2 veces el mismo objeto
Objeto depersistirpergamino(int ultimo);
Objeto depersistirpocion(int ultimo);
Objeto depersistirarma(int ultimo);
Objeto depersistirarmadura(int );

#endif // OBJETO_H_INCLUDED
