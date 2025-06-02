#include <stdio.h>  // Biblioteca para entrada e saída de dados

int main() {
    // Vetor com letras para identificar as colunas A até J
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declara que o tabuleiro sera uma matriz 10x10 
    int tabuleiro[10][10];

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

    // Imprime o cabeçalho das colunas com as letras A até J
    printf("   ");  // Espaço inicial para alinhar com os números das linhas
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);  // Imprime as letras das colunas
    }
    printf("\n"); // Quebra de linha após o cabeçalho

    // Imprime as linhas do tabuleiro, com os números no início
    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);        // Imprime o número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor de cada célula
        }
        printf("\n");   
        
    }

    return 0;  // Finaliza o programa
}

