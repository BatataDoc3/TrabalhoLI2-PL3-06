/**
 * @file estrutura.h
 * \brief conjunto de funções que alteram o estado
 */
#ifndef PROJETO_FINALIZADO_ESTRUTURA_H
#define PROJETO_FINALIZADO_ESTRUTURA_H

/**
 * Defiir BUF_SIZE PARA 1024
 */
#define BUF_SIZE 1024
#include <stdio.h>

/**
 *\brief tipo de dados para a CASA
 */
typedef enum {
    /**
     CASA UM
     */
    UM = '1',
    /**
    CASA DOIS
    */
    DOIS = '2',
    /**
    CASA VAZIO
    */
    VAZIO = '.',
    /**
     * CASA BRANCA
     */
    BRANCA = '*',
    /**
     * CASA PRETA
     */
    PRETA = '#'
} CASA ;

/**
 * \brief tipo de dados para a COR
 */
typedef enum {
    /**
     * COR PINTADA
     */
    PINTADA = '#',
    /**
     * COR NAO_PINTADA
     */
    NAO_PINTADA = '1'
} COR;


/**
 \brief Tipo de dados para a COORDENADA
 */
typedef struct {
    /**
     * linha
     */
    int linha;
    /**
     * coluna
     */
    int coluna;
} COORDENADA;

/**
* \brief Tipo de dados para a JOGADA
*/
typedef struct {
    /**
    * Coordenada do jogador 1.
    */
    COORDENADA jogador1;
    /**
     * Coordenada do jogador 2.
     */
    COORDENADA jogador2;
} JOGADA;


/**
 * \brief Tipo de dados para as JOGADAS
 */
typedef JOGADA JOGADAS[32];

/**
 * \brief Tipo de dados para o ESTADO
 */
typedef struct {
    /** As peças do tabuleiro */
    CASA tab[8][8];
    /** Colocar as peças como PINTADAS se forem pretas ou NAO_PINTADAS, caso contrário */
    COR tab_cor [8] [8];
    /** coordenada da ultima jogada */
    COORDENADA ultima_jogada;
    /** jogadas efetuadas */
    JOGADAS jogadas;
    /** número de jogadas */
    int num_jogadas;
    /** jogador atual */
    int jogador_atual;
    /** número de  comandos efectuados */
    int num_comandos;
    /** variável guardada utilizada no comando pos */
    int posx;
} ESTADO;

/**
 \brief Função que diz o estado de uma determinada casa.
 @param e pointer do estado
 @param coluna coluna da coordenada
 @param linha linha da coordenada
 @return devolve uma CASA
 */
CASA obter_estado_casa (ESTADO *e, int coluna, int linha);

/**
 \brief função que troca a posição da peça branca
 * @param e pointer do estado
 * @param c coordenada
 * @return devolve a CASA com a peça branca
 */
CASA atualizar_casa (ESTADO *e, COORDENADA c);

/**
 \brief função que muda a posição onde estava a branca por uma preta.
 * @param e pointer do estado
 */
void atualizar_casa_preta (ESTADO *e);

/**
 \brief Função que diz o número de jogadas.
 * @param e pointer do estado
 * @return numero de jogadas
 */
int obter_numero_de_jogadas (ESTADO *e);

/**
 *\brief função que diz qual é o jogador a jogar
 * @param e pointer da função
 * @return do jogador atual (1 ou 2)
 */
int obter_jogador_atual (ESTADO *e);

/**
 \brief função que muda o jogador
 * @param e pointer do estado
 * @return o próximo jogador a jogar
 */
void atualizar_jogador_atual (ESTADO *e);

/**
 *\brief função que incrementa o número de jogadas
 * @param e pointer do estado
 * @return a jogada para que vamos
 */
void atualizar_num_jogadas (ESTADO *e);

/**
 *\brief função que atualiza o array das jogadas
 * @param e pointer do estado
 * @param c a cordenada
 */
void atualizar_jogadas (ESTADO *e, COORDENADA c);

/**
 * \brief função quê vai ao ficheiro guardado e altera o estado das casas, o jogador e o número de jogadas de acordo com o que está no ficheiro
 * @param e pointer do edtado
 * @param f ficheiro
 */
void le_ficheiro (ESTADO *e,FILE *f);

/**
 * \brief função atualiza o estado para uma posição anterior (usada no comando pos)
 * @param e estado
 */
void posicao (ESTADO *e);

/**
 * \brief esta função atualiza o tabuleiro dependendo do input da pos
 * @param e Estado
 */
void atualizar_tabuleiro_jogadas (ESTADO *e);

/**
 \brief Função que inicializa o estado inicial do jogo
 * @return  estado inicial
 */
ESTADO *inicializar_estado();

/**
 * \brief Função que coloca o x na variável posx do estado
 * @param e pointer do estado
 * @param x valor
 */
void atualiza_posx (ESTADO *e,int x);

/**
 * Função que devolve a variável posx
 * @param e estado
 * @return o valor da variavel posx
 */
int devolve_posx (ESTADO *e);

/**
 * Função que atualiza o número de jogadas para o fim (num_jogadas=32)
 * @param e estado
 */
void atualiza_num_jogadas_fim (ESTADO *e);

/**
 * Função que atualiza a casa da respetiva cordenada recebida para BRANCA
 * @param e estado
 * @param c coordenada
 */
void atualizar_casa_branca(ESTADO *e,COORDENADA c);

/**
 * Função que devolve a linha que está no array jogadas no indice que recebe
 * @param e estado
 * @param jogador jogador
 * @param indice indice
 * @return valor da linha do indice do array
 */
int obter_indice_jogadas_linha (ESTADO  *e,int jogador,int indice);

/**
 * Função que devolve a coluna que está no array jogadas no indice que recebe
 * @param e estado
 * @param jogador jogador
 * @param indice indice
 * @return valor da coluna do indice do array
 */
int obter_indice_jogadas_coluna (ESTADO  *e,int jogador,int indice);

/**
 * \brief função que coloca as peças pretas como "PINTADAS" e as outras como "NAO_PINTADAS"
 * @param e pointer do estado
 */
void preenche_tab_cor (ESTADO *e);

/**
 * função que devolve a cor de uma certa coordenada (PINTADA ou NAO_PINTADA)
 * @param e pointer do estado
 * @param linha que queremos verificar
 * @param coluna que queremos verificar
 * @return COR da coordenada
 */
COR obter_cor (ESTADO *e, int linha, int coluna);

/**
 * Esta função troca uma casa para PINTADA
 * @param e pointer do estado
 * @param linha a linha
 * @param coluna a coluna
 */
void troca_casa_pintada (ESTADO *e, int linha , int coluna);

/**
 * função que troca uma peça para BRANCA
 * @param e pointer do estado
 * @param c coordenada
 */
void atualizar_casa_branca(ESTADO *e,COORDENADA c);

/**
 * função que troca todas as casas livres para PINTADA
 * @param e pointer do estado
 * @param linha a linha
 * @param coluna a coluna
 */
void flood_fill (ESTADO *e ,int linha, int coluna);

/**
 * função que conta quantas casas livres existem
 * @param e pointer do estado
 * @param linha a linha
 * @param coluna a coluna
 * @return numero de casas livres
 */
int conta_casas_livres (ESTADO *e, int linha, int coluna);

/**
 * \brief função que devolve as coordenadas da ultima posição
 * @param e pointer do estado
 * @return coordenada onde está a peça branca
 */
COORDENADA ultima_jogada (ESTADO *e);

#endif //PROJETO_FINALIZADO_ESTRUTURA_H
