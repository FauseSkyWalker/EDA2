#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *antecessor(no *r) {
    no *atual = r;
    while (atual && atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL;
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        } else if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        } else {
            no *temp = antecessor(r->esq);
            r->chave = temp->chave;
            r->esq = remover(r->esq, temp->chave);
        }
    }

    return r;
}
