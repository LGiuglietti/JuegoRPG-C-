#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Inventario.h"

typedef struct heroe
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

Heroe crearheroe();///Crea un heroe listo para la aventura
Heroe recogerloot(Heroe jugador, Objeto elobjeto);
int inventariolleno(nododoble* inventarioheroe);
Heroe actualizaciondestats(Objeto elobjeto);

#endif // JUGADOR_H_INCLUDED
