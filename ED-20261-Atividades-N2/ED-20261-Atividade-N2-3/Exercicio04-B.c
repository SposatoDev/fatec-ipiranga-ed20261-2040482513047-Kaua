// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

int chamadasRapida = 0;
int chamadasIngenua = 0;

long long potenciaRapida(long long base, int exp) {
    long long metade;

    chamadasRapida++;

    if (exp == 0) {
        return 1;
    }

    if (exp % 2 == 0) {
        metade = potenciaRapida(base, exp / 2);

        return metade * metade;
    }

    return base * potenciaRapida(base, exp - 1);
}

long long potenciaIngenua(long long base, int exp) {
    chamadasIngenua++;

    if (exp == 0) {
        return 1;
    }

    return base * potenciaIngenua(base, exp - 1);
}

int main() {
    printf("2^10 = %lld\n", potenciaRapida(2, 10));
    printf("Chamadas rapida: %d\n\n", chamadasRapida);

    chamadasRapida = 0;

    printf("3^7 = %lld\n", potenciaRapida(3, 7));
    printf("Chamadas rapida: %d\n\n", chamadasRapida);

    chamadasRapida = 0;

    printf("5^0 = %lld\n", potenciaRapida(5, 0));
    printf("Chamadas rapida: %d\n\n", chamadasRapida);

    chamadasRapida = 0;

    printf("7^12 = %lld\n", potenciaRapida(7, 12));
    printf("Chamadas rapida: %d\n\n", chamadasRapida);

    printf("Comparacao:\n");

    potenciaIngenua(2, 10);

    printf("Ingenua 2^10: %d chamadas\n", chamadasIngenua);

    chamadasIngenua = 0;

    potenciaRapida(2, 10);

    printf("Rapida 2^10: %d chamadas\n", chamadasRapida);

    return 0;
}

/*
Potencia ingenua:
b^n = b * b^(n-1)

A recursao acontece uma vez para cada expoente.

Exemplo:
2^10 -> 10 chamadas

Potencia rapida:
divide o problema pela metade quando o expoente eh par.

Complexidade:
Ingenua -> O(n)
Rapida -> O(log n)
*/
