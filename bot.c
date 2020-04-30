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



int jogada_valida_bot (ESTADO *e ,int linha,int coluna) {
    if (linha < 0 || linha > 7) return (-1);
    if (coluna < 0 || coluna > 7)  return (-1);
    if (devolve_posicao(e,linha,coluna) == '#')
        return (-1);
    else return 1;
}


TREE criar_arvore (ESTADO *e,int linha,int coluna,int profundidade){
    TREE arvore = malloc (sizeof(struct nodoArv));
    if (profundidade == 0) return NULL;
    if (profundidade == 1) arvore->classificacao = classificacao (arvore->valor, e);
    arvore->valor.linha = linha;
    arvore->valor.coluna = coluna;
    profundidade--;
    TREE ce, cc, cd, dd, ee, be, bb, bd;
    if (jogada_valida_bot (e, linha + 1 , coluna - 1) == 1)
        ce = criar_arvore (e, linha + 1 , coluna - 1 , profundidade);
    else
        ce = NULL;
    if (jogada_valida_bot (e, linha + 1 , coluna) == 1)
        cc = criar_arvore (e, linha + 1, coluna, profundidade);
    else
        cc = NULL;
    if (jogada_valida_bot (e, linha + 1 , coluna + 1) == 1)
        cd = criar_arvore (e, linha + 1 , coluna + 1, profundidade);
    else
        cd = NULL;
    if (jogada_valida_bot (e, linha , coluna + 1) == 1)
        dd = criar_arvore (e,  linha, coluna + 1, profundidade);
    else
        dd = NULL;
    if (jogada_valida_bot (e, linha - 1, coluna + 1) == 1)
        bd = criar_arvore (e, linha - 1, coluna + 1, profundidade);
    else
        bd = NULL;
    if (jogada_valida_bot (e, linha - 1, coluna) == 1)
        bb = criar_arvore (e, linha - 1, coluna, profundidade);
    else
        bb = NULL;
    if (jogada_valida_bot (e, linha - 1, coluna - 1) == 1)
        be = criar_arvore (e, linha - 1, coluna - 1, profundidade);
    else
        be = NULL;
    if (jogada_valida_bot (e, linha, coluna - 1) == 1)
        ee = criar_arvore (e, linha, coluna - 1, profundidade);
    else
        ee = NULL;
    arvore->CE = ce;
    arvore->CC = cc;
    arvore->CD = cd;
    arvore->DD = dd;
    arvore->BD = bd;
    arvore->BB = bb;
    arvore->BE = be;
    arvore->EE = ee;
    return arvore;
}

float classificacao (COORDENADA c,ESTADO *e) {
    float clas;
    if (jogada_valida_bot(e,c.linha,c.coluna) == 1){
        if (obter_jogador_atual(e)==1)
            clas = sqrt (pow(c.coluna,2) + pow(c.linha,2));
        else
            clas = sqrt (pow(7 - c.coluna,2) + pow(7-c.linha,2));
    }
    else {
        clas = 1000;
    }
    return clas;
}

COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore){
    COORDENADA c;
    c.linha = 10;
    c.coluna = 10;
    atualizar_casa_preta(e);
    if (arvore -> BB != NULL && jogo_finalizado_bot (e,arvore->BB->valor) == 1) c = arvore->BB->valor;
    if (arvore -> BE != NULL && jogo_finalizado_bot (e,arvore->BE->valor) == 1) c = arvore->BE->valor;
    if (arvore -> BD != NULL && jogo_finalizado_bot (e,arvore->BD->valor) == 1) c = arvore->BD->valor;
    if (arvore -> EE != NULL && jogo_finalizado_bot (e,arvore->EE->valor) == 1) c = arvore->EE->valor;
    if (arvore -> DD != NULL && jogo_finalizado_bot (e,arvore->DD->valor) == 1) c = arvore->DD->valor;
    if (arvore -> CE != NULL && jogo_finalizado_bot (e,arvore->CE->valor) == 1) c = arvore->CE->valor;
    if (arvore -> CC != NULL && jogo_finalizado_bot (e,arvore->CC->valor) == 1) c = arvore->CC->valor;
    if (arvore -> CD != NULL && jogo_finalizado_bot (e,arvore->CD->valor) == 1) c = arvore->CD->valor;
    e -> tab [arvore->valor.linha] [arvore->valor.coluna] = BRANCA;
    return c;
}


