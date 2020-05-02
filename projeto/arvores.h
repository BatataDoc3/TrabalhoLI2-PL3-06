#ifndef PROJETO_LI2_ARVORES_H
#define PROJETO_LI2_ARVORES_H
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
 * Função que cria uma árvore.
 * @param e o estado.
 * @param linha a linha.
 * @param coluna a coluna.
 * @param profundidade a profundidade da árvore. (número de nodos)
 * @return
 */
TREE criar_arvore (ESTADO *e,int linha,int coluna,int profundidade);

/**
 * Função que calcula o minimo de um array de 8 elementos.
 * @param a a árvore.
 * @param n o tamanho do array.
 * @return
 */
float min8 (float *a,int n);

/**
 * Função que calcula o maximo de um array de 8 elementos.
 * @param a a arvore.
 * @param n o tamanho do array.
 * @return
 */
float max8  (float *a,int n);

/**
 * Preenche os nodos da árvore com as classificações utilizando a heurística MinMax.
 * @param arvore a árvore.
 * @param profundidade a profundidade.
 * @return
 */
float preencher_class (TREE arvore,int profundidade);

/**
 * Função que liberta o espaço ocupado apos a criação de uma árvore.
 * @param arvore a árvore.
 * @param profundidade a profundidade.
 */
void free_arvore (TREE arvore,int profundidade);

#endif //TRABALHOLI2_PL3_06_MASTER_8_2_CÓPIA_ARVORES_H
