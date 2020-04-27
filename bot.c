#include "bot.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "estrutura.h"
#include "logicaProg.h"
#include <math.h>

LISTA poe_lista (LISTA L, COORDENADA *c, ESTADO *e) {
    if (e->tab[c->linha][c->coluna] == VAZIO) {
        L = insere_cabeca (L, &c);
    }
    return L ;
}

int comprimentoLista (LISTA l){
    int i = 0;
    while (l!=NULL) {
        i++;
        l = l->proximo;
    }
    return i;
}

void jogs (ESTADO *e) {
    if (e->posx != 50) {
        posicao(e);
        e->posx = 50;
    }
    COORDENADA c;
    COORDENADA *c1 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c2 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c3 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c4 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c5 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c6 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c7 = (COORDENADA *) malloc (sizeof(COORDENADA));
    COORDENADA *c8 = (COORDENADA *) malloc (sizeof(COORDENADA));
    c = e->ultima_jogada;
    c1->linha = c.linha + 1;
    c1->coluna = c.coluna - 1;
    c2->linha = c.linha + 1;
    c2->coluna = c.coluna;
    c3->linha = c.linha + 1;
    c3->coluna = c.coluna + 1;
    c4->linha = c.linha;
    c4->coluna = c.coluna - 1;
    c5->linha = c.linha;
    c5->coluna = c.coluna + 1;
    c6->linha = c.linha - 1;
    c6->coluna = c.coluna - 1;
    c7->linha = c.linha - 1;
    c7->coluna = c.coluna;
    c8->linha = c.linha - 1;
    c8->coluna = c.coluna + 1;
    COORDENADA *vizinhas[8] = {c1, c2, c3, c4, c5, c6, c7, c8};
    int i = 0;
    LISTA livres = malloc(sizeof(NODO));
    while (i < 8) {
        if (jogada_valida(e, *vizinhas [i]) == 1)
            livres = insere_cabeca(livres, vizinhas[i]) ;
        i++;
    }
    int comprimento_da_lista = comprimentoLista(livres) - 1;
    srandom(time(NULL));
    int x = random() % comprimento_da_lista ;
    i = 0;
    while (i != x) {
        livres = livres->proximo;
        i++;
    }
    COORDENADA *cord = (COORDENADA *) devolve_cabeca(livres);
    jogar(e, *cord);
    free (c1); free (c2) ; free (c3); free (c4) ; free (c5); free (c6) ; free (c7); free (c8);
}

int casa_valida_bot (int linha,int coluna,ESTADO *e){
    int r = 0;
    if ((linha  >= 0 && linha  < 8 && coluna >= 0 && coluna  < 8)
        && (obter_estado_casa(e,coluna ,linha ) != PRETA))
        r = 1;
    //printf ("%d", r);
    return r;
}


TREE singular (int linha, int coluna){
    TREE r;
    COORDENADA c;
    c.linha = linha;
    c.coluna = coluna;
    r = malloc (sizeof (struct nodoArv));
    r->valor = c;
    //if (c.coluna > 7 || c.coluna < 0 || c.linha < 0 || c.linha > 7)
    //  return NULL;
    r->CE = r->CC = r->CD = r->DD = r->BD = r->BB = r->BE = r->EE= NULL;
    return r;
}

TREE arvore_1nivel (int linha, int coluna,ESTADO *e) {
    COORDENADA cord;
    cord.linha = linha;
    cord.coluna = coluna;
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce , cc , cd , dd , ee ,be ,bb , bd;
    if (casa_valida_bot (cord.linha + 1,cord.coluna - 1,e) == 1)
        ce = singular (cord.linha + 1,cord.coluna - 1);
    else
        ce = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna,e) == 1)
        cc = singular (cord.linha + 1,cord.coluna);
    else
        cc = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna + 1,e) == 1)
        cd = singular (cord.linha + 1,cord.coluna + 1);
    else
        cd = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna + 1,e) == 1)
        dd = singular (cord.linha,cord.coluna + 1);
    else
        dd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna + 1,e) == 1)
        bd = singular (cord.linha - 1,cord.coluna + 1);
    else
        bd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna,e) == 1)
        bb = singular (cord.linha - 1,cord.coluna);
    else
        bb = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna - 1,e) == 1)
        be = singular (cord.linha - 1,cord.coluna - 1);
    else
        be = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna - 1,e) == 1)
        ee = singular (cord.linha,cord.coluna - 1);
    else
        ee = NULL;
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

