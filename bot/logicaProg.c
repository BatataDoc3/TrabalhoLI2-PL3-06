#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "logicaProg.h"
#include "arvores.h"

int jogada_valida_pecaBranca (ESTADO*e, COORDENADA c) {
    if (obter_estado_casa (e, c.linha+1, c.coluna) == '*' ||
       obter_estado_casa (e, c.linha, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha + 1, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna) == '*' ||
       obter_estado_casa (e, c.linha, c.coluna - 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna - 1) == '*' ||
       obter_estado_casa (e, c.linha - 1, c.coluna + 1) == '*' ||
       obter_estado_casa (e, c.linha + 1, c.coluna - 1) == '*')
        return 1;
    else return 0;
}

int jogada_valida (ESTADO *e , COORDENADA c) {
    if (c.linha < 0 || c.linha > 7) return (-1);
    if (c.coluna < 0 || c.coluna > 7)  return (-1);
    if (jogada_valida_pecaBranca(e, c) == 1) {
        if (obter_estado_casa (e, c.linha,c.coluna) == '#')
            return (-1);
        else return 1;
    }
    else return (-1);
}

int casa_Preta (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (obter_estado_casa (e, linha + 1, coluna)== '#' &&
        obter_estado_casa (e, linha, coluna + 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna) == '#' &&
        obter_estado_casa (e, linha, coluna - 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
        obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
        obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
        obter_estado_casa (e, linha + 1, coluna + 1) == '#' )
        return 1;
    else if (linha == 0 && coluna == 0 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (linha == 0 && coluna == 7 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 0 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (linha == 7 && coluna == 7 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#')
        return 1;
    else if (linha == 7 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#')
        return 1;
    else if (linha == 0 &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#' &&
            obter_estado_casa (e, linha + 1, coluna + 1) == '#')
        return 1;
    else if (coluna == 0 &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna +1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna + 1) == '#' &&
            obter_estado_casa (e, linha, coluna + 1) == '#')
        return 1;
    else if (coluna == 7 &&
            obter_estado_casa (e, linha, coluna - 1) == '#' &&
            obter_estado_casa (e, linha - 1, coluna) == '#' &&
            obter_estado_casa (e, linha + 1, coluna) == '#' &&
            obter_estado_casa (e, linha - 1, coluna - 1) == '#' &&
            obter_estado_casa (e, linha + 1, coluna - 1) == '#')
        return 1;
    else return 0;
}


int rodeado_pretas (ESTADO *e, COORDENADA c){
    int x;
    x = casa_Preta (e,c);
    return x;
}


int jogo_finalizado (ESTADO *e, COORDENADA c) {
    int colunaJog, linhaJog;
    int r = 0;
    colunaJog = c.coluna;
    linhaJog = c.linha;
    if (obter_numero_de_jogadas(e) == 32 || (colunaJog == 0 && linhaJog == 0) ||
        (colunaJog == 7 && linhaJog == 7) || rodeado_pretas(e, c)){
        r = 1;
    }
    return r;
}

int parabens_jogador (ESTADO *e){
    int x=0;
    if (obter_estado_casa (e, 7, 7) == '*') x = 2;
    else if (obter_estado_casa(e, 0, 0) == '*') x = 1;
    else {
        if (obter_jogador_atual(e) == 1) x = 2;
        else if (obter_jogador_atual(e) == 2) x = 1;}
    return x;
}


int jogo_finalizado_bot (ESTADO *e, COORDENADA c) {
    int r = 0;
    if (obter_jogador_atual (e) == 1) {
         if (obter_numero_de_jogadas (e) == 32 || (c.coluna == 0 && c.linha == 0) ||rodeado_pretas(e, c))
             r = 1;
    }
    else if (obter_numero_de_jogadas (e) == 32 || (c.coluna == 7 && c.linha == 7) ||rodeado_pretas(e, c))
             r = 1;
    return r;
}

int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogada_valida (e, c) == 1) {
        if (devolve_posx(e) != 50) {
            posicao(e);
            atualiza_posx(e,50);
        }
        atualizar_casa_preta (e);
        atualizar_casa (e, c);
        atualizar_jogadas (e, c);
        atualizar_num_jogadas (e);
        atualizar_jogador_atual (e);
        if (jogo_finalizado (e, c) == 1){
            x = parabens_jogador (e);
            atualiza_num_jogadas_fim (e);
            return 0;
        }
        return 1;
    }
    else {
        return 0;
    }
}

int jogada_valida_bot (ESTADO *e ,int linha,int coluna) {
    if (linha < 0 || linha > 7) return (-1);
    if (coluna < 0 || coluna > 7)  return (-1);
    if (obter_estado_casa(e,linha,coluna) == '#')
        return (-1);
    else return 1;
}

float classificacao (COORDENADA c,ESTADO *e) {
    CLASSIFICACAO *f = (CLASSIFICACAO *) calloc(1,sizeof(CLASSIFICACAO));
    *f = (CLASSIFICACAO){.clas1 = {{7,6,5,4,3,2,1,0},
                                   {6,5,4,3,2,1,0,-1},
                                   {5,4,3,2,1,0,-1,-2},
                                   {4,3,2,1,0,-1,-2,-3},
                                   {3,2,1,0,-1,-2,-3,-4},
                                   {2,1,0,-1,-2,-3,-4,-5},
                                   {1,0,-1,-2,-3,-4,-5,-6},
                                   {0,-1,-2,-3,-4,-5,-6,-1000}}};
    if (obter_jogador_atual(e)==1)
        return f->clas1 [c.linha] [c.coluna];
    else
        return (- (f->clas1 [c.linha] [c.coluna]));
}

COORDENADA jogo_finalizado_arvore (ESTADO *e,TREE arvore){
    COORDENADA c;
    c.linha = 10;
    c.coluna = 10;
    atualizar_casa_preta(e);
    if (arvore -> BB != NULL && jogo_finalizado_bot (e,arvore->BB->valor) == 1) c = arvore->BB->valor;
    if (arvore -> BE != NULL && jogo_finalizado_bot (e,arvore->BE->valor) == 1) c = arvore->BE->valor;
    if (arvore -> BD != NULL && jogo_finalizado_bot (e,arvore->BD->valor) == 1) c = arvore->BD->valor;
    if (arvore -> EE != NULL && jogo_finalizado_bot (e,arvore->EE->valor) == 1) c = arvore->EE->valor;
    if (arvore -> DD != NULL && jogo_finalizado_bot (e,arvore->DD->valor) == 1) c = arvore->DD->valor;
    if (arvore -> CE != NULL && jogo_finalizado_bot (e,arvore->CE->valor) == 1) c = arvore->CE->valor;
    if (arvore -> CC != NULL && jogo_finalizado_bot (e,arvore->CC->valor) == 1) c = arvore->CC->valor;
    if (arvore -> CD != NULL && jogo_finalizado_bot (e,arvore->CD->valor) == 1) c = arvore->CD->valor;
    atualizar_casa_branca(e,arvore->valor);
    return c;
}

COORDENADA verifica_melhor_pos (TREE arvore){
    COORDENADA c;
    c.linha = 50;
    c.coluna = 50;
    if (arvore -> CE != NULL)
        if (arvore->classificacao == arvore->CE->classificacao)  c = arvore->CE->valor;
    if (arvore -> CC != NULL)
        if (arvore->classificacao == arvore->CC->classificacao)  c = arvore->CC->valor;
    if (arvore -> CD != NULL)
        if (arvore->classificacao == arvore->CD->classificacao)  c = arvore->CD->valor;
    if (arvore -> EE != NULL)
        if (arvore->classificacao == arvore->EE->classificacao)  c = arvore->EE->valor;
    if (arvore -> DD != NULL)
        if (arvore->classificacao == arvore->DD->classificacao)  c = arvore->DD->valor;
    if (arvore -> BE != NULL)
        if (arvore->classificacao == arvore->BE->classificacao)  c = arvore->BE->valor;
    if (arvore -> BB != NULL)
        if (arvore->classificacao == arvore->BB->classificacao)  c = arvore->BB->valor;
    if (arvore -> BD != NULL)
        if (arvore->classificacao == arvore->BD->classificacao)  c = arvore->BD->valor;
    return c;
}


int bloqueada (ESTADO *e, int linha, int coluna) {
    flood_fill(e, linha, coluna);
    if (obter_cor(e, 0, 0) == NAO_PINTADA && obter_cor(e, 7, 7) == NAO_PINTADA )
        return 1;
    else return 0;
}


COORDENADA conta_mais_casas (ESTADO *e, COORDENADA c) {
    preenche_tab_cor(e);
    int i = 0;
    atualizar_casa_preta(e);
    COORDENADA cord = c;
    if (jogada_valida_bot(e, cord.linha + 1, cord.coluna) == 1 && conta_casas_livres(e, c.linha , c.coluna - 1) > i) {
        i = conta_casas_livres(e, c.linha + 1,c.coluna);
        c = cord;
        c.linha = c.linha +1;
        c.coluna = c.coluna ;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha + 1, cord.coluna - 1) == 1&& conta_casas_livres(e, c.linha + 1, c.coluna - 1) > i) {
        i = conta_casas_livres(e, c.linha + 1, c.coluna);
        c = cord;
        c.linha = c.linha +1;
        c.coluna = c.coluna - 1;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha + 1, cord.coluna + 1) == 1 && conta_casas_livres(e, c.linha + 1, c.coluna + 1) > i) {
        i = conta_casas_livres(e, c.linha + 1, c.coluna + 1);
        c = cord;
        c.linha = c.linha +1;
        c.coluna = c.coluna + 1;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha , cord.coluna + 1) == 1 && conta_casas_livres(e, c.linha , c.coluna + 1) >i) {
        i = conta_casas_livres(e, c.linha , c.coluna + 1);
        c = cord;
        c.linha = c.linha ;
        c.coluna = c.coluna + 1 ;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha , cord.coluna - 1) == 1 && conta_casas_livres(e, c.linha , c.coluna - 1) > i) {
        i = conta_casas_livres(e, c.linha , c.coluna - 1);
        c = cord;
        c.linha = c.linha ;
        c.coluna = c.coluna - 1 ;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna) == 1 && conta_casas_livres (e, c.linha - 1, c.coluna) > i) {
        i = conta_casas_livres(e, c.linha - 1, c.coluna);
        c = cord;
        c.linha = c.linha - 1;
        c.coluna = c.coluna ;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna - 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna - 1) > i ) {
        i = conta_casas_livres(e, c.linha - 1, c.coluna - 1);
        c = cord;
        c.linha = c.linha - 1;
        c.coluna = c.coluna - 1;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna + 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna + 1) > i) {
        i = conta_casas_livres(e, c.linha - 1, c.coluna + 1);
        c = cord;
        c.linha = c.linha - 1;
        c.coluna = c.coluna + 1;
        preenche_tab_cor(e);
    }
    preenche_tab_cor(e);
    atualizar_casa_branca(e, cord);
    return c ;
}


