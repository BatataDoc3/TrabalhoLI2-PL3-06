#include "bot.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "estrutura.h"
#include "logicaProg.h"
#include <math.h>

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

TREE singular (int linha, int coluna){
    TREE r;
    COORDENADA c;
    c.linha = linha;
    c.coluna = coluna;
    r = malloc (sizeof (struct nodoArv));
    r->valor = c;
    r->CE = r->CC = r->CD = r->DD = r->BD = r->BB = r->BE = r->EE= NULL;
    return r;
}

TREE arvore_1nivel (int linha, int coluna) {
    COORDENADA cord;
    cord.linha = linha;
    cord.coluna = coluna;
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce = singular(cord.linha + 1,cord.coluna - 1);
    TREE cc = singular(cord.linha + 1,cord.coluna);
    TREE cd = singular(cord.linha + 1,cord.coluna + 1);
    TREE dd = singular(cord.linha,cord.coluna + 1);
    TREE bd = singular(cord.linha - 1,cord.coluna + 1);
    TREE bb = singular(cord.linha - 1,cord.coluna);
    TREE be = singular(cord.linha - 1,cord.coluna - 1);
    TREE ee = singular(cord.linha,cord.coluna - 1);
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

TREE arvore_2nivel (int linha, int coluna){
    COORDENADA cord;
    cord.linha = linha;
    cord.coluna = coluna;
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce = arvore_1nivel (cord.linha + 1,cord.coluna - 1);
    TREE cc = arvore_1nivel (cord.linha + 1,cord.coluna);
    TREE cd = arvore_1nivel (cord.linha + 1,cord.coluna + 1);
    TREE dd = arvore_1nivel (cord.linha,cord.coluna + 1);
    TREE bd = arvore_1nivel (cord.linha - 1,cord.coluna + 1);
    TREE bb = arvore_1nivel (cord.linha - 1,cord.coluna);
    TREE be = arvore_1nivel (cord.linha - 1,cord.coluna - 1);
    TREE ee = arvore_1nivel (cord.linha,cord.coluna - 1);
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

TREE arvore_3nivel (COORDENADA cord){
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce = arvore_2nivel (cord.linha + 1,cord.coluna - 1);
    TREE cc = arvore_2nivel (cord.linha + 1,cord.coluna);
    TREE cd = arvore_2nivel (cord.linha + 1,cord.coluna + 1);
    TREE dd = arvore_2nivel (cord.linha,cord.coluna + 1);
    TREE bd = arvore_2nivel (cord.linha - 1,cord.coluna + 1);
    TREE bb = arvore_2nivel (cord.linha - 1,cord.coluna);
    TREE be = arvore_2nivel (cord.linha - 1,cord.coluna - 1);
    TREE ee = arvore_2nivel (cord.linha,cord.coluna - 1);
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

float classificacao (COORDENADA c,ESTADO *e) {
    float clas;
    if (jogada_valida(e,c) == 1){
        if (obter_jogador_atual(e)==1)
            clas = sqrt (pow(c.coluna,2) + pow(c.linha,2));
        else
            clas = sqrt (pow(7 - c.coluna,2) + pow(7-c.linha,2));
    }
    else clas = 1000;
    //printf ("%f\n",clas);
    return clas;
}

COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore){
    COORDENADA c;
    c.linha = 10;
    c.coluna = 10;
    atualizar_casa_preta(e);
    if (jogo_finalizado(e,arvore->BB->valor)==1) c = arvore->BB->valor;
    if (jogo_finalizado(e,arvore->BE->valor)==1) c = arvore->BE->valor;
    if (jogo_finalizado(e,arvore->BD->valor)==1) c = arvore->BD->valor;
    if (jogo_finalizado(e,arvore->EE->valor)==1){
        c = arvore->EE->valor;
    }
    if (jogo_finalizado(e,arvore->DD->valor)==1) c = arvore->DD->valor;
    if (jogo_finalizado(e,arvore->CE->valor)==1) c = arvore->CE->valor;
    if (jogo_finalizado(e,arvore->CC->valor)==1) c = arvore->CC->valor;
    if (jogo_finalizado(e,arvore->CD->valor)==1) c = arvore->CD->valor;
    e -> tab [arvore->valor.linha] [arvore->valor.coluna] = BRANCA;
    return c;
}

float analisa_1nivel (TREE arvore,ESTADO *e){
        float x = classificacao (arvore->CE->valor,e);
        if (classificacao(arvore->BD->valor,e) < x) x = classificacao (arvore->BD->valor,e);
        if (classificacao(arvore->BE->valor,e) < x) x = classificacao (arvore->BE->valor,e);
        if (classificacao(arvore->EE->valor,e) < x) x = classificacao (arvore->EE->valor,e);
        if (classificacao(arvore->DD->valor,e) < x) x = classificacao (arvore->DD->valor,e);
        if (classificacao(arvore->BB->valor,e) < x) x = classificacao (arvore->CE->valor,e);
        if (classificacao(arvore->CC->valor,e) < x) x = classificacao (arvore->CC->valor,e);
        if (classificacao(arvore->CD->valor,e) < x) x = classificacao (arvore->CD->valor,e);
        return x;
}

float analisa_2nivel (TREE arvore,ESTADO *e) { //FIXME  mudar para 2nivel
    float pior = analisa_1nivel(arvore->CE,e);
    if (analisa_1nivel(arvore->CC,e) > pior) {
        pior = analisa_1nivel(arvore->CC,e);
    }
    if (analisa_1nivel(arvore->CD,e) > pior){
        pior = analisa_1nivel(arvore->CD,e);
    }
    if (analisa_1nivel(arvore->EE,e)> pior){
        pior = analisa_1nivel(arvore->EE,e);
    }
    if (analisa_1nivel(arvore->DD,e)> pior) {
        pior = analisa_1nivel(arvore->DD,e);
    }
    if (analisa_1nivel(arvore->BE,e)> pior) {
        pior = analisa_1nivel(arvore->BE,e);
    }
    if (analisa_1nivel(arvore->BB,e)> pior)   {
        pior = analisa_1nivel(arvore->BB,e);
    }
    if (analisa_1nivel(arvore->BD,e)> pior) {
        pior = analisa_1nivel(arvore->BD,e);
    }
    return pior;
}

COORDENADA verifica_melhor_pos (ESTADO *e, TREE arvore){
    float melhor = analisa_2nivel (arvore->CE,e);
    COORDENADA c_melhor;
    if (analisa_2nivel(arvore->CC,e)< melhor &&  classificacao(arvore->CC->valor,e)!= 1000) {
        melhor = analisa_2nivel(arvore->CC,e);
        c_melhor = arvore->CC->valor;
    }
    if (analisa_2nivel(arvore->CD,e)< melhor &&  classificacao(arvore->CD->valor,e)!= 1000){
        melhor = analisa_2nivel(arvore->CD,e);
        c_melhor = arvore->CD->valor;
    }
    if (analisa_2nivel(arvore->EE,e)< melhor && classificacao(arvore->EE->valor,e)!= 1000){
        melhor = analisa_2nivel(arvore->EE,e);
        c_melhor = arvore->EE->valor;
    }
    if (analisa_2nivel(arvore->DD,e)< melhor && classificacao(arvore->DD->valor,e)!= 1000) {
        melhor = analisa_2nivel(arvore->DD,e);
        c_melhor = arvore->DD->valor;
    }
    if (analisa_2nivel(arvore->BE,e)< melhor && classificacao(arvore->BE->valor,e)!= 1000) {
        melhor = analisa_2nivel(arvore->BE,e);
        c_melhor = arvore->BE->valor;
    }
    if (analisa_2nivel(arvore->BB,e)< melhor && classificacao(arvore->BB->valor,e)!= 1000)   {
        melhor = analisa_2nivel(arvore->BB,e);
        c_melhor = arvore->BB->valor;
    }
    if (analisa_2nivel(arvore->BD,e)< melhor && classificacao(arvore->BD->valor,e)!= 1000) {
        melhor = analisa_2nivel(arvore->BD,e);
        c_melhor = arvore->BD->valor;
    }
    printf ("%f",melhor);
    return c_melhor;
}

void jog2 (ESTADO *e){
    TREE arvore;
    arvore = arvore_3nivel(e->ultima_jogada);
    COORDENADA c;
    c = jogo_finalizado_arvore (e,arvore);
    if (c.linha != 10 ){
        jogar (e,c);
    }
    else {
       c = verifica_melhor_pos(e,arvore);
       /*
       printf("\n%d %d\n",arvore->CE->CE->CE->valor.linha,arvore->CE->CE->CE->valor.coluna);
       printf("\n%d %d\n",arvore->CC->valor.linha,arvore->CC->valor.coluna);
        printf("\n%d %d\n",arvore->CD->valor.linha,arvore->CD->valor.coluna);
        printf("\n%d %d\n",arvore->EE->valor.linha,arvore->EE->valor.coluna);
        printf("\n%d %d\n",arvore->DD->valor.linha,arvore->DD->valor.coluna);
        printf("\n%d %d\n",arvore->BE->valor.linha,arvore->BE->valor.coluna); */
       
       jogar (e,c);
       free (arvore);
    }
}

