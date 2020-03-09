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
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    COORDENADA *c = (COORDENADA *) malloc (sizeof(COORDENADA));
    c -> coluna = 5;
    c -> linha = 4;
    JOGADA *j = (JOGADA *) malloc (sizeof(JOGADA));
    j -> jogador1 = *c;
    e->jogadas = JOGADAS[0];
    // Falta a resto da inicialização.
    return e;
}



void mostrar_tabuleiro(ESTADO *e) {

}

