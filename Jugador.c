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

Heroe recogerLootCofre(Heroe jugador)
{
    srand(time(NULL));

    printf("En frente de nuestro heroe se encuentra un cofre, con mucho cuidado va a abrirlo y en el. \n");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".\n");

    int cantEspaciosUsados=contarItemsInventario(jugador.inventarioheroe);

    if(cantEspaciosUsados<LIMITE)
    {
        printf("Encuentra una pocion y un pergamino!!");
        Sleep(2300);
        int decisionCofre=3;

        if(cantEspaciosUsados==9)
        {
            printf("Tu inventario tiene espacio solo para un objeto mas!\n");

            printf("desea tomar la pocion o el pergamino?\n");
            printf("1. pocion\t2. pergamino\n");
            fflush(stdin);
            scanf("%i",&decisionCofre);

            jugador=dropsp(jugador,decisionCofre);
        }
        else
        {
            jugador=dropsp(jugador,decisionCofre);
        }
    }

    jugador=armaduraoarma(jugador);

    return jugador;
}

Heroe dropsp(Heroe jugador,int designado)
{
    switch(designado)
    {
    case 1:
        jugador.inventarioheroe=agregarobjeto(jugador.inventarioheroe,dropoti());
        break;
    case 2:
        jugador.inventarioheroe=agregarobjeto(jugador.inventarioheroe,dropperga());
        break;
    case 3:
        jugador.inventarioheroe=agregarobjeto(jugador.inventarioheroe,dropoti());
        jugador.inventarioheroe=agregarobjeto(jugador.inventarioheroe,dropperga());
        break;
    }

    return jugador;
}

Heroe armaduraoarma(Heroe jugador)
{
    int var=rand()%2;

    if(var==0)
    {
        Objeto arma=droparmauarmadura(jugador.atk,3);
        printf("Ataque del arma: %i \n",arma.modificador);
        jugador.atk=arma.modificador;
    }
    else
    {

        Objeto armadura=droparmauarmadura(jugador.armadura,4);
        printf("Defensa de la armadura: %i \n",armadura.modificador);
        jugador.armadura=armadura.modificador;
    }
    Sleep(2300);

    return jugador;
}

int combate(Heroe* jug)
{
    float nivelJugador=jug->cantidadCombates;
    float statsJugador=0;
    statsJugador=((jug->atk+jug->armadura)/2);
    nivelJugador=nivelJugador+statsJugador;
    int nivelJugadorEntero=0;
    nivelJugadorEntero=nivelJugador;
    Mob aux=depersistenciamob(nivelJugadorEntero);
    int seescapo=0;///Si escapa se cambiaria a 1 este valor y si no queda igual
    Heroe heroeaux=(*jug);

    printf("Al entrar a la habitacion, sucecede algo inesperado y se encuentra a %s, %s\n",aux.nombre,aux.prefacio);
    printf("PREPARESE PARA EL COMBATE!!\n");
    system("pause");
    system("cls");

    int variableSwitch=0;

    while(heroeaux.vidaActual!=0 && aux.estado!=0)
    {
        printf("Que desea hacer?");
        printf("1: atacar");
        printf("2: utilizar objeto");
        printf("3: intentar retroceder");
        fflush(stdin);
        scanf("%i",&variableSwitch);

        switch (variableSwitch)
        {
        case 1:
            heroeaux=ataque(heroeaux,&aux);
            break;
        case 2:
            heroeaux=utilizarObjetoEnCombate(heroeaux,&aux);
            break;
        case 3:
            seescapo=intentoescape(seescapo,&aux);
            break;
        }

        system("pause");
        system("cls");
    }

    if(aux.vida<=0)
    {
        heroeaux.cantidadCombates++;
        heroeaux.vidaMax+=2;     //sube su vida en 2
        heroeaux.vidaActual+=2;  //se cura en 2
        //actualizacion de estado de habitacion de 0 a 1 y actualizacion de ubicacion de jugador
    }
    else
    {
        printf("Ha Muerto");
    }

    (*jug)=heroeaux;

    return seescapo;
}

