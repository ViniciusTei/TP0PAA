#include "header.h"

int main(){

  int slct;
  int qtd;
  int controle;

  do {
      iniciaQuadro();
      printf("PROGRAMA GERADOR DE OBRA DE ARTE\n");
      printf("================================\n");
      printf("Escolha o tipo de figura a ser usada: \n");
      printf("1. Asterisco simples.\n");
      printf("2. Simbolo de soma com asteriscos.\n");
      printf("3. Letra X com asteriscos.\n");
      printf("4. Figuras aleatorias\n");
      printf("5. Jogo da velha\n");
      printf("Digite o tipo de figura desejada: ");
      scanf("%d", &slct);
      printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
      scanf("%d", &qtd);

      if(qtd <= 0){
          srand(time(NULL));
          qtd = rand() % 100;
      } else if ( qtd > 100){
          qtd = 100;
      }

      criaFigura(slct, qtd);
      imprime();

      printf("Deseja criar outro quadro?\n");
      printf("(1)Sim (2)Não: ");
      scanf("%d", &controle);

  } while(controle == 1);

  return 0;
}
