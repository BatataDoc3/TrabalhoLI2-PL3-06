/**
 * @file logicaProg.h
 * \brief conjunto de funções que verificam se a jogada é válida e faz a jogada
 */

#ifndef PROJETO_LI2_LOGICAPROG_H
#define PROJETO_LI2_LOGICAPROG_H
#include "estrutura.h"
#include "arvores.h"

/**
 * \brief tabuleiro com as classificações das casas respetivas
 */
typedef struct {
    /** O tabuleiro com classificações*/
    float clas1[8][8];
} CLASSIFICACAO;


/**
 * Função que analisa se a peça branca esta nas posições à volta da atual para verificar se a posição é válida.
 * @param e o estado.
 * @param c a coordenada
 * @return 1 se se verificar a condição acima descrita
 */
int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c);


/**
 * Função que verifica as Jogadas e analisa quando o jogo acaba.
 * @param e Apontador para o ESTADO.
 * @param c Recebe uma COORDENADA para onde pretende ir.
 * @return 1 caso seja possível continuar a jogar
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
 * @return 1 se o jogo acaba
 */
int jogo_finalizado (ESTADO *e, COORDENADA c);

/**
 * Função que avalia se o jogo finaliza e que é usada para o bot.
 * @param e o estado.
 * @param c a coordenada
 * @return 1 se for verdade
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


/**
 * Função que avalia se uma jogada do bot é válida.
 * @param e o estado.
 * @param c a coordenada.
 * @return 1 caso seja válida, (-1) caso não seja
 */
int jogada_valida_bot (ESTADO *e ,int linha,int coluna);

/**
 * Função que calcula a distância à casa-objetivo.
 * @param c a coordenada.
 * @param e o estado.
 * @return do valor da classificação da coordenada recebida
 */
float classificacao (COORDENADA c,ESTADO *e);

/**
 * Função que verifica se o jogo finaliza
 * @param e o estado.
 * @param arvore
 * @return da coordenada caso o jogo finalize na próxima jogada
 */
COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore);

/**
 * Função que verifica qual a melhor posição para movimentar.
 * @param arvore a árvore.
 * @return da melhor coordenada
 */
COORDENADA verifica_melhor_pos (TREE arvore);

/**
 * função que verifica se existe um caminho possível para a casa 1 (caso seja o jogador 1) ou para a casa 2 (casa seja o 2)
 * @param e pointer do estado
 * @param linha a linha
 * @param coluna a coluna
 * @return retorna 1 caso não seja possível ou 0 se for
 */
int bloqueada (ESTADO *e, int linha, int coluna);

/**
 * função que vê, quando estamos blloqueados e o numero de casas vazias depois da jogada é par, qual caminho deixa mais casas livres
 * @param e pointer do estado
 * @param c coordenada
 * @return coordenada para onde temos de ir
 */
COORDENADA conta_mais_casas (ESTADO *e, COORDENADA c);

/**
 * função que vê, quando estamos encurralados, para que posição nos podemos mover para ficar com um número par de casas vazias
 * @param e pointer do estado
 * @param c coordenada
 * @return coordenada para onde devemos ir
 */
COORDENADA paridade (ESTADO *e, COORDENADA c);

/**
 * função que vê se na próxima jogada vamos ficar bloqueados e se sim, com quantas casas livres (par ou ímpar)
 * @param e pointer do estado
 * @param c pointer da coordenada
 * @return coordenada para nos devemos movimentar
 */
COORDENADA verifica_se_vai_bloquear (ESTADO *e, COORDENADA c);

/**
 * Função que efetua jogadas com base numa eurística Min-Max.
 * @param e o estado
 */
void jog2 (ESTADO *e);

#endif //PROJETO_LI2_LOGICAPROG_H
