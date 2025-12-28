#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define LETRAS 10

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    char linha[11] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    
    printf("      TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    
    // Imprime as letras (A-J)
    for (int j = 0; j < LETRAS; j++) {
        printf("%c  ", linha[j]);
    }
    printf("\n");  
    
    // Imprime as linhas com números
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Habilidade 1: CONE (triângulo apontando para baixo)
void habilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linha_centro, int coluna_centro) {
    printf("\n=== APLICANDO HABILIDADE: CONE ===\n");
    printf("Centro: Linha %d, Coluna %c\n", linha_centro + 1, coluna_centro + 'A');
    
    // Desenha o padrão do cone
    // Linha 0: apenas o centro
    if(linha_centro >= 0 && linha_centro < LINHAS && coluna_centro >= 0 && coluna_centro < COLUNAS) {
        // Só marca se não for navio (navio = 3)
        if(tabuleiro[linha_centro][coluna_centro] != 3) {
            tabuleiro[linha_centro][coluna_centro] = 1;
        }
    }
    
    // Linha 1: centro, esquerda e direita
    if(linha_centro + 1 < LINHAS) {
        // Centro
        if(coluna_centro >= 0 && coluna_centro < COLUNAS && tabuleiro[linha_centro + 1][coluna_centro] != 3) {
            tabuleiro[linha_centro + 1][coluna_centro] = 1;
        }
        // Esquerda
        if(coluna_centro - 1 >= 0 && tabuleiro[linha_centro + 1][coluna_centro - 1] != 3) {
            tabuleiro[linha_centro + 1][coluna_centro - 1] = 1;
        }
        // Direita
        if(coluna_centro + 1 < COLUNAS && tabuleiro[linha_centro + 1][coluna_centro + 1] != 3) {
            tabuleiro[linha_centro + 1][coluna_centro + 1] = 1;
        }
    }
    
    // Linha 2: linha completa (5 posições)
    if(linha_centro + 2 < LINHAS) {
        for(int j = coluna_centro - 2; j <= coluna_centro + 2; j++) {
            if(j >= 0 && j < COLUNAS && tabuleiro[linha_centro + 2][j] != 3) {
                tabuleiro[linha_centro + 2][j] = 1;
            }
        }
    }
    
    printf("Padrao do Cone:\n");
    printf("0 0 1 0 0\n");
    printf("0 1 1 1 0\n");
    printf("1 1 1 1 1\n");
}

// Habilidade 2: CRUZ
void habilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linha_centro, int coluna_centro) {
    printf("\n=== APLICANDO HABILIDADE: CRUZ ===\n");
    printf("Centro: Linha %d, Coluna %c\n", linha_centro + 1, coluna_centro + 'A');
    
    // Linha horizontal da cruz (5 posições)
    for(int j = coluna_centro - 2; j <= coluna_centro + 2; j++) {
        if(j >= 0 && j < COLUNAS && linha_centro >= 0 && linha_centro < LINHAS) {
            if(tabuleiro[linha_centro][j] != 3) {
                tabuleiro[linha_centro][j] = 1;
            }
        }
    }
    
    // Coluna vertical da cruz (3 posições)
    for(int i = linha_centro - 1; i <= linha_centro + 1; i++) {
        if(i >= 0 && i < LINHAS && coluna_centro >= 0 && coluna_centro < COLUNAS) {
            if(tabuleiro[i][coluna_centro] != 3) {
                tabuleiro[i][coluna_centro] = 1;
            }
        }
    }
    
    printf("Padrao da Cruz:\n");
    printf("0 0 1 0 0\n");
    printf("1 1 1 1 1\n");
    printf("0 0 1 0 0\n");
}

// Habilidade 3: OCTAEDRO (diamante)
void habilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linha_centro, int coluna_centro) {
    printf("\n=== APLICANDO HABILIDADE: OCTAEDRO ===\n");
    printf("Centro: Linha %d, Coluna %c\n", linha_centro + 1, coluna_centro + 'A');
    
    // Linha do meio (horizontal - 3 posições)
    for(int j = coluna_centro - 1; j <= coluna_centro + 1; j++) {
        if(j >= 0 && j < COLUNAS && linha_centro >= 0 && linha_centro < LINHAS) {
            if(tabuleiro[linha_centro][j] != 3) {
                tabuleiro[linha_centro][j] = 1;
            }
        }
    }
    
    // Linhas acima e abaixo (apenas centro)
    if(linha_centro - 1 >= 0 && coluna_centro >= 0 && coluna_centro < COLUNAS) {
        if(tabuleiro[linha_centro - 1][coluna_centro] != 3) {
            tabuleiro[linha_centro - 1][coluna_centro] = 1;
        }
    }
    if(linha_centro + 1 < LINHAS && coluna_centro >= 0 && coluna_centro < COLUNAS) {
        if(tabuleiro[linha_centro + 1][coluna_centro] != 3) {
            tabuleiro[linha_centro + 1][coluna_centro] = 1;
        }
    }
    
    printf("Padrao do Octaedro:\n");
    printf("0 0 1 0 0\n");
    printf("0 1 1 1 0\n");
    printf("0 0 1 0 0\n");
}

