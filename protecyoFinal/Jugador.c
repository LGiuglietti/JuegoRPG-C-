#include "Jugador.h"

Heroe crearheroe()
{
    Heroe acrear;

    printf("Ingrese su Nombre jugador: ");
    fflush(stdin);
    gets(acrear.nombre);

    acrear.vidaMax=10;
    acrear.vidaActual=10;
    acrear.atk=2;
    acrear.armadura=3;
    acrear.cantidadCombates=0;
    acrear.habitacionActual=1;
    acrear.inventarioheroe=inicinventario();

    return acrear;
}

