#include <stdio.h>

// ==============================
// Função recursiva para a Torre
// ==============================
void moverTorre(int casas, int atual, char *direcao) {
    if (atual >= casas) {
        return; // Caso base: já percorreu todas as casas
    }
    printf("%s\n", direcao); // Imprime a direção
    moverTorre(casas, atual + 1, direcao); // Chamada recursiva
}

// ==============================
// Função recursiva para o Bispo
// (diagonal: cima + direita)
// ==============================
void moverBispoRecursivo(int casas, int atual) {
    if (atual >= casas) {
        return; // Caso base
    }
    printf("Cima\n");
    printf("Direita\n");
    moverBispoRecursivo(casas, atual + 1); // Próxima casa diagonal
}

// ==============================
// Bispo também com loops aninhados
// ==============================
void moverBispoLoops(int casas) {
    for (int i = 0; i < casas; i++) {          // movimento vertical
        for (int j = 0; j < 1; j++) {          // movimento horizontal
            printf("Cima\n");
            printf("Direita\n");
        }
    }
}

// ==============================
// Função recursiva para a Rainha
// (combina Torre + Bispo)
// ==============================
void moverRainha(int casas, int atual) {
    if (atual >= casas) {
        return;
    }
    printf("Cima\n");    // movimento vertical
    printf("Direita\n"); // movimento horizontal (diagonal simplificada)
    moverRainha(casas, atual + 1);
}

// ==============================
// Cavalo com loops complexos
// (duas casas para cima e uma para a direita)
// ==============================
void moverCavalo() {
    int movimentosVerticais = 2; // duas casas para cima
    int movimentosHorizontais = 1; // uma casa para direita

    for (int i = 0; i < movimentosVerticais; i++) {
        if (i == 1) {
            // continue para pular condição específica (exemplo)
            continue;
        }
        printf("Cima\n");
    }

    // loop while para o movimento horizontal
    int j = 0;
    while (j < movimentosHorizontais) {
        if (j == -1) {
            break; // só exemplo de controle extra
        }
        printf("Direita\n");
        j++;
    }
}

// ==============================
// Programa principal
// ==============================
int main() {
    int casas = 3; // Número de casas de exemplo

    // Torre
    printf("=== Torre ===\n");
    moverTorre(casas, 0, "Cima");

    // Linha em branco
    printf("\n");

    // Bispo recursivo
    printf("=== Bispo (Recursão) ===\n");
    moverBispoRecursivo(casas, 0);

    printf("\n");

    // Bispo com loops aninhados
    printf("=== Bispo (Loops Aninhados) ===\n");
    moverBispoLoops(casas);

    printf("\n");

    // Rainha
    printf("=== Rainha ===\n");
    moverRainha(casas, 0);

    printf("\n");

    // Cavalo
    printf("=== Cavalo ===\n");
    moverCavalo();

    return 0;
}
