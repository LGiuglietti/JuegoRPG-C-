#include "arbol.h"

nodoArbol* inicArbol()
{
    return NULL;
}
nodoArbol* crearNodoArbol(int dato)
{
    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    aux->id=dato;
    aux->derecha=NULL;
    aux->izquierda=NULL;
    aux->encuentro=rand()%1;
    aux->estado=0;
    return aux;
}
nodoArbol* insertar(nodoArbol*arbol,int dato)
{
    if(arbol==NULL)
    {
        arbol=crearNodoArbol(dato);
    }
    else
    {
        if(dato>arbol->id) //si dato es mayor al dato en arbol insertamos en la derecha
        {
            arbol->derecha=insertar(arbol->derecha,dato);
        }
        else //si no iria a la izquierda
        {
            arbol->izquierda=insertar(arbol->izquierda,dato);
        }
    }
    return arbol;
}
void preorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        printf("%d\n",arbol->id);
        preorder(arbol->izquierda);
        preorder(arbol->derecha);
    }
}
void inorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izquierda);
        printf("%d",arbol->id);
        inorder(arbol->derecha);
    }
}
void postorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izquierda);
        postorder(arbol->derecha);
        printf("%d", arbol->id);
    }
}
nodoArbol* buscarArbol(nodoArbol*arbol, int dato)
{
    nodoArbol*rta=NULL;
    if(arbol!=NULL)
    {
        if(dato==arbol->id)
        {
            rta=arbol;
        }
        else
        {
            if(dato>arbol->id)
            {
                rta=buscarArbol(arbol->derecha,dato);
            }
            else
            {
                rta=buscarArbol(arbol->izquierda,dato);
            }
        }
    }
    return rta;
}
int esHoja (nodoArbol* nodo)
{
    int rta=0;
    if((nodo->derecha==NULL) && (nodo->derecha==NULL))
    {
        rta=1;
    }
    return rta;
}
