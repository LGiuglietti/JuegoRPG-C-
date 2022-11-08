#ifndef GUARDARYCARGAR_H_INCLUDED
#define GUARDARYCARGAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "mapa.h"


typedef struct PartidaPersistenciaArbol
{
    int id; ///del 1 al 7, inicia en 4
    int estado; ///1 completado, 0 no completado
    int encuentro; ///1 si es combate, 0 si es cofre
}PartidaPersistenciaArbol;

typedef struct Partida
{
    nodoArbol* saveArbol;
    Heroe saveJugador;
    int partida;///1, 2 o 3 nro de partida
} Partida;

void inicarreglopartida(Partida partidas[3]);///Inicializa el arreglo de partidas
void save(Partida lapartida, int nropartida, nodoArbol* arbol);///
void persistenciaarbolpartida(Partida lapartid, FILE* fp);///cargaarchivopartida
void persistenciaHeroeinvenpartida(Partida lapartid, FILE* fp);///cargaarchivopartida

#endif // GUARDARYCARGAR_H_INCLUDED
