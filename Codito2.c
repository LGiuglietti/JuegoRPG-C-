#include "Codito2.h"

nododoble* iniclista()
{
    return NULL;
}

nododoble* crearnodo(Objeto objetito)
{
    nododoble* nuevo=(nododoble*) malloc(sizeof(nododoble));

    nuevo->dato=objetito;
    nuevo->ante=NULL;
    nuevo->sig=NULL;

    return nuevo;
}

nododoble* agregarfinal2(nododoble* lista, nododoble* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nododoble* ultimo=buscarultimo(lista);
        ultimo->sig=nuevo;
        nuevo->ante=ultimo;
    }

    return lista;
}

nododoble* buscarultimo(nododoble* lista)
{
    nododoble* seg=lista;

    if(lista!=NULL)
    {
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
    }

    return seg;
}

int contarItemsInventario(nododoble* lista)
{
    nododoble* seg=lista;
    int cantEspaciosUsados=0;
    if(lista!=NULL)
    {
        while(seg!=NULL)
        {
            cantEspaciosUsados++;
            seg=seg->sig;
        }
    }

    return cantEspaciosUsados;
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
        nododoble* aborrar;

        if(strcpy(lista->dato.nombre,dato)==0)
        {
            aborrar=lista;
            lista=lista->sig;
            free(aborrar);
        }
        else
        {
            aborrar=buscar(lista,dato);

            if(aborrar!=NULL)
            {
                if(aborrar->sig==NULL)
                {
                    (aborrar->ante)->sig=NULL;
                }
                else
                {
                    (aborrar->ante)->sig=aborrar->sig;
                    (aborrar->sig)->ante=aborrar->ante;
                }

                free(aborrar);
            }
            else
            {
                printf("No existe el objeto solicitado");
            }
        }
    }
    else
    {
        printf("NO HAY OBJETOS");
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

        while(seg!=NULL)
        {
            printf("%i. %s  ",i,seg->dato.nombre);
            i++;
            seg=seg->sig;
        }
    }
}
