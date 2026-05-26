// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

int main() {
    int v[] = {10, 20, 30, 40, 50};

    int *inicio = v;
    int *fim = v + 4;

    int *p;
    int soma = 0;

    printf("Vetor original:\n");

    for (p = v; p < v + 5; p++) {
        printf("Valor: %d\n", *p);
        printf("Endereco: %p\n", p);

        soma += *p;
    }

    printf("\nSoma = %d\n", soma);

    while (inicio < fim) {
        *inicio = *inicio + *fim;
        *fim = *inicio - *fim;
        *inicio = *inicio - *fim;

        inicio++;
        fim--;
    }

    printf("\nVetor invertido:\n");

    for (p = v; p < v + 5; p++) {
        printf("%d ", *p);
    }

    printf("\n");

    return 0;
}
