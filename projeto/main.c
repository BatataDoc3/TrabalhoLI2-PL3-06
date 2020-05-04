/**
 * @file main.c
 * \brief função principal
 */

#include "estrutura.h"
#include "camadaInterface.h"

/**
 * funçao principal do jogo
 * @return 0
 */
int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (e -> num_jogadas <32) {
        interpretador(e);
    }
    return 0;
}
