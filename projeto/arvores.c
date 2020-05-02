#include "arvores.h"
#include "logicaProg.h"
#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>



TREE criar_arvore (ESTADO *e,int linha,int coluna,int profundidade){
    TREE arvore = malloc (sizeof(struct nodoArv));
    if (profundidade == 0) return NULL;
    arvore->valor.linha = linha;
    arvore->valor.coluna = coluna;
    // f (tudo_null(arvore) == 1) arvore->classificacao = classificacao (arvore->valor, e);
    profundidade--;
    TREE ce, cc, cd, dd, ee, be, bb, bd;
    if ((linha == 7 && coluna == 7) || (linha == 0 && coluna == 0)) {
        ce = cc = cd = dd = ee = be = bb = bd = NULL;
    }
    else {
        if (jogada_valida_bot(e, linha + 1, coluna - 1) == 1)
            ce = criar_arvore(e, linha + 1, coluna - 1, profundidade);
        else
            ce = NULL;
        if (jogada_valida_bot(e, linha + 1, coluna) == 1)
            cc = criar_arvore(e, linha + 1, coluna, profundidade);
        else
            cc = NULL;
        if (jogada_valida_bot(e, linha + 1, coluna + 1) == 1)
            cd = criar_arvore(e, linha + 1, coluna + 1, profundidade);
        else
            cd = NULL;
        if (jogada_valida_bot(e, linha, coluna + 1) == 1)
            dd = criar_arvore(e, linha, coluna + 1, profundidade);
        else
            dd = NULL;
        if (jogada_valida_bot(e, linha - 1, coluna + 1) == 1)
            bd = criar_arvore(e, linha - 1, coluna + 1, profundidade);
        else
            bd = NULL;
        if (jogada_valida_bot(e, linha - 1, coluna) == 1)
            bb = criar_arvore(e, linha - 1, coluna, profundidade);
        else
            bb = NULL;
        if (jogada_valida_bot(e, linha - 1, coluna - 1) == 1)
            be = criar_arvore(e, linha - 1, coluna - 1, profundidade);
        else
            be = NULL;
        if (jogada_valida_bot(e, linha, coluna - 1) == 1)
            ee = criar_arvore(e, linha, coluna - 1, profundidade);
        else
            ee = NULL;
    }
    arvore->CE = ce;
    arvore->CC = cc;
    arvore->CD = cd;
    arvore->DD = dd;
    arvore->BD = bd;
    arvore->BB = bb;
    arvore->BE = be;
    arvore->EE = ee;
    if (ce == NULL && cc == NULL && cd == NULL && dd == NULL && ee == NULL && bd == NULL && be == NULL && bb == NULL)
        arvore->classificacao = classificacao (arvore->valor, e);
    return arvore;
}


float min8 (float *a,int n){
    int i;
    float menor = a[0];
    for (i = 1 ; i < n ; i++){
        if (a[i] < menor) menor = a[i];
    }
    return menor;
}

float max8  (float *a,int n){
    int i;
    float maior = a[0];
    for (i = 1 ; i < n ; i++){
        if (a[i] > maior) maior = a[i];
    }
    return maior;
}


float preencher_class (TREE arvore,int profundidade){
        if (profundidade >1){
        float arr[8];
        int i=0, n=0;
        if (arvore->CE != NULL) {
            preencher_class(arvore->CE,profundidade-1);
            arr[i++] = arvore->CE->classificacao;
            n++;
        }
        if (arvore-> CC != NULL) {
            preencher_class(arvore-> CC,profundidade-1);
            arr[i++] = arvore-> CC->classificacao;
            n++;
        }
        if (arvore->CD != NULL) {
            preencher_class(arvore->CD,profundidade-1);
            arr[i++] = arvore->CD->classificacao;
            n++;
        }
        if (arvore->EE != NULL) {
            preencher_class(arvore->EE,profundidade-1);
            arr[i++] = arvore->EE->classificacao;
            n++;
        }
        if (arvore->DD != NULL) {
            preencher_class(arvore->DD,profundidade-1);
            arr[i++] = arvore->DD->classificacao;
            n++;
        }
        if (arvore->BE != NULL) {
            preencher_class(arvore->BE,profundidade-1);
            arr[i++] = arvore->BE->classificacao;
            n++;
        }
        if (arvore->BB != NULL) {
            preencher_class(arvore->BB,profundidade-1);
            arr[i++] = arvore->BB->classificacao;
            n++;
        }
        if (arvore->BD != NULL) {
            preencher_class(arvore->BD,profundidade-1);
            arr[i++] = arvore->BD->classificacao;
            n++;
        }
        if (profundidade % 2 != 0)
            arvore->classificacao = max8 (arr,n);
        else
            arvore->classificacao = min8 (arr,n);
    }
    else {
        float arr[8];
        int i = 0, n = 0;
        if (arvore->CE != NULL) {
            arr[i++] = arvore->CE->classificacao;
            n++;
        }
        if (arvore->CC != NULL) {
            arr[i++] = arvore->CC->classificacao;
            n++;
        }
        if (arvore->CD != NULL) {
            arr[i++] = arvore->CD->classificacao;
            n++;
        }
        if (arvore->EE != NULL) {
            arr[i++] = arvore->EE->classificacao;
            n++;
        }
        if (arvore->DD != NULL) {
            arr[i++] = arvore->DD->classificacao;
            n++;
        }
        if (arvore->BE != NULL) {
            arr[i++] = arvore->BE->classificacao;
            n++;
        }
        if (arvore->BB != NULL) {
            arr[i++] = arvore->BB->classificacao;
            n++;
        }
        if (arvore->BD != NULL) {
            arr[i++] = arvore->BD->classificacao;
            n++;
        }
        arvore->classificacao = max8(arr,n);
    }
    return 0;
}



void free_arvore (TREE arvore,int profundidade) {
    if (profundidade == 0)
        return;
    profundidade--;
    if (arvore -> CE != NULL) free_arvore (arvore -> CE,profundidade);
    if (arvore -> CC != NULL) free_arvore (arvore -> CC,profundidade);
    if (arvore -> CD != NULL) free_arvore (arvore -> CD,profundidade);
    if (arvore -> DD != NULL) free_arvore (arvore -> DD,profundidade);
    if (arvore -> BD != NULL) free_arvore (arvore -> BD,profundidade);
    if (arvore -> BB != NULL) free_arvore (arvore -> BB,profundidade);
    if (arvore -> BE != NULL) free_arvore (arvore -> BE,profundidade);
    if (arvore -> EE != NULL) free_arvore (arvore -> EE,profundidade);
    free (arvore);
}
