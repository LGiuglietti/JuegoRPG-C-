#include "libreriaNueva.h"
void recogerLootCofre(heroe jugador, nododoble*lista)
{
    int cantEspaciosUsados=0;
    nododoble* ultimo=buscarultimo(lista,&cantEspaciosUsados);
    if(cantEspaciosUsados<10)
    {
        printf("encontraste una pocion y un pergamino");
        if(cantEspaciosUsados==9)
        {
            printf("desea tomar la pocion o el pergamino");
            printf("1. pocion\t2. pergamino");
            int decisionCofre=0;
            scanf(&decisionCofre);
            if(decisionCofre==1)
            {
                objeto poti;
                strcpy(poti.nombre,"Curacion");
                poti.modificador=5;
                poti.tipo=1;
                nododoble* nuevo=crearnodo(poti);
                lista=agregarfinal2(lista,nuevo);
            }
            else
            {
                FILE*archi=fopen("pergaminos.bin","rb");
                decisionCofre=rand()%10;
                fseek(archi,sizeof(objeto)*decisionCofre,1);
                objeto pergamino;
                fread(&pergamino,sizeof(objeto),SEEK_CUR,archi);
                nododoble*pergamino=crearnodo(pergamino);
                lista=agregarfinal2(lista,pergamino);

            }
        }
        else
        {
            objeto poti;
            strcpy(poti.nombre,"Curacion");
            poti.modificador=5;
            poti.tipo=1;
            nododoble* nuevo=crearnodo(poti);
            lista=agregarfinal2(lista,nuevo);

            FILE*archi=fopen("pergaminos.bin","rb");
            int decisionCofre=rand()%10;
            fseek(archi,sizeof(objeto)*decisionCofre,1);
            objeto pergamino;
            fread(&pergamino,sizeof(objeto),SEEK_CUR,archi);
            nododoble*pergamino=crearnodo(pergamino);
            lista=agregarfinal2(lista,pergamino);

        }
    }
    int var=rand()%2;
    if(var==0)
    {
        FILE *archi=fopen("armas.bin","rb");
        fseek(archi,sizeof(objeto)*jugador.danio,1);
        objeto loot;
        fread(&loot,sizeof(objeto),SEEK_CUR,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        Sleep(7);
        jugador.danio=loot.modificador;
        fclose(archi);
    }
    else
    {
        FILE *archi=fopen("armaduras.bin","rb");
        fseek(archi,sizeof(objeto)*jugador.armadura,1);
        objeto loot;
        fread(&loot,sizeof(objeto),SEEK_CUR,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        Sleep(7);
        jugador.armadura=loot.modificador;
        fclose(archi);
    }
}
