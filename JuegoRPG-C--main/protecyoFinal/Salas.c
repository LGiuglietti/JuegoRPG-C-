#include "Salas.h"

void inicladungeon(Dungeon* ladungeon)
{
    ladungeon->raiz=inicArbol();
    ladungeon->raiz=cargaMapa(ladungeon->raiz);
}
/*
int funcion()
{
    /// inicio del setup

    srand(time(NULL)); ///Declara el seed para el rand

    Heroe jugador;
    cargaUsuario(&jugador);
    jugador.inventarioheroe=inicinventario();

    ///fin del setup

    int fin=0; //0=no se completo mazmorra, 1=se completo mazmorra
    int aux=0;
MENU:
    while((fin==0)&&(jugador.vidaActual>0))
    {
        printf("\nque desea hacer?\n");
        printf("1: avanzar\t");
        printf("2: retroceder\t");
        printf("3: abrir inventario\t");
        printf("4: guardar y salir\t");
        scanf("%d",&aux);
        if(aux>4)
        {
            printf("solo tienes 4 opciones, elija de vuelta\n");
            Sleep(2300);
            system("cls");
            goto MENU;
        }
        switch(aux)
        {
        //movimiento izquierda derecha
        case 1:

            printf("desea ir a la izquierda o la derecha?");
            printf("1: izquierda\t2: derecha");
            scanf("%d",&aux);
            switch(aux)
            {
                system("cls");
            case 1:
                printf("nuestro heroe avanza por la izquierda");
                Sleep(2300);
                system("cls");
                avanzarIzquierda(mapa,jugador.habitacionActual,&jugador);
                break;

            case 2:
                system("cls");
                printf("nuestro heroe avanza por la derecha");
                Sleep(2300);
                system("cls");
                avanzarDerecha(mapa,jugador.habitacionActual,&jugador);
                system("cls");
                break;
            }
            break;

        //movimiento izquierda derecha
        case 2:
            if(jugador.habitacionActual==4)
            {
                printf("cuando nuestro heroe intenta salir del castillo, se percata de que las puertas estan cerradas\n");
                Sleep(2300);
                system("cls");
            }
            else
            {
                retroceso(&jugador,mapa);
            }
            break;
        case 3:
            mostrarlista(jugador.inventarioheroe);

            break;
        case 4:
            //guarda lista de arboles el estado actual del mapa bajo el nombre del heroe

            break;
        }

    }//fin del bucle

    return 0;
}
*/
