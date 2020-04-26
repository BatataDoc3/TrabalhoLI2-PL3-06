#ifndef TRABALHOLI2_PL3_06_MASTER_4_BOT_H
#define TRABALHOLI2_PL3_06_MASTER_4_BOT_H
#include "estrutura.h"
typedef struct nodoArv {
    COORDENADA valor;
    struct nodoArv *CE , *CC , *CD , *DD , *BD , *BB, *BE , *EE;
} *TREE ;

void jogs ( ESTADO *e);

void jog2 (ESTADO *e);
#endif //TRABALHOLI2_PL3_06_MASTER_4_BOT_H
