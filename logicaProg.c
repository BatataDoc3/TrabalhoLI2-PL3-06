#include "estrutura.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    if (jogada_valida (e,c) == 1) {
        printf("jogar %d %d\n", c.coluna, c.linha);
        atualizar_casa_preta(e);
        atualizar_casa(e, c);
        e->num_jogadas = atualizar_num_jogadas(e);
        e->jogador_atual = atualizar_jogador_atual(e);
        return 1;
    }
    else {
        printf ("Jogada inválida\n");
        return 0;
    }
}
