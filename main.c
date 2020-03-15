#include "estrutura.h"
#include "camadaInterface.h"


int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    int num_jogadas;
    num_jogadas = obter_numero_de_jogadas(e);
    while (num_jogadas <32) {
        interpretador(e);
        num_jogadas++;
    }
    return 0;
}