COORDENADA paridade (ESTADO *e, COORDENADA c) {
    preenche_tab_cor(e);
    atualizar_casa_preta(e);
    COORDENADA cord = c;
    if (jogada_valida_bot(e, cord.linha , cord.coluna - 1) == 1 && conta_casas_livres(e, c.linha + 1, c.coluna) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha ;
        c.coluna = c.coluna - 1;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha , cord.coluna + 1) == 1&& conta_casas_livres(e, c.linha + 1, c.coluna - 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha ;
        c.coluna = c.coluna + 1;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha + 1, cord.coluna + 1) && conta_casas_livres(e, c.linha + 1, c.coluna + 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha +1;
        c.coluna = c.coluna + 1;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha + 1 , cord.coluna ) == 1 && conta_casas_livres(e, c.linha , c.coluna + 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha + 1 ;
        c.coluna = c.coluna  ;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha + 1, cord.coluna - 1) == 1 && conta_casas_livres(e, c.linha , c.coluna - 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha + 1;
        c.coluna = c.coluna - 1 ;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna) == 1 && conta_casas_livres (e, c.linha - 1, c.coluna) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha - 1;
        c.coluna = c.coluna ;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna - 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna - 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha - 1;
        c.coluna = c.coluna - 1;
        return  c ;
    }
    preenche_tab_cor(e);
    if (jogada_valida_bot(e, cord.linha - 1, cord.coluna + 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna + 1) % 2 != 0) {
        atualizar_casa_branca(e, cord);
        c.linha = c.linha - 1;
        c.coluna = c.coluna + 1;
        return  c ;
    }
    preenche_tab_cor(e);
    atualizar_casa_branca(e, cord);
    c = conta_mais_casas (e, cord);
    return c;
}

