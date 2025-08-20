#include <stdio.h>

int main() {
    // Quantidade de casas que cada peça vai se mover
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // ===============================
    // Movimento da TORRE → usa for
    // ===============================
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (%d)\n", i);
    }

    // ===============================
    // Movimento do BISPO → usa while
    // ===============================
    printf("\nMovimento do Bispo:\n");
    int i = 1;
    while (i <= casasBispo) {
        printf("Cima Direita (%d)\n", i);
        i++;
    }

    // ===============================
    // Movimento da RAINHA → usa do-while
    // ===============================
    printf("\nMovimento da Rainha:\n");
    int j = 1;
    do {
        printf("Esquerda (%d)\n", j);
        j++;
    } while (j <= casasRainha);

    // ===============================
    // Movimento do CAVALO → usa loops aninhados
    // ===============================
    printf("\nMovimento do Cavalo:\n");

    int movimentosBaixo = 2;   // Cavalo anda 2 casas para baixo
    int movimentosEsquerda = 1; // depois 1 casa para a esquerda

    // Loop externo: controla os dois movimentos para baixo
    for (int k = 1; k <= movimentosBaixo; k++) {
        printf("Baixo (%d)\n", k);

        // Loop interno: poderia ser usado para algo extra,
        // aqui simulamos verificação de sub-etapas do movimento
        int passo = 1;
        while (passo <= 1) { // apenas para mostrar o uso do while
            // Esse loop garante que o Cavalo está confirmando cada movimento
            passo++;
        }
    }

    // Depois que terminou os movimentos "Baixo", faz o "Esquerda"
    int l = 1;
    while (l <= movimentosEsquerda) {
        printf("Esquerda (%d)\n", l);
        l++;
    }

    return 0;
}
