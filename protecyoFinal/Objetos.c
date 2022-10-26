#include "Objetos.h"

Objeto cargaobjeto()
{
    Objeto aux;

    printf("Nombre del Objeto");
    gets(aux.prefacio);

    printf("Modificador del Objeto");
    fflush(stdin);
    scanf("%i",&aux.mod);

    printf("Tipo de objeto");
    fflush(stdin);
    scanf("%i",&aux.tipo);

    return aux;
}

void cargaarchivoobjeto(Objeto elobjeto)
{
    FILE* fp=fopen(OBJETO,"ab");

    if(fp!=NULL)
    {
        fwrite(&elobjeto,sizeof(Objeto),1,fp);
    }
}
