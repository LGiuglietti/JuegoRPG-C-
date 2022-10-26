#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct jugador
{
    char nombre[50];
    int vidamax = 10;///Vida max que pude llegar a tener el pj
    int vida=10;///Vida actual del pj
    int armadura=0;///Armor del pj
    int atk=2;///Ataque del personaje
}jugador;

jugador ingresesunombre(jugador jogo);
jugador cambiodevida(jugador jogo,int tipodecambio); ///tipo de cambio existe como constante para observar si se suma o resta algun valor
jugador cambiodearmadura(jugador jogo,int mod);
jugador cambiodeatk(jugador jogo,int mod);

#endif // JOGADOR_H_INCLUDED
