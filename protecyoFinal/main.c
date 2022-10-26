#include "libreriaNueva.h"
#include "arbol.h"
void cargaUsuario(heroe *jug);
nodoArbol*cargaMapa(nodoArbol*arbol);
int main()
{
    /// inicio del setup

    srand (time(NULL)); ///para dar verdadera randomizacion a los rand
    heroe jugador;
    cargaUsuario(&jugador);
    nodoArbol*mapa=inicArbol();
    mapa=cargaMapa(mapa);

    ///fin del setup

    int fin=0; //0=no se completo mazmorra, 1=se completo mazmorra
    int aux=0;
MENU:
    while(fin==0)
    {
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
            //movimiento izquierda derecha
            switch(aux)
            {
                printf("desea ir a la izquierda o la derecha?");
                printf("1: izquierda\t2: derecha");
            case 1:
                    /*busqueda en el arbol de ubicacion actual
                    avanzamos una habitacion por la izquierda
                    chequeamos estado de la habitacion para ver si ya se completo el encuentro respectivo o si es boss
                    y llamamos o a combate o a cofre dependiendo del encuentro*/
                break;
            case 2:
                    /*busqueda en el arbol de ubicacion actual
                    avanzamos una habitacion por la derecha
                    chequeamos estado de la habitacion para ver si ya se completo el encuentro respectivo o si es boss
                    y llamamos o a combate o a cofre dependiendo del encuentro*/

                break;

            }
        //movimiento izquierda derecha
        case 2:
            if(jugador.habitacionActual==4)
            {
                printf("cuando nuestro heroe intenta salir del castillo, se percata de que las puertas estan cerradas");
                printf("prueba rama");
            }
            else
            {
                //movimientoRetroceso
            }
            break;
        case 3:


            break;
        case 4:
            //guarda lista de arboles el estado actual del mapa bajo el nombre del heroe

            break;
        }

    }//fin del bucle
    return 0;
}
void combate(heroe*jug)
{
    FILE *archi=fopen("mobs.bin","rb");
    mob aux;
    fread(&aux,sizeof(mob),1,archi);
    fclose(archi);
    puts(aux.prefacio);
    int variableSwitch=0, variableAtaque, danioAtaque, intentoEscape;
    while(jug->vidaActual!=0 && aux.vida!=0)
    {
        switch (variableSwitch)
        {
            printf("que desea hacer?");
            printf("1: atacar");
            printf("2: inventario");
            printf("2: intentar retroceder");
        case 1:
            variableAtaque=rand()%11+1;
            if(variableAtaque>9)
            {
                printf("atacas con todas tus fuerzas y impactas contra el %s\n", aux.nombre);
                danioAtaque=rand()%7+1;
                danioAtaque+=jug->danio;
                aux.vida-=danioAtaque;
            }
            else if(variableAtaque<10 && variableAtaque>6)
            {
                printf("en un cruce de ataques tanto %s como %s reciben danio\n",jug->nombre,aux.nombre);
                danioAtaque=rand()%7+1;
                aux.vida-=danioAtaque;
                printf("el %s recibe %d puntos de danio",aux.nombre,danioAtaque);
                danioAtaque=aux.danio;
                danioAtaque-=jug->armadura;
                jug->vidaActual-=danioAtaque;

            }
            else
            {
                printf("tu ataque fallo y el %s aprovecha y te ataca",aux.nombre);
                jug->vidaActual-=aux.danio;
            }
            break;
        case 2:
            break;
        case 3:
            intentoEscape=rand()%2+1;
            if(intentoEscape==1){
            //funcion retroceder;
            aux.vida=0; //para cortar el bucle, la vida del enemigo se resetea en caso de huir
            }
            else
            {
                printf("intentaste escapar pero el %s bloquea la salida",aux.nombre);
            }
            break;
        }
    }
    if(aux.vida<=0)
    {
        jug->cantidadCombates++;
        jug->vidaMax+=2;     //sube su vida en 2
        jug->vidaActual+=2;  //se cura en 2
        //actualizacion de estado de habitacion de 0 a 1 y actualizacion de ubicacion de jugador
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
    jug->habitacionActual=4;
}
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

