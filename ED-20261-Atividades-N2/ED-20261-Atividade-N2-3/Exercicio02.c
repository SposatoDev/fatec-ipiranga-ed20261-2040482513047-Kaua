// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

float calcularMedia(float *vet, int n) {
    float soma = 0;
    int i;

    for (i = 0; i < n; i++) {
        soma += *vet;
        vet++;
    }

    return soma / n;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    int i;

    *maior = *vet;
    *menor = *vet;

    for (i = 0; i < n; i++) {
        if (*vet > *maior) {
            *maior = *vet;
        }

        if (*vet < *menor) {
            *menor = *vet;
        }

        vet++;
    }
}

void normalizar(float *vet, int n) {
    int i;
    float maior = *vet;

    for (i = 0; i < n; i++) {
        if (*vet > maior) {
            maior = *vet;
        }

        vet++;
    }

    vet = vet - n;

    for (i = 0; i < n; i++) {
        *vet = *vet / maior;
        vet++;
    }
}

void imprimirVetor(float *vet, int n, const char *titulo) {
    int i;

    printf("%s\n", titulo);

    for (i = 0; i < n; i++) {
        printf("%.2f ", *vet);
        vet++;
    }

    printf("\n\n");
}

int main() {
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    float media;
    float maior;
    float menor;

    imprimirVetor(notas, 6, "Vetor original:");

    media = calcularMedia(notas, 6);

    encontrarExtremos(notas, 6, &maior, &menor);

    normalizar(notas, 6);

    imprimirVetor(notas, 6, "Vetor normalizado:");

    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);

    return 0;
}
