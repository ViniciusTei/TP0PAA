#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define COL 80 //numero de colunas do quadro
#define LIN 20 //numero de linhas do quadro

char quadro[LIN][COL]; // variavel global q sera utilizada como quadro

void iniciaQuadro();
void criaFigura(int slct, int qtd);
int desenhaAsterisco(int i, int j);
int desenhaSoma(int i, int j);
int desenhaX(int i, int j);
int desenhaJogoDaVelha(int i, int j);
int desenhaPiramide(int x, int y);
int checaChars(int i, int j);
int verificaPosicoes(int i, int j);
void imprime();
