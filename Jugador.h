#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Inventario.h"

typedef struct Heroe
{
    char nombre[30];
    int vidaMax;
    int vidaActual;
    int atk;
    int armadura;
    int cantidadCombates;
    int habitacionActual; //del 1 al 7, 4 es la inicial
    nododoble* inventarioheroe;
}Heroe;

void cargaUsuario(Heroe* jug);
void combate(Heroe* jug);
#endif // JUGADOR_H_INCLUDED
