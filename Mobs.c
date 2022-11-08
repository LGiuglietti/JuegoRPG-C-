#include "Mobs.h"

///Mobs
Mob crearmob(int tipo)
{
    char nombremobs[6][20]={"No Muerto","Boomer","Hunter","A","B","C"};
    char prefacion[6][20]={"El No Muerto","Boomer","E","A","B","C"};
    int daniomobs[6]={1,2,3,4,5,6};
    int defensamobs[6]={0,2,3,4,5,6};
    int vidamobs[6]={1,2,3,4,5,6};

    Mob nuevomob;

    if((tipo>=0)&&(tipo<6))
    {
        nuevomob.defensa=defensamobs[tipo];
        nuevomob.danio=daniomobs[tipo];
        nuevomob.vida=vidamobs[tipo];
        nuevomob.estado=1;
        strcpy(nuevomob.nombre,nombremobs[tipo]);
        strcpy(nuevomob.prefacio,prefacion[tipo]);
    }

    return nuevomob;
}

void persistenciamobs(Mob losmobs[])
{
    FILE* fp=fopen(MOBS,"ab");

    if(fp!=NULL)
    {
        fwrite(losmobs,sizeof(Mob),1,fp);

        fclose(fp);
    }
}

void cargararchimobs()
{
    Mob arreglo[6];

    for(int i=0;i<6;i++)
    {
        arreglo[i]=crearmob(i);
    }
    persistenciamobs(arreglo);
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

///Boss
