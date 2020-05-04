/**
 * @file estrutura.c
 * \brief conjunto de funções que alteram o estado
 */

#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>


CASA obter_estado_casa (ESTADO *e, int linha, int coluna){
    return e -> tab [linha] [coluna];
}

int obter_numero_de_jogadas (ESTADO *e) {
    return e -> num_jogadas;
}


int obter_jogador_atual (ESTADO *e) {
    return e -> jogador_atual;
}

void atualizar_jogador_atual (ESTADO *e) {
    int jogador;
    if (obter_jogador_atual(e) == 1)  jogador = 2;
    else jogador = 1;
    e -> jogador_atual = jogador;
}

void atualizar_num_jogadas (ESTADO *e) {
    int num = obter_numero_de_jogadas (e);
    if (obter_jogador_atual(e) == 2) num++;
    e -> num_jogadas = num;
}

ESTADO *inicializar_estado() {
    int linha, coluna;
    ESTADO *e = (ESTADO *) calloc(1,sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
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
    e -> posx = 50;
    int i = 0;
    while (i < 32){
        e -> jogadas[i].jogador1.linha = -1;
        e -> jogadas[i].jogador1.coluna = -1;
        e -> jogadas[i].jogador2.linha = -1;
        e -> jogadas[i].jogador2.coluna = -1;
        i++;
    }
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
    if (obter_jogador_atual(e) == 1) {
        e -> jogadas [obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
        e -> jogadas [obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
    }
    if (obter_jogador_atual(e)==2) {
        e -> jogadas [obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;
        e -> jogadas [obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
    }
    e -> ultima_jogada = c;
}


void le_ficheiro (ESTADO *e , FILE *f) {
    char linha[BUF_SIZE];
    char *result;
    int i = 0, j;
    while (i < 32){
        e -> jogadas[i].jogador1.linha = -1;
        e -> jogadas[i].jogador1.coluna = -1;
        e -> jogadas[i].jogador2.linha = -1;
        e -> jogadas[i].jogador2.coluna = -1;
        i++;
    }
    e ->  num_jogadas = 0;
    i = 0;
    while (!feof(f)){
        result = fgets(linha, BUF_SIZE, f);
        if (result) {
            if (i <= 7) {
                for (j = 0; j <= 7; j++) {
                    if (linha[j] == '.') e -> tab[7 - i][j] = VAZIO;
                    else if (linha[j] == '*') e -> tab[7 - i][j] = BRANCA;
                    else if (linha[j] == '#') e -> tab[7 - i][j] = PRETA;
                }
            } else if (i>=9){
                if ((linha[4] >= 'a' && linha[4] <= 'h') && (linha[5]>='1' && linha[5]<='8')) {
                    e -> jogador_atual = 2;
                    e -> jogadas[i - 9].jogador1.linha = linha[5] - '1';
                    e -> jogadas[i - 9].jogador1.coluna = linha[4] - 'a';
                    e -> ultima_jogada.coluna = linha[4] - 'a';
                    e -> ultima_jogada.linha = linha[5] - '1';
                }
                if (linha[6] == ' '){
                    atualizar_jogador_atual(e);
                    e -> jogadas[i - 9].jogador2.linha = linha[8] - '1';
                    e -> jogadas[i - 9].jogador2.coluna = linha[7] - 'a';
                    e -> num_jogadas++;
                    e -> ultima_jogada.coluna = linha[7] - 'a';
                    e -> ultima_jogada.linha = linha[8] - '1';
                }
            }
        }
        i++;
    }
}

void atualizar_tabuleiro_jogadas (ESTADO *e) {
    int posx = e -> posx;
    if (posx > e -> num_jogadas  || posx < 0) {
        printf("Posição Inválida \n");
    }
    else {
        int i = 0, linha, coluna;
        for (linha = 0; linha < 8; linha++) {
            for (coluna = 0; coluna < 8; coluna++) {
                e -> tab [linha] [coluna] = VAZIO;
            }
        }
        while (i < posx) {
            e -> tab [e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
            e -> tab [e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = PRETA;
            i++;
        }
        if (posx != 0)
                e -> tab [e->jogadas[posx - 1].jogador2.linha] [e->jogadas[posx - 1].jogador2.coluna] = BRANCA;
        else e -> tab[4] [4] = BRANCA;
        if (posx > 0)
            e -> tab [4] [4] = PRETA;
        e -> tab [0] [0] = UM;
        e -> tab [7] [7] = DOIS;
    }
}

void posicao (ESTADO *e) {
    int posx = e -> posx ;
    if (posx > e -> num_jogadas || posx < 0) {
        printf("Posição Inválida \n");
    } else {
        e -> num_jogadas = posx ;
        e -> jogador_atual = 1;
        if (posx == 0) {
            e -> ultima_jogada.coluna = 4;
            e -> ultima_jogada.linha = 4;
        } else {
            e -> ultima_jogada = e -> jogadas[posx - 1].jogador2;
        }
        atualizar_tabuleiro_jogadas(e);
        while (posx < 32) {
            e -> jogadas [posx].jogador1.linha = -1;
            e -> jogadas [posx].jogador1.coluna = -1;
            e -> jogadas [posx].jogador2.linha = -1;
            e -> jogadas [posx].jogador2.coluna = -1;
            posx++;
        }
    }
}

void atualiza_posx (ESTADO *e,int x){
    e -> posx = x;
}

int devolve_posx (ESTADO *e){
    return e -> posx;
}

void atualiza_num_jogadas_fim (ESTADO *e){
    e -> num_jogadas = 32;
}

void atualizar_casa_branca(ESTADO *e,COORDENADA c){
    e -> tab [c.linha] [c.coluna] = BRANCA;
}

int obter_indice_jogadas_linha (ESTADO  *e,int jogador,int indice) {
    if (jogador == 1) {
        return e->jogadas[indice].jogador1.linha;
    }
    else
        return e->jogadas[indice].jogador2.linha;
}


int obter_indice_jogadas_coluna (ESTADO  *e,int jogador,int indice) {
    if (jogador == 1) {
        return e->jogadas[indice].jogador1.coluna;
    }
    else
        return e->jogadas[indice].jogador2.coluna;
}

COORDENADA ultima_jogada (ESTADO *e) {
    if (obter_jogador_atual(e) == 2)
        return e -> jogadas [obter_numero_de_jogadas(e) ].jogador1;
    else return e -> jogadas [obter_numero_de_jogadas(e) - 1].jogador2;

}

void preenche_tab_cor (ESTADO *e) {
    int i, j;
    for (i = 7; i >= 0; i--) {
        for (j = 0; j < 8; j++) {
            if (e -> tab [i] [j] == '#') {
                e->tab_cor[i][j] = PINTADA;
            }
            else e -> tab_cor[i][j] = NAO_PINTADA;

        }
    }
}

COR obter_cor (ESTADO *e, int linha, int coluna) {
    if ( e-> tab_cor [linha] [coluna]  == PINTADA) return PINTADA;
    else return NAO_PINTADA;
}

int conta_casas_livres (ESTADO *e, int linha, int coluna) {
    int n = 0;
    if (obter_cor(e,linha, coluna) == PINTADA) return 0;
    if (obter_cor(e,linha, coluna) == NAO_PINTADA && linha < 8 && linha >= 0 && coluna >= 0 && coluna < 8) {
        n++ ;
        e -> tab_cor [linha] [coluna] = PINTADA;
        n = n + conta_casas_livres (e, linha + 1, coluna - 1);
        n = n + conta_casas_livres (e, linha + 1, coluna);
        n = n + conta_casas_livres (e, linha + 1, coluna + 1 );
        n = n + conta_casas_livres (e, linha, coluna - 1);
        n = n + conta_casas_livres (e, linha, coluna + 1);
        n = n + conta_casas_livres (e, linha - 1, coluna + 1);
        n = n + conta_casas_livres (e, linha - 1, coluna);
        n = n + conta_casas_livres (e, linha - 1, coluna - 1);
    }
    return n;
}

void flood_fill (ESTADO *e ,int linha, int coluna) {
    if (obter_cor(e,linha, coluna) == PINTADA ) {
        return;
    }
    if (obter_cor(e,linha, coluna) == NAO_PINTADA && linha < 8 && linha >= 0 && coluna >= 0 && coluna < 8) {
        e -> tab_cor [linha] [coluna] = PINTADA;
        flood_fill(e, linha + 1, coluna - 1);
        flood_fill(e, linha + 1, coluna);
        flood_fill(e, linha + 1, coluna + 1);
        flood_fill(e, linha, coluna - 1);
        flood_fill(e, linha, coluna + 1);
        flood_fill(e, linha - 1, coluna + 1);
        flood_fill(e, linha - 1, coluna);
        flood_fill(e, linha - 1, coluna - 1);
    }
}
