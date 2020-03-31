#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>


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


int le_ficheiro (ESTADO *e , FILE *f) {
    char linha[BUF_SIZE];
    char *result;
    int i=0, j,n_jogadas;
    while (i<32){
        e->jogadas[i].jogador1.linha = 0;
        e->jogadas[i].jogador1.coluna = 0;
        e->jogadas[i].jogador2.linha = 0;
        e->jogadas[i].jogador2.coluna = 0;
        i++;
    }
    e ->  num_jogadas = 0;
    i = 0;
    while (!feof(f)){
        result = fgets(linha, BUF_SIZE, f);
        if (result) {
            if (i <= 7) {
                for (j = 0; j <= 7; j++) {
                    if (linha[j] == '.') e->tab[7 - i][j] = VAZIO;
                    else if (linha[j] == '*') e->tab[7 - i][j] = BRANCA;
                    else if (linha[j] == '#') e->tab[7 - i][j] = PRETA;
                }
            } else if (i>=9){
                if ((linha[4] >= 'a' && linha[4] <= 'h') && (linha[5]>='1' && linha[5]<='8')) {
                    e->jogador_atual = 2;
                    e->jogadas[i - 9].jogador1.linha = linha[5] - '1';
                    e->jogadas[i - 9].jogador1.coluna = linha[4] - 'a';
                    e -> ultima_jogada.coluna = linha[4] - 'a';
                    e -> ultima_jogada.linha = linha[5] - '1';
                }
                if (linha[6] == ' '){
                    e->jogador_atual = atualizar_jogador_atual(e);
                    e->jogadas[i - 9].jogador2.linha = linha[8] - '1';
                    e->jogadas[i - 9].jogador2.coluna = linha[7] - 'a';
                    e -> num_jogadas++;
                    e -> ultima_jogada.coluna = linha[7] - 'a';
                    e -> ultima_jogada.linha = linha[8] - '1';
                }
            }
        }
        i++;
    }
    return 1;
}

void atualizar_tabuleiro_jogadas (ESTADO *e,int posx) {
    int i=0, linha, coluna;
    for (linha = 0; linha < 8 ; linha ++) {
        for (coluna = 0; coluna < 8; coluna ++) {
                e -> tab [linha] [coluna] = VAZIO;
        }
    }
    while (i < posx) {
        e->tab[e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
        e->tab[e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = PRETA;
        i++;
    }
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = BRANCA;
    if (posx > 0)
        e->tab[4][4] = PRETA;
    e -> tab [0] [0] = UM;
    e -> tab [7] [7] = DOIS;
}

void posicao (ESTADO *e,int posx) {
    if (posx > e->num_jogadas || posx < 0) {
        printf("Posição Inválida");
    } else {
        if (posx == 0) {
            e->ultima_jogada.coluna = 4;
            e->ultima_jogada.linha = 4;
        } else {
            e->ultima_jogada.coluna = e->jogadas[posx - 1].jogador2.coluna;
            e->ultima_jogada.linha = e->jogadas[posx - 1].jogador2.linha;
            e->num_jogadas = posx;
            e->jogador_atual = 1;
        }
        atualizar_tabuleiro_jogadas(e, posx);
        while (posx < 32) {
            e->jogadas[posx].jogador1.linha = 0;
            e->jogadas[posx].jogador1.coluna = 0;
            e->jogadas[posx].jogador2.linha = 0;
            e->jogadas[posx].jogador2.coluna = 0;
            posx++;
        }
    }
}
