int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[0-7]%[0-7]", col, lin) == 2) {COORDENADA coord = {*col -'0', *lin -'0'};
    jogar(e, coord);mostrar_tabuleiro(e);
    }
    return 1;
}

void mostrar_tabuleiro (ESTADO *e) {
    int linha,coluna;
    for (linha = 0; linha < 8; linha ++) {
        for (coluna = 0; coluna < 8; coluna ++) {
            if (e -> tab [0] [7]) putchar ('2');
            else if (e-> tab [7] [0]) putchar ('1');
            else if (e -> tab [linha] [coluna]  == VAZIO) putchar ('.') ;
            else if (e -> tab [linha] [coluna]  == BRANCA) putchar ('*');
            else putchar ('#');
        }
        printf ("\n");
    }
}