TREE arvore_2nivel (int linha, int coluna,ESTADO *e){
    COORDENADA cord;
    cord.linha = linha;
    cord.coluna = coluna;
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce , cc , cd , dd , ee ,be ,bb , bd;
    if (casa_valida_bot (cord.linha + 1,cord.coluna - 1,e) == 1)
        ce = arvore_1nivel (cord.linha + 1,cord.coluna - 1,e);
    else
        ce = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna,e) == 1)
        cc = arvore_1nivel (cord.linha + 1,cord.coluna,e);
    else
        cc = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna + 1,e) == 1)
        cd = arvore_1nivel (cord.linha + 1,cord.coluna + 1,e);
    else
        cd = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna + 1,e) == 1)
        dd = arvore_1nivel (cord.linha,cord.coluna + 1,e);
    else
        dd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna + 1,e) == 1)
        bd = arvore_1nivel (cord.linha - 1,cord.coluna + 1,e);
    else
        bd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna,e) == 1)
        bb = arvore_1nivel (cord.linha - 1,cord.coluna,e);
    else
        bb = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna - 1,e) == 1)
        be = arvore_1nivel (cord.linha - 1,cord.coluna - 1,e);
    else
        be = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna - 1,e) == 1)
        ee = arvore_1nivel (cord.linha,cord.coluna - 1,e);
    else
        ee = NULL;
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

TREE arvore_3nivel (ESTADO *e){
    COORDENADA cord = e -> ultima_jogada;
    TREE arvore = malloc (sizeof(struct nodoArv));
    TREE ce , cc , cd , dd , ee ,be ,bb , bd;
    if (casa_valida_bot (cord.linha + 1,cord.coluna - 1,e) == 1)
        ce = arvore_2nivel (cord.linha + 1,cord.coluna - 1,e);
    else
        ce = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna,e) == 1)
        cc = arvore_2nivel (cord.linha + 1,cord.coluna,e);
    else
        cc = NULL;
    if (casa_valida_bot (cord.linha + 1,cord.coluna + 1,e) == 1)
        cd = arvore_2nivel (cord.linha + 1,cord.coluna + 1,e);
    else
        cd = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna + 1,e) == 1)
        dd = arvore_2nivel (cord.linha,cord.coluna + 1,e);
    else
        dd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna + 1,e) == 1)
        bd = arvore_2nivel (cord.linha - 1,cord.coluna + 1,e);
    else
        bd = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna,e) == 1)
        bb = arvore_2nivel (cord.linha - 1,cord.coluna,e);
    else
        bb = NULL;
    if (casa_valida_bot (cord.linha - 1,cord.coluna - 1,e) == 1)
        be = arvore_2nivel (cord.linha - 1,cord.coluna - 1,e);
    else
        be = NULL;
    if (casa_valida_bot (cord.linha,cord.coluna - 1,e) == 1)
        ee = arvore_2nivel (cord.linha,cord.coluna - 1,e);
    else
        ee = NULL;
    arvore -> valor = cord;
    arvore -> CE = ce;
    arvore -> CC = cc;
    arvore -> CD = cd;
    arvore -> DD = dd;
    arvore -> BD = bd;
    arvore -> BB = bb;
    arvore -> BE = be;
    arvore -> EE = ee;
    return arvore;
}

int jogada_valida_bot (ESTADO *e , COORDENADA c) {
    if (c.linha < 0 || c.linha > 7) return (-1);
    if (c.coluna < 0 || c.coluna > 7)  return (-1);
    if (devolve_posicao(e,c.linha,c.coluna) == '#')
        return (-1);
    else return 1;
}

float classificacao (COORDENADA c,ESTADO *e) {
    float clas;
    if (jogada_valida_bot(e,c) == 1){
        if (obter_jogador_atual(e)==1)
            clas = sqrt (pow(c.coluna,2) + pow(c.linha,2));
        else
            clas = sqrt (pow(7 - c.coluna,2) + pow(7-c.linha,2));
    }
    else {
        clas = 1000;
        // printf ("ERRADO \n");
    }
    //printf ("%f\n",clas);
    return clas;
}

COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore){
    COORDENADA c;
    c.linha = 10;
    c.coluna = 10;
    atualizar_casa_preta(e);
    if (arvore -> BB != NULL && jogo_finalizado_bot (e,arvore->BB->valor)==1) c = arvore->BB->valor;
    if (arvore -> BE != NULL && jogo_finalizado_bot (e,arvore->BE->valor)==1) c = arvore->BE->valor;
    if (arvore -> BD != NULL && jogo_finalizado_bot (e,arvore->BD->valor)==1) c = arvore->BD->valor;
    if (arvore -> EE != NULL && jogo_finalizado_bot (e,arvore->EE->valor)==1) c = arvore->EE->valor;
    if (arvore -> DD != NULL && jogo_finalizado_bot (e,arvore->DD->valor)==1) c = arvore->DD->valor;
    if (arvore -> CE != NULL && jogo_finalizado_bot (e,arvore->CE->valor)==1) c = arvore->CE->valor;
    if (arvore -> CC != NULL && jogo_finalizado_bot (e,arvore->CC->valor)==1) c = arvore->CC->valor;
    if (arvore -> CD != NULL && jogo_finalizado_bot (e,arvore->CD->valor)==1) c = arvore->CD->valor;
    e -> tab [arvore->valor.linha] [arvore->valor.coluna] = BRANCA;
    return c;
}


