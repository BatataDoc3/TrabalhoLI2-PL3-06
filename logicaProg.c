
#include "estrutura.h"
#include <stdio.h>

int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (e -> tab [linha+1] [coluna] == '*' ||
        e -> tab [linha] [coluna + 1] == '*' ||
        e -> tab [linha + 1] [coluna + 1] == '*' ||
        e -> tab [linha - 1] [coluna] == '*' ||
        e -> tab [linha] [coluna - 1] == '*' ||
        e -> tab [linha - 1] [coluna - 1] == '*' ||
        e -> tab [linha - 1] [coluna + 1] == '*' ||
        e -> tab [linha + 1] [coluna - 1] == '*')
        return 1;
    else return 0;
}

int jogada_valida (ESTADO *e , COORDENADA c) {
    if (jogada_valida_pecaBranca(e,c) == 1) {
        if (e-> tab [c.linha] [c.coluna] == '#')
            return (-1);
        else return 1;
    }
    else return (-1);
}


int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogada_valida(e, c) == 1) {
        printf("jogar %d %d\n", c.coluna, c.linha);
        atualizar_casa_preta(e);
        atualizar_casa(e, c);
        e->num_jogadas = atualizar_num_jogadas(e);
        e->jogador_atual = atualizar_jogador_atual(e);
        if (jogo_finalizado(e, c) == 1){
            x = parabens_jogador(e);
            printf("Jogo Finalizado! Parabéns Jogador %d\n", x);
            e -> num_jogadas = 32;
            return 0;
        }
        return 1;
    }
    else {
        printf ("Jogada inválida\n");
        return 0;
    }
}
