#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *minimo (no *r) { 
    no* atual = r;

    while (atual != NULL && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual; 
}