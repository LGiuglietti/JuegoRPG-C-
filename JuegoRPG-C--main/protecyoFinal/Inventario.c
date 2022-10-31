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
