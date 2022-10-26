#ifndef LIBRERIANUEVA_H_INCLUDED
#define LIBRERIANUEVA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dirX;
    int dirY;
    int estado; ///1 completado, 0 no completado
    int encuentro;
    struct nodo*sig;
}nodo;

typedef struct mob
{
    char nombre[30];
    char prefacio[200];
    int vida;
    int danio;
    int estado;///0 muerto, 1 vivo
}mob;

//void recogerLootCofre(heroe jugador, int *validosArchivoArmas, int *validosArchivoArmaduras);
#endif // LIBRERIANUEVA_H_INCLUDED
