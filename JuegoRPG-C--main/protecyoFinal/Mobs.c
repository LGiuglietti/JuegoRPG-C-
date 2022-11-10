#include "Mobs.h"

///Mobs
void crearmob()
{
    Mob nuevomob;

    for(int i=0;i<CANTMOBS;i++)
    {
        printf("Ingrese el nombre del Mob a crear: ");
        fflush(stdin);
        gets(nuevomob.nombre);

        printf("De una breve descripcion de su Mob (Prefacio): ");
        fflush(stdin);
        gets(nuevomob.prefacio);

        printf("Ingrese la defensa del Mob a crear: ");
        fflush(stdin);
        scanf("%i",&nuevomob.defensa);

        printf("Ingrese el danio del Mob a crear: ");
        fflush(stdin);
        scanf("%i",&nuevomob.danio);

        printf("Ingrese la vida del Mob a crear: ");
        fflush(stdin);
        scanf("%i",&nuevomob.vida);

        nuevomob.estado=1;

        persistenciamobs(nuevomob);
    }
}

void persistenciamobs(Mob mob)
{
    FILE* fp=fopen(MOBS,"ab");

    if(fp!=NULL)
    {
        fwrite(&mob,sizeof(Mob),1,fp);

        fclose(fp);
    }
}

Mob depersistenciamob(int ultimo)
{
    Mob nuevo;

    FILE* fp=fopen(MOBS,"rb");

    if(fp!=NULL)
    {
        fseek(fp,ultimo*sizeof(Mob),SEEK_SET);
        fread(&nuevo,sizeof(Mob),1,fp);

        fclose(fp);
    }

    return nuevo;
}

Mob mobatacado(Mob elmob,int danio)
{
    elmob.vida-=danio;

    if(elmob.vida==0)
    {
        elmob.estado=0;
    }

    return elmob;
}

///Boss
