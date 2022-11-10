#include "Inventario.h"

nododoble* inicinventario()
{
    nododoble* inventario=iniclista();

    return inventario;
}

nododoble* usarobjeto(nododoble* inventario,Objeto elobjeto)
{
    if(inventario!=NULL)
    {
        borrarnodo(inventario,elobjeto.nombre);
    }
    else
    {
        printf("No hay elementos");
    }
    //Hacer la verificacion desde donde llamo la funcion y de ahi en caso de que el inventairo sea NULL hago el printf

    return inventario;
}

nododoble* agregarobjeto(nododoble* inventario,Objeto elobjeto)
{
    nododoble* nuevo=crearnodo(elobjeto);

    if(inventario==NULL)
    {
        inventario=nuevo;
    }
    else
    {
        nododoble* aux=inventario;
        aux=buscarultimo(aux);

        aux->sig=nuevo;
        nuevo->ante=aux;
    }

    return inventario;
}

void verinventario(nododoble* inventario)
{
    if(inventario==NULL)
    {
        printf("No hay Objetos");
    }
    else
    {
        int limite=contarItemsInventario(inventario);
        mostrarlista(inventario);
        while(limite<LIMITE)
        {
            limite++;
            printf("%i. ---------",limite);
        }

    }
}

Objeto buscarobjeto(nododoble* inventario,int posicion)
{
    Objeto abuscar;
    abuscar.tipo=0;///Inicializo este campo en 0 para poder hacer comprobaciones fuera de la funcion

    if(inventario!=NULL)
    {
        nododoble* aux=inventario;
        int i=0;

        while((i<posicion)&&(aux!=NULL))
        {
            aux=aux->sig;
            i++;
        }

        if(aux!=NULL)
        {
            abuscar=aux->dato;
        }
        else
        {
            printf("No se encontro");
        }

    }

    return abuscar;
}

void efectoObjetoEnCombate(nododoble*dato,Heroe*jug,Mob*mob)
{
    if(dato->dato.tipo==2) //el item es pocion
    {
        jug->vidaActual=jug->vidaActual+5;
        if(jug->vidaActual>jug->vidaMax)
        {
            jug->vidaActual=jug->vidaMax;
            printf("te curas todos tus puntos de golpe");
        }
        else
        {
            printf("te curas 5 puntos de golpe");
        }
        Sleep(2000);
        system("cls");
    }
    else
    {
        printf("utilizando tu pergamino de %s atacas al %s",dato->dato.nombre, mob->nombre);
        mob->vida=mob->vida-dato->dato.modificador;
        Sleep(2300);
        system("cls");
    }
}
