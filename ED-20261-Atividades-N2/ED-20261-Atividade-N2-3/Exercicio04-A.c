// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

int chamadas = 0;

int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    int meio;

    chamadas++;

    if (inicio > fim) {
        return -1;
    }

    meio = (inicio + fim) / 2;

    if (vet[meio] == alvo) {
        return meio;
    }

    if (alvo < vet[meio]) {
        return buscaBinaria(vet, inicio, meio - 1, alvo);
    }

    return buscaBinaria(vet, meio + 1, fim, alvo);
}

int main() {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};

    int resultado;

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 23);

    printf("Busca do 23:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n\n", chamadas);

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 50);

    printf("Busca do 50:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n\n", chamadas);

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 2);

    printf("Busca do 2:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n", chamadas);

    return 0;
}
