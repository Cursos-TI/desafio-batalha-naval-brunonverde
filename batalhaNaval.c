#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Sistema completo de posicionamento de navios e habilidades especiais

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

int main() {

    // =================================================
    // Nível Novato / Aventureiro - Tabuleiro e Navios
    // =================================================

    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------------
    // Navio horizontal
    // -------------------------------
    int linhaH = 2, colunaH = 2;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // -------------------------------
    // Navio vertical
    // -------------------------------
    int linhaV = 5, colunaV = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // -------------------------------
    // Navio diagonal principal
    // -------------------------------
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // -------------------------------
    // Navio diagonal secundária
    // -------------------------------
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    // =================================================
    // Nível Mestre - Habilidades Especiais
    // =================================================

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // -------------------------------
    // Construção do CONE
    // -------------------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // -------------------------------
    // Construção da CRUZ
    // -------------------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // -------------------------------
    // Construção do OCTAEDRO
    // -------------------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // -------------------------------
    // Aplicação das habilidades
    // -------------------------------
    int origemLinha = 5;
    int origemColuna = 5;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            int tLinha = origemLinha + i - 2;
            int tColuna = origemColuna + j - 2;

            if (tLinha >= 0 && tLinha < TAM && tColuna >= 0 && tColuna < TAM) {

                if (cone[i][j] == 1 || cruz[i][j] == 1 || octaedro[i][j] == 1) {
                    if (tabuleiro[tLinha][tColuna] == AGUA) {
                        tabuleiro[tLinha][tColuna] = HABILIDADE;
                    }
                }
            }
        }
    }

    // =================================================
    // Exibição do Tabuleiro Final
    // =================================================

    printf("Tabuleiro Final:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
