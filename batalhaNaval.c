#include <stdio.h>  // Biblioteca para entrada e saída de dados

int main() {
    // Vetor com letras para identificar as colunas A até J
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declara que o tabuleiro sera uma matriz 10x10 
    int tabuleiro[10][10];

    // Título do programa
    printf("## Batalha naval ## ");
    printf(" \n");
    // Inicializa o tabuleiro preenchendo todas as posições com 0
    for (int i = 0; i < 10; i++) {    // Para cada linha
        for (int j = 0; j < 10; j++) { // Para cada coluna
            tabuleiro[i][j] = 0;  // Coloca 0 na posição correspondente
        }
    }

    // Posiciona três valores 3 na horizontal na linha 3 (quarta linha)
    // Colunas H (7), I (8), J (9)
    tabuleiro[3][7] = 3;
    tabuleiro[3][8] = 3;
    tabuleiro[3][9] = 3;

    // Posiciona três valores 3 na vertical na coluna H (7)
    // Linhas 5, 6, 7 (sexta a oitava linhas)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    
       
    // Coloca três valores 3 na diagonal principal (de cima para baixo, da esquerda para direita)
    // Posições: [0] [0] [1][1], [2][2], 
            //obs. Podeiria seguir a logica anterior seria mais pratico, 
            //tabuleiro[1][1] = 3;
            //tabuleiro[2][2] = 3;
            //tabuleiro[3][3] = 3; 

    for (int i = 0; i < 3; i++) {
        int linh = 0 + i;
        int coluna = 0 + i;
        tabuleiro[linh][coluna] = 3;
               
    }
    // Usando for para colocar três 3 na diagonal secundária
    //  posição  (9,0) (8,1) (7,2)
        for (int i = 0; i < 3; i++) {
        int linha = 9 - i ;
        int coluna = 0 + i ;
        tabuleiro[linha][coluna] = 3;
    }



    // Imprime o cabeçalho das colunas com as letras A até J
    printf("   ");  // Espaço inicial para alinhar com os números das linhas, 
    // fedback: poderia ter explicado melhor na aula esse printf com espaço, fica mais organizado 
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);  // Imprime as letras das colunas
    }
    printf("\n"); // Quebra de linha após o cabeçalho

     //Imprime as linhas do tabuleiro, com os números no início
   for (int i = 0; i < 10; i++) {
        printf("%d  ", i);        // Imprime o número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor de cada célula
       }printf("\n");
    }

      


    return 0;  // Finaliza o programa
}