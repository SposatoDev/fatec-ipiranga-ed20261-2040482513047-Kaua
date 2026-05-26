// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

void espacos(int nivel) {
    int i;

    for (i = 0; i < nivel * 2; i++) {
        printf(" ");
    }
}

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    if (n == 1) {
        espacos(nivel);

        printf("Nivel %d -> mover disco 1 de %c para %c\n",
               nivel,
               origem,
               destino);

        return;
    }

    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    espacos(nivel);

    printf("Nivel %d -> mover disco %d de %c para %c\n",
           nivel,
           n,
           origem,
           destino);

    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {
    int n;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B', 0);

    return 0;
}
