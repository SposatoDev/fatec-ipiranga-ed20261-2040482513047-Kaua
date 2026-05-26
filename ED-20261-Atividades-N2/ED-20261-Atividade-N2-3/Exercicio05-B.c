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

void preOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->dado);

    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void emOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->esq);

    printf("%d ", raiz->dado);

    emOrdem(raiz->dir);
}

void posOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);

    printf("%d ", raiz->dado);
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

    for (i = 0; i < 7; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Pre-ordem:\n");
    preOrdem(raiz);

    printf("\n\nEm ordem:\n");
    emOrdem(raiz);

    printf("\n\nPos-ordem:\n");
    posOrdem(raiz);

    printf("\n");

    liberarArvore(raiz);

    return 0;
}
