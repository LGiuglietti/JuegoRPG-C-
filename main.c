#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <time.h>
#include "Jugador.h"


int main()
{
    /// inicio del setup

    srand(time(NULL)); ///Declara el seed para el rand
    Heroe jugador;
    cargaUsuario(&jugador);
    jugador.inventarioheroe=inicinventario();
    nodoArbol*mapa=inicArbol();
    mapa=cargaMapa(mapa);
    char decisionSalir='n';
    ///fin del setup

    int fin=0; //0=no se completo mazmorra, 1=se completo mazmorra
    int aux=0;
MENU:
    while(fin==0)
    {
        printf("habitacion: %d", jugador.habitacionActual);
        printf("VIDA: %d/%d\n\n\n\n",jugador.vidaActual,jugador.vidaMax);
        printf("\nque desea hacer?\n");
        printf("1: avanzar\t");
        printf("2: retroceder\t");
        printf("3: abrir inventario\t");
        printf("4: salir\t");
        scanf("%d", &aux);
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

            printf("desea ir a la izquierda o la derecha\n");
            printf("1: izquierda\t\t\t2: derecha\n");
            scanf("%d", &aux);
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
            jugador=utilizarObjetoFueraDeCombate(jugador);
            Sleep(2300);
            system("cls");
            break;
        case 4:

            printf("esta seguro que desea salir?\t(s/n)");
            fflush(stdin);
            scanf("%c", &decisionSalir);
            if(decisionSalir=='s')
            {
                exit(1);
            }


            break;
        }

    }//fin del bucle
    return 0;
}



