/*-----------------------------------------------*/
/* FATEC - Ipiranga                              */
/* ADS - Estrutura de Dados                      */
/* Atividade: N1-3                               */
/* Pilha RPN (HP12c - simples)                   */
/* Autor: SposatoDev                             */
/*-----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    float t, z, y, x;
} HP12c;

void inicializar(HP12c *c) {
    c->t = c->z = c->y = c->x = 0.0f;
}

void mostrar(HP12c *c) {
    printf("T: %.2f | Z: %.2f | Y: %.2f | X: %.2f\n\n", c->t, c->z, c->y, c->x);
}

void empilhar(HP12c *c, float valor) {
    c->t = c->z;
    c->z = c->y;
    c->y = c->x;
    c->x = valor;
}

void calcular(HP12c *c, char op) {
    float r;

    if (op == '+') r = c->y + c->x;
    else if (op == '-') r = c->y - c->x;
    else if (op == '*') r = c->y * c->x;
    else if (op == '/') {
        if (c->x == 0.0f) {
            printf("Erro: divisao por zero!\n");
            return;
        }
        r = c->y / c->x;
    } else {
        printf("Operador invalido!\n");
        return;
    }

    c->x = r;
    c->y = c->z;
    c->z = c->t;
}

int main(void) {
    HP12c calc;
    inicializar(&calc);

    char expressao[] = "5 1 2 + 4 * + 3 -";
    printf("Expressao RPN: %s\n\n", expressao);

    char *token = strtok(expressao, " ");
    while (token != NULL) {
        printf("Lendo: %s\n", token);

        if (isdigit((unsigned char)token[0])) {
            empilhar(&calc, (float)atof(token));
        } else {
            calcular(&calc, token[0]);
        }

        mostrar(&calc);
        token = strtok(NULL, " ");
    }

    printf("Resultado final: %.0f\n", calc.x);
    return 0;
}
