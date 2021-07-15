
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

  int jogoInit();
  int rankingInit();

   int valor;

  //Loop do painel
  do{ 
    system("clear"); 

    printf("\nJogo da Velha\n");
    printf("1. Jogar \n");
    printf("2. Placar \n");
    printf("3. Sair\n");

    printf("\nEscolha uma op��o:");
    scanf("%d", & valor);

    //Analisa a op��o do usuario, caso seja valida chama a fun��o correspondente, sen�o apresenta o painel novamente 
    switch(valor){
      case 1:
        jogoInit();
      case 2:
        rankingInit();
        break;
    }

  }while(valor != 3);

  return 0;
}

//Inicia o Loop do Jogo
int jogoInit(){
  
  void redefinirTabuleiro(int a[3][3]);
  void rodadaInit(int a[3][3], int);

  int tabuleiro[3][3];
  int valor;

  //Loop para jo jogo, onde vai executando as rodadas
  do{ 
    system("clear"); 
 
    redefinirTabuleiro(tabuleiro);
    rodadaInit(tabuleiro, 1);

    printf("\n\n1. Continuar \n\n");
    printf("2. Sair\n");

    printf("\nEscolha uma op��o:");
    scanf("%d", & valor);


  }while(valor != 2); 

  return 0;
}

//Executa o loop da rodada
void rodadaInit(int tabuleiro[3][3], int jogador){

  void desenharTabuleiro(int (*tabuleiro)[3]);
  void rodadaJogador(int (*tabuleiro)[3], int);

  int existemPossibilidades(int (*tabuleiro)[3]);
  int verificaVencedor(int (*tabuleiro)[3], int);
  
  void jogada_bot(int (*tabuleiro)[3], int);

  int bot = jogador == 1?-1:1;
  int vez = rand()%3 + jogador;
  int vencedor = 0;

  //Loop para as jogadas
  while(existemPossibilidades(tabuleiro)){
    system("clear"); 
    desenharTabuleiro(tabuleiro);
    int rodada = 0;

    if(vez % 2 == 0){
      //jogada do usuario
      printf("\n\nSua Vez!");
      rodadaJogador(tabuleiro, jogador);
      rodada = jogador;
    }else{
      // jogada do bot
      printf("\n");
      jogada_bot(tabuleiro, bot);
      rodada = bot;
    }

    vez++;

    // caso houver vencedor
    if(verificaVencedor(tabuleiro, rodada)){
      system("clear");

      if(rodada == jogador){
        printf("\nParabens voce ganhou\n\n");
        vencedor = 1;
      }else{
         printf("Ixi voce perdeu\n");
         vencedor = 1;
      }

      desenharTabuleiro(tabuleiro);
      break;
    }
  }

  if(!vencedor){
    system("clear");
    printf("\n Deu Velha \n\n");
    desenharTabuleiro(tabuleiro);
  } 

}

//recebe e testa as jogadas do usuario para efetuala
void rodadaJogador(int tabuleiro[3][3], int jogador){
  int verificaJogada(int (*tab)[3], int, int);
  void efetuarJogada(int (*tab)[3],int, int, int);

  int linha, coluna;

  //Loop o usuario definiar uma jogada correta
  do{

    printf("\nInsira a Linha que deseja jogar:");
    scanf("%d", &linha); 

    printf("\nInsira a Coluna que deseja jogar:");
    scanf("%d", &coluna);

  }while(!verificaJogada(tabuleiro, linha-1, coluna-1));
  efetuarJogada(tabuleiro, linha-1, coluna-1, jogador);
}

//Inicia a Visualiza��o do Ranking
int rankingInit(){
  int sair;

  system("clear");
  printf("Ranking\n");

  //apenas para travar o loop
  printf("\n\nSelecione 1 para continuar... \n");
  scanf("%d", &sair);  

  return 0;
}

//Desenhar o tabuleiro 
void desenharTabuleiro(int tabuleiro[3][3]){
  char converteNumero(int);
  int tabuleiroChar[3][3];

  printf("\n\t   1    2   3 \n");
  for(int i = 0; i <3; i++){
    printf("\n  %d", i+1);
     printf("\t ");
    for(int j = 0; j<3; j++){
      tabuleiroChar[i][j] = converteNumero(tabuleiro[i][j]);
      if(j < 2){
        printf("  %c |", tabuleiroChar[i][j]);
      }else{
        printf(" %c  ", tabuleiroChar[i][j]);
      }
    }
    if(i<2){
      printf("\n\t  ------------");
    }
  } 

}

