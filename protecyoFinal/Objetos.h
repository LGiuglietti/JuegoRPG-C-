#ifndef OBJETOS_H_INCLUDED
#define OBJETOS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define OBJETO "objeto.bin"

typedef struct Objeto
{
    char prefacio[100]; ///Nombre del objeto
    int mod; ///Modificador de daño-curacion-armadura, etc del objeto
    int tipo; ///0. Pergamino, 1. Pocion,2. Arma,3. Armadura,-1. Vacio
}Objeto;

Objeto cargaobjeto(); ///Carga un objeto
void cargaarchivoobjeto(Objeto elobjeto); ///Carga en un archivo


#endif // OBJETOS_H_INCLUDED
