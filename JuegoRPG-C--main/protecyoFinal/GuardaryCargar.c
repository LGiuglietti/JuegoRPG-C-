#include "GuardaryCargar.h"

void inicarreglopartida(Partida partidas[3])
{
    for(int i=0;i<3;i++)
    {
        partidas[i].partida=i+1;
    }
}

void save(Partida lapartida, int nropartida, nodoArbol* arbol)
{
    char arreglo[3][15]={"Partida1.bin","Partida2.bin","Partida3.bin"};

    FILE* fp=fopen(arreglo[nropartida],"wb");

    persistenciaarbolpartida(lapartida,fp);

    fclose(fp);
}


void persistenciaarbolpartida(Partida lapartida, FILE* fp)///cargaarchivopartida
{

    if(fp!=NULL)
    {

    }
}

void persistenciaHeroeinvenpartida(Partida lapartida,FILE* fp)
{
    if(fp!=NULL)
    {
        fwrite(&lapartida.saveJugador,sizeof(Heroe),1,fp);
        while(lapartida.saveJugador.inventarioheroe!=NULL)
        {
            fwrite(&lapartida.saveJugador.inventarioheroe,sizeof(Objeto),1,fp);
            lapartida.saveJugador.inventarioheroe=lapartida.saveJugador.inventarioheroe->sig;
        }
    }
}
