
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"
#define BUF_SIZE 1024


LISTA criar_lista(){
    LISTA new = malloc (sizeof (NODO));
    new -> valor = NULL;
    new -> proximo = NULL;
    return new;
}



LISTA insere_cabeca(LISTA L, void *valor){
    LISTA new = malloc (sizeof (NODO));
    new->valor = valor;
    new->proximo = L;
    return new ;
}

void *devolve_cabeca(LISTA L){
   // LISTA lista = malloc (sizeof (NODO));
   // lista->valor = L->valor;
   // lista->proximo = NULL;
   // L = lista;
    return L->valor;
}

LISTA proximo(LISTA L){
    // L = L->proximo;
    return L -> proximo;
}



LISTA remove_cabeca(LISTA L){
    LISTA tmp = L -> proximo;
    free (L);
    L = tmp;
    return L;
}



int lista_esta_vazia(LISTA L){
    if (L -> proximo  == NULL) return 1;
    else return 0;
}

int comprimentoLista (LISTA l){
    int i = 0;
    while (l!=NULL) {
        i++;
        l = l->proximo;
    }
    return i;
}
