#ifndef LIBRERIANUEVA_H_INCLUDED
#define LIBRERIANUEVA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    char nombre[30];
    int vidaMax;
    int vidaActual;
    int danio;
    int armadura;
    int cantidadCombates;
    //objeto inventario[7];
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

void recogerLootCofre(heroe jugador);
#endif // LIBRERIANUEVA_H_INCLUDED
