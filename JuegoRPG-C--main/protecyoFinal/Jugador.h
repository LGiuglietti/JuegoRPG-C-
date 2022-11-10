#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Inventario.h"
#include "Mobs.h"

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
Heroe recogerLootCofre(Heroe jugador);
Heroe dropsp(Heroe jugador,int designado);
Heroe armaduraoarma(Heroe jugador);
int combate(Heroe* jug);
Heroe ataque(Heroe jug,Mob* elmob);
Heroe recibedanio(Heroe jugador,int danio);
Heroe utilizarobjetoencombate(Heroe jugador);
void efectoObjetoEnCombate(nododoble* dato,Heroe* jug,Mob* mob);//realiza los efectos del  objeto en combate
int intentoescape(int seescapo,Mob* elmob);

#endif // JUGADOR_H_INCLUDED
