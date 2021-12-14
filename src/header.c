#include "header.h"

// define caracteres para os desenhos que serao gerados
char BORDA_LATERAL = '|';
char BORDA_SUPINF = '-';
char ASTERISCO = '*';
char CRUZ = '+';

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
    int totalFiguras = qtd - 1;
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

        if (totalFiguras > 0) {
            qtdSoma = rand() % totalFiguras;
            totalFiguras -= qtdSoma;

        }

        if (totalFiguras > 0) {
            qtdX = rand() % totalFiguras;
            totalFiguras -= qtdX;

        }

        int qtdPir = totalFiguras;


        int numAsteriscos = 0;
        int numSoma = 0;
        int numX = 0;
        int numPir = 0;
        
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

        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaPiramide(i, j)){
                numPir++;
            }
        }while(numPir < qtdPir);
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
        case 6:
        do {
            i = rand() % (LIN-1);
            j = rand() % (COL-1);

            if(desenhaPiramide(i, j))
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

/*
 * x: linha inicial
 * y: coluna inicial
*/
int desenhaPiramide(int x, int y) {
    /*
     * 1 2 3 4 5      |  1 2 * 4 5
     * 6 7 8 9 10     |  6 * * * 10
     * 12 13 14 15 16 |  * * * * *
    */
    int isFreeToDraw = 0, rows = 3, cols = 5;
    int posMaxX = x + rows;
    int posMaxY = y + cols;
    for (int i = x; i < posMaxX; i+=1) {
        for (int j = y; j < posMaxY; j+=1) {
            if(checaChars(i, j) == 1) {
                isFreeToDraw = 1;
            } else {
                isFreeToDraw = 0;
            }
        }
    }

    if (isFreeToDraw) {
        for (int i = x; i < posMaxX; i+=1) {
            for (int j = y; j < posMaxY; j+=1) {
                if (i == x) { // desenha a primeira linha da piramide
                    if (j == posMaxY - 3) {
                        quadro[i][j] = ASTERISCO;
                    }
                } else if (i == posMaxX - 2 && (j != y && j != posMaxY - 1)) {
                    // desenha a segunda linha
                    quadro[i][j] = ASTERISCO;
                } else if (i == posMaxX - 1) {
                    // desenha a base, e ultima linha
                    quadro[i][j] = ASTERISCO;
                }
            }
        }
    }

   return isFreeToDraw;
}

int checaChars(int i, int j) {

    if (quadro[i][j] != BORDA_SUPINF &&
        quadro[i][j] != BORDA_LATERAL &&
        quadro[i][j] != CRUZ &&
        quadro[i][j] != ASTERISCO
        ) {
            
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
