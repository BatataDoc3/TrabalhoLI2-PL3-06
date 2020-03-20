int casa_Preta (ESTADO*e, COORDENADA c) {
    int linha,coluna;
    linha = c.linha;
    coluna = c.coluna;
    if (e -> tab [linha + 1] [coluna] == '#' &&
        e -> tab [linha] [coluna + 1] == '#' &&
        e -> tab [linha - 1] [coluna] == '#' &&
        e -> tab [linha] [coluna - 1] == '#' &&
        e -> tab [linha - 1] [coluna - 1] == '#' &&
        e -> tab [linha - 1] [coluna + 1] == '#' &&
        e -> tab [linha + 1] [coluna - 1] == '#' &&
        e -> tab [linha + 1] [coluna + 1] == '#' )
        return 1;
        else if (linha == 0 && coluna == 0 &&
                e -> tab [linha + 1] [coluna] == '#' &&
                e -> tab [linha + 1] [coluna + 1] == '#' &&
                e -> tab [linha] [coluna + 1] == '#')
            return 1;
                else if (linha == 0 && coluna == 7 &&
                        e -> tab [linha + 1] [coluna] == '#' &&
                        e -> tab [linha + 1] [coluna - 1] == '#' &&
                        e -> tab [linha] [coluna - 1] == '#')
                    return 1;
                    else if (linha == 7 && coluna == 0 &&
                             e -> tab [linha - 1] [coluna] == '#' &&
                             e -> tab [linha - 1] [coluna + 1] == '#' &&
                             e -> tab [linha] [coluna + 1] == '#')
                        return 1;
                        else if (linha == 7 && coluna == 7 &&
                                 e -> tab [linha - 1] [coluna] == '#' &&
                                 e -> tab [linha - 1] [coluna - 1] == '#' &&
                                 e -> tab [linha] [coluna - 1] == '#')
                        return 1;
                        else if (linha == 7 &&
                                 e -> tab [linha - 1] [coluna] == '#' &&
                                 e -> tab [linha - 1] [coluna - 1] == '#' &&
                                 e -> tab [linha] [coluna - 1] == '#' &&
                                 e -> tab [linha] [coluna + 1] == '#' &&
                                 e -> tab [linha - 1] [coluna + 1] == '#')
                            return 1;
                            else if (linha == 0 &&
                                     e -> tab [linha + 1] [coluna] == '#' &&
                                     e -> tab [linha + 1] [coluna - 1] == '#' &&
                                     e -> tab [linha] [coluna - 1] == '#' &&
                                     e -> tab [linha] [coluna + 1] == '#' &&
                                     e -> tab [linha + 1] [coluna + 1] == '#')
                                return 1;
                                else if (coluna == 0 &&
                                         e -> tab [linha - 1] [coluna] == '#' &&
                                         e -> tab [linha + 1] [coluna] == '#' &&
                                         e -> tab [linha + 1] [coluna +1] == '#' &&
                                         e -> tab [linha - 1] [coluna + 1] == '#' &&
                                         e -> tab [linha] [coluna + 1] == '#')
                                    return 1;
                                else if (coluna == 7 &&
                                         e -> tab [linha] [coluna - 1] == '#' &&
                                         e -> tab [linha - 1] [coluna] == '#' &&
                                         e -> tab [linha + 1] [coluna] == '#' &&
                                         e -> tab [linha - 1] [coluna - 1] == '#' &&
                                         e -> tab [linha + 1] [coluna - 1] == '#')
                                    return 1;
    else return 0;
}
