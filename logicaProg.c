int jogar(ESTADO *e, COORDENADA c) {
printf("jogar %d %d\n", c.coluna, c.linha);
e -> tab [c.coluna] [c.linha] = BRANCA;
return 1;
}
