#include "Jogador.h"
jugador ingresesunombre(jugador jogo)
{
    printf("Ingrese su nombre de jugador: ");
    gets(jogo.nombre);

    return jogo;
}

jugador cambiodevida(jugador jogo,int tipocambio)
{
    return jogo;
}

jugador cambiodearmadura(juagador jogo,int mod)
{
    jogo.armadura=mod;

    return jogo;
}

jugador cambiodeatk(juagador jogo,int mod)
{
    jogo.atk=mod;

    return jogo;
}
