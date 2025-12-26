#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define melhor as linhas e colunas, assim nao ha necessidade de mudar codigo todo 
#define LINHAS 10
#define COLUNAS 10
#define LETRAS 10


int main() {
    
    char linha[11] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    
    int tabuleiro[10][10] = {
        {0}
    };
    
    tabuleiro[2][7] = 3;  // Linha 3, Coluna H
    tabuleiro[3][7] = 3;  // Linha 4, Coluna H  
    tabuleiro[4][7] = 3;  // Linha 5, Coluna H
    
    // Navio 2: Horizontal na linha 9 (índice 8), colunas C, D e E
    tabuleiro[8][2] = 3;  // Linha 9, Coluna C
    tabuleiro[8][3] = 3;  // Linha 9, Coluna D
    tabuleiro[8][4] = 3;  // Linha 9, Coluna E


    printf("      TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    
    // vetor para Imprimir as letras (A-J)
    for (int j = 0; j < LETRAS; j++) {
        printf("%c  ", linha[j]);
    }
    printf("\n");  
    
    // Imprime as linhas com números começando em 1
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);  // i + 1 para começar do 1, %2 é para aumentar uma casa e manter a simetria do tabuleiro
        
        // Loop para todas as colunas
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}