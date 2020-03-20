
#ifndef PROJETO_LI2_ESTRUTURA_H
#define PROJETO_LI2_ESTRUTURA_H
#define BUF_SIZE 1024
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA ;
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
    int num_comandos;
} ESTADO;


CASA obter_estado_casa (ESTADO *e, int coluna, int linha);
CASA atualizar_casa (ESTADO *e, COORDENADA c);
void atualizar_casa_preta (ESTADO *e);
int obter_numero_de_jogadas (ESTADO *e);
int obter_jogador_atual (ESTADO *e);
int atualizar_jogador_atual (ESTADO *e);
int atualizar_num_jogadas (ESTADO *e);
ESTADO *inicializar_estado();
int jogo_finalizado (ESTADO *e, COORDENADA c);
int rodeado_pretas (ESTADO *e, COORDENADA c);
int casa_Preta (ESTADO*e, COORDENADA c);
int parabens_jogador (ESTADO *e);

#endif //PROJETO_LI2_ESTRUTURA_H
