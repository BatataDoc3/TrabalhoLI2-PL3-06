/**
 * @file logicaProg.h
 * \brief conjunto de funções que verificam se a jogada é válida e faz a jogada
 */

#ifndef PROJETO_LI2_LOGICAPROG_H
#define PROJETO_LI2_LOGICAPROG_H

#include "estrutura.h"


/**
 * Função que analisa se a peça branca esta nas posições à volta da atual para verificar se a posição é válida.
 * @param e o estado.
 * @param c a coordenada
 * @return
 */
int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c);


/**
 * Função que verifica as Jogadas e analisa quando o jogo acaba.
 * @param e Apontador para o ESTADO.
 * @param c Recebe uma COORDENADA para onde pretende ir.
 * @return
 */

int jogar(ESTADO *e, COORDENADA c);

/**
 * \brief Função que verifica se uma jogada é válida
 * @param e pointer do estado
 * @param c coordenada
 * @return 1 caso seja válida, (-1) caso não seja
 */
int jogada_valida (ESTADO *e, COORDENADA c);

/**
 * Função que avalia se o jogo finaliza.
 * @param e o estado.
 * @param c a coordenada.
 * @return
 */
int jogo_finalizado (ESTADO *e, COORDENADA c);

/**
 * Função que avalia se o jogo finaliza e que é usada para o bot.
 * @param e o estado.
 * @param c a coordenada
 * @return
 */
int jogo_finalizado_bot (ESTADO *e, COORDENADA c);

/**
 * \brief Função que verifica se o jogador está rodeado de peças pretas
 * @param e pointer do estado
 * @param c coordenada
 * @return 1 se estiver rodeado de pretas ou 0 se não
 */
int rodeado_pretas (ESTADO *e, COORDENADA c);

/**
 * \brief Função que verifica se o jogador está rodeado de peças pretas
 * @param e pointer do estado
 * @param c coordenada
 * @return 1 se estiver rodeado de pretas ou 0 se não
 */
int casa_Preta (ESTADO*e, COORDENADA c);

/**
 * \brief Função que diz qual é o jogador vencedor
 * @param e pointer do estado
 * @return jogador vencedor
 */
int parabens_jogador (ESTADO *e);


#endif //PROJETO_LI2_LOGICAPROG_H

