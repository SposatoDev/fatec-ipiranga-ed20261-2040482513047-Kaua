// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int contarFolhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }

    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

int contarInternos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 0;
    }

    return 1 + contarInternos(raiz->esq) + contarInternos(raiz->dir);
}

int somarValores(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return raiz->dado +
           somarValores(raiz->esq) +
           somarValores(raiz->dir);
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);

    free(raiz);
}

int main() {
    int valores[] = {50, 30, 70, 20, 40, 60, 80};

    No* raiz = NULL;

    int i;

    int totalNos;
    int folhas;
    int internos;
    int soma;

    float media;

    for (i = 0; i < 7; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    totalNos = contarNos(raiz);

    folhas = contarFolhas(raiz);

    internos = contarInternos(raiz);

    soma = somarValores(raiz);

    media = (float) soma / totalNos;

    printf("Total de nos: %d\n", totalNos);
    printf("Folhas: %d\n", folhas);
    printf("Nos internos: %d\n", internos);
    printf("Soma dos valores: %d\n", soma);
    printf("Media: %.2f\n", media);

    liberarArvore(raiz);

    return 0;
}
