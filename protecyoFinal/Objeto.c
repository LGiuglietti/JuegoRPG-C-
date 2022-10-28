#include "Objeto.h"

Objeto crearobjeto()
{
    Objeto acrear;

    int flag=0;
    char nombres[4][10]= {"Pergamino","Pocion","Arma","Armadura"}; ///Solo tiene un fin visual
    while(flag==0)
    {
        printf("Tipos de objetos\n");
        printf("1. Pergamino\n");
        printf("2. Pocion\n");
        printf("3. Arma\n");
        printf("4. Armadura\n");
        printf("Que tipo de objeto creara: ");
        fflush(stdin);
        scanf("%i",&acrear.tipo);

        if((acrear.tipo>0)&&(acrear.tipo<5))
        {
            flag=1;
        }
        else
        {
            printf("Ingrese una opcion valida");
            system("pause");
            system("cls");
        }
    }


    printf("Termine de cargar su %s\n",nombres[acrear.tipo-1]);
    printf("Nombre: ");
    fflush(stdin);
    gets(acrear.nombre);
    printf("Prefacio: ");
    fflush(stdin);
    gets(acrear.prefacio);
    printf("Modificador: ");
    fflush(stdin);
    scanf("%i",&acrear.modificador);

    return acrear;
}

void persistenciaobj(Objeto elobjeto)
{
    switch(elobjeto.tipo)
    {
    case 1:
        persistirpergamino(elobjeto);
        break;
    case 2:
        persistirpocion(elobjeto);
        break;
    case 3:
        persistirarma(elobjeto);
        break;
    case 4:
        persistirarmadura(elobjeto);
        break;
    }
}

void persistirpergamino(Objeto elobjeto)
{
    FILE* fp=fopen(PERGAMINO,"ab");

    if(fp!=NULL)
    {
        fwrite(&elobjeto,sizeof(Objeto),1,fp);
        fclose(fp);
    }
}

void persistirpocion(Objeto elobjeto)
{
    FILE* fp=fopen(POCION,"ab");

    if(fp!=NULL)
    {
        fwrite(&elobjeto,sizeof(Objeto),1,fp);
        fclose(fp);
    }
}

void persistirarma(Objeto elobjeto)
{
    FILE* fp=fopen(ARMA,"ab");

    if(fp!=NULL)
    {
        fwrite(&elobjeto,sizeof(Objeto),1,fp);
        fclose(fp);
    }
}

void persistirarmadura(Objeto elobjeto)
{
    FILE* fp=fopen(ARMADURA,"ab");

    if(fp!=NULL)
    {
        fwrite(&elobjeto,sizeof(Objeto),1,fp);
        fclose(fp);
    }
}

Objeto depersistenciaobjetos(int tipo,int* ultimo)
{
     switch(tipo)
    {
    case 1:
        depersistirpergamino((*ultimo));
        break;
    case 2:
        depersistirpocion((*ultimo));
        break;
    case 3:
        depersistirarma((*ultimo));
        break;
    case 4:
        depersistirarmadura((*ultimo));
        break;
    }
    (*ultimo)++;
}

Objeto depersistirpergamino(int ultimo)
{
    FILE* fp=fopen(PERGAMINO,"rb");
    Objeto elobjeto;

    if(fp!=NULL)
    {
        fseek(fp,ultimo*sizeof(Objeto),SEEK_SET);
        if(!feof(fp))
        {
            fread(&elobjeto,sizeof(Objeto),1,fp);
        }

        fclose(fp);
    }

    return elobjeto;
}

Objeto depersistirpocion(int ultimo)
{
    FILE* fp=fopen(POCION,"rb");
    Objeto elobjeto;

    if(fp!=NULL)
    {
        fseek(fp,ultimo*sizeof(Objeto),SEEK_SET);
        if(!feof(fp))
        {
            fread(&elobjeto,sizeof(Objeto),1,fp);
        }

        fclose(fp);
    }

    return elobjeto;
}

Objeto depersistirarma(int ultimo)
{
    FILE* fp=fopen(ARMA,"rb");
    Objeto elobjeto;

    if(fp!=NULL)
    {
        fseek(fp,ultimo*sizeof(Objeto),SEEK_SET);
        if(!feof(fp))
        {
            fread(&elobjeto,sizeof(Objeto),1,fp);
        }

        fclose(fp);
    }

    return elobjeto;
}

Objeto depersistirarmadura(int ultimo)
{
    FILE* fp=fopen(ARMADURA,"rb");
    Objeto elobjeto;

    if(fp!=NULL)
    {
        fseek(fp,ultimo*sizeof(Objeto),SEEK_SET);
        if(!feof(fp))
        {
            fread(&elobjeto,sizeof(Objeto),1,fp);
        }

        fclose(fp);
    }

    return elobjeto;
}
