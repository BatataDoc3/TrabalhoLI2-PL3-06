#include "estrutura.h"
#include <stdlib.h>


CASA obter_estado_casa (ESTADO *e, COORDENADA *x){
    CASA casa;
    int coluna, linha;
    coluna = x -> coluna;
    linha = x -> linha;
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
    e -> ultima_jogada.coluna = 4;
    e -> ultima_jogada.linha = 3;
    return e ;
}
