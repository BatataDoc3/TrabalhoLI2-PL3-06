#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024




typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {int coluna;int linha;} COORDENADA;
typedef struct {COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;






// Função que deve ser completada e colocada na camada de dados
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
}
