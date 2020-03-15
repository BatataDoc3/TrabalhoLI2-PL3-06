#include "estrutura.h"
#include "camadaInterface.h"


int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (e -> num_jogadas <32) {
        interpretador(e);
    }
    return 0;
}
