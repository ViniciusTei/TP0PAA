#include "header.h"

/* Funcao que cria um
 * quadro vazio.
 */
void iniciaQuadro(){
  int i, j;

  for(i = 0; i < LIN; i++){
    for(j = 0; j < COL; j++){
      if (i == 0 || i == LIN - 1) {
          quadro[i][j] = '-';
      } else if ((j == 0 || j == COL - 1) && (i != 0 || i != LIN - 1)) {
          quadro[i][j] = '|';
      } else {
          quadro[i][j] = ' ';
      }
    }
  }
}

/*
 * Metedo define o posicionamento da figura escolhida
 * e chama o metodo responsavel por verificar a posicao
 * e desenhar a figura no quadro
 * Params:
 *  slct: tipo de figura selecionada pelo usuario
 *  qtd: quatidade e figuras selecionadas pelo usuario
 */
void criaFigura(int slct, int qtd){
    int i, j;
    int numFiguras = 0;
    int num;
    int totalFiguras = qtd;
    int qtdAsterisco, qtdSoma, qtdX;

    srand(time(NULL));

    switch (slct) {
        case 1:
        //asterisco simples
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaAsterisco(i, j))
                numFiguras++;

        } while(numFiguras < qtd);
        break;
        case 2:
        //soma com asteriscos
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaSoma(i, j))
                numFiguras++;

        } while(numFiguras < qtd);
        break;
        case 3:
        //X com asteriscos
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaX(i, j))
                numFiguras++;

        } while(numFiguras < qtd);
        break;
        case 4:
        //Figuras aleatorias
        qtdAsterisco = rand() % totalFiguras;
        totalFiguras -= qtdAsterisco;
        qtdSoma = rand() % totalFiguras;
        totalFiguras -= qtdSoma;
        qtdX = totalFiguras;

        int numAsteriscos = 0;
        int numSoma = 0;
        int numX = 0;

        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaAsterisco(i, j)){
                numAsteriscos++;
            }
        } while(numAsteriscos < qtdAsterisco);
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaSoma(i, j)){
                numSoma++;
            }
        } while(numSoma < qtdSoma);
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaX(i, j)){
                numX++;
            }
        } while(numX < qtdX);
        break;
        case 5:
        //Jogo da velha com '+'
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaJogoDaVelha(i, j))
                numFiguras++;

        } while(numFiguras < qtd);
        break;
    }

}

int desenhaAsterisco(int i, int j){
    if (quadro[i][j] != '-' && quadro[i][j] != '|'
        && quadro[i][j+1] != '*' && quadro[i][j-1] != '*'
        && quadro[i+1][j] != '*' && quadro[i-1][j] != '*'
        && quadro[i-1][j+1] != '*' && quadro[i+1][j-1] != '*'
        && quadro[i+1][j+1] != '*' && quadro[i-1][j-1] != '*'){

        quadro[i][j] = '*';
        return 1;
    }
    return 0;
}

int desenhaSoma(int i, int j){
    if (quadro[i][j] != '-' && quadro[i][j] != '|'
        && quadro[i+1][j] != '|' && quadro[i-1][j] != '|'
        && quadro[i+1][j] != '-' && quadro[i-1][j] != '-'
        && quadro[i][j+1] != '-' && quadro[i][j-1] != '-'
        && quadro[i][j+1] != '|' && quadro[i][j-1] != '|'
        && quadro[i][j+1] != '*' && quadro[i][j-1] != '*'
        && quadro[i+1][j] != '*' && quadro[i-1][j] != '*'
        && quadro[i-1][j-1] != '|' && quadro[i-1][j+1] != '|'
        && quadro[i-1][j-1] != '-' && quadro[i-1][j+1] != '-'
        && quadro[i+1][j+1] != '-' && quadro[i+1][j-1] != '-'
        && quadro[i-1][j+1] != '|' && quadro[i-1][j-1] != '|'
        && quadro[i-1][j+1] != '*' && quadro[i+1][j-1] != '*'
        && quadro[i+1][j+1] != '*' && quadro[i-1][j-1] != '*'){

        quadro[i][j] = '*';
        quadro[i+1][j] = '*';
        quadro[i-1][j] = '*';
        quadro[i][j+1] = '*';
        quadro[i][j-1] = '*';

        return 1;
    }
    return 0;
}

int desenhaX(int i, int j){
    if (quadro[i][j] != '-' && quadro[i][j] != '|'
        && quadro[i-1][j-1] != '|' && quadro[i-1][j+1] != '|'
        && quadro[i-1][j-1] != '-' && quadro[i-1][j+1] != '-'
        && quadro[i+1][j+1] != '-' && quadro[i+1][j-1] != '-'
        && quadro[i-1][j+1] != '|' && quadro[i-1][j-1] != '|'
        && quadro[i-1][j+1] != '*' && quadro[i+1][j-1] != '*'
        && quadro[i+1][j+1] != '*' && quadro[i-1][j-1] != '*'
        && quadro[i+1][j] != '|' && quadro[i-1][j] != '|'
        && quadro[i+1][j] != '-' && quadro[i-1][j] != '-'
        && quadro[i][j+1] != '-' && quadro[i][j-1] != '-'
        && quadro[i][j+1] != '|' && quadro[i][j-1] != '|'
        && quadro[i][j+1] != '*' && quadro[i][j-1] != '*'
        && quadro[i+1][j] != '*' && quadro[i-1][j] != '*'){

        quadro[i][j] = '*';
        quadro[i+1][j-1] = '*';
        quadro[i-1][j+1] = '*';
        quadro[i+1][j+1] = '*';
        quadro[i-1][j-1] = '*';

        return 1;
    }
    return 0;
}

int desenhaJogoDaVelha(int i, int j){

    if (quadro[i][j] != '-' && quadro[i][j] != '|'
        && quadro[i][j+1] != '|' && quadro[i][j+1] != '+'
        && quadro[i+1][j] != '-' && quadro[i+1][j] != '+'
        && quadro[i+1][j+1] != '-' && quadro[i+1][j+1] != '|' 
        && quadro[i+1][j+1] != '+') {

            quadro[i][j] = '+';
            quadro[i][j+1] = '+';
            quadro[i+1][j] = '+';
            quadro[i+1][j+1] = '+';

            return 1;
        }
    return 0;
}

void imprime(){
    int i, j;

    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
}
