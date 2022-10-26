#ifndef MOBS_H_INCLUDED
#define MOBS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mobs
{
    char nombre[30];
    int vida;
    int danio;
    int estado;///0 muerto, 1 vivo
}mobs;

#endif // MOBS_H_INCLUDED