COORDENADA verifica_se_vai_bloquear (ESTADO *e, COORDENADA c) {
    COORDENADA cord;
    atualizar_casa_preta(e);
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha + 1, c.coluna) == 1) {
        preenche_tab_cor(e);
        if ( jogada_valida_bot (e,c.linha + 1, c.coluna) == 1 && conta_casas_livres(e, c.linha + 1, c.coluna ) % 2 != 0 ) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha + 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha + 1, c.coluna + 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha + 1, c.coluna + 1) == 1 && conta_casas_livres(e, c.linha + 1, c.coluna + 1 ) % 2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha + 1;
            c.coluna =c.coluna + 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha + 1, c.coluna - 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha + 1, c.coluna - 1) == 1&& conta_casas_livres(e, c.linha + 1, c.coluna - 1) % 2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha + 1;
            c.coluna =c.coluna - 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha , c.coluna - 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha , c.coluna - 1) == 1&& conta_casas_livres(e, c.linha , c.coluna -1 ) % 2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.coluna =c.coluna - 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha , c.coluna  + 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha , c.coluna + 1) == 1 && conta_casas_livres(e, c.linha , c.coluna + 1) % 2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.coluna =c.coluna + 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha - 1, c.coluna) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha - 1, c.coluna) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna) % 2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha - 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha - 1, c.coluna + 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha - 1, c.coluna + 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna + 1) %2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha - 1;
            c.coluna =c.coluna + 1;
            return c;
        }
    }
    preenche_tab_cor(e);
    if (bloqueada(e, c.linha - 1, c.coluna - 1) == 1) {
        preenche_tab_cor(e);
        if (jogada_valida_bot (e,c.linha - 1, c.coluna - 1) == 1 && conta_casas_livres(e, c.linha - 1, c.coluna - 1) %2 != 0) {
            atualizar_casa_branca(e,c);
            preenche_tab_cor(e);
            c.linha = c.linha - 1;
            c.coluna =c.coluna - 1;
            return c;
        }
    }
    atualizar_casa_branca(e,c);
    return c;
}

void jog2 (ESTADO *e) {
    if (devolve_posx(e) != 50) {
        posicao(e);
        atualiza_posx(e, 50);
    }
    TREE arvore;
    int profundidade = 3;
    arvore = criar_arvore(e, e->ultima_jogada.linha, e->ultima_jogada.coluna, profundidade + 1);
    preencher_class(arvore, profundidade);
    COORDENADA c, cord;
    cord = ultima_jogada(e);
    c = jogo_finalizado_arvore(e, arvore);
    preenche_tab_cor(e);
    if (c.linha != 10) {
        jogar(e, c);
    }
    else {
        COORDENADA b = cord ;
        b = (verifica_se_vai_bloquear(e, cord) );
        preenche_tab_cor(e);
        if (bloqueada(e, cord.linha, cord.coluna) == 1) {
            preenche_tab_cor(e);
            cord = paridade(e, cord);
            jogar(e, cord);
        }
        else if (b.linha != cord.linha || b.coluna != cord.coluna) {
            jogar(e, b);
        }
        else {
            c = verifica_melhor_pos(arvore);
            jogar(e, c);
        }
        free_arvore(arvore, profundidade + 1);
    }
}

