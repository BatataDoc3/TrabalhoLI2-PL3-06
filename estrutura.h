/**
 * @file estrutura.h
 \brief conjunto de funções que alteram e definem o estado
 */

#ifndef PROJETO_LI2_ESTRUTURA_H
#define PROJETO_LI2_ESTRUTURA_H
#define BUF_SIZE 1024

/**
 *\brief tipo de dados para a CASA
 */
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA ;

/**
 \brief Tipo de dados para a COORDENADA
 */
typedef struct {int linha;int coluna;} COORDENADA;

/**
 * \brief Tipo de dados para a JOGADA
 */
typedef struct {COORDENADA jogador1;
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
    /** coordenada da ultima jogada */
    COORDENADA ultima_jogada;
    /** jogadas efetuadas */
    JOGADAS jogadas;
    /** número de jogadas */
    int num_jogadas;
    /** jogador atual */
    int jogador_atual;
    /** número de comandos efectuados */
    int num_comandos;
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
int atualizar_jogador_atual (ESTADO *e);

/**
 *\brief função que incrementa o número de jogadas
 * @param e pointer do estado
 * @return a jogada para que vamos
 */
int atualizar_num_jogadas (ESTADO *e);
/**
 \brief Função que inicializa o estado inicial do jogo
 * @return  estado inicial
 */
ESTADO *inicializar_estado();

/**
 * \brief Função que verifica se o jogo terminou
 * @param e pointer do estado
 * @param c coordenada
 * @return 1 caso o jogo finalizou ou 0 se não
 */

#endif //PROJETO_LI2_ESTRUTURA_H
