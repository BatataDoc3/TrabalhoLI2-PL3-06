#include "estrutura.h"
#include <stdlib.h>


CASA obter_estado_casa (ESTADO *e, int coluna, int linha){
    CASA casa;
    casa = e -> tab [linha] [coluna] ;
    return casa;
}

int obter_numero_de_jogadas (ESTADO *e) {
    int num_jogadas;
    num_jogadas = e -> num_jogadas;
    return num_jogadas ;
}


int obter_jogador_atual (ESTADO *e) {
    int jogadorAtual;
    jogadorAtual = e -> jogador_atual;
    return jogadorAtual;
}

int atualizar_jogador_atual (ESTADO *e) {
    int jogador;
    if (obter_jogador_atual(e) == 1)  jogador = 2;
    else jogador = 1;
    return jogador;
}

int atualizar_num_jogadas (ESTADO *e) {
    int num = obter_numero_de_jogadas (e);
    if (obter_jogador_atual(e) == 2) num++;
    return num;
}


ESTADO *inicializar_estado() {
    int linha, coluna;
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for (linha = 0; linha < 8 ; linha ++) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (linha == 3 && coluna == 4)
                e -> tab [linha] [coluna] = BRANCA;
            else
                e -> tab [linha] [coluna] = VAZIO;
        }
    }
    e -> tab [7] [7] = UM;
    e -> tab [0] [0] = DOIS;
    e -> ultima_jogada.coluna = 4;
    e -> ultima_jogada.linha = 3;
    return e ;
}

CASA atualizar_casa (ESTADO *e, COORDENADA c) {
    CASA casa;
    casa = e -> tab [c.linha] [c.coluna] = BRANCA;
    return casa;
}

void atualizar_casa_preta (ESTADO *e) {
    int linha, coluna;
    for (linha = 7; linha >= 0; linha --) {
        for (coluna = 0; coluna <=7 ; coluna ++) {
            if (e -> tab [linha] [coluna] == BRANCA) e -> tab [linha] [coluna] = PRETA;
        }
    }
}



int casa_Preta (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (e -> tab [linha + 1] [coluna] == '#' &&
        e -> tab [linha] [coluna + 1] == '#' &&
        e -> tab [linha - 1] [coluna] == '#' &&
        e -> tab [linha] [coluna - 1] == '#' &&
        e -> tab [linha - 1] [coluna - 1] == '#' &&
        e -> tab [linha - 1] [coluna + 1] == '#' &&
        e -> tab [linha + 1] [coluna - 1] == '#' &&
        e -> tab [linha + 1] [coluna + 1] == '#' )
        return 1;
    else if (linha == 0 && coluna == 0 &&
             e -> tab [linha + 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna + 1] == '#' &&
             e -> tab [linha] [coluna + 1] == '#')
        return 1;
    else if (linha == 0 && coluna == 7 &&
             e -> tab [linha + 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna - 1] == '#')
        return 1;
    else if (linha == 7 && coluna == 0 &&
             e -> tab [linha - 1] [coluna] == '#' &&
             e -> tab [linha - 1] [coluna + 1] == '#' &&
             e -> tab [linha] [coluna + 1] == '#')
        return 1;
    else if (linha == 7 && coluna == 7 &&
             e -> tab [linha - 1] [coluna] == '#' &&
             e -> tab [linha - 1] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna - 1] == '#')
        return 1;
    else if (linha == 7 &&
             e -> tab [linha - 1] [coluna] == '#' &&
             e -> tab [linha - 1] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna + 1] == '#' &&
             e -> tab [linha - 1] [coluna + 1] == '#')
        return 1;
    else if (linha == 0 &&
             e -> tab [linha + 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna - 1] == '#' &&
             e -> tab [linha] [coluna + 1] == '#' &&
             e -> tab [linha + 1] [coluna + 1] == '#')
        return 1;
    else if (coluna == 0 &&
             e -> tab [linha - 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna +1] == '#' &&
             e -> tab [linha - 1] [coluna + 1] == '#' &&
             e -> tab [linha] [coluna + 1] == '#')
        return 1;
    else if (coluna == 7 &&
             e -> tab [linha] [coluna - 1] == '#' &&
             e -> tab [linha - 1] [coluna] == '#' &&
             e -> tab [linha + 1] [coluna] == '#' &&
             e -> tab [linha - 1] [coluna - 1] == '#' &&
             e -> tab [linha + 1] [coluna - 1] == '#')
        return 1;
    else return 0;
}


int rodeado_pretas (ESTADO *e, COORDENADA c){
    int x;
    x = casa_Preta(e,c);
    return x;
}


int jogo_finalizado (ESTADO *e, COORDENADA c) {
    int colunaJog, linhaJog;
    int r = 0;
    colunaJog = c.coluna;
    linhaJog = c.linha;
    if (obter_numero_de_jogadas(e) == 64 || (colunaJog == 0 && linhaJog == 0) ||
        (colunaJog == 7 && linhaJog == 7) || rodeado_pretas(e, c)){
        r = 1;
    }
    return r;
}


int parabens_jogador (ESTADO *e){
    int x;
    x = e -> jogador_atual;
    return x;
}
