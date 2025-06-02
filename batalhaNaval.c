#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados, como printf e scanf

int main() {
    // Cria um vetor de caracteres com as letras de A até J, que serão usadas para identificar as colunas
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declara uma matriz 10x10 representando o tabuleiro do jogo
    int tabuleiro[10][10];

    // Imprime o título do jogo
    printf("## Batalha naval ## ");
    printf(" \n");

    // Inicializa o tabuleiro preenchendo todas as posições com o valor 0
    for (int i = 0; i < 10; i++) {        // Percorre todas as linhas
        for (int j = 0; j < 10; j++) {    // Percorre todas as colunas
            tabuleiro[i][j] = 0;          // Define a célula atual como 0
        }
    }

    // Posiciona um navio horizontal com valor 3 na quarta linha (índice 3), colunas H, I, J (índices 7, 8, 9)
    tabuleiro[3][7] = 3;
    tabuleiro[3][8] = 3;
    tabuleiro[3][9] = 3;

    // Posiciona um navio vertical com valor 3 na coluna H (índice 7), linhas 5, 6, 7
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Posiciona um navio na diagonal principal ↘ (de cima esquerda para baixo direita)
    // Coloca 3 nas posições (0,0), (1,1), (2,2)
    for (int i = 0; i < 3; i++) {
        int linh = 0 + i;
        int coluna = 0 + i;
        tabuleiro[linh][coluna] = 3;
    }

    // Posiciona um navio na diagonal secundária ↙ (de cima direita para baixo esquerda)
    // Coloca 3 nas posições (9,0), (8,1), (7,2)
    for (int i = 0; i < 3; i++) {
        int linha = 9 - i;   // Começa em 9 e desce: 9, 8, 7
        int coluna = 0 + i;  // Começa em 0 e sobe: 0, 1, 2
        tabuleiro[linha][coluna] = 3;
    }

    // Marca ataque em cruz centrado na posição (1,1)
    int centro = 1;
    for (int d = -1; d <= 1; d++) {  // Variação de -1 a +1 para montar a cruz
        // Parte vertical da cruz
        if (tabuleiro[centro + d][centro] == 3) {
            // Se há um navio (valor 3), marca com 1 (acerto)
            tabuleiro[centro + 1][centro] = 1;
        } else {
            // Se não, marca com 5 (erro)
            tabuleiro[centro + d][centro] = 5;
        }

        // Parte horizontal da cruz
        if (tabuleiro[centro][centro + d] == 3) {
            tabuleiro[centro][centro + d] = 1;  // acerto 
        } else {
            tabuleiro[centro][centro + d] = 5;  // Erro
        }
    }

    // Define o centro do ataque octaedro como (7,6)
    int x = 7, y = 6, R = 2;  // R é o "raio" da cruz (alcança 2 casas para cada lado)

    // Percorre o eixo vertical do octaedro
    for (int d = -R ; d <= R; d++) {
        // Se encontrar valor 3 (navio), marca como 1 (acerto)
        if (tabuleiro[x + d][y] == 3) tabuleiro[x + d][y] = 1;
        else                          tabuleiro[x + d][y] = 5;  // Se não, marca erro (5)
    } 

    // Percorre o eixo horizontal do octaedro
    for (int d = -R ; d <= R; d++) {
        if (tabuleiro[x][y + d] == 3) tabuleiro[x][y + d] = 1;  // Se encontrar 3 marca 1 Acerto
        else                          tabuleiro[x][y + d] = 5;  // Erro
    }    

    // Diagonais em formato de X centradas em (7,6)
    int w = 7, z = 6, s = 2;

    for (int d = -s; d < s; d++) {  // Percorre de -2 a +1 (4 posições)
        // Diagonal  (de canto superior direito para inferior esquerdo)
        // Soma d nas duas direções
        if (tabuleiro[w + d][z + d] == 3)
            tabuleiro[w + d][z + d] = 1;  // Acertou navio
        else
            tabuleiro[w + d][z + d] = 5;  // Errou

        // Diagonal (de canto superior esquerdo para inferior direito)
        // Soma d e subtrai d nas direções (espelhado)
        if (tabuleiro[w + d][z - d] == 3)
            tabuleiro[w + d][z - d] = 1;  // Acertou
        else
            tabuleiro[w + d][z - d] = 5;  // Errou
    }

    // Desenha um "cone" com topo em (5,2), e base com largura 5
    int cx = 2;      // Coluna central do cone 
    int cy = 5;      // Linha onde o cone começa (índice 5)
    int raio = 2;    // Altura do cone e largura máxima da base

    // Para cada linha do cone (de cima para baixo)
    for (int linha = 0; linha <= raio; linha++) {
        int largura = raio - linha;  // Define a largura da linha atual do cone
        for (int dx = -largura; dx <= largura; dx++) {
            int x = cx + dx;         // Coluna ajustada com deslocamento
            int y = cy + linha;      // Linha sendo processada

            // Verifica se está dentro dos limites do tabuleiro
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                // Se tiver navio (3), marca como 1 (acertou)
                if (tabuleiro[y][x] == 3)
                    tabuleiro[y][x] = 1;
                else
                    tabuleiro[y][x] = 5;  // Caso contrário, marca como erro (5)
            }
        }
    }

    // Imprime o cabeçalho das colunas com letras A até J
    printf("   ");  // Espaço para alinhar com os números das linhas
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);  // Imprime as letras das colunas
    }
    printf("\n"); // Quebra de linha após o cabeçalho

    // Imprime cada linha do tabuleiro com os valores
    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);        // Número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime cada célula
        }
        printf("\n");  // Quebra de linha após cada linha
    }

    return 0;  // Fim do programa
}