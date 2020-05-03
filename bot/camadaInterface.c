#include "logicaProg.h"
#include "estrutura.h"
#include <stdio.h>
#include <string.h>
#include "arvores.h"

void gravar_tabuleiro (FILE *f,ESTADO *e) {
    int linha,coluna;
    for (linha = 7; linha >= 0; linha--) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (obter_estado_casa(e,linha,coluna) == DOIS) fprintf (f,"2");
            else if (obter_estado_casa(e,linha,coluna) == UM) fprintf (f,"1");
            else if (obter_estado_casa(e,linha,coluna)  == VAZIO) fprintf (f,".") ;
            else if (obter_estado_casa(e,linha,coluna)  == BRANCA) fprintf (f,"*");
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
           // else {
             //   fprintf(f, "\n");
           // }
        }
    }
}

int gravar (ESTADO *e,char *filename) {
    FILE *f = fopen (filename,"w");
    if (f == NULL)
        return 0;
    gravar_tabuleiro(f,e);
    fprintf (f,"\n");
    print_array(f,e);
    fclose(f);
    return 1;
}

int ler (ESTADO *e,char *filename){
    FILE *f = fopen (filename, "r");
    if (f == NULL){
        printf ("Erro ao abrir ficheiro\n");
        return 0;
    }
    le_ficheiro(e, f);
    return 1;
}
