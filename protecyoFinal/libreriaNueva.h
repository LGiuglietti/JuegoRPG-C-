#ifndef LIBRERIANUEVA_H_INCLUDED
#define LIBRERIANUEVA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Codito2.h"
typedef struct
{
    char nombre[30];
    int vidaMax;
    int vidaActual;
    int danio;
    int armadura;
    int cantidadCombates;
    int habitacionActual; //del 1 al 7, 4 es la inicial
}heroe;

typedef struct mob
{
    char nombre[30];
    char prefacio[200];
    int vida;
    int danio;
    int estado;///0 muerto, 1 vivo
}mob;

void recogerLootCofre(heroe jugador, nododoble*lista);
#endif // LIBRERIANUEVA_H_INCLUDED
