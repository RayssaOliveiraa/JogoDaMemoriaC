#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posicao_dos_numeros[4][4];
int contador_de_pares[9][1];
int tabuleiro[4][4];
int vetor_salvar[4][4];
int cenario_atual;
int vetor_status_atual[4][4];

void printar_vetorsalvo()
{
  printf("\n\n");
  for(int linha = 0; linha < 4; linha++)
  {
    for(int coluna = 0; coluna < 4;coluna++)
    {
      printf("%i ", vetor_salvar[linha][coluna]);
    }
    printf("\n");
  }
}

/*Vetor que imprime as peças digitadas na tela*/ 
void printar_status_atual(int x, int y, int a, int b)
{
  printf("\n");
  for(int linha = 0; linha < 4; linha++)
  {
    for(int coluna = 0; coluna < 4;coluna++)
    {
      vetor_status_atual[linha][coluna] = vetor_salvar[linha][coluna];
    }
  }
  for(int linha = 0; linha < 4; linha++)
  {
    for(int coluna = 0; coluna < 4;coluna++)
    {
      if(vetor_status_atual[x][y] == 0)
      {
        vetor_status_atual[x][y] = posicao_dos_numeros[x][y];
      }
      if(vetor_status_atual[a][b] == 0)
      {
        vetor_status_atual[a][b] = posicao_dos_numeros[a][b];
      }
      printf("%i ", vetor_status_atual[linha][coluna]);
    }
    printf("\n");
  }
  if(posicao_dos_numeros[x][y] != posicao_dos_numeros[a][b])
  {
    vetor_status_atual[x][y] = 0;
    vetor_status_atual[a][b] = 0;
  }
}

int main(void) {

srand(time(NULL));

/*Gerar numeros aleatórios e alocar dentro da matriz no maximo 2x*/
 for(int linha = 0; linha < 4; linha++)
 {
  for(int coluna = 0; coluna < 4;)
  {
    int num_aleatorio = 1 + rand() % 8;
    if(posicao_dos_numeros[linha][coluna] == 0 && contador_de_pares[num_aleatorio][0] < 2)
    {
      posicao_dos_numeros[linha][coluna] = num_aleatorio;
      printf("%i ", posicao_dos_numeros[linha][coluna]);
      coluna++;
      contador_de_pares[num_aleatorio][0]++;
    }
  }
   printf("\n");
 }

int player = 1;
int x,y,a,b;
int score[2];
score[0] = 0;
score[1] = 0;
int numero_de_pares_encotrados = 0;

do{
  printf("\n----------------------------------------------------");
  printf("\nSituação do tabuleiro:\n");

  printf("\nQuantidade de pares encontrados: %i\n", numero_de_pares_encotrados);
  printf("Score player1: %i", score[0]);
  printf("  Score player2: %i", score[1]);

  printar_vetorsalvo();

  do
  {
  printf("\nPlayer%i : Digite a localizaçao da peça 1(x,y): ", player);
  scanf("%i,%i",&x,&y);
  }while(posicao_dos_numeros[x][y] == vetor_salvar[x][y] || x >= 4 || y >= 4);

  do
  {
  printf("Player%i : Digite a localizaçao da peça 2(x,y): ", player);
  scanf("%i,%i",&a,&b);
  }while(posicao_dos_numeros[a][b] == vetor_salvar[a][b] || a >= 4 || b >= 4 || ((x == a) && (y == b)));

  printf("\nOs números digitados foram: ");
  printf("\n");
  
  printar_status_atual(x,y,a,b);

  switch(player)
  {
  /*Player 1: Código*/
    case 1:

    if(posicao_dos_numeros[x][y] == posicao_dos_numeros[a][b])
    {
      printf("\nO player 1 encontrou um par de %i\n",posicao_dos_numeros[x][y]);
      vetor_salvar[x][y] = posicao_dos_numeros[x][y];
      vetor_salvar[a][b]=posicao_dos_numeros[a][b];
      score[0]++;
      numero_de_pares_encotrados++;
    }
    player = 2; break;

    /*Player 2: Código*/
    case 2:

    if(posicao_dos_numeros[x][y] == posicao_dos_numeros[a][b])
    { 
      printf("\nO player 2 encontrou um par de %i\n",posicao_dos_numeros[x][y]);
      vetor_salvar[x][y] = posicao_dos_numeros[x][y];
      vetor_salvar[a][b]=posicao_dos_numeros[a][b];
      score[1]++;
      numero_de_pares_encotrados++;
    }
    player = 1; break;
}
}while(numero_de_pares_encotrados <= 7);
    

/*resultado final do jogo*/
if(score[0] > score[1])
{
  printf("\nFim  do jogo,o player1 venceu com %i pares achados\n", score[0]);
}
else if (score[0] == score[1])
{
  printf("\nFim  do jogo, foi empate!");
}
else
{
  printf("\nFim  do jogo,o player2 venceu com %i pares achados\n", score[1]);
}
}