float analisa_1nivel (TREE arvore,ESTADO *e){
    //COORDENADA c = arvore -> CE -> valor ;
    float x = 1000;
    //printf ("\n%d %d \n", c.coluna , c.linha);
    if (arvore -> CE != NULL) {
        if (classificacao(arvore->CE->valor,e) < x) x = classificacao (arvore->CE->valor,e);
    }
    if (arvore -> BD != NULL) {
        if (classificacao(arvore->BD->valor,e) < x) x = classificacao (arvore->BD->valor,e);
    }
    if (arvore -> BE != NULL) {
        if (classificacao(arvore->BE->valor,e) < x) x = classificacao (arvore->BE->valor,e);
    }
    if (arvore -> EE != NULL) {
        if (classificacao(arvore->EE->valor,e) < x) x = classificacao (arvore->EE->valor,e);
    }
    if (arvore -> DD != NULL) {
        if (classificacao(arvore->DD->valor,e) < x) x = classificacao (arvore->DD->valor,e);
    }
    if (arvore -> BB != NULL) {
        if (classificacao(arvore->BB->valor,e) < x) x = classificacao (arvore->BB->valor,e);
    }
    if (arvore -> CC != NULL) {
        if (classificacao(arvore->CC->valor,e) < x) x = classificacao (arvore->CC->valor,e);
    }
    if (arvore -> CD != NULL) {
        if (classificacao(arvore->CD->valor,e) < x) x = classificacao (arvore->CD->valor,e);
    }
    return x;
}

float analisa_2nivel (TREE arvore,ESTADO *e) { //FIXME  mudar para 2nivel
    float pior = 0;
    if (arvore -> CE != NULL) {
        if (analisa_1nivel(arvore->CE, e) > pior)
            pior = analisa_1nivel(arvore->CE, e);
    }
    if (arvore -> CC != NULL) {
        if (analisa_1nivel(arvore->CC,e) > pior)
            pior = analisa_1nivel(arvore->CC,e);
    }
    if (arvore -> CD != NULL) {
        if (analisa_1nivel(arvore->CD,e) > pior)
            pior = analisa_1nivel(arvore->CD,e);
    }
    if (arvore -> EE != NULL) {
        if (analisa_1nivel(arvore->EE,e) > pior)
            pior = analisa_1nivel(arvore->EE,e);
    }
    if (arvore -> DD != NULL) {
        if (analisa_1nivel(arvore->DD,e) > pior)
            pior = analisa_1nivel(arvore->DD,e);
    }
    if (arvore -> BE != NULL) {
        if (analisa_1nivel(arvore->BE,e) > pior)
            pior = analisa_1nivel(arvore->BE,e);
    }
    if (arvore -> BB != NULL) {
        if (analisa_1nivel(arvore->BB,e) > pior)
            pior = analisa_1nivel(arvore->BB,e);
    }
    if (arvore -> BD != NULL) {
        if (analisa_1nivel(arvore->BD,e) > pior)
            pior = analisa_1nivel(arvore->BD,e);
    }
    return pior;
}

COORDENADA verifica_melhor_pos (ESTADO *e, TREE arvore){
    float melhor = 1000;
    COORDENADA c_melhor ;
    if (arvore -> CE != NULL) {
        if (analisa_2nivel(arvore->CE, e) < melhor && classificacao(arvore->CE->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->CE, e);
            c_melhor = arvore->CE->valor;
        }
    }
    if (arvore -> CC != NULL) {
        if (analisa_2nivel(arvore->CC, e) < melhor && classificacao(arvore->CC->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->CC, e);
            c_melhor = arvore->CC->valor;
        }
    }
    if (arvore -> CD != NULL) {
        if (analisa_2nivel(arvore->CD, e) < melhor && classificacao(arvore->CD->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->CD, e);
            c_melhor = arvore->CD->valor;
        }
    }
    if (arvore -> EE != NULL) {
        if (analisa_2nivel(arvore->EE, e) < melhor && classificacao(arvore->EE->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->EE, e);
            c_melhor = arvore->EE->valor;
        }
    }
    if (arvore -> DD != NULL) {
        if (analisa_2nivel(arvore->DD, e) < melhor && classificacao(arvore->DD->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->DD, e);
            c_melhor = arvore->DD->valor;
        }
    }
    if (arvore -> BE != NULL) {
        if (analisa_2nivel(arvore->BE, e) < melhor && classificacao(arvore->BE->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->BE, e);
            c_melhor = arvore->BE->valor;
        }
    }
    if (arvore -> BB != NULL) {
        if (analisa_2nivel(arvore->BB, e) < melhor && classificacao(arvore->BB->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->BB, e);
            c_melhor = arvore->BB->valor;
        }
    }
    if (arvore -> BD != NULL) {
        if (analisa_2nivel(arvore->BD, e) < melhor && classificacao(arvore->BD->valor, e) != 1000) {
            melhor = analisa_2nivel(arvore->BD, e);
            c_melhor = arvore->BD->valor;
        }
    }
    return c_melhor;
}

void jog2 (ESTADO *e){
    TREE arvore;
    arvore = arvore_3nivel(e);
    COORDENADA c;
    c = jogo_finalizado_arvore (e,arvore);
    if (c.linha != 10 ){
        jogar (e,c);
    }
    else {
        c = verifica_melhor_pos(e,arvore);
        jogar (e,c);
        free (arvore);
    }
}
