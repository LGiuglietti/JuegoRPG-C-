#ifndef LIBRERIANUEVA_H_INCLUDED
#define LIBRERIANUEVA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct objeto
{
    char nombre[30];
    int mod; ///numeros positivos= modificadores danio, 0=pocion, numeros negativos=armaduras
    int estado; ///1=espacio usado, 0=espacio libre, por defecto 0
} objeto;

typedef struct objetoMagico
{
    char nombre[30];
    char prefacio[200];
    int mod;
}objetoMagico;

typedef struct
{
    char nombre[30];
    int vidaMax;
    int vidaActual;
    int danio;
    int armadura;
    objeto inventario[10];
}heroe;

typedef struct nodoArbol
{
    int dirX;
    int dirY;
    int estado; ///1 completado, 0 no completado
    int encuentro;
    struct nodo*sig;
}nodoArbol;
typedef struct mob
{
    char nombre[30];
    char prefacio[200];
    int vida;
    int danio;
    int estado;///0 muerto, 1 vivo
}mob;
void recogerLootCofre(heroe jugador, int *validosArchivoArmas, int *validosArchivoArmaduras);
#endif // LIBRERIANUEVA_H_INCLUDED
