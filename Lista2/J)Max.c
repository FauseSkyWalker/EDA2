#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no* maximo(no* r) { 
    no* atual = r;

    while (atual != NULL && atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual; 
}