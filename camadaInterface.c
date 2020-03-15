#include "logicaProg.h"
#include "estrutura.h"
#include <stdio.h>
#include <string.h>



void mostrar_tabuleiro (ESTADO *e) {
    int linha,coluna;
    for (linha = 7; linha >= 0; linha--) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (linha == 7 && coluna ==7) putchar ('2');
            else if (linha == 0 && coluna == 0) putchar ('1');
            else if (e -> tab [linha] [coluna]  == VAZIO) putchar ('.') ;
            else if (e -> tab [linha] [coluna]  == BRANCA) putchar ('*');
            else putchar ('#');
        }
        printf ("\n");
    }
}



int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}

