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
            if (obter_estado_casa(e,coluna,linha) == DOIS) printf (" 2");
            else if (obter_estado_casa(e,coluna,linha) == UM) printf (" 1");
            else if (obter_estado_casa(e,coluna,linha)  == VAZIO) printf (" .") ;
            else if (obter_estado_casa(e,coluna,linha)  == BRANCA) printf (" *");
            else printf (" #");
        }
        printf ("\n");
    }
    printf ("  1 2 3 4 5 6 7 8 \n");
}


void gravar_tabuleiro (FILE *f,ESTADO *e) {
    int linha,coluna;
    for (linha = 7; linha >= 0; linha--) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (obter_estado_casa(e,coluna,linha) == DOIS) fprintf (f,"2");
            else if (obter_estado_casa(e,coluna,linha) == UM) fprintf (f,"1");
            else if (obter_estado_casa(e,coluna,linha)  == VAZIO) fprintf (f,".") ;
            else if (obter_estado_casa(e,coluna,linha)  == BRANCA) fprintf (f,"*");
            else fprintf (f,"#");
        }
        fprintf (f,"\n");
    }
}

void print_array (FILE *f, ESTADO *e){
  int i;
  for (i=0;i <= (obter_numero_de_jogadas(e)); i++ ){
      if (i<9){
          if ((e->jogadas[i].jogador1.linha)!= 0 || e->jogadas[i].jogador1.coluna != 0) {
              fprintf(f, "0%d: %c%d ", i + 1, (e->jogadas[i].jogador1.linha) + 'a', e->jogadas[i].jogador1.coluna + 1);
          }
          if ((e->jogadas[i].jogador2.linha)!= 0 || e->jogadas[i].jogador2.coluna != 0) {
              fprintf(f, "%c%d ", (e->jogadas[i].jogador2.linha) + 'a', e->jogadas[i].jogador2.coluna + 1);
              fprintf(f, "\n");
          }
          if (((e->jogadas[i].jogador1.linha)!= 0 || e->jogadas[i].jogador1.coluna != 0) && ((e->jogadas[i].jogador2.linha)== 0 && e->jogadas[i].jogador2.coluna == 0)){
              fprintf(f, "\n");
          }
      }
      else {
          if ((e->jogadas[i].jogador1.linha)!= 0 || e->jogadas[i].jogador1.coluna != 0) {
              fprintf(f, "%d: %c%d ", i + 1, (e->jogadas[i].jogador1.linha) + 'a', e->jogadas[i].jogador1.coluna + 1);
          }
          if ((e->jogadas[i].jogador2.linha)!= 0 || e->jogadas[i].jogador2.coluna != 0) {
              fprintf(f, "%c%d ", (e->jogadas[i].jogador2.linha) + 'a', e->jogadas[i].jogador2.coluna + 1);
              fprintf(f, "\n");
          }
          if (((e->jogadas[i].jogador1.linha)!= 0 || e->jogadas[i].jogador1.coluna != 0) && ((e->jogadas[i].jogador2.linha) ==  0 || e->jogadas[i].jogador2.coluna == 0)){
              fprintf(f, "\n");
          }
      }
  }
}

int gravar (ESTADO *e,char *filename) {
    FILE *f = fopen (filename,"w");
    if (f == NULL)
        return 0;
    gravar_tabuleiro(f,e);
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
    char linha[BUF_SIZE];
    char *result;
    int i=1;
    while (!feof(f)){
        result = fgets(linha, BUF_SIZE, f);
        if (result)
            printf("%s",linha);
        i++;
    }
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
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    if (sscanf (linha,"gr %s",filename) == 1){
        gravar (e,filename);
    }
    if (sscanf (linha, "ler %s",filename) == 1){
        ler (e,filename);
    }
    char quit;
    if (sscanf (linha, "%[Q]" ,&quit) == 1){
        e->num_jogadas=32;
        printf ("O jogo terminou.\n");
    }
    char arr[BUF_SIZE];
    if (sscanf(linha,"%[movs]",arr)==1){
        print_array (stdout,e);
    }
    return 1;
}