Heroe ataque(Heroe jugador,Mob* elmob)
{
    int variableAtaque=rand()%11+1;
    int danioAtaque=rand()%7+1;;
    Mob aux=(*elmob);

    if(variableAtaque>=10)
    {
        printf("atacas con todas tus fuerzas y impactas contra el %s\n", elmob->nombre);
        danioAtaque+=jugador.atk;
        aux=mobatacado(aux,danioAtaque);
    }
    else if(variableAtaque<=9 && variableAtaque>=7)
    {
        printf("en un cruce de ataques tanto %s como %s reciben danio por igual\n",jugador.nombre,elmob->nombre);
        aux=mobatacado(aux,danioAtaque);
        printf("el %s recibe %d puntos de danio",elmob->nombre,danioAtaque);
        jugador=recibedanio(jugador,aux.danio);
    }
    else
    {
        printf("tu ataque fallo y el %s aprovecha y te ataca",elmob->nombre);
        jugador=recibedanio(jugador,aux.danio);
    }

    (*elmob)=aux;

    return jugador;
}

Heroe recibedanio(Heroe jugador,int danio)
{
    danio-=jugador.armadura;
    jugador.vidaActual-=danio;

    return jugador;
}
Heroe utilizarObjetoFueraDeCombate(Heroe jugador)
{
    verinventario(jugador.inventarioheroe);
    if(jugador.inventarioheroe!=NULL)
    {
        int opusuario;
        fflush(stdin);
        scanf("%i",&opusuario);

        while((opusuario<1)&&(opusuario>contarItemsInventario(jugador.inventarioheroe)))
        {
            system("cls");
            verinventario(jugador.inventarioheroe);
            printf("Reingrese su opcion: ");
            fflush(stdin);
            scanf("%i",&opusuario);
            system("pause");
        }

        Objeto elobjeto=buscarobjeto(jugador.inventarioheroe,opusuario);

        if(elobjeto.tipo!=0)
        {
            jugador.inventarioheroe=usarobjeto(jugador.inventarioheroe,elobjeto);
            efectoObjetoFueraDeCombate(elobjeto,&jugador);
        }
        else
        {
            printf("No hay Objetos");
        }
    }
    return jugador;
}

Heroe utilizarObjetoEnCombate(Heroe jugador,Mob*mob)
{
    printf("En medio del combate, abres tu bolsa con esperanza de encontrar algo que te ayude en este combate");
    verinventario(jugador.inventarioheroe);
    if(jugador.inventarioheroe!=NULL)
    {
        int opusuario;
        fflush(stdin);
        scanf("%i",&opusuario);

        while((opusuario<1)&&(opusuario>contarItemsInventario(jugador.inventarioheroe)))
        {
            system("cls");
            verinventario(jugador.inventarioheroe);
            printf("Reingrese su opcion: ");
            fflush(stdin);
            scanf("%i",&opusuario);
            system("pause");
        }

        Objeto elobjeto=buscarobjeto(jugador.inventarioheroe,opusuario);

        if(elobjeto.tipo!=0)
        {
            jugador.inventarioheroe=usarobjeto(jugador.inventarioheroe,elobjeto);
            efectoObjetoEnCombate(elobjeto,&jugador,mob);
        }
        else
        {
            printf("No hay Objetos");
        }
    }
    return jugador;
}

int intentoescape(int seescapo,Mob* elmob)
{
    seescapo=rand()%2;
    if(seescapo==1)
    {
        //funcion retroceder;
        elmob->vida=0; //para cortar el bucle, la vida del enemigo se resetea en caso de huir
    }
    else
    {
        printf("intentaste escapar pero el %s bloquea la salida",elmob->nombre);
    }

    return seescapo;
}
void efectoObjetoEnCombate(Objeto objetito,Heroe*jug,Mob*mob)
{
    if(objetito.tipo==2) //el item es pocion
    {
        jug->vidaActual=jug->vidaActual+5;
        if(jug->vidaActual>jug->vidaMax)
        {
            jug->vidaActual=jug->vidaMax;
            printf("te curas todos tus puntos de golpe");
        }
        else
        {
            printf("te curas 5 puntos de golpe");
        }
        Sleep(2000);
        system("cls");
    }
    else
    {
        printf("utilizando tu pergamino de %s atacas al %s",objetito.nombre, mob->nombre);
        mob->vida=mob->vida-objetito.modificador;
        Sleep(2300);
        system("cls");
    }
}
void efectoObjetoFueraDeCombate(Objeto objetito,Heroe*jug)
{
    if(objetito.tipo==2) //el item es pocion
    {
        jug->vidaActual=jug->vidaActual+5;
        if(jug->vidaActual>jug->vidaMax)
        {
            jug->vidaActual=jug->vidaMax;
            printf("te curas todos tus puntos de golpe");
        }
        else
        {
            printf("te curas 5 puntos de golpe");
        }
        Sleep(2000);
        system("cls");
    }
    else
    {
        printf("no es momento de usar un pergamino");
    }
}
