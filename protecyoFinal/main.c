#include "libreriaNueva.h"
void cargaUsuario(heroe *jug);
int main()
{
    printf("Hello World");
    /// inicio del setup

    srand (time(NULL)); ///para dar verdadera randomizacion a los rand
    heroe jugador;
    cargaUsuario(&jugador);
    ///fin del setup
    int fin=0; //0=no se completo mazmorra, 1=se completo mazmorra
    int aux=0;
    int gpsX=0, gpsY=0; //direccion actual en el arbol
    int orientacion; /* para conocer la primera decision de derecha o izquierda,
                        si la primera es izquierda cada siguiente izquierda sumara
                        +1 al gpsY y la derecha sumara +0 al gpsY
                        para comodidad nuestra usaremos 1=derecha*/
    while(fin==0)
    {
        MENU:
        printf("que desea hacer?");
        printf("1: avanzar");
        printf("2: retroceder");
        printf("3: abrir inventario");
        printf("4: guardar y salir");
        scanf("%d", &aux);
        if(aux>4)
        {
            printf("no existe opcion 5, elija de vuelta");
            goto MENU;
        }
        switch(aux)
        {
        case 1:
            //movimiento
            switch(aux)
            {
                printf("desea ir a la izquierda o la derecha?");
                printf("1: izquierda\t2: derecha");
            case 1:
                if(gpsX==0 && gpsY==0)
                {
                    orientacion=0;
                    /*funcion movimiento:
                                         busqueda del arbol mediante gpsx e y;
                                         presentacion y resolucion de habitacion
                                            combate de ser necesario
                                            actualizacion de inventario y pj;
                                         actualizacion con punteros de gps's
                                         en caso de ser derecha==NULL, se presenta menu sala pre boss*/
                }
                else
                {

                }
                break;
            case 2:
                if(gpsX==0 && gpsY==0)
                {
                    orientacion=1;
                }
                else
                {

                }
                break;
            case 3:
                break;
            case 4:
                break;
            }
        }

    }//fin del bucle
    return 0;
}
void combate()
{
    FILE *archi=fopen("mobs.bin","rb");

    int aux=0;
    switch (aux)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}
void cargaUsuario(heroe *jug)
{
    printf("ingrese el nombre de su heroe:\t");
    fflush(stdin);
    gets(jug->nombre);
    jug->armadura=0;
    jug->vidaMax=10;
    jug->danio=0;
    jug->vidaActual=10;
}
/*nodoArbol*cargaMapa()
{

}*/

