#include "libreriaNueva.h"
#include "Jugador.h"
#include "objeto.h"

nododoble* recogerLootCofre(Heroe*jugador, nododoble*lista)
{
    printf("en frente de nuestro heroe se encuentra un cofre, con mucho cuidado va a abrirlo y en el");
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
        printf("encuentra una pocion y un pergamino!!");
        if(cantEspaciosUsados==9)
        {
            printf("tu inventario tiene espacio solo para un objeto mas!\n");

            int decisionCofre=0;
            printf("desea tomar la pocion o el pergamino?\n");
            printf("1. pocion\t2. pergamino\n");
            fflush(stdin);
            scanf("%i",&decisionCofre);
            if(decisionCofre==1)
            {
                Objeto poti;
                strcpy(poti.nombre,"Curacion");
                poti.modificador=5;
                poti.tipo=1;
                nododoble*aux=crearnodo(poti);
                lista=agregarfinal2(lista, aux);
            }
            else
            {
                FILE*archi=fopen("pergaminos.bin","rb");
                if(archi!=NULL)
                {
                    decisionCofre=rand()%10;
                    fseek(archi,sizeof(Objeto)*decisionCofre,1);
                    Objeto pergamino;
                    fread(&pergamino,sizeof(Objeto),SEEK_CUR,archi);
                    nododoble*aux=crearnodo(pergamino);
                    lista=agregarfinal2(lista,aux);
                }
            }
        }
        else
        {
            Objeto poti;
            strcpy(poti.nombre,"Curacion");
            poti.modificador=5;
            poti.tipo=1;
            nododoble*aux=crearnodo(poti);
            lista=agregarfinal2(lista, aux);

            FILE*archi=fopen("pergaminos.bin","rb");
            int decisionCofre=rand()%10;
            fseek(archi,sizeof(Objeto)*decisionCofre,1);
            Objeto pergamino;
            fread(&pergamino,sizeof(Objeto),SEEK_CUR,archi);
            aux=crearnodo(pergamino);
            lista=agregarfinal2(lista, aux);;
        }
    }
    int var=rand()%2;
    if(var==0)
    {
        FILE *archi=fopen("armas.bin","rb");
        fseek(archi,sizeof(Objeto)*(jugador->atk),1);
        Objeto loot;
        fread(&loot,sizeof(Objeto),SEEK_CUR,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        Sleep(15);
        system("cls");
        jugador->atk=loot.modificador;
        fclose(archi);
    }
    else
    {
        FILE *archi=fopen("armaduras.bin","rb");
        fseek(archi,sizeof(Objeto)*(jugador->armadura),1);
        Objeto loot;
        fread(&loot,sizeof(Objeto),SEEK_CUR,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        Sleep(15);
        system("cls");
        jugador->armadura=loot.modificador;
        fclose(archi);
    }
    return lista;
}
