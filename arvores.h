#ifndef TRABALHOLI2_PL3_06_MASTER_8_2_CÓPIA_ARVORES_H
#define TRABALHOLI2_PL3_06_MASTER_8_2_CÓPIA_ARVORES_H
#include "estrutura.h"

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


TREE criar_arvore (ESTADO *e,int linha,int coluna,int profundidade);

float min8 (float *a,int n);

float max8  (float *a,int n);

float preencher_class (TREE arvore,int profundidade);   //FIXME

void free_arvore (TREE arvore,int profundidade);

#endif //TRABALHOLI2_PL3_06_MASTER_8_2_CÓPIA_ARVORES_H
