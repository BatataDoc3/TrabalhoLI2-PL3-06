#include "logicaProg.h"
#include "estrutura.h"
#include <stdio.h>
#include <string.h>



void mostrar_tabuleiro (ESTADO *e) {
    int linha,coluna;
    char letra = 'H';
    for (linha = 7; linha >= 0; linha--) {
        putchar (letra) ;
        letra--;
        for (coluna = 0; coluna < 8; coluna ++) {
            if (linha == 7 && coluna ==7) printf (" 2");
            else if (linha == 0 && coluna == 0) printf (" 1");
            else if (e -> tab [linha] [coluna]  == VAZIO) printf (" .") ;
            else if (e -> tab [linha] [coluna]  == BRANCA) printf (" *");
            else printf (" #");
        }
        printf ("\n");
    }
    printf ("  1 2 3 4 5 6 7 8 \n");
    printf ("Jogador atual : %d \nNúmero de jogadas : %d \n", obter_jogador_atual(e), obter_numero_de_jogadas(e));
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
