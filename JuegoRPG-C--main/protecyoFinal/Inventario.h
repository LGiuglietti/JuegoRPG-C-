#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED
#include "Codito2.h"
#define LIMITE 10

///Elegimos utilizar lista para el inventario porque a pesar de saber que van a ser 10, era el mejor lugar para incluir una lista

nododoble* inicinventario(); ///Inicializa la lista de invnetario
nododoble* usarobjeto(nododoble* inventario,Objeto elobjeto); ///Utiliza un oobjeto del inventario
nododoble* agregarobjeto(nododoble* inventario,int tipo,int* ultimo); ///Agrega un objeto al inventario
void verinventario(nododoble* inventario); ///Visuliaza los objetos en el inventario


#endif // INVENTARIO_H_INCLUDED
