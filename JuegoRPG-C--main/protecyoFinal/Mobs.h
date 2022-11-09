#ifndef MOBS_H_INCLUDED
#define MOBS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MOBS "mobs.bin"
#define CANTMOBS 6
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
    struct Mob theboss;
    struct fila* primero;
    struct fila* ultimo;
}Boss;

///Mob
void cargararchimobs();///Inicializa el archivo con los mobs
Mob crearmob(int tipo);///Trae por referencia que tipo de mob se desea crear
void persistenciamobs(Mob losmob[]);
Mob depersistenciamob(int ultimo);///Toma en cuenta la cant de combates del pj, para aumentar gradualmente la dificultad
Mob mobatacado(Mob elmob,int danio);///Mide cuanta vida se le resta a un enemigo cuando es atacado, actualiza su estado en caso que sea necesario

///Boss
Boss crearboss();

#endif // MOBS_H_INCLUDED