//Recebe tabuleiro, e altera seus valores em nulo
void redefinirTabuleiro(int tab[3][3]){
  for(int i = 0; i <3; i++){
    for(int j = 0; j<3; j++){
      tab[i][j] = 0;
    }
  }
}

//Recebe um numero e converte em seu respectivo caracter
char converteNumero(int valor){
  if(valor == 0){
    return ' ';
  }else{
    if(valor == 1){
      return 'X';
    }else{
      if(valor == -1){
        return 'O';
      }
    }
  }
  return ' ';
} 

//Efetuar jogada
void efetuarJogada(int tabuleiro[3][3], int linha, int coluna, int jogador){
  tabuleiro[linha][coluna] = jogador;
}

//Recebe a jogada e verifica se esta disponivel, sendo 1 ou 0
int verificaJogada(int tab[3][3], int x, int y) {
  if(x >= 0 && y >= 0 && x <= 3 && y<= 3){
    if(tab[x][y] == 0){
       return 1;
    }
  }
  return 0;
}

//Verifica se existe um vencedor
int verificaVencedor(int tabuleiro[3][3], int jogador){
  
   // Verificando as linhas para a vit�ria.
   if (tabuleiro[0][0]==jogador 
      && tabuleiro[0][1]==jogador 
      && tabuleiro[0][2]==jogador) {
      printf("\nLinha 1\n");
    return 1 ;
  }
  if (tabuleiro[1][0]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[1][2]==jogador) {
        printf("\nLinha 2\n");
    return 1 ;
  }
  if (tabuleiro[2][0]==jogador 
      && tabuleiro[2][1]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nLinha 3\n");
    return 1 ;
  }
  if (tabuleiro[0][0]==jogador 
      && tabuleiro[1][0]==jogador 
      && tabuleiro[2][0]==jogador) {
        printf("\nColuna 1\n");
    return 1 ;
  } 
   // Verificando as ncolunas para a vit�ria.
  if (tabuleiro[0][1]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][1]==jogador) {
        printf("\nColuna 2\n");
    return 1 ;
  } 
  if (tabuleiro[0][2]==jogador 
      && tabuleiro[1][2]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nColuna 3\n");
    return 1 ;
  }
   // Verificando as diagonais para a vit�ria.
  if (tabuleiro[0][0]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nDiagonal principal\n");
    return 1 ;
  }
  if (tabuleiro[0][2]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][0]==jogador) { 
        printf("\nDiagonal secundaria\n");
    return 1 ;
  }   

  return 0; //Caso n�o tenha vencedor, retorna 0
}

// Esta fun��o retorna verdadeiro se houver movimentos
// permanecendo no tabuleiro. Retorna 0 se
// n�o h� mais movimentos para jogar.
int existemPossibilidades(int tabuleiro[3][3])
{
  for (int i = 0; i<3; i++)
      for (int j = 0; j<3; j++)
          if (tabuleiro[i][j]== 0)
              return 1;
  return 0;
}

//Codigo referente a analise do Bot

//struct movimentos do bot
struct Move
{
  int linha, coluna;
};

void jogada_bot(int tabuleiro[3][3], int bot)
{
  struct Move movimentoBot(int a[3][3], int);
  void efetuarJogada(int (*tabuleiro)[3], int linha, int coluna, int jogador);

  struct Move jogadaBot = movimentoBot(tabuleiro, bot);

  efetuarJogada(tabuleiro, jogadaBot.linha, jogadaBot.coluna, bot);
} 
 
//Esse fun��o avalia se a jogada ir� resultar chances de vitoria ou derrota 
int avaliaJogada(int tabuleiro[3][3], int jogador)
{
  // Verificando as linhas para a vit�ria de X ou O.
  for (int linha = 0; linha<3; linha++)
  {
      if (tabuleiro[linha][0]==tabuleiro[linha][1] &&
          tabuleiro[linha][1]==tabuleiro[linha][2] && tabuleiro[linha][2]!=0)
      {
          if (tabuleiro[linha][0]==jogador)
              return +10;
          else 
              return -10;
      }
  }

  // Verificando colunas nas para vit�ria de X ou O.
  for (int coluna = 0; coluna<3; coluna++)
  {
      if (tabuleiro[0][coluna]==tabuleiro[1][coluna] &&
          tabuleiro[1][coluna]==tabuleiro[2][coluna] && tabuleiro[2][coluna]!=0)
      {
          if (tabuleiro[0][coluna]==jogador)
              return +10;
          else
              return -10;
      }
  }

  // Verificando as diagonais para a vit�ria de X ou O.
  if (tabuleiro[0][0]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][2] && tabuleiro[2][2]!=0)
  {
      if (tabuleiro[0][0]==jogador)
          return +10;
      else 
          return -10;
  }

  if (tabuleiro[0][2]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][0] !=0)
  {
      if (tabuleiro[0][2]==jogador)
          return +10;
      else 
          return -10;
  }

  // Do contr�rio, se nenhum deles ganhou, retorna 0
  return 0;
}
 
