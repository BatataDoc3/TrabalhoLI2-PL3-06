#include "estrutura.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogada_valida(e, c) == 1) {
        printf("jogar %d %d\n", c.coluna, c.linha);
        atualizar_casa_preta(e);
        atualizar_casa(e, c);
        e->num_jogadas = atualizar_num_jogadas(e);
        e->jogador_atual = atualizar_jogador_atual(e);
        if (jogo_finalizado(e, c) == 1){
            x = parabens_jogador(e);
            printf("Jogo Finalizado! Parabéns Jogador %d\n", x);
            return 0;
        }
        return 1;
    }
    else {
        printf ("Jogada inválida\n");
        return 0;
    }
}
