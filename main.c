#include "estrutura.h"
#include "logicaProg.h"
#include "camadaInterface.h"
#include <stdio.h>

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
