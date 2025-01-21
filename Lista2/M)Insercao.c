#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
    if (r == NULL) {
        no *novo = (no *)malloc(sizeof(no));
        novo->chave = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    }
    else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }

    return r;
}

no* buscar(struct no* raiz, int chave) {
    // Se a árvore está vazia ou o valor foi encontrado
    if (raiz == NULL || raiz->chave == chave)
        return raiz;

    // Se o valor é maior que o valor do nó atual, buscar na subárvore direita
    if (chave > raiz->chave)
        return buscar(raiz->dir, chave);

    // Se o valor é menor que o valor do nó atual, buscar na subárvore esquerda
    return buscar(raiz->esq, chave);
}