#include "Jugador.h"


void cargaUsuario(Heroe* jug)
{
    printf("Ingrese el nombre de su heroe: ");
    fflush(stdin);
    gets(jug->nombre);
    jug->armadura=0;
    jug->vidaMax=10;
    jug->atk=0;
    jug->vidaActual=10;
    jug->habitacionActual=4;
}

void combate(Heroe* jug)
{
    FILE *archi=fopen("mobs.bin","rb");
    Mob aux;
    fread(&aux,sizeof(Mob),1,archi);
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
            if(intentoEscape==1)
            {
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

nododoble* recogerLootCofre(Heroe* jugador, nododoble* lista)
{
    srand(time(NULL));

    printf("En frente de nuestro heroe se encuentra un cofre, con mucho cuidado va a abrirlo y en el. \n");
    Sleep(3);
    printf(".");
    Sleep(3);
    printf(".");
    Sleep(3);
    printf(".\n");
    Sleep(3);

    int cantEspaciosUsados=contarItemsInventario(lista);

    if(cantEspaciosUsados<10)
    {
        printf("Encuentra una pocion y un pergamino!!");

        if(cantEspaciosUsados==9)
        {
            printf("Tu inventario tiene espacio solo para un objeto mas!\n");

            int decisionCofre=0;
            printf("desea tomar la pocion o el pergamino?\n");
            printf("1. pocion\t2. pergamino\n");
            fflush(stdin);
            scanf("%i",&decisionCofre);

            if(decisionCofre==1)
            {
                Objeto poti=dropoti();
                nododoble* aux=crearnodo(poti);
                lista=agregarfinal2(lista,aux);
            }
            else
            {
                int aleer=rand()%10;///Da el numero que llegara por parametro para el fseek
                Objeto pergamino=pergamino=depersistirpergamino(aleer);
                nododoble* aux=crearnodo(pergamino);
                lista=agregarfinal2(lista,aux);

            }
        }
        else
        {
            Objeto poti=dropoti();
            nododoble* aux=crearnodo(poti);
            lista=agregarfinal2(lista,aux);

            int aleer=rand()%10;
            Objeto pergamino=depersistirpergamino(aleer);
            aux=crearnodo(pergamino);
            lista=agregarfinal2(lista,aux);
        }
    }

    int var=rand()%2;
    if(var==0)
    {
        Objeto arma=depersistirarma(jugador->atk);
        printf("Encontraste %s \n",arma.nombre);
        printf("%s \n",arma.prefacio);
        printf("Ataque del arma: %i \n",arma.modificador);
        Sleep(15);
        system("cls");

        jugador->atk=arma.modificador;
    }
    else
    {
        Objeto armadura=depersistirarmadura(jugador->armadura);
        printf("Encontraste %s \n",armadura.nombre);
        printf("%s \n",armadura.prefacio);
        printf("Defensa de la armadura: %i \n",armadura.modificador);
        Sleep(15);
        system("cls");

        jugador->armadura=armadura.modificador;
    }

    return lista;
}
