#include "bot.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "estrutura.h"
#include "logicaProg.h"

LISTA poe_lista (LISTA L, COORDENADA *c, ESTADO *e) {
    if (e->tab[c->linha][c->coluna] == VAZIO) {
        L = insere_cabeca (L, &c);
    }
    return L ;
}

int comprimentoLista (LISTA l){
    int i = 0;
    while (l!=NULL) {
        i++;
        l = l->proximo;
    }
    return i;
}

void jogs (ESTADO *e) {
    if (e->posx != 50) {
        posicao(e);
        e->posx = 50;
    }
    COORDENADA c;
    COORDENADA *c1 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c2 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c3 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c4 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c5 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c6 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c7 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c8 = (COORDENADA *) malloc (sizeof(COORDENADA));
    c = e->ultima_jogada;
    c1->linha = c.linha + 1;
    c1->coluna = c.coluna - 1;
    c2->linha = c.linha + 1;
    c2->coluna = c.coluna;
    c3->linha = c.linha + 1;
    c3->coluna = c.coluna + 1;
    c4->linha = c.linha;
    c4->coluna = c.coluna - 1;
    c5->linha = c.linha;
    c5->coluna = c.coluna + 1;
    c6->linha = c.linha - 1;
    c6->coluna = c.coluna - 1;
    c7->linha = c.linha - 1;
    c7->coluna = c.coluna;
    c8->linha = c.linha - 1;
    c8->coluna = c.coluna + 1;
    COORDENADA *vizinhas[8] = {c1, c2, c3, c4, c5, c6, c7, c8};
    int i = 0;
    LISTA livres = malloc(sizeof(NODO));
    while (i < 8) {
        if (jogada_valida(e, *vizinhas [i]) == 1)
            livres = insere_cabeca(livres, vizinhas[i]) ;
        i++;
    }
    int comprimento_da_lista = comprimentoLista(livres) - 1;
    srandom(time(NULL));
    int x = random() % comprimento_da_lista ;
    i = 0;
    while (i != x) {
        livres = livres->proximo;
        i++;
    }
    COORDENADA *cord = (COORDENADA *) devolve_cabeca(livres);
    jogar(e, *cord);
    free (c1); free (c2) ; free (c3); free (c4) ; free (c5); free (c6) ; free (c7); free (c8);
}
