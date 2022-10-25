#include "libreriaNueva.h"
void recogerLootCofre(heroe jugador)
{
    int var=rand()%2;
    if(var==0)
    {
        FILE *archi=fopen("armas.bin","rb");
        fseek(archi,sizeof(objeto)*jugador.danio,1);
        objeto loot;
        fread(&loot,sizeof(objeto),1,archi);
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
        fread(&loot,sizeof(objeto),1,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        Sleep(7);
        jugador.armadura=loot.modificador;
        fclose(archi);
    }
}
