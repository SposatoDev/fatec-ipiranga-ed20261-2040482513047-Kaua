// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        movimentos++;
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);

    movimentos++;

    hanoi(n - 1, auxiliar, destino, origem);
}

int calcularEsperado(int n) {
    if (n == 0) {
        return 0;
    }

    return 2 * calcularEsperado(n - 1) + 1;
}

int main() {
    int n;

    printf("n | Contado | Esperado\n");

    for (n = 1; n <= 6; n++) {
        movimentos = 0;

        hanoi(n, 'A', 'C', 'B');

        printf("%d | %d | %d\n",
               n,
               movimentos,
               calcularEsperado(n));
    }

    return 0;
}

/*
n | Contado | Esperado
1 | 1 | 1
2 | 3 | 3
3 | 7 | 7
4 | 15 | 15
5 | 31 | 31
6 | 63 | 63
*/
