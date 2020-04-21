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

/*LISTA poe_lista2 (LISTA L, COORDENADA c, ESTADO *e) {
    COORDENADA x;
    if (e->tab[c.linha +1 ][c.coluna - 1] == VAZIO) {
        x.coluna = c.coluna - 1;
        x.linha = c.linha +1;
        L = insere_cabeca (L, &x);
    }
    else if (e -> tab [c.linha + 1] [c.coluna]== VAZIO) {
        x.coluna = c.coluna ;
        x.linha = c.linha +1;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha + 1] [c.coluna + 1]== VAZIO) {
        x.coluna = c.coluna + 1 ;
        x.linha = c.linha + 1;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha] [c.coluna + 1]== VAZIO) {
        x.coluna = c.coluna + 1;
        x.linha = c.linha ;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha - 1] [c.coluna + 1]== VAZIO) {
        x.coluna = c.coluna + 1 ;
        x.linha = c.linha - 1;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha - 1] [c.coluna]== VAZIO) {
        x.coluna = c.coluna ;
        x.linha = c.linha - 1;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha - 1] [c.coluna - 1]== VAZIO) {
        x.coluna = c.coluna - 1 ;
        x.linha = c.linha  - 1;
        L = insere_cabeca (L, &x) ;
    }
    else if (e -> tab [c.linha] [c.coluna - 1]== VAZIO) {
        x.coluna = c.coluna - 1;
        x.linha = c.linha ;
        L = insere_cabeca (L, &x) ;
    }
    return L ;
}


LISTA vizinhas (COORDENADA c,ESTADO *e) {
    COORDENADA c1, c2, c3, c4, c5, c6, c7, c8;
    c1.linha = c.linha + 1;
    c1.coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c1);
    c2.linha = c.linha + 1;
    c2.coluna = c.coluna;
    //vizinhas = insere_cabeca(vizinhas,&c2);
    c3.linha = c.linha + 1;
    c3.coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c3);
    c4.linha = c.linha;
    c4.coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c4);
    c5.linha = c.linha;
    c5.coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c5);
    c6.linha = c.linha - 1;
    c6.coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c6);
    c7.linha = c.linha - 1;
    c7.coluna = c.coluna;
    //vizinhas = insere_cabeca(vizinhas,&c7);
    c8.linha = c.linha - 1;
    c8.coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c8);
    //COORDENADA array[8] = {*c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8};
    //vizinhas = fromArray (array,8);
    COORDENADA vizinhas[8] = {c1,c2,c3,c4,c5,c6,c7,c8};
    LISTA livres = malloc (sizeof(NODO));
    int i = 0;
    while (i<8){
        poe_lista(livres,&vizinhas[i],e);
        i++;
    }
    return livres;
}
*/

int comprimentoLista (LISTA l){
    int i = 0;
    while (l!=NULL) {
        i++;
        l = l->proximo;
    }
    printf ("%d",i);
    return i;
}

void jogs (ESTADO *e) {
    if (e->posx != 50) {
        posicao(e);
        e->posx = 50;
    }
    COORDENADA c;
    COORDENADA *c1 = malloc (sizeof(COORDENADA));
    COORDENADA *c2 = malloc (sizeof(COORDENADA));
    COORDENADA *c3 = malloc (sizeof(COORDENADA));
    COORDENADA *c4 = malloc (sizeof(COORDENADA));
    COORDENADA *c5 = malloc (sizeof(COORDENADA));
    COORDENADA *c6 = malloc (sizeof(COORDENADA));
    COORDENADA *c7 = malloc (sizeof(COORDENADA));
    COORDENADA *c8 = malloc (sizeof(COORDENADA));
    c = e->ultima_jogada;
    c1->linha = c.linha + 1;
    c1->coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c1);
    c2->linha = c.linha + 1;
    c2->coluna = c.coluna;
    //vizinhas = insere_cabeca(vizinhas,&c2);
    c3->linha = c.linha + 1;
    c3->coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c3);
    c4->linha = c.linha;
    c4->coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c4);
    c5->linha = c.linha;
    c5->coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c5);
    c6->linha = c.linha - 1;
    c6->coluna = c.coluna - 1;
    //vizinhas = insere_cabeca(vizinhas,&c6);
    c7->linha = c.linha - 1;
    c7->coluna = c.coluna;
    //vizinhas = insere_cabeca(vizinhas,&c7);
    c8->linha = c.linha - 1;
    c8->coluna = c.coluna + 1;
    //vizinhas = insere_cabeca(vizinhas,&c8);
    //COORDENADA array[8] = {*c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8};
    //vizinhas = fromArray (array,8);
    COORDENADA vizinhas[8] = {*c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8};
    LISTA livres = malloc(sizeof(NODO));
    int i = 0;
    while (i < 8) {
        poe_lista(livres, &vizinhas[i], e);
        i++;
    }
    int comprimento_da_lista = comprimentoLista(livres);
    srandom(time(NULL));
    int x = random() % comprimento_da_lista - 1;
    i = 0;
    while (i != x) {
        livres = livres->proximo;
        i++;
    }
    COORDENADA *cord = (COORDENADA *) devolve_cabeca(livres->valor);
    jogar(e, *cord);
}

