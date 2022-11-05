#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PERGAMINO "pergamino.bin"
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
Objeto dropoti();
void persistenciaobj(Objeto elobjeto); /// Carga a un archivo un objeto
void persistirpergamino(Objeto elobjeto);
void persistirarma(Objeto elobjeto);
void persistirarmadura(Objeto elobjeto);
Objeto depersistirpergamino(int ultimo);///Ultimo es un entero para reposicionar luego el puntero del archivo
Objeto depersistirarma(int ultimo);
Objeto depersistirarmadura(int ultimo);

#endif // OBJETO_H_INCLUDED
