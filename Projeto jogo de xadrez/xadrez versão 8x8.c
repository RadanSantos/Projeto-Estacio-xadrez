#include <stdio.h>

#define N 8

// Códigos no tabuleiro (inteiros, como pedido)
#define VAZIO 0
#define TORRE 1
#define BISPO 2
#define RAINHA 3
#define CAVALO 4

// ========================= Utilitários de tabuleiro =========================
void limparTabuleiro(int b[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i][j] = VAZIO;
}

void imprimirTabuleiro(int b[N][N]) {
    // eixo Y (linhas) de cima para baixo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = '.';
            switch (b[i][j]) {
                case TORRE:  c = 'T'; break;
                case BISPO:  c = 'B'; break;
                case RAINHA: c = 'Q'; break;
                case CAVALO: c = 'C'; break;
                case VAZIO:  c = '.'; break;
            }
            printf(" %c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

int dentro(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

// Reposiciona uma peça: limpa a célula anterior e coloca na nova, imprime
void atualizarPosicao(int b[N][N], int *r, int *c, int nr, int nc, int peca) {
    if (!dentro(nr, nc)) {
        printf("Parou: sairia do tabuleiro em (%d,%d).\n\n", nr, nc);
        return;
    }
    b[*r][*c] = VAZIO;
    *r = nr; *c = nc;
    b[*r][*c] = peca;
    imprimirTabuleiro(b);
}

// ========================= Torre (recursivo) =========================
// Move k casas em uma direção fixa. dir: "Cima", "Baixo", "Esquerda", "Direita"
void moverTorreRec(int b[N][N], int peca, int *r, int *c, int k, const char *dir) {
    if (k == 0) return;

    int dr = 0, dc = 0;
    if (dir[0] == 'C' && dir[1] == 'i') dr = -1;            // Cima
    else if (dir[0] == 'B')            dr =  1;             // Baixo
    else if (dir[0] == 'E')            dc = -1;             // Esquerda
    else                               dc =  1;             // Direita

    printf("%s\n", dir);
    int nr = *r + dr, nc = *c + dc;
    if (!dentro(nr, nc)) {
        printf("Parou: sairia do tabuleiro.\n\n");
        return;
    }
    atualizarPosicao(b, r, c, nr, nc, peca);
    moverTorreRec(b, peca, r, c, k - 1, dir);
}

// ========================= Bispo (recursivo) =========================
// Diagonal: Cima + Direita (como no básico, mas agora recursivo)
void moverBispoRec(int b[N][N], int peca, int *r, int *c, int k) {
    if (k == 0) return;
    printf("Cima\n");
    printf("Direita\n");
    int nr = *r - 1, nc = *c + 1;
    if (!dentro(nr, nc)) {
        printf("Parou: sairia do tabuleiro.\n\n");
        return;
    }
    atualizarPosicao(b, r, c, nr, nc, peca);
    moverBispoRec(b, peca, r, c, k - 1);
}

// ========================= Bispo (loops aninhados) =========================
// Loop externo = vertical (subindo k vezes), interno = horizontal (1 passo à direita por iteração)
void moverBispoLoops(int b[N][N], int peca, int *r, int *c, int k) {
    for (int passoV = 0; passoV < k; passoV++) {   // vertical (Cima)
        // Sobe 1
        if (!dentro(*r - 1, *c)) {
            printf("Parou (vertical): sairia do tabuleiro.\n\n");
            return;
        }
        printf("Cima\n");
        atualizarPosicao(b, r, c, *r - 1, *c, peca);

        // Horizontal: 1 passo à Direita (loop interno)
        for (int passoH = 0; passoH < 1; passoH++) {
            if (!dentro(*r, *c + 1)) {
                printf("Parou (horizontal): sairia do tabuleiro.\n\n");
                return;
            }
            printf("Direita\n");
            atualizarPosicao(b, r, c, *r, *c + 1, peca);
        }
    }
}

// ========================= Rainha (recursivo) =========================
// Exemplo: mover k casas na diagonal Cima+Direita (poderia ser qualquer direção da Rainha)
void moverRainhaRec(int b[N][N], int peca, int *r, int *c, int k) {
    if (k == 0) return;
    printf("Cima\n");
    printf("Direita\n");
    int nr = *r - 1, nc = *c + 1;
    if (!dentro(nr, nc)) {
        printf("Parou: sairia do tabuleiro.\n\n");
        return;
    }
    atualizarPosicao(b, r, c, nr, nc, peca);
    moverRainhaRec(b, peca, r, c, k - 1);
}

// ========================= Cavalo (loops complexos) =========================
// Movimento em L: duas para CIMA e uma para DIREITA.
// Usa for + while com múltiplas condições, e demonstra continue/break.
void moverCavaloComplexo(int b[N][N], int peca, int *r, int *c) {
    int subir = 2;   // duas para cima
    int direita = 1; // uma para direita

    printf("Movimento do Cavalo (complexo):\n");

    // FOR para as subidas (duas vezes)
    for (int i = 0; i < subir; i++) {
        // exemplo de controle: se já está na borda superior, não dá para subir
        if (!dentro(*r - 1, *c)) {
            printf("Cima (bloqueado) -> break\n");
            break; // não consegue mais subir
        }
        printf("Cima\n");
        atualizarPosicao(b, r, c, *r - 1, *c, peca);

        // while “inútil” mas demonstrando múltiplas condições e continue
        int checagens = 0;
        while (checagens < 2 && dentro(*r, *c)) {
            checagens++;
            if (checagens == 1) {
                // primeira checagem não muda nada, apenas demonstra continue
                continue;
            }
            // segunda checagem também não altera; serve para ilustrar fluxo
        }
    }

    // Agora 1 para a direita (se possível)
    int j = 0;
    while (j < direita) {
        if (!dentro(*r, *c + 1)) {
            printf("Direita (bloqueado) -> break\n");
            break;
        }
        printf("Direita\n");
        atualizarPosicao(b, r, c, *r, *c + 1, peca);
        j++;
    }
    printf("\n");
}

// ========================= Programa principal =========================
int main(void) {
    int board[N][N];

    // ------------------ TORRE (recursivo) ------------------
    limparTabuleiro(board);
    int r = 7, c = 0;               // canto inferior esquerdo (linha 7, col 0)
    board[r][c] = TORRE;
    printf("=== TORRE (recursão) – mover 5 para a Direita ===\n");
    imprimirTabuleiro(board);
    moverTorreRec(board, TORRE, &r, &c, 5, "Direita");
    printf("\n");

    // ------------------ BISPO (recursivo) ------------------
    limparTabuleiro(board);
    r = 7; c = 1;
    board[r][c] = BISPO;
    printf("=== BISPO (recursão) – mover 3 na diagonal Cima+Direita ===\n");
    imprimirTabuleiro(board);
    moverBispoRec(board, BISPO, &r, &c, 3);
    printf("\n");

    // ------------------ BISPO (loops aninhados) ------------------
    limparTabuleiro(board);
    r = 6; c = 0;
    board[r][c] = BISPO;
    printf("=== BISPO (loops aninhados) – 3 passos (Cima + Direita) ===\n");
    imprimirTabuleiro(board);
    moverBispoLoops(board, BISPO, &r, &c, 3);
    printf("\n");

    // ------------------ RAINHA (recursivo) ------------------
    limparTabuleiro(board);
    r = 7; c = 2;
    board[r][c] = RAINHA;
    printf("=== RAINHA (recursão) – mover 4 na diagonal Cima+Direita ===\n");
    imprimirTabuleiro(board);
    moverRainhaRec(board, RAINHA, &r, &c, 4);
    printf("\n");

    // ------------------ CAVALO (loops complexos) ------------------
    limparTabuleiro(board);
    r = 4; c = 1;
    board[r][c] = CAVALO;
    printf("=== CAVALO (loops complexos) – L: 2×Cima + 1×Direita ===\n");
    imprimirTabuleiro(board);
    moverCavaloComplexo(board, CAVALO, &r, &c);

    return 0;
}
