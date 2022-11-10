#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"
#include "Jugador.h"

typedef struct Dungeon
{
    struct nodoArbol* raiz;
    int nrotry;
}Dungeon;

int funcion();
void inicdungeon(Dungeon* ladungeon);

#endif // SALAS_H_INCLUDED
