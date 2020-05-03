#include "camadaInterface.h"
#include "logicaProg.h"
#include "estrutura.h"

int main (int x , char *array[]){
   if (x == 3){
       ESTADO *e = inicializar_estado();
       ler (e,array[1]);
       jog2(e);
       gravar(e,array[2]);
   }
}


