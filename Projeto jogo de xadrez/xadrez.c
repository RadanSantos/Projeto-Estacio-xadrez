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

    return 0;
}
