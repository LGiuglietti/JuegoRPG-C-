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
