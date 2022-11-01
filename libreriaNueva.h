#ifndef LIBRERIANUEVA_H_INCLUDED
#define LIBRERIANUEVA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Codito2.h"
#include "Jugador.h"
typedef struct mob
{
    char nombre[30];
    char prefacio[200];
    int vida;
    int danio;
    int estado;///0 muerto, 1 vivo
}mob;

nododoble* recogerLootCofre(Heroe* jugador, nododoble* lista);
#endif // LIBRERIANUEVA_H_INCLUDED
