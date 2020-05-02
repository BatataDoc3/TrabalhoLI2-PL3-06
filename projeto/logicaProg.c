#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "estrutura.h"
#include "logicaProg.h"
#include "arvores.h"

int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c) {
    if (obter_estado_casa (e, c.linha+1, c.coluna) == '*' ||
       obter_estado_casa (e, c.linha, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha + 1, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna) == '*' ||
       obter_estado_casa (e, c.linha, c.coluna - 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna - 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha + 1, c.coluna - 1) == '*')
        return 1;
    else return 0;
}

int jogada_valida (ESTADO *e , COORDENADA c) {
    if (c.linha < 0 || c.linha > 7) return (-1);
    if (c.coluna < 0 || c.coluna > 7)  return (-1);
    if (jogada_valida_pecaBranca(e, c) == 1) {
        if (obter_estado_casa (e, c.linha,c.coluna) == '#')
            return (-1);
        else return 1;
    }
    else return (-1);
}

int casa_Preta (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (obter_estado_casa (e, linha + 1, coluna)== '#' &&
        obter_estado_casa (e, linha, coluna + 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna) == '#' &&
        obter_estado_casa (e, linha, coluna - 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
        obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
        obter_estado_casa (e, linha + 1, coluna + 1) == '#' )
        return 1;
    else if (linha == 0 && coluna == 0 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (linha == 0 && coluna == 7 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 0 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 7 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#')
        return 1;
    else if (linha == 7 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#')
        return 1;
    else if (linha == 0 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#' &&
            obter_estado_casa (e, linha + 1, coluna + 1) == '#')
        return 1;
    else if (coluna == 0 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna +1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (coluna == 7 &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#')
        return 1;
    else return 0;
}


int rodeado_pretas (ESTADO *e, COORDENADA c){
    int x;
    x = casa_Preta (e,c);
    return x;
}


int jogo_finalizado (ESTADO *e, COORDENADA c) {
    int colunaJog, linhaJog;
    int r = 0;
    colunaJog = c.coluna;
    linhaJog = c.linha;
    if (obter_numero_de_jogadas(e) == 32 || (colunaJog == 0 && linhaJog == 0) ||
        (colunaJog == 7 && linhaJog == 7) || rodeado_pretas(e, c)){
        r = 1;
    }
    return r;
}

int parabens_jogador (ESTADO *e){
    int x=0;
    if (obter_estado_casa (e, 7, 7) == '*') x = 2;
    else if (obter_estado_casa(e, 0, 0) == '*') x = 1;
    else {
        if (obter_jogador_atual(e) == 1) x = 2;
        else if (obter_jogador_atual(e) == 2) x = 1;}
    return x;
}


int jogo_finalizado_bot (ESTADO *e, COORDENADA c) {
    int r = 0;
    if (obter_jogador_atual (e) == 1) {
         if (obter_numero_de_jogadas (e) == 32 || (c.coluna == 0 && c.linha == 0) ||rodeado_pretas(e, c))
             r = 1;
    }
    else if (obter_numero_de_jogadas (e) == 32 || (c.coluna == 7 && c.linha == 7) ||rodeado_pretas(e, c))
             r = 1;
    return r;
}

int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogada_valida (e, c) == 1) {
        printf("jogar %d %d\n", c.coluna, c.linha);
        if (devolve_posx(e) != 50) {
            posicao(e);
            atualiza_posx(e,50);
        }
        atualizar_casa_preta (e);
        atualizar_casa (e, c);
        atualizar_jogadas (e, c);
        atualizar_num_jogadas (e);
        atualizar_jogador_atual (e);
        if (jogo_finalizado (e, c) == 1){
            x = parabens_jogador (e);
            printf("Jogo Finalizado! Parabéns Jogador %d\n", x);
            atualiza_num_jogadas_fim (e);
            return 0;
        }
        return 1;
    }
    else {
        printf ("Jogada inválida\n");
        return 0;
    }
}

void jogs (ESTADO *e) {
    if (devolve_posx(e) != 50) {
        posicao(e);
        atualiza_posx(e,50);
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
    c = e -> ultima_jogada;
    c1 -> linha = c.linha + 1;
    c1 -> coluna = c.coluna - 1;
    c2 -> linha = c.linha + 1;
    c2 -> coluna = c.coluna;
    c3 -> linha = c.linha + 1;
    c3 -> coluna = c.coluna + 1;
    c4 -> linha = c.linha;
    c4 -> coluna = c.coluna - 1;
    c5 -> linha = c.linha;
    c5 -> coluna = c.coluna + 1;
    c6 -> linha = c.linha - 1;
    c6 -> coluna = c.coluna - 1;
    c7 -> linha = c.linha - 1;
    c7 -> coluna = c.coluna;
    c8 -> linha = c.linha - 1;
    c8 -> coluna = c.coluna + 1;
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
        livres = livres -> proximo;
        i++;
    }
    COORDENADA *cord = (COORDENADA *) devolve_cabeca(livres);
    jogar(e, *cord);
    free (c1); free (c2) ; free (c3); free (c4) ; free (c5); free (c6) ; free (c7); free (c8);
}

int jogada_valida_bot (ESTADO *e ,int linha,int coluna) {
    if (linha < 0 || linha > 7) return (-1);
    if (coluna < 0 || coluna > 7)  return (-1);
    if (obter_estado_casa(e,linha,coluna) == '#')
        return (-1);
    else return 1;
}

float classificacao (COORDENADA c,ESTADO *e) {
    CLASSIFICACAO *f = (CLASSIFICACAO *) calloc(1,sizeof(CLASSIFICACAO));
    *f = (CLASSIFICACAO){.clas1 = {{7,6,5,4,3,2,1,0},
                                   {6,5,4,3,2,1,0,-1},
                                   {5,4,3,2,1,0,-1,-2},
                                   {4,3,2,1,0,-1,-2,-3},
                                   {3,2,1,0,-1,-2,-3,-4},
                                   {2,1,0,-1,-2,-3,-4,-5},
                                   {1,0,-1,-2,-3,-4,-5,-6},
                                   {0,-1,-2,-3,-4,-5,-6,-1000}}};
    if (obter_jogador_atual(e)==1)
        return f->clas1 [c.linha] [c.coluna];
    else
        return (- (f->clas1 [c.linha] [c.coluna]));
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

COORDENADA verifica_melhor_pos (TREE arvore){
    COORDENADA c;
    c.linha = 50;
    c.coluna = 50;
    if (arvore -> CE != NULL)
        if (arvore->classificacao == arvore->CE->classificacao)  c = arvore->CE->valor;
    if (arvore -> CC != NULL)
        if (arvore->classificacao == arvore->CC->classificacao)  c = arvore->CC->valor;
    if (arvore -> CD != NULL)
        if (arvore->classificacao == arvore->CD->classificacao)  c = arvore->CD->valor;
    if (arvore -> EE != NULL)
        if (arvore->classificacao == arvore->EE->classificacao)  c = arvore->EE->valor;
    if (arvore -> DD != NULL)
        if (arvore->classificacao == arvore->DD->classificacao)  c = arvore->DD->valor;
    if (arvore -> BE != NULL)
        if (arvore->classificacao == arvore->BE->classificacao)  c = arvore->BE->valor;
    if (arvore -> BB != NULL)
        if (arvore->classificacao == arvore->BB->classificacao)  c = arvore->BB->valor;
    if (arvore -> BD != NULL)
        if (arvore->classificacao == arvore->BD->classificacao)  c = arvore->BD->valor;
    return c;
}


void jog2 (ESTADO *e) {
    if (devolve_posx(e) != 50) {
        posicao(e);
        atualiza_posx(e,50);
    }
    TREE arvore;
    int profundidade = 1;
    arvore = criar_arvore (e, e->ultima_jogada.linha, e->ultima_jogada.coluna, profundidade + 1);
    preencher_class (arvore,profundidade);
    COORDENADA c;
    c = jogo_finalizado_arvore(e, arvore);
    if (c.linha != 10) {
        jogar(e, c);
    } else {
        c = verifica_melhor_pos(arvore);
        jogar(e, c);
    }
    free_arvore(arvore,profundidade+1);
}
