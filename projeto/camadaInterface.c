/**
 * @file camadaInterface.c
 * \brief conjunto de funções que desenham o tabuleiro e recebem o input do jogador, e fazem várias ações dependendo do input
 */

#include "logicaProg.h"
#include "estrutura.h"
#include <stdio.h>
#include <string.h>
#include "arvores.h"

void mostrar_tabuleiro (ESTADO *e) {
    int linha,coluna;
    char letra = '8';
    for (linha = 7; linha >= 0; linha--) {
        putchar (letra) ;
        letra--;
        for (coluna = 0; coluna < 8; coluna ++) {
            if (obter_estado_casa (e,linha,coluna) == DOIS) printf (" 2");
            else if (obter_estado_casa (e,linha,coluna) == UM) printf (" 1");
            else if (obter_estado_casa (e,linha,coluna)  == VAZIO) printf (" .") ;
            else if (obter_estado_casa (e,linha,coluna)  == BRANCA) printf (" *");
            else printf (" #");
        }
        printf ("\n");
    }
    printf ("  A B C D E F G H \n");
}

void gravar_tabuleiro (FILE *f,ESTADO *e) {
    int linha,coluna;
    for (linha = 7; linha >= 0; linha--) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (obter_estado_casa (e,linha , coluna) == DOIS) fprintf (f,"2");
            else if (obter_estado_casa (e, linha, coluna) == UM) fprintf (f,"1");
            else if (obter_estado_casa (e, linha, coluna)  == VAZIO) fprintf (f,".") ;
            else if (obter_estado_casa (e, linha, coluna)  == BRANCA) fprintf (f,"*");
            else fprintf (f,"#");
        }
        fprintf (f,"\n");
    }
}

void print_array (FILE *f, ESTADO *e){
    int i;
    for (i = 0;i <= (obter_numero_de_jogadas(e)) && i  < 32; i++ ){
        if (i<9){
            if (obter_indice_jogadas_linha(e,1,i) != -1|| obter_indice_jogadas_coluna(e,1,i) != -1) {
                fprintf(f, "0%d: %c%d", i + 1, (obter_indice_jogadas_coluna(e,1,i)) + 'a', obter_indice_jogadas_linha(e,1,i) + 1);
            }
            if (obter_indice_jogadas_linha(e,2,i) != -1 || obter_indice_jogadas_coluna(e,2,i) != -1) {
                fprintf(f, " %c%d\n", (obter_indice_jogadas_coluna(e,2,i)) + 'a', obter_indice_jogadas_linha(e,2,i) + 1);
            }
            if ((obter_indice_jogadas_linha(e,1,i) != -1 && obter_indice_jogadas_coluna(e,1,i) != -1) && (obter_indice_jogadas_linha(e,2,i) == -1 && obter_indice_jogadas_coluna(e,2,i) == -1)){
                fprintf(f,"\n");
            }
        }
        else {
            if (obter_indice_jogadas_linha(e,1,i) != -1|| obter_indice_jogadas_coluna(e,1,i) != -1) {
                fprintf(f, "%d: %c%d", i + 1, obter_indice_jogadas_coluna(e,1,i) + 'a', obter_indice_jogadas_linha(e,1,i) + 1);
            }
            if (obter_indice_jogadas_linha(e,2,i) != -1|| obter_indice_jogadas_coluna(e,2,i) != -1) {
                fprintf(f, " %c%d\n", obter_indice_jogadas_coluna(e,2,i) + 'a', obter_indice_jogadas_linha(e,2,i) + 1);
            }
            else {
                fprintf(f, "\n");
            }
        }
    }
}

int gravar (ESTADO *e,char *filename) {
    FILE *f = fopen (filename,"w");
    if (f == NULL)
        return 0;
    gravar_tabuleiro (f,e);
    fprintf (f,"\n");
    print_array (f,e);
    fclose (f);
    return 1;
}

int ler (ESTADO *e,char *filename){
    FILE *f = fopen (filename, "r");
    if (f == NULL){
        printf ("Erro ao abrir ficheiro\n");
        return 0;
    }
    le_ficheiro (e, f);
    mostrar_tabuleiro (e);
    return 1;
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char filename[BUF_SIZE];
    e -> num_comandos++;
    printf("# %02d  Jogador:%d  Número de jogada:%d> ", e -> num_comandos , e -> jogador_atual , e -> num_jogadas);
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        jogar (e, coord);
        mostrar_tabuleiro (e);
    }
    if (sscanf (linha,"gr %s",filename) == 1){
        gravar (e,filename);
    }
    if (sscanf (linha, "ler %s",filename) == 1){
        ler (e,filename);
    }
    if(strcmp(linha, "Q\n") == 0) {
        e->num_jogadas=32;
        printf ("O jogo terminou.\n");
    }
    if(strcmp(linha, "movs\n") == 0) {
        print_array(stdout, e);
    }
    int x;
    if (sscanf (linha,"pos %d",&x) == 1) {
        e -> posx = x;
        atualizar_tabuleiro_jogadas (e);
        mostrar_tabuleiro(e);
    }
    if (strcmp (linha,"jog\n") == 0) {
        jogs (e);
        mostrar_tabuleiro(e);
    }
    if (strcmp (linha,"jog2\n") == 0) {
        jog2 (e);
        mostrar_tabuleiro(e);
    }
    else return 0;
    return 1;
}

