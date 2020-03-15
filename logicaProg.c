#include "estrutura.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    e -> tab [c.coluna] [c.linha] = BRANCA;
    e -> num_jogadas = atualizar_num_jogadas(e);
    e -> jogador_atual = atualizar_jogador_atual (e);
    return 1;
}
