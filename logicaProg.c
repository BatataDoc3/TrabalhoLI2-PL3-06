#include "estrutura.h"
#include <stdio.h>

int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (devolve_posicao(e,linha+1,coluna) == '*' ||
       devolve_posicao(e,linha,coluna + 1) == '*' ||
       devolve_posicao(e,linha + 1,coluna + 1) == '*' ||
       devolve_posicao(e,linha - 1,coluna) == '*' ||
       devolve_posicao(e,linha,coluna - 1) == '*' ||
       devolve_posicao(e,linha - 1,coluna - 1) == '*' ||
       devolve_posicao(e,linha - 1,coluna + 1) == '*' ||
       devolve_posicao(e,linha + 1,coluna - 1) == '*')
        return 1;
    else return 0;
}

int jogada_valida (ESTADO *e , COORDENADA c) {
    if (c.linha < 0 || c.linha > 7) return (-1);
    if (c.coluna < 0 || c.coluna > 7)  return (-1);
    if (jogada_valida_pecaBranca(e, c) == 1) {
        if (devolve_posicao(e,c.linha,c.coluna) == '#')
            return (-1);
        else return 1;
    }
    else return (-1);
}

int casa_Preta (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (devolve_posicao(e,linha + 1,coluna)== '#' &&
        devolve_posicao(e,linha,coluna + 1) == '#' &&
        devolve_posicao(e,linha - 1,coluna) == '#' &&
        devolve_posicao(e,linha,coluna - 1) == '#' &&
        devolve_posicao(e,linha - 1,coluna - 1) == '#' &&
        devolve_posicao(e,linha - 1,coluna + 1) == '#' &&
        devolve_posicao(e,linha + 1,coluna - 1) == '#' &&
        devolve_posicao(e,linha + 1,coluna + 1) == '#' )
        return 1;
    else if (linha == 0 && coluna == 0 &&
            devolve_posicao(e,linha + 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna + 1) == '#' &&
            devolve_posicao(e,linha,coluna + 1) == '#')
        return 1;
    else if (linha == 0 && coluna == 7 &&
            devolve_posicao(e,linha + 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna - 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 0 &&
            devolve_posicao(e,linha - 1,coluna) == '#' &&
            devolve_posicao(e,linha - 1,coluna + 1) == '#' &&
            devolve_posicao(e,linha,coluna + 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 7 &&
            devolve_posicao(e,linha - 1,coluna) == '#' &&
            devolve_posicao(e,linha - 1,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna - 1) == '#')
        return 1;
    else if (linha == 7 &&
            devolve_posicao(e,linha - 1,coluna) == '#' &&
            devolve_posicao(e,linha - 1,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna + 1) == '#' &&
            devolve_posicao(e,linha - 1,coluna + 1) == '#')
        return 1;
    else if (linha == 0 &&
            devolve_posicao(e,linha + 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna - 1) == '#' &&
            devolve_posicao(e,linha,coluna + 1) == '#' &&
            devolve_posicao(e,linha + 1,coluna + 1) == '#')
        return 1;
    else if (coluna == 0 &&
            devolve_posicao(e,linha - 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna +1) == '#' &&
            devolve_posicao(e,linha - 1,coluna + 1) == '#' &&
            devolve_posicao(e,linha,coluna + 1) == '#')
        return 1;
    else if (coluna == 7 &&
            devolve_posicao(e,linha,coluna - 1) == '#' &&
            devolve_posicao(e,linha - 1,coluna) == '#' &&
            devolve_posicao(e,linha + 1,coluna) == '#' &&
            devolve_posicao(e,linha - 1,coluna - 1) == '#' &&
            devolve_posicao(e,linha + 1,coluna - 1) == '#')
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
    if (obter_numero_de_jogadas(e) == 32 || (colunaJog == 0 && linhaJog == 0) ||
        (colunaJog == 7 && linhaJog == 7) || rodeado_pretas(e, c)){
        r = 1;
    }
    return r;
}

int parabens_jogador (ESTADO *e){
    int x=0;
    if (obter_estado_casa(e,7,7) == '*') x = 2;
    else if (obter_estado_casa(e,0,0) == '*') x = 1;
    else {
        if (obter_jogador_atual(e) == 1) x = 2;
        else if (obter_jogador_atual(e) == 2) x = 1;}
    return x;
}


int jogo_finalizado_bot (ESTADO *e, COORDENADA c) {
    int colunaJog, linhaJog;
    int r = 0;
    colunaJog = c.coluna;
    linhaJog = c.linha;
    if (obter_jogador_atual(e) == 1) {
         if (obter_numero_de_jogadas(e) == 32 || (colunaJog == 0 && linhaJog == 0) ||rodeado_pretas(e, c))
             r = 1;
    }
    else if (obter_numero_de_jogadas(e) == 32 || (colunaJog == 0 && linhaJog == 0) ||rodeado_pretas(e, c))
             r = 1;
    return r;
}

int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogada_valida(e, c) == 1) {
        printf("jogar %d %d\n", c.coluna, c.linha);
        if (e -> posx != 50) {
            posicao(e);
            e -> posx = 50;
        }
        atualizar_casa_preta(e);
        atualizar_casa(e, c);
        atualizar_jogadas (e, c);
        atualizar_num_jogadas(e);
        atualizar_jogador_atual(e);
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
