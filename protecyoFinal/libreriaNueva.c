#include "libreriaNueva.h"
void recogerLootCofre(heroe jugador, int *validosArchivoArmas, int *validosArchivoArmaduras)
{
    int var=rand()%2;
    if(var==0)
    {
        FILE *archi=fopen("armas.bin","rb");
        fseek(archi,sizeof(objetoMagico)*(*validosArchivoArmas),1);
        objetoMagico loot;
        fread(&loot,sizeof(objetoMagico),1,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        printf("\nrecoges la nueva arma?");
        char respuesta='n';
        fflush(stdin);
        scanf("%c", &respuesta);
        if(respuesta=='s' || respuesta=='S')
        {
            jugador.danio=loot.mod;
        }
        *validosArchivoArmas=*validosArchivoArmas+1;
        fclose(archi);
    }
    else
    {
        FILE *archi=fopen("armaduras.bin","rb");
        fseek(archi,sizeof(objetoMagico)*(*validosArchivoArmaduras),1);
        objetoMagico loot;
        fread(&loot,sizeof(objetoMagico),1,archi);
        puts(loot.nombre);
        printf("\n");
        puts(loot.prefacio);
        printf("\nrecoges la nueva armadura?");
        char respuesta='n';
        fflush(stdin);
        scanf("%c", &respuesta);
        if(respuesta=='s' || respuesta=='S')
        {
            jugador.armadura=loot.mod;
        }
        *validosArchivoArmaduras=*validosArchivoArmaduras+1;
        fclose(archi);
}
}
