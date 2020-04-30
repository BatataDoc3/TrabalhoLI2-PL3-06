/**
 * @file camadaInterface.h
 * \brief conjunto de funções que desenham o tabuleiro e recebem o input do jogador, e fazem várias ações dependendo do input
 */

#ifndef PROJETO_LI2_CAMADAINTERFACE_H
#define PROJETO_LI2_CAMADAINTERFACE_H
/**
 * \brief Função que atualiza o desenho do tabuleiro.
 * @param e Apontador para o ESTADO.
 */
void mostrar_tabuleiro (ESTADO *e);


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
 * @return
 */
int gravar (ESTADO *e,char *filename);


/**
 * Função que lê um tabuleiro.
 * @param e o estado.
 * @param filename o nome do ficheiro.
 * @return
 */
int ler (ESTADO *e,char *filename);


/**
 * Função que lê os inputs e efetua as Jogadas no tabuleiro.
 * @param e Apontador para o ESTADO.
 * @return
 */
int interpretador(ESTADO *e);

#endif //PROJETO_LI2_CAMADAINTERFACE_H