int main() {
    
    // Tabuleiro inicial com navios
    int tabuleiro[LINHAS][COLUNAS] = {0};
    
    // POSICIONAMENTO DOS NAVIOS (número 3)
    printf("=== POSICIONANDO NAVIOS NO TABULEIRO ===\n");
    
    // Navio 1 - Horizontal (linha 2, colunas B-D)
    for(int j = 1; j <= 3; j++) {
        tabuleiro[1][j] = 3;
    }
    
    // Navio 2 - Vertical (coluna F, linhas 5-7)
    for(int i = 4; i <= 6; i++) {
        tabuleiro[i][5] = 3;
    }
    
    // Navio 3 - Horizontal (linha 8, colunas G-I)
    for(int j = 7; j <= 9; j++) {
        tabuleiro[8][j] = 3;
    }
    
    // Navio 4 - Diagonal (linhas 4-6, colunas C-E)
    for(int i = 0; i < 3; i++) {
        tabuleiro[3 + i][2 + i] = 3;
    }
    
    // Imprime tabuleiro inicial com navios
    printf("\n=== TABULEIRO INICIAL (Navios = 3) ===\n");
    imprimirTabuleiro(tabuleiro);
    
    // Menu para aplicar habilidades
    int opcao;
    char continuar;
    
    do {
        printf("\n======================================\n");
        printf("      APLICAR HABILIDADES\n");
        printf("======================================\n");
        printf("Legenda: 3 = Navio, 1 = Habilidade\n");
        printf("======================================\n");
        printf("1. Cone (Triangulo para baixo)\n");
        printf("2. Cruz\n");
        printf("3. Octaedro (Diamante)\n");
        printf("4. Ver tabuleiro atual\n");
        printf("5. Sair\n");
        printf("======================================\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        if(opcao >= 1 && opcao <= 3) {
            int linha;
            char coluna_char;
            
            printf("\nDigite a posicao central (ex: 5 C): ");
            scanf("%d %c", &linha, &coluna_char);
            
            // Ajusta índices
            linha = linha - 1;
            int coluna = coluna_char - 'A';
            
            if(linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
                printf("Posicao invalida! Tente novamente.\n");
                continue;
            }
            
            // Aplica a habilidade escolhida
            switch(opcao) {
                case 1:
                    habilidadeCone(tabuleiro, linha, coluna);
                    break;
                case 2:
                    habilidadeCruz(tabuleiro, linha, coluna);
                    break;
                case 3:
                    habilidadeOctaedro(tabuleiro, linha, coluna);
                    break;
            }
            
            // Imprime tabuleiro atualizado
            printf("\n=== TABULEIRO ATUALIZADO ===\n");
            imprimirTabuleiro(tabuleiro);
            
        } else if(opcao == 4) {
            printf("\n=== TABULEIRO ATUAL ===\n");
            imprimirTabuleiro(tabuleiro);
        } else if(opcao == 5) {
            printf("Encerrando programa...\n");
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
        
        if(opcao != 5) {
            printf("\nAplicar outra habilidade? (s/n): ");
            scanf(" %c", &continuar);
            if(continuar == 'n' || continuar == 'N') {
                break;
            }
        }
        
    } while(opcao != 5);
    
    // Tabuleiro final
    printf("\n=== TABULEIRO FINAL ===\n");
    imprimirTabuleiro(tabuleiro);
    
    // Estatísticas
    printf("\n=== ESTATISTICAS ===\n");
    int navios = 0, habilidades = 0;
    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            if(tabuleiro[i][j] == 3) navios++;
            if(tabuleiro[i][j] == 1) habilidades++;
        }
    }
    printf("Casas com navios: %d\n", navios);
    printf("Casas com habilidades: %d\n", habilidades);
    printf("Casas vazias: %d\n", 100 - navios - habilidades);
    
    return 0;
}