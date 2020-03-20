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
 * Função que lê os inputs e efetua as Jogadas no tabuleiro.
 * @param e Apontador para o ESTADO.
 * @return
 */
int interpretador(ESTADO *e);

#endif //PROJETO_LI2_CAMADAINTERFACE_H
