#include "Codito2.h"

nododoble* iniclista()
{
    return NULL;
}

nododoble* crearnodo(objeto objetito)
{
    nododoble* nuevo=(nododoble*) malloc(sizeof(nododoble));

    nuevo->dato=objetito;
    nuevo->ante=NULL;
    nuevo->sig=NULL;

    return nuevo;
}

nododoble* agregarfinal2(nododoble* lista,nododoble* nuevo)
{
    if(lista!=NULL)
    {
        int basura=0;///Para simplificar rey
        nododoble* ultimo=buscarultimo(lista,&basura);
        ultimo->sig=nuevo;
        nuevo->ante=ultimo;
    }

    return lista;
}

nododoble* buscarultimo(nododoble* lista, int*cantEspaciosUsados)
{
    nododoble* seg=lista;

    if(lista!=NULL)
    {
        while(seg->sig!=NULL)
        {
            (*cantEspaciosUsados)++;
            seg=seg->sig;
        }
    }

    return seg;
}

nododoble* buscar(nododoble* lista,char dato[])
{
    nododoble* abuscar=NULL;

    if(lista!=NULL)
    {
        nododoble* seg=lista;

        while((seg!=NULL)&&(strcmpi(dato,seg->dato.nombre)!=0))
        {
            seg=seg->sig;
        }

        if(seg!=NULL)
        {
            abuscar=seg;
        }
    }

    return abuscar;
}

nododoble* borrarnodo(nododoble* lista,char dato[])
{
    if(lista!=NULL)
    {
        nododoble* aborrar=buscar(lista,dato);

        if(aborrar!=NULL)
        {
            nododoble* auxante=aborrar->ante;
            nododoble* auxsig=aborrar->sig;

            auxante->sig=auxsig;
            auxsig->ante=auxante;
            free(aborrar);
        }
        else
        {
            printf("NO HAY OBJETOS");
        }
    }

    return lista;
}

void mostrarlista(nododoble* lista)
{
    if(lista==NULL)
    {
        printf("inventario vacio, anda a farmear noob");
    }
    else
    {
        nododoble* seg=lista;
        int i=1;///Contador que funciona solo para enumerar

        while(seg->sig!=NULL)
        {
            printf("%i. %s",i,seg->dato.nombre);
            i++;
            seg=seg->sig;
        }
        while(i<11)
        {
            printf("%i. ------",i);
            i++;
        }
    }
}
