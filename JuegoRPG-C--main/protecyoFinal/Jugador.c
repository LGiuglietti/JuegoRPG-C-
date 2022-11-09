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
    Sleep(3);
    printf(".");
    Sleep(3);
    printf(".");
    Sleep(3);
    printf(".\n");
    Sleep(3);

    int cantEspaciosUsados=contarItemsInventario(jugador.inventarioheroe);

    if(cantEspaciosUsados<LIMITE)
    {
        printf("Encuentra una pocion y un pergamino!!");
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
        Objeto arma=depersistirarma(jugador.atk);
        printf("Encontraste %s \n",arma.nombre);
        printf("%s \n",arma.prefacio);
        printf("Ataque del arma: %i \n",arma.modificador);
        Sleep(15);
        system("cls");

        jugador.atk=arma.modificador;
    }
    else
    {
        Objeto armadura=depersistirarmadura(jugador.armadura);
        printf("Encontraste %s \n",armadura.nombre);
        printf("%s \n",armadura.prefacio);
        printf("Defensa de la armadura: %i \n",armadura.modificador);
        Sleep(15);
        system("cls");

        jugador.armadura=armadura.modificador;
    }

    return jugador;
}

int combate(Heroe* jug)
{
    Mob aux=depersistenciamob(jug->cantidadCombates);
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
            heroeaux=utilizarobjeto(heroeaux);
            break;
        case 3:
            seescapo=intentoescape(seescapo,&aux);
            break;
        }

        system("pause");
        system("cls");
    }

    if(aux.vida<0)
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

Heroe utilizarobjeto(Heroe jugador)
{
    printf("En medio del combate, abres tu bolsa con esperanza de encontrar algo que te ayude en este combate");
    printf("Que desea utilizar");
    verinventario(jugador.inventarioheroe);

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
        usarobjeto(jugador.inventarioheroe,elobjeto);
    }
    else
    {
        printf("No hay Objetos");
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
