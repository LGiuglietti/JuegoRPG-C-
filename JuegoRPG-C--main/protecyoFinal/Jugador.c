#include "Jugador.h"
#include "libreriaNueva.h"
void cargaUsuario(Heroe *jug)
{
    printf("ingrese el nombre de su heroe:\t");
    fflush(stdin);
    gets(jug->nombre);
    jug->armadura=0;
    jug->vidaMax=10;
    jug->atk=0;
    jug->vidaActual=10;
    jug->habitacionActual=4;
}
void combate(Heroe*jug)
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
                danioAtaque+=jug->atk;
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
