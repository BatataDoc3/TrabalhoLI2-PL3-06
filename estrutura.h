//
// Created by josejoao on 09/03/20.
//

#ifndef PROJETO_ESTRUTURA_H
#define PROJETO_ESTRUTURA_H
#define BUF_SIZE 1024


typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {int linha;int coluna;} COORDENADA;
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


CASA obter_estado_casa (ESTADO *e, COORDENADA *x);
int obter_numero_de_jogadas (ESTADO *e);
int obter_jogador_atual (ESTADO *e);
ESTADO *inicializar_estado();



#endif //PROJETO_ESTRUTURA_H
