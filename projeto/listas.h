/**
 * @file listas.h
 \brief funções relativas às listas ligadas.
 */
#ifndef PROJETO_FINALIZADO_LISTAS_H
#define PROJETO_FINALIZADO_LISTAS_H
/**
 * Definir BUF_SIZE para 1024
 */
#define BUF_SIZE 1024
#include "estrutura.h"

/**
 *\brief struct relativa à definição de uma lista.
 */
typedef struct nodo {
    /** O valor referente ao nodo. */
    void *valor;
    /** O seguimento da lista ligada. */
    struct nodo *proximo;
} NODO,
    /**
    * a lista
    */
    *LISTA;


/**
 * função que cria uma lista vazia.
 * @return lista vazia criada.
 */
LISTA criar_lista();


/**
 * Função que insere um valor na cabeça de uma lista.
 * @param L a lista.
 * @param valor o valor a inserir.
 * @return a nova lista com o valor na cabeça.
 */
LISTA insere_cabeca(LISTA L, void *valor);



/**
 * Função que devolve a cabeça da lista.
 * @param L a lista.
 * @return a cabeça da lista.
 */
void *devolve_cabeca(LISTA L);


/**
 * Função que devolve a cauda da lista.
 * @param L a lista.
 * @return a cauda da lista.
 */
LISTA proximo(LISTA L);


/**
 * Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
 * @param L a lista.
 * @return a cauda da lista.
 */
LISTA remove_cabeca(LISTA L);


/**
 * Função que devolve verdareiro se a lista é vazia.
 * @param L a lista.
 * @return 0 caso seja falso e 1 caso seja verdadeiro.
 */
int lista_esta_vazia(LISTA L);

/**
 * Função que devolve o comprimento de uma lista.
 * @param l a lista.
 * @return do comprimento da lista
 */
int comprimentoLista (LISTA l);

#endif //PROJETO_FINALIZADO_LISTAS_H
