#include "mapa.h"

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

// funciones de manejo de mapa

nodoArbol*cargaMapa(nodoArbol*arbol)
{
    arbol=insertar(arbol,4);
    arbol=insertar(arbol,2);
    arbol=insertar(arbol,6);
    arbol=insertar(arbol,1);
    arbol=insertar(arbol,3);
    arbol=insertar(arbol,5);
    arbol=insertar(arbol,7);
    return arbol;
}
void avanzarIzquierda(nodoArbol* mapa, int habitacionActual, Heroe* jugador)
{
    if(habitacionActual==mapa->id)
    {
        if(mapa->derecha==NULL)
        {
            // combateBoss
        }
        else
        {
            nodoArbol*aux=mapa;
            aux=aux->izquierda;
            jugador->habitacionActual=aux->id;
            if(aux->estado==1)
            {
                if(aux->encuentro==1)
                {
                    printf("el cadaver de tu enemigo yace en el suelo");
                    Sleep(2300);
                }
                else
                {
                    printf("el cofre abierto yace en la habitacion");
                    Sleep(2300);
                }
            }
            else
            {
                if(aux->encuentro==1)
                {
                    combate(jugador);
                }
                else
                {
                    (*jugador)=recogerLootCofre((*jugador));
                }
            }

        }
    }
    else
    {
        if(habitacionActual>mapa->id)
        {
            buscarArbol(mapa->derecha,habitacionActual);
        }
        else
        {
            buscarArbol(mapa->izquierda,habitacionActual);
        }
    }
}
void avanzarDerecha(nodoArbol*mapa, int habitacionActual, Heroe*jugador)
{
    if(habitacionActual==mapa->id)
    {
        if(mapa->derecha==NULL)
        {
            // combateBoss
        }
        else
        {

            nodoArbol*aux=mapa;
            aux=aux->derecha;
            jugador->habitacionActual=aux->id;
            if(aux->estado==1)
            {
                if(aux->encuentro==1)
                {
                    printf("el cadaver de tu enemigo yace en el suelo");
                    Sleep(2300);
                }
                else
                {
                    printf("el cofre abierto yace en la habitacion");
                    Sleep(2300);
                }
            }
            else
            {
                if(aux->encuentro==1)
                {
                    combate(jugador);
                }
                else
                {
                    (*jugador)=recogerLootCofre((*jugador));
                }
            }

        }
    }
    else
    {
        if(habitacionActual>mapa->id)
        {
            buscarArbol(mapa->derecha,habitacionActual);
        }
        else
        {
            buscarArbol(mapa->izquierda,habitacionActual);
        }
    }
}
void retroceso(Heroe*jug,nodoArbol*mapa)
{
    nodoArbol*aux=mapa;
    if(jug->habitacionActual==1 || jug->habitacionActual==3)
    {
        jug->habitacionActual=2;
        aux=buscarYmostrarRestrocediendo(mapa,jug->habitacionActual);
    }
    else if(jug->habitacionActual==5 || jug->habitacionActual==7)
    {
        jug->habitacionActual=6;
        aux=buscarYmostrarRestrocediendo(mapa,jug->habitacionActual);
    }
    else
    {
        jug->habitacionActual=4;
        aux=buscarYmostrarRestrocediendo(mapa,jug->habitacionActual);
    }

    if(aux->estado==1)
    {
        if(aux->encuentro==1)
        {
            printf("el cadaver de tu enemigo yace en el suelo");
            Sleep(2300);
            system("cls");
        }
        else
        {
            printf("el cofre abierto yace en la habitacion");
            Sleep(2300);
            system("cls");
        }
    }
    else
    {
        if(aux->encuentro==1)
        {
            combate(jug);
        }
    }
}

nodoArbol*buscarYmostrarRestrocediendo(nodoArbol*arbol, int dato)
{
    if(arbol!=NULL)
    {
        if(dato==arbol->id)
        {
            printf("Nuestro heroe retrocede a la habitacion anterior");
            Sleep(2300);
            system("cls");
        }
        else if(dato>arbol->id)
        {
            arbol->derecha=buscarYmostrarRestrocediendo(arbol->derecha,dato);
        }
        else
        {
            arbol->izquierda=buscarYmostrarRestrocediendo(arbol->izquierda,dato);
        }
    }
    return arbol;
}


