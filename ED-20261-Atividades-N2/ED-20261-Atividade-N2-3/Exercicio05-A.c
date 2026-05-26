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

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }

    if (valor < raiz->dado) {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}

int alturaNo(No* no) {
    int esq;
    int dir;

    if (no == NULL) {
        return -1;
    }

    esq = alturaNo(no->esq);
    dir = alturaNo(no->dir);

    if (esq > dir) {
        return esq + 1;
    }

    return dir + 1;
}

int profundidadeNo(No* raiz, int valor, int prof) {
    if (raiz == NULL) {
        return -1;
    }

    if (raiz->dado == valor) {
        return prof;
    }

    if (valor < raiz->dado) {
        return profundidadeNo(raiz->esq, valor, prof + 1);
    }

    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No* no) {
    int grau = 0;

    if (no == NULL) {
        return -1;
    }

    if (no->esq != NULL) {
        grau++;
    }

    if (no->dir != NULL) {
        grau++;
    }

    return grau;
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
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};

    No* raiz = NULL;

    int i;

    for (i = 0; i < 11; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Altura do no 50: %d\n", alturaNo(buscar(raiz, 50)));
    printf("Profundidade do no 45: %d\n", profundidadeNo(raiz, 45, 0));
    printf("Grau do no 30: %d\n", grauNo(buscar(raiz, 30)));

    liberarArvore(raiz);

    return 0;
}
