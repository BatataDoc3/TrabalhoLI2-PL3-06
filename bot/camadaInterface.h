/**
 * @file camadaInterface.h
 * \brief conjunto de funções que desenham o tabuleiro e recebem o input do jogador, e fazem várias ações dependendo do input
 */

#ifndef PROJETO_LI2_CAMADAINTERFACE_H
#define PROJETO_LI2_CAMADAINTERFACE_H

#include "estrutura.h"



/**
 * Função auxiliar para a função gravar.
 * @param f o ficheiro.
 * @param e o estado.
 */
void gravar_tabuleiro (FILE *f,ESTADO *e);

/**
 * Função que dá print de um array.
 * @param f o ficheiro.
 * @param e o estado.
 */
void print_array (FILE *f, ESTADO *e);

/**
 * Função que grava o tabuleiro (comando gr).
 * @param e o estado.
 * @param filename o nome do ficheiro.
 * @return 0 caso ficheiro seja NULL , 1 caso contrário
 */
int gravar (ESTADO *e,char *filename);


/**
 * Função que lê um tabuleiro.
 * @param e o estado.
 * @param filename o nome do ficheiro.
 * @return 0 caso esse ficheiro não exista, 1 caso contrário
 */
int ler (ESTADO *e,char *filename);



#endif //PROJETO_LI2_CAMADAINTERFACE_H
