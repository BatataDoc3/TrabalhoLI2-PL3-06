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
            if (linha == 4 && coluna == 4)
                e -> tab [linha] [coluna] = BRANCA;
            else
                e -> tab [linha] [coluna] = VAZIO;
        }
    }
    e -> tab [0] [0] = UM;
    e -> tab [7] [7] = DOIS;
    e -> ultima_jogada.coluna = 4;
    e -> ultima_jogada.linha = 4;
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

void atualizar_jogadas (ESTADO *e, COORDENADA c) {
    if (obter_jogador_atual(e)==1) {
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
    }
    if (obter_jogador_atual(e)==2) {
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
    }
}