float min8 (float a1,float a2,float a3,float a4,float a5,float a6,float a7,float a8){
    float menor = a1;
    if (a2 < menor) menor = a2;
    if (a3 < menor) menor = a3;
    if (a4 < menor) menor = a4;
    if (a5 < menor) menor = a5;
    if (a6 < menor) menor = a6;
    if (a7 < menor) menor = a7;
    if (a8 < menor) menor = a8;
    return menor;
}

float max8 (float a1,float a2,float a3,float a4,float a5,float a6,float a7,float a8){
    float maior = a1;
    if (a2 > maior) maior = a2;
    if (a3 > maior) maior = a3;
    if (a4 > maior) maior = a4;
    if (a5 > maior) maior = a5;
    if (a6 > maior) maior = a6;
    if (a7 > maior) maior = a7;
    if (a8 > maior) maior = a8;
    return maior;
}


float preencher_class (TREE arvore,int profundidade){
    if (profundidade > 0) {
        if (profundidade % 2 != 0)
             arvore->classificacao = max8 (preencher_class (arvore->CE,profundidade-1),preencher_class (arvore->CC,profundidade-1)
                                          ,preencher_class (arvore->CD,profundidade-1),preencher_class (arvore->EE,profundidade-1)
                                          ,preencher_class (arvore->DD,profundidade-1),preencher_class (arvore->BE,profundidade-1)
                                          ,preencher_class (arvore->BB,profundidade-1),preencher_class (arvore->BD,profundidade-1));
         else
            arvore->classificacao = min8 (preencher_class (arvore->CE,profundidade-1),preencher_class (arvore->CC,profundidade-1)
                                         ,preencher_class (arvore->CD,profundidade-1),preencher_class (arvore->EE,profundidade-1)
                                         ,preencher_class (arvore->DD,profundidade-1),preencher_class (arvore->BE,profundidade-1)
                                         ,preencher_class (arvore->BB,profundidade-1),preencher_class (arvore->BD,profundidade-1));
    }
    else
        arvore->classificacao = max8 (arvore->CE->classificacao, arvore->CC->classificacao,arvore->CD->classificacao
                                    ,arvore->EE->classificacao,arvore->DD->classificacao,arvore->BE->classificacao
                                    ,arvore->BB->classificacao,arvore->BD->classificacao);
    return 0;
}

COORDENADA verifica_melhor_pos (TREE arvore){
    COORDENADA c;
    if (arvore->classificacao == arvore->CE->classificacao)  c = arvore->CE->valor;
    if (arvore->classificacao == arvore->CC->classificacao)  c = arvore->CC->valor;
    if (arvore->classificacao == arvore->CD->classificacao)  c = arvore->CD->valor;
    if (arvore->classificacao == arvore->EE->classificacao)  c = arvore->EE->valor;
    if (arvore->classificacao == arvore->DD->classificacao)  c = arvore->DD->valor;
    if (arvore->classificacao == arvore->BE->classificacao)  c = arvore->BE->valor;
    if (arvore->classificacao == arvore->BB->classificacao)  c = arvore->BB->valor;
    if (arvore->classificacao == arvore->BD->classificacao)  c = arvore->BD->valor;
    return c;
}


void free_arvore (TREE arvore,int profundidade) {
    if (profundidade == 0)
        return;
    profundidade--;
    if (arvore -> CE != NULL) free_arvore (arvore -> CE,profundidade);
    if (arvore -> CC != NULL) free_arvore (arvore -> CC,profundidade);
    if (arvore -> CD != NULL) free_arvore (arvore -> CD,profundidade);
    if (arvore -> DD != NULL) free_arvore (arvore -> DD,profundidade);
    if (arvore -> BD != NULL) free_arvore (arvore -> BD,profundidade);
    if (arvore -> BB != NULL) free_arvore (arvore -> BB,profundidade);
    if (arvore -> BE != NULL) free_arvore (arvore -> BE,profundidade);
    if (arvore -> EE != NULL) free_arvore (arvore -> EE,profundidade);
    free (arvore);
}


void jog2 (ESTADO *e) {
    TREE arvore;
    int profundidade = 3;
    arvore = criar_arvore (e, e->ultima_jogada.linha, e->ultima_jogada.coluna, profundidade + 1);
    preencher_class (arvore,profundidade);
    COORDENADA c;
    c = jogo_finalizado_arvore(e, arvore);
    if (c.linha != 10) {
        jogar(e, c);
    } else {
        c = verifica_melhor_pos(e,arvore);
        jogar(e, c);
    }
    free_arvore(arvore,profundidade+1);
}