// Esta � a fun��o minimax. Considera tudo
// os caminhos poss�veis que o jogo pode seguir e retornar
// o valor do tabuleiro
int minimax(int tabuleiro[3][3], int isMax, int jogador){
  int avaliaJogada(int (*tabuleiro)[3], int);

  int pontuacaoJogada = avaliaJogada(tabuleiro, jogador);

  // Se o Maximizer ganhou o jogo, devolva o seu
  // pontua��o avaliada
  if (pontuacaoJogada == 10){
    return pontuacaoJogada;
  }  
  // Se o Minimizer ganhou o jogo, devolva o seu
  // pontua��o avaliada
  if (pontuacaoJogada == -10){
    return pontuacaoJogada;
  }

  if (existemPossibilidades(tabuleiro)){
    return 0;
  }

  // Se n�o houver mais movimentos e nenhum vencedor, ent�o
  // � um empate
  // If this maximizer's move
  if (isMax == 1)
  {
      int melhor = -1000;

      // Percorre todas as c�lulas
      for (int i = 0; i<3; i++)
      {
          for (int j = 0; j<3; j++)
          {
              // Verifique se a c�lula est� vazia
              if (tabuleiro[i][j]== 0)
              {
                  // Fa�a o movimento
                  tabuleiro[i][j] = jogador;

                  // Chame minimax recursivamente e escolunaha
                  // o valor m�ximo
                  melhor =  minimax(tabuleiro, !isMax, jogador);

                  // Desfaz o movimento
                  tabuleiro[i][j] =  0;
              }
          }
      }
      return melhor;
  }

  // Se este minimizador se mover
  else
  {
      int melhor = 1000;

      // Percorre todas as c�lulas
      for (int i = 0; i<3; i++)
      {
          for (int j = 0; j<3; j++)
          {
            // Verifique se a c�lula est� vazia
              if (tabuleiro[i][j]== 0)
              {
                  // Make the move
                  tabuleiro[i][j] = jogador == 1 ? -1: 1;
                  // Chame minimax recursivamente e escolunaha
                  // o valor m�nimo
                  melhor =  minimax(tabuleiro, !isMax, jogador);

                  tabuleiro[i][j] =  0;
              }
          }
      }
      return melhor;
  }
}

// Isso retornar� o melhor movimento poss�vel para o jogador
struct Move movimentoBot(int tabuleiro[3][3], int jogador)
{
  int verificaJogada(int (*tab)[3], int, int);

  int pontuacaoJogada = -1000;
  struct Move melhorMovimento;
  melhorMovimento.linha = -1;
  melhorMovimento.coluna = -1;

  // Percorre todas as c�lulas, avalia a fun��o minimax para
  // todas as c�lulas vazias. E retornar o celular com �timo
  // valor.
  for (int i = 0; i<3; i++)
  {
      for (int j = 0; j<3; j++)
      {
          // Verifique se a c�lula est� vazia
          if (tabuleiro[i][j]== 0)
          {
              // Make the move
              tabuleiro[i][j] = jogador;
              // computar fun��o de avalia��o para este
              // mover.
              int moveVal = minimax(tabuleiro, 0, jogador);

              // Desfaz o movimento
              tabuleiro[i][j] =  0;

              // Se o valor do movimento atual for
              // mais do que o melhor valor, ent�o atualize
              // melhor/
              if (moveVal > pontuacaoJogada)
              {
                  melhorMovimento.linha = i;
                  melhorMovimento.coluna = j;
                  pontuacaoJogada = moveVal;
              }
          }
      }
  }

  //Caso n�o tenha uma melhor jogada, sera definido uma posi��o aleatoria
  if(pontuacaoJogada == 0){
    melhorMovimento.linha = rand()%3;
    melhorMovimento.coluna = rand()%3;

    //Caso essa jogada aleatoria seja invalida, ent�o jogara na primeira posi��o vazia do tabueiro
    if(!verificaJogada(tabuleiro, melhorMovimento.linha,melhorMovimento.coluna)){

      for(int i = 0; i<3; i++){
        for(int j = 0; j<3;j++){
          if(verificaJogada(tabuleiro, i,j)){
            melhorMovimento.linha = i;
            melhorMovimento.coluna = j;
            break;
          }
        }
      }
    }
  }

  return melhorMovimento;
}
