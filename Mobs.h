#ifndef MOBS_H_INCLUDED
#define MOBS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MOBS "mobs.bin"
#define BOSSES "bosses.bin"

typedef struct Mob
{
    char nombre[30];
    char prefacio[200];
    int vida;
    int danio;
    int defensa;
    int estado;///0 muerto, 1 vivo
}Mob;

typedef struct Boss
{
    int relleno;
}Boss;

///Mob
Mob crearmob();
void persistenciamobs();
Mob depersistenciamob(int ultimo);///Toma en cuenta la cant de combates del pj, para aumentar gradualmente la dificultad

///Boss

#endif // MOBS_H_INCLUDED
