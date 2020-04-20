#include "bot.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "estrutura.h"
#include "logicaProg.h"

COORDENADA Random () {
    int x,y ;
    srandom(time(NULL));
    COORDENADA c;
    x= (random() % 3) - 1;
    y = (random () % 3) - 1;
    c.coluna = x;
    c.linha = y;
    return c;
}

void jogs (ESTADO *e) {
    if (e -> posx != 50) {
        posicao(e);
        e -> posx = 50;
    }
    //printf ("%d %d\n",e->ultima_jogada.coluna,e->ultima_jogada.linha);
    COORDENADA nova_p, c ;
    c = Random() ;
    //printf ("%d %d\n",c.coluna,c.linha);
    nova_p.coluna = e -> ultima_jogada.coluna + c.coluna;
    nova_p.linha = e -> ultima_jogada.linha + c.linha;
    while (jogada_valida(e, nova_p) != 1|| (nova_p.coluna < 0 || nova_p.coluna >7) || (nova_p.linha < 0 || nova_p.linha > 7) || (c.coluna == 0 && c.linha == 0)) {
        c = Random() ;
        nova_p.coluna = e->ultima_jogada.coluna + c.coluna;
        nova_p.linha = e->ultima_jogada.linha + c.linha;
    }
    jogar (e, nova_p);
}
