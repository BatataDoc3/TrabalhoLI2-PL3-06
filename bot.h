#ifndef TRABALHOLI2_PL3_06_MASTER_4_BOT_H
#define TRABALHOLI2_PL3_06_MASTER_4_BOT_H
#include "estrutura.h"
#include "listas.h"

/**
 * Struct de uma árvore com um valor e os respetivos nodos.
 */
typedef struct nodoArv {
    /**
     * O valor correspondente à raiz.
     */
    COORDENADA valor;
    /**
     * A classificação da posição que se encontra guardada na variável valor
     */
    float classificacao;
    /**
     * Os movimentos a partir de uma posição : CE-cima e esquerda , CD-cima e direita , CC-centro , DD-direita , EE-esquerda , BE-baixo e esquerda , BD-baixo e direita.
     */
    struct nodoArv *CE , *CC , *CD , *DD , *BD , *BB, *BE , *EE;
} *TREE ;

/**
 * Função que insere um elemento na cabeça da lista.
 * @param L a lista.
 * @param c a coordenada a inserir.
 * @param e o estado.
 * @return
 */
LISTA poe_lista (LISTA L, COORDENADA *c, ESTADO *e);

/**
 * Função que verifica se um casa é valida para jogar.
 * @param linha a linha da casa.
 * @param coluna a coluna da casa.
 * @param e o estado.
 * @return
 */
int casa_valida_bot (int linha,int coluna,ESTADO *e);

/**
 * Função que avalia se uma jogada do bot é válida.
 * @param e o estado.
 * @param c a coordenada.
 * @return
 */
int jogada_valida_bot (ESTADO *e ,int linha,int coluna);   //FIXME adicionei variavel

/**
 * Função que calcula a distância à casa-objetivo.
 * @param c a coordenada.
 * @param e o estado.
 * @return
 */
float classificacao (COORDENADA c,ESTADO *e);

/**
 * Função que verifica se o jogo finaliza
 * @param e o estado.
 * @param arvore
 * @return
 */
COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore);

/**
 * Função que verifica qual a melhor posição para movimentar.
 * @param arvore a árvore.
 * @return
 */
COORDENADA verifica_melhor_pos (ESTADO *e,TREE arvore);

/**
 * Fução que efetua jogadas aleatorias (comando jog1).
 * @param e o estado.
 */
void jogs ( ESTADO *e);

/**
 * Função que efetua jogadas com base numa eurística Min-Max.
 * @param e o estado
 */
void jog2 (ESTADO *e);
#endif //TRABALHOLI2_PL3_06_MASTER_4_BOT_H
