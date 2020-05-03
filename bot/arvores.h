#ifndef TRABALHOLI2_PL3_06_MASTER_8_2_COPIA_ARVORES_H
#define TRABALHOLI2_PL3_06_MASTER_8_2_COPIA_ARVORES_H
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

/**
 * Função que cria uma árvore com classificação nas ultimas folhas
 * @param e estado
 * @param linha para a coordenada a meter no valor da struct nodoArv
 * @param coluna para a coordenada a meter no valor da struct nodoArv
 * @param profundidade da arvore
 * @return arvore
 */
TREE criar_arvore (ESTADO *e,int linha,int coluna,int profundidade);

/**
 * Função que dado um array de 8 elementos retorna o menor
 * @param a array
 * @param n numero de elementos do array
 * @return menor elemento
 */
float min8 (float *a,int n);

/**
 * Função que dado um array de 8 elementos retorna o maior
 * @param a array
 * @param n numero de elementos do array
 * @return maior elemento
 */
float max8  (float *a,int n);

/**
 * Função que preenche o resto das classificações da arvore de acordo com a heurística min-max
 * @param arvore a arvore
 * @param profundidade a profundidade
 */
void preencher_class (TREE arvore,int profundidade);

/**
 * Função que dá free à árvore
 * @param arvore a arvore
 * @param profundidade a profundidade
 */
void free_arvore (TREE arvore,int profundidade);

#endif //TRABALHOLI2_PL3_06_MASTER_8_2_COPIA_ARVORES_H
