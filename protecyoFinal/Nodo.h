#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Lo cree porque tmb hay que usar listas y bueno que ya este aca, despues vemos
typedef struct nodo
{
    //Tipo de dato
    struct nodo* sig;
}nodo;

nodo* iniclista();

#endif // NODO_H_INCLUDED
