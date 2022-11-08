#include "filas.h"
#include "libreriaDoble.h"
void inicfila(fila*fila)
{
    fila->cabecera=iniclista();
    fila->cola=iniclista();
}
void agregar(fila*fila, int dato)
{
    nodoD*nuevo=crearNodoD(dato);
    if(fila->cabecera==NULL)
    {
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else
    {
        fila->cabecera=agregarFinal(fila->cabecera,nuevo);
        fila->cola=nuevo;
    }
}
int extraer (fila*fila)
{
    int rsp;
    if(fila->cabecera!=NULL)
    {
        rsp=verPrimero(fila->cabecera);
        fila->cabecera=borrarPrimero(fila->cabecera);
        if(fila->cabecera==NULL)
        {
            fila->cola=iniclista();
        }
    }
    return rsp;
}
nodoD*borrarPrimero(nodoD*lista)
{
    nodoD*aborrar=lista;
    if(lista!=NULL)
    {
        lista=lista->sig;
        if(lista!=NULL)
        {
            lista->ante=NULL;
        }
        free(aborrar);
    }
    return lista;
}
int verPrimero(nodoD*lista)
{
    int rta=-1;
    if(lista!=NULL)
    {
        rta=lista->dato;
    }
    return rta;
}
