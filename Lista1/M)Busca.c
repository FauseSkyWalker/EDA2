#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *p;
    for (p = le->prox; p != NULL; p = p->prox) {
        if (p->dado == x) {
            return p;
        }
    }
    return NULL;
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL;
    }
    if (le->dado == x) {
        return le;
    }
    return busca_rec(le->prox, x);
}